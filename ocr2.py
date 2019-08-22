import cv2
import imutils
import pytesseract
from conversion import convertpdf2jpg
from imtools import showim, imbinarize
import numpy as np


img = cv2.imread('C:\\Users\\kartik.gokte\\Desktop\\python tut\\opencv\\0_JP-43-A08-0011-02.pdf.jpg')
img = cv2.resize(img, (img.shape[1]*4, img.shape[0]*4))
print(img.shape)
img = imbinarize(img)
img = ~img
kernelh = np.zeros((2,1),np.uint8)
horiz = cv2.morphologyEx(img, cv2.MORPH_OPEN, kernelh)
kernelv = np.zeros((1,2),np.uint8)
print(kernelh)
print(kernelv)
vert = cv2.morphologyEx(img, cv2.MORPH_OPEN, kernelv)

edgesh = cv2.Canny(horiz, 80,20,apertureSize = 7)
linesh = cv2.HoughLinesP(edgesh,1, np.pi/180, 100, minLineLength=250, maxLineGap=30)
for line in linesh:
    for x1,y1,x2,y2 in line:
        cv2.line(img,(x1,y1),(x2,y2),(0,255,0),2)
edgesv = cv2.Canny(vert, 80,20 ,apertureSize = 7)
linesv = cv2.HoughLinesP(edgesv,1, np.pi/180, 100, minLineLength=250, maxLineGap=30)
for line in linesv:
    for x1,y1,x2,y2 in line:
        cv2.line(img,(x1,y1),(x2,y2),(0,255,0),2)
joint = cv2.bitwise_and(horiz, vert)
#showim(joint)
img = cv2.resize(img, (int(img.shape[1]/4), int(img.shape[0]/4)))
test = cv2.resize(img, (int(720*(img.shape[1]/img.shape[0])), 720))
showim(test)
cv2.imwrite('delined.jpg', img)