import cv2
import imutils
import pytesseract
from conversion import convertpdf2jpg
from imtools import showim



img = cv2.imread('delined.jpg')


outp = img.copy()
print(img.shape)
print(img.shape[1]/img.shape[0])
outi = cv2.resize(outp, (int(1080*(img.shape[1]/img.shape[0])), 1080))
print(outi.shape)
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
gray = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)[1]
d = pytesseract.image_to_data(img, output_type=pytesseract.Output.DICT)
l = []
for i in range(0, len(d['top'])):
    l.append((d['left'][i], d['top'][i], d['width'][i], d['height'][i], d['conf'][i]))
    cv2.rectangle(img, (l[i][0], l[i][1]), (l[i][0] + l[i][2], l[i][1] + l[i][3]), (0, 255, 0), 2)
    cv2.putText(img, f'{l[i][4]}',(l[i][0], l[i][1]), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255))
outi = cv2.resize(img, (int(1080*(img.shape[1]/img.shape[0])), 1080))
cv2.imwrite('binaryout.jpg', gray)
cv2.imwrite('segout.jpg', img)
for i in l:
    print(i, end='\n')

out = []
print('Decoding text\n')
for i in l:
    if (i[4] == '-1' or i[4] > 95):
        print(i)
        out.append((i, pytesseract.image_to_string(img[i[1]:(i[1]+i[3]), i[0]:(i[0]+i[2])])))

for i in out:
    print(i, end='\n')
