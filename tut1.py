import cv2
import imutils

img = cv2.imread("shapes.jpg")
(h, w, d) = img.shape
print(h)
print(w)
print(d)
cv2.imshow("Image", img[:, :, 0])
cv2.waitKey(0)
cv2.imshow("Image", img[:, :, 1])
cv2.waitKey(0)
cv2.imshow("Image", img[:, :, 2])
cv2.waitKey(0)
cv2.imshow("Image", img)
cv2.waitKey(0)
cv2.imshow("Image", img[0:399, 0:399, :])
cv2.waitKey(0)
im2 = cv2.resize(img, (int(w/2), int(h/2)))
cv2.imshow("Image", im2)
cv2.waitKey(0)
im3 = cv2.resize(img, (int(w/10), int(h/10)))
im4 = cv2.resize(im3, (int(im3.shape[1]*10), int(im3.shape[0]*10)))
cv2.imshow("Image", im3)
cv2.waitKey(0)
cv2.imshow("Image", im4)
cv2.waitKey(0)
thr1 = img >= 128
thr2 = img < 128
imb = img.copy()
imb[thr1] = 255
imb[thr2] = 0
cv2.imshow("Binary B", imb[:, :, 0])
cv2.waitKey(0)
cv2.imshow("Binary G", imb[:, :, 1])
cv2.waitKey(0)
cv2.imshow("Binary R", imb[:, :, 2])
cv2.waitKey(0)