# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
import matplotlib.pyplot as plt
import numpy as np
import time

import cv2
from torchvision import datasets, transforms
from torch.utils.data import DataLoader

# def imshow(tensor, title=None):
#     image = tensor.cpu().clone()  # we clone the tensor to not do changes on it
#     image = image.squeeze(0)  # remove the fake batch dimension
#     image = unloader(image)
#     plt.imshow(image)
#     if title is not None:
#         plt.title(title)
#     plt.pause(0.001)


class Net(nn.Module):
    def __init__(self):
        super(Net, self).__init__()
        self.conv1 = nn.Conv2d(1, 10, 5) # in out kernel
        self.conv2 = nn.Conv2d(10, 20, 3)
        self.fc1 = nn.Linear(20*10*10, 500)
        self.fc2 = nn.Linear(500, 10)

    def forward(self, x):
        input_size = x.size(0) # batch_size 一次进入16张 x.size() [batch_size, 1, 28, 28] 如下
        x = self.conv1(x) # 输入 batch_size * 1个image neuron * 28 * 28
        # 输出 batch * 10个neuron * (28 - 5 + 1(卷积)) * 24
        x = F.relu(x)
        x = F.max_pool2d(x, 2, 2) # 输入：batch*1*24*24 -> batch * 10 *12 *12

        x = self.conv2(x) # 10 -> 20
        # # -> batch * 20 * (12 - 3 + 1) *10
        x = F.relu(x)

        x = x.view(input_size, -1) # -1 为自动计算维度， 20*10*10
        # 拉平成一排 batch * 2000
        x = self.fc1(x)
        x = F.relu(x)

        x = self.fc2(x) # batch 500 ->10

        output = F.log_softmax(x, dim=1)
        return output

def imshow(inp,cmap=None):
    """Imshow for Tensor."""
    inp = inp.numpy().transpose((1, 2, 0))
    mean = np.array([0.485, 0.456, 0.406])
    std = np.array([0.229, 0.224, 0.225])
    inp = std * inp + mean
    inp = np.clip(inp, 0, 1)
    plt.imshow(inp, cmap)

def train_model(model, device, train_loader, optimizer,  epoch):
    model.train() #
    for batch_index, (data, target) in enumerate(train_loader): # data 图片， target 标签
        #   enumerate 同时获取 index 和 内容
        #   print(data, target, "\n***********************")
        data, target = data.to(device), target.to(device)
        optimizer.zero_grad()  # 梯度初始画为 0
        output = model(data)
        loss = F.cross_entropy(output, target)   # 多酚类
        # find id max
        # id_max = output.argmax(dim=1) # 每一行上找到最大值
        loss.backward()
        #  优化
        optimizer.step()
        if batch_index % 1000 == 0:
            print("batch_index : {} \t Epoch : {}Loss : {:6f}".format(batch_index,epoch, loss.item()))

def test_model (model, device, test_loader):
    # 模型验证
    model.eval()
    correct = 0.0 # 正确数
    test_loss_sum = 0.0
    cnt = 0
    with torch.no_grad():
        for data, target in test_loader:
            data, target = data.to(device), target.to(device)

            output = model(data)
            test_loss_sum += F.cross_entropy(output, target).item()
            pred = output.argmax(dim=1) # 每一行上找到最大值, 共64（batch_size）行
            # for i in range(0, 16):
            #     plt.imshow(data[i, 0, :, :].numpy())
            #     plt.show()
            #     image_name = "" + str(cnt) + "++" + str(pred.numpy()[i]) + ".jpg"
            #     cv2.imwrite(image_name, (data[i, 0, :, :].numpy()*0.3081 + 0.1307)*255)
            correct += pred.eq(target.view_as(pred)).sum().item() # 同一批次中匹配的求和
            cnt += 1

    loss_rate = test_loss_sum / len(test_loader.dataset)
    accuracy = correct / len(test_loader.dataset)
    print("loss: {:6f} || accu: {:6f}".format(loss_rate, accuracy) )



if __name__ == '__main__':
    BATCH_SIZE = 16
    DEVICE = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    EPOCHS = 1

    pipeline = transforms.Compose(
        [
            transforms.ToTensor(),
            transforms.Normalize((0.1307,), (0.3081,))
        ]
    )

    train_set = datasets.MNIST("data", train=True, download=True, transform=pipeline)
    test_set = datasets.MNIST("data", train=False, download=True, transform=pipeline)

    train_loader = DataLoader(train_set, batch_size=BATCH_SIZE, shuffle=True)
    # DATA loader
    test_loader = DataLoader(test_set, batch_size=BATCH_SIZE, shuffle=True)
    print(test_loader)

    model = Net().to(DEVICE) # 把 网搞到设备上
    # optimizer = optim.SGD(model.parameters(), lr=0.02, momentum=0.8)
    optimizer = optim.Adam(model.parameters())

    time_start = time.time()

    for epoch in range(1, EPOCHS + 1):
        train_model(model, DEVICE, train_loader, optimizer, epoch)
        test_model(model, DEVICE, test_loader)
        # test_once(model, DEVICE, test_loader, 1)

    time_end = time.time()
    print('totally cost', time_end - time_start)
