# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

import os.path
import os
import glob
import numpy as np
import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
import matplotlib.pyplot as plt
import numpy as np
import time
import cv2
import sys
from torchvision import datasets, transforms, models
from torch.utils.data import DataLoader


def train_model(model, DEVICE, train_loader, optimizer, scheduler):
    start_time = time.time()
    model.train()
    loss_sum = 0.0
    correct_num = 0
    for batch_index, (data, target) in enumerate(train_loader):
        data = data.to(DEVICE)
        target = target.to(DEVICE)
        optimizer.zero_grad()

        output = model(data)
        loss = F.cross_entropy(output, target)
        # loss = loss.requires_grad_()
        loss_sum += loss.item()
        pred = output.argmax(dim=1)
        correct_num += pred.eq(target.view_as(pred)).sum().item() # 同一批次中匹配的求和

        loss.backward()
        optimizer.step()
        if batch_index % 8 == 0:
            print("BATCH INDEX: {}\t LOSS: {:4f}".format(batch_index, loss.item()))
        if batch_index > 30:
            break
    # loss_rate = loss_sum / len(train_loader.dataset)
    # accuracy = correct_num / len(train_loader.dataset)
    loss_rate = loss_sum / 31 / 16
    accuracy = correct_num / 31 / 16
    time_cost = time.time() - start_time
    model_weights = model.state_dict()
    print("train loss: {:6f} || accu: {:6f} || time_cost {:f}".format(loss_rate, accuracy, time_cost))
    return accuracy, model_weights


def valid_model(model, DEVICE, valid_loader, optimizer, scheduler):
    start_time = time.time()
    model.eval()
    loss_sum = 0.0
    correct_num = 0
    with torch.no_grad():
        for batch_index, (data, target) in enumerate(valid_loader):
            data = data.to(DEVICE)
            target = target.to(DEVICE)
            optimizer.zero_grad()

            output = model(data)
            loss = F.cross_entropy(output, target)
            loss = loss.requires_grad_()
            loss_sum += loss.item()
            pred = output.argmax(dim=1)
            correct_num += pred.eq(target.view_as(pred)).sum().item() # 同一批次中匹配的求和

            optimizer.step()
            if batch_index % 8 == 0:
                print("BATCH INDEX: {}\t LOSS: {:4f}".format(batch_index, loss.item()))
            if batch_index > 10:
                break
    # loss_rate = loss_sum / len(train_loader.dataset)
    # accuracy = correct_num / len(train_loader.dataset)
    loss_rate = loss_sum / 11 / 16
    accuracy = correct_num / 11 / 16
    time_cost = time.time() - start_time
    print("train loss: {:6f} || accu: {:6f} || time_cost {:f}".format(loss_rate, accuracy, time_cost))


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    path = r"D:/PyCharm Community Edition 2021.1.3/Pyproj 5/dogs-vs-cats/"
    # os.makedirs(os.path.join(path, 'valid/'))

    files = glob.glob(os.path.join(path, "*/*.jpg"))
    image_num = len(files)
    print(f"Total number of images {len(files)}")
    shuffle = np.random.permutation(image_num)
    try:
        os.makedirs(os.path.join(path, 'valid'))
    except Exception:
        pass
    for t in ["train/", "valid/"]:
        for f in ["dog/", "cat/"]:
            try:
                os.makedirs(os.path.join(path, t, f))
            except Exception:
                pass
    #
    # for i in shuffle[:4000]:
    #     folder = files[i].split('\\')[-1]
    #     next_folder = folder.split(".")[-3]
    #     os.rename(files[i], os.path.join(path, "valid", next_folder, folder))
    # for i in shuffle[4000:]:
    #     folder = files[i].split('\\')[-1]
    #     next_folder = folder.split(".")[-3]
    #     os.rename(files[i], os.path.join(path, "train", next_folder, folder))

    # 0 - image_num-1 输出随机排列
    DEVICE = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    EPOCHS = 4
    pipeline = transforms.Compose([
        transforms.Resize((224, 224)),
        #  UserWarning: The use of the transforms.Scale transform is deprecated, please use transforms.Resize instead.
        transforms.ToTensor(),
        #  mean, std
        transforms.Normalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225])
    ])

    train_set = datasets.ImageFolder("dogs-vs-cats/train", pipeline)
    valid_set = datasets.ImageFolder("dogs-vs-cats/valid", pipeline)

    train_loader = DataLoader(train_set, batch_size=16, shuffle=True, num_workers=3)
    valid_loader = DataLoader(valid_set, batch_size=16, shuffle=True, num_workers=3)

    model = models.resnet18(pretrained=True)
    # cnt how many neuron in fc
    num_features = model.fc.in_features
    model.fc = nn.Linear(num_features, 2)
    model = model.to(DEVICE)
    optimizer = optim.SGD(model.parameters(), lr=0.01, momentum=0.8)
    scheduler = torch.optim.lr_scheduler.StepLR(optimizer, step_size=2, gamma=0.1)
    max_accuracy = 0.0
    for epoch in range(1, EPOCHS + 1):
        [accuracy, model_weight] = train_model(model, DEVICE, train_loader, optimizer, scheduler)
        if accuracy>max_accuracy:
            max_accuracy = accuracy
            best_model_weight = model_weight
        valid_model(model, DEVICE, valid_loader, optimizer, scheduler)
        scheduler.step()
    print("max acc : {:4f}".format(max_accuracy))
    model.load_state_dict(best_model_weight)

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
