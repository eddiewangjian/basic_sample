mkdir output
cd output/ && rm * -rf && cd -

g++ -c -std=c++11 -pthread *.h *.cpp
ar -crv output/libj.a *.o
cp *.h output

rm *.o *.gch
