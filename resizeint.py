from imutils.object_detection import non_max_suppression
import numpy as np
import cv2
from math import ceil
from imtools import showim, imbinarize
import pytesseract
import csv
import os
import shutil
import time

def resizeint(imgpath, scale=2):
    img = cv2.imread(imgpath)
    img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    print(img.shape)
    (h, w) = img.shape
    nh = int(h * scale)
    nw = int(w * scale)
    resimg = cv2.resize(img, (nw, nh), interpolation=cv2.INTER_AREA)
    print(resimg.shape)
    return resimg

if __name__ == "__main__":
    img = resizeint('C:\\Users\\kartik.gokte\\Desktop\\python tut\\opencv\\output\\basf\\0_JP-43-A08-0011-03.pdf.jpg')
    cv2.imwrite('res.jpg', img)
