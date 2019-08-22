import cv2
import imutils
from imtools import showim
from imtools import imbinarize
img = cv2.imread("Tetris.jpg")
size = (int(1080 * (img.shape[1]/img.shape[0])), 1080)
img2 = cv2.resize(img, size)
showim(img2 , 'Tetris')
gray = cv2.cvtColor(img2,cv2.COLOR_BGR2GRAY)
showim(gray, 'Grayscale')
showim(imbinarize(gray, 255  ), 'Binary image')
edge = cv2.Canny(gray, 0, 255 )
showim(edge, 'Edges')