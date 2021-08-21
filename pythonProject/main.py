# This is a sample Python script.
import numpy
import scipy.special
import matplotlib.pyplot

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.


class neural_network :

    def __init__(self, input_num, hidden_num, output_num, learning_rate):
        self.input_nodes = input_num
        self.hidden_nodes = hidden_num
        self.output_nodes = output_num
        self.learn_rate = learning_rate
        self.w_i2h = numpy.random.normal(0.0, pow(self.hidden_nodes,-0.5),(hidden_nodes, input_num))
        self.w_h2o = numpy.random.normal(0.0, pow(self.output_nodes, -0.5), (output_num, hidden_num))
        self.act_func = lambda x: scipy.special.expit(x)
        pass

    def train(self, __input, __target):
        inputs = numpy.array(__input, ndmin=2).T
        targets = numpy.array(__target, ndmin=2).T
        hidden_inputs = numpy.dot(self.w_i2h, inputs)
        hidden_outputs = self.act_func(hidden_inputs)
        final_inputs = numpy.dot(self.w_h2o, hidden_outputs)
        outputs = self.act_func(final_inputs)
        output_error = targets - outputs
        hidden_error = numpy.dot(self.w_h2o.T, output_error)
        self.w_h2o += self.learn_rate * numpy.dot(output_error * (outputs) * (1.0-(outputs)), numpy.transpose(hidden_outputs))
        self.w_i2h += self.learn_rate * numpy.dot(hidden_error * (hidden_outputs) * (1-(hidden_outputs)), numpy.transpose(inputs))
        pass

    def query(self, __input):
        inputs = numpy.array(__input, ndmin=2).T
        hidden_inputs = numpy.dot(self.w_i2h, inputs)
        hidden_outputs = self.act_func(hidden_inputs)
        final_inputs = numpy.dot(self.w_h2o, hidden_outputs)
        outputs = self.act_func(final_inputs)
        return outputs


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    input_nodes = 784
    hidden_nodes = 150
    output_nodes = 10
    learning_rate = 0.4
    n = neural_network(input_nodes, hidden_nodes, output_nodes, learning_rate)
    data = open('mnist_train.csv', 'r+')
    data_lists = data.readlines()
    data.close()
    test = open('mnist_test.csv', 'r+')
    test_lists = test.readlines()
    test.close()
    for lists in data_lists[1:20000]:
        all_values = lists.split(',')
        # image_array = numpy.asfarray(all_values[1:]/256.0 * 0.99 + 0.01).reshape((28, 28))
        inputs = numpy.asfarray(all_values[1:])/256.0 * 0.99 + 0.01
        targets = numpy.zeros(output_nodes) + 0.01
        targets[int(all_values[0])] = 1
        n.train(inputs, targets)

    # for lists in test_lists:
    #     all_values = lists.split(',')
    #     inputs = numpy.asfarray(all_values[1:] / 256.0 * 0.99 + 0.01)
    #     image_array = numpy.asfarray(all_values[1:]).reshape((28, 28))
    #     matplotlib.pyplot.imshow(image_array, cmap='Greys')
    #     matplotlib.pyplot.show()
    #     print(n.query(inputs))
    for lists in test_lists[50:55]:
        all_values = lists.split(',')
        inputs = numpy.asfarray(all_values[1:])/256.0 * 0.99 + 0.01
        image_array = numpy.asfarray(all_values[1:]).reshape((28, 28))
        matplotlib.pyplot.imshow(image_array, cmap='Greys')
        matplotlib.pyplot.show()
        ans = n.query(inputs)
        ans = ans.tolist()
        max_id = ans.index(max(ans))
        print(max_id)




# See PyCharm help at https://www.jetbrains.com/help/pycharm/
