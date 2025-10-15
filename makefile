apk.out: main.o
	g++ -o apk.out main.o 

main.o: main.cpp
	g++ -c main.cpp