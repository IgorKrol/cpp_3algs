#!make -f

# all: test
# 	./$<

test: main.cpp alg.h
	g++ -std=c++11 main.cpp alg.h -o test

clean:
	rm -f *.o demo test