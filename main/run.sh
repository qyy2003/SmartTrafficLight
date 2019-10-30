./generate
cd ../darknet
#rm out.txt
./darknet detect cfg/yolov3.cfg yolov3.weights ../main/now.jpg
#eog predictions.jpg &
cp -vf out.txt ../main/main.in
cd ../main
#gedit main.in & 
#g++ -o main main.cpp -lm
#./main<main.in
