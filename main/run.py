import cv2
import os
def work(time):
    print(time)
    os.system('./run.sh')
    os.system('./main<main.in')

vc = cv2.VideoCapture('data/main.mp4')
os.system('g++ -o main main.cpp')
c = 0
print("Begin")
if vc.isOpened():
    rval, frame = vc.read()
else:
    rval = False
    print("Can't open file")

f=open("../darknet/out.txt","w");
f.write('0\n0 0\n');
f.close();
os.system('firefox index.html &')
os.system('rm main.in out1.txt out2.txt main1.in')
os.system('g++ -o main main.cpp')
os.system('cmake .')
os.system('make')

timeF =int(vc.get(5))
rval,frame = vc.read()
while rval: 
    #print(c);
    if (c % timeF == 0):
        cv2.imwrite('now.jpg', frame)
        #if(c / timeF <=5):
        work( int( c / timeF ) )
    c = c + 1
    rval,frame = vc.read()
vc.release()
print("End")

