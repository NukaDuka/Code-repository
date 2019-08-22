from imutils.object_detection import non_max_suppression
import numpy as np
import cv2
from math import ceil
from imtools import showim, imbinarize
import csv
import os
from east import *

img = cv2.imread("C:\\Users\\kartik.gokte\\Desktop\\python tut\\out.jpg")
img = 255-img
img = cv2.resize(img, (int(img.shape[1]*2), int(img.shape[0]*2)))
print(img.shape)
img = cv2.dilate(img,cv2.getStructuringElement(cv2.MORPH_RECT,(5,5)), iterations = 1)
img = cv2.morphologyEx(img, cv2.MORPH_OPEN, cv2.getStructuringElement(cv2.MORPH_RECT,(5,5)))

img = cv2.resize(img, (int(img.shape[1]/2), int(img.shape[0]/2)))
img = 255-img
cv2.imwrite('t.jpg', img)

detect('C:\\Users\\kartik.gokte\\Desktop\\python tut\\t.jpg', True, 'C:\\Users\\kartik.gokte\\Desktop\\deleting_instruments\\Video_output\\PAGE-1_PP-HM1224.pdf\\output_drawing.jpg')