#
#import time
# time_start=time.time()
# time_end=time.time()
# print('totally cost',time_end-time_start)
# from __future__ import print_function
# import argparse
# import torch
# import torch.nn as nn
# import torch.nn.functional as F
# import torch.optim as optim
# from torchvision import datasets, transforms
# from torch.optim.lr_scheduler import StepLR
#
#
# class Net(nn.Module):
#     def __init__(self):
#         super(Net, self).__init__()
#         self.conv1 = nn.Conv2d(1, 32, 3, 1)
#         self.conv2 = nn.Conv2d(32, 64, 3, 1)
#         self.dropout1 = nn.Dropout(0.25)
#         self.dropout2 = nn.Dropout(0.5)
#         self.fc1 = nn.Linear(9216, 128)
#         self.fc2 = nn.Linear(128, 10)
#
#     def forward(self, x):
#         x = self.conv1(x)
#         x = F.relu(x)
#         x = self.conv2(x)
#         x = F.relu(x)
#         x = F.max_pool2d(x, 2)
#         x = self.dropout1(x)
#         x = torch.flatten(x, 1)
#         x = self.fc1(x)
#         x = F.relu(x)
#         x = self.dropout2(x)
#         x = self.fc2(x)
#         output = F.log_softmax(x, dim=1)
#         return output
#
#
# def train(args, model, device, train_loader, optimizer, epoch):
#     model.train()
#     for batch_idx, (data, target) in enumerate(train_loader):
#         data, target = data.to(device), target.to(device)
#         optimizer.zero_grad()
#         output = model(data)
#         loss = F.nll_loss(output, target)
#         loss.backward()
#         optimizer.step()
#         if batch_idx % args.log_interval == 0:
#             print('Train Epoch: {} [{}/{} ({:.0f}%)]\tLoss: {:.6f}'.format(
#                 epoch, batch_idx * len(data), len(train_loader.dataset),
#                 100. * batch_idx / len(train_loader), loss.item()))
#             if args.dry_run:
#                 break
#
#
# def test(model, device, test_loader):
#     model.eval()
#     test_loss = 0
#     correct = 0
#     with torch.no_grad():
#         for data, target in test_loader:
#             data, target = data.to(device), target.to(device)
#             output = model(data)
#             test_loss += F.nll_loss(output, target, reduction='sum').item()  # sum up batch loss
#             pred = output.argmax(dim=1, keepdim=True)  # get the index of the max log-probability
#             correct += pred.eq(target.view_as(pred)).sum().item()
#
#     test_loss /= len(test_loader.dataset)
#
#     print('\nTest set: Average loss: {:.4f}, Accuracy: {}/{} ({:.0f}%)\n'.format(
#         test_loss, correct, len(test_loader.dataset),
#         100. * correct / len(test_loader.dataset)))
#
#
# def main():
#     # Training settings
#     parser = argparse.ArgumentParser(description='PyTorch MNIST Example')
#     parser.add_argument('--batch-size', type=int, default=64, metavar='N',
#                         help='input batch size for training (default: 64)')
#     parser.add_argument('--test-batch-size', type=int, default=1000, metavar='N',
#                         help='input batch size for testing (default: 1000)')
#     parser.add_argument('--epochs', type=int, default=2, metavar='N',
#                         help='number of epochs to train (default: 2)')
#     parser.add_argument('--lr', type=float, default=1.0, metavar='LR',
#                         help='learning rate (default: 1.0)')
#     parser.add_argument('--gamma', type=float, default=0.7, metavar='M',
#                         help='Learning rate step gamma (default: 0.7)')
#     parser.add_argument('--no-cuda', action='store_true', default=False,
#                         help='disables CUDA training')
#     parser.add_argument('--dry-run', action='store_true', default=False,
#                         help='quickly check a single pass')
#     parser.add_argument('--seed', type=int, default=1, metavar='S',
#                         help='random seed (default: 1)')
#     parser.add_argument('--log-interval', type=int, default=10, metavar='N',
#                         help='how many batches to wait before logging training status')
#     parser.add_argument('--save-model', action='store_true', default=False,
#                         help='For Saving the current Model')
#     args = parser.parse_args()
#     use_cuda = not args.no_cuda and torch.cuda.is_available()
#
#     torch.manual_seed(args.seed)
#
#     device = torch.device("cuda" if use_cuda else "cpu")
#
#     train_kwargs = {'batch_size': args.batch_size}
#     test_kwargs = {'batch_size': args.test_batch_size}
#     if use_cuda:
#         cuda_kwargs = {'num_workers': 1,
#                        'pin_memory': True,
#                        'shuffle': True}
#         train_kwargs.update(cuda_kwargs)
#         test_kwargs.update(cuda_kwargs)
#
#     transform=transforms.Compose([
#         transforms.ToTensor(),
#         transforms.Normalize((0.1307,), (0.3081,))
#         ])
#     dataset1 = datasets.MNIST('../data', train=True, download=True,
#                        transform=transform)
#     dataset2 = datasets.MNIST('../data', train=False,
#                        transform=transform)
#     train_loader = torch.utils.data.DataLoader(dataset1,**train_kwargs)
#     test_loader = torch.utils.data.DataLoader(dataset2, **test_kwargs)
#
#     model = Net().to(device)
#     optimizer = optim.Adadelta(model.parameters(), lr=args.lr)
#
#     scheduler = StepLR(optimizer, step_size=1, gamma=args.gamma)
#     for epoch in range(1, args.epochs + 1):
#         train(args, model, device, train_loader, optimizer, epoch)
#         test(model, device, test_loader)
#         scheduler.step()
#
#     if args.save_model:
#         torch.save(model.state_dict(), "mnist_cnn.pt")
#
#
# if __name__ == '__main__':
#     main()