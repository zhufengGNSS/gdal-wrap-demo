.PHONY : all-it clean-it

CC = gcc
CXX = g++

CFLAGS = -O0 -g
CXXFLGS = -00 -g

all-it :
	gcc -g -I/usr/include/gdal -lgdal  -fPIC -shared -o libgdal_simplesurf_wrap.so gdal_simplesurf_wrap.cpp
clean-it :
	rm -f *.o *.so
	