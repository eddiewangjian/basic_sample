CXX = g++ 

ROOTPATH = .
CPPFLAGS = -g -Wall -fPIC -std=c++11 -pthread


CXXINCLUDE = -I$(ROOTPATH)	\
			-I$(ROOTPATH)/jlib/output	\
			-L$(ROOTPATH)/jlib/output	\
			-lj


CXXOBJ = ./test_main.o


%.o : %.cpp
	$(CXX) $(CPPFLAGS) $< -c -o $@ $(CXXINCLUDE) 


all : $(CXXOBJ)
	$(CXX) -o test_main $(CXXOBJ) $(CXXINCLUDE)
	rm *.o

clean:
	rm *.o
	rm test_main
