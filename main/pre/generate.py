import cv2
import os
vc = cv2.VideoCapture('../data/main.mp4')
print("generate Begin")
if vc.isOpened():
    rval, frame = vc.read()
else:
    rval = False
    print("Can't open file")

if rval: 
    cv2.imwrite('now.jpg', frame)
vc.release()
print("generate End")
