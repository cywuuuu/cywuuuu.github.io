# -*- coding = utf-8 -*-
# @Time : 2021-09-04 17:54
# @Author : 陈一文
# @File : make_cartoon.py
# @Software : PyCharm
import cv2
import os
from PIL import Image


def PicToVideo(imgPath, videoPath):
    images = os.listdir(imgPath)
    img = []
    for image in images:
        img.append(int(image[9:-4]))
    img.sort()
    fps = 15  # 帧率
    fourcc = cv2.VideoWriter_fourcc(*"MJPG")
    im = Image.open(imgPath + "generated" + str(img[0]) + ".jpg")
    videoWriter = cv2.VideoWriter(videoPath, fourcc, fps, im.size)
    for im_name in range(len(images)):
        frame = cv2.imread(imgPath + "generated" + str(img[im_name]) + ".jpg")
        videoWriter.write(frame)
    videoWriter.release()


imgPath = r'''C:\Users\cyw\Downloads\mygann\content\gen\\'''
videoPath = "videoo.avi"
PicToVideo(imgPath, videoPath)
