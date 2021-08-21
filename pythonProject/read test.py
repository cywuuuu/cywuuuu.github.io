# -*- coding = utf-8 -*-
# @Time : 2021-08-18 10:59
# @Author : 陈一文
# @File : read test.py
# @Software : PyCharm
import cv2
import numpy
import matplotlib.pyplot

if __name__ == '__main__':
    data = open('mnist_test.csv', 'r')
    data_lists = data.readlines()
    all_values = data_lists[28].split(',')
    image_array = numpy.asfarray(all_values[1:]).reshape((28, 28))
    matplotlib.pyplot.imshow(image_array, cmap='Greys')
    matplotlib.pyplot.show()

