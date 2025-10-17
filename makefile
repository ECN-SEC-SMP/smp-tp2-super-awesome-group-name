apk.out: main.o utilitaires.o lit_ecrit.o
	g++ -o apk.out main.o utilitaires.o lit_ecrit.o

main.o: main.cpp
	g++ -c -Wall -O0 -g main.cpp

utilitaires.o: utilitaires.cpp
	g++ -c -Wall -O0 -g utilitaires.cpp


lit_ecrit.o: lit_ecrit.cpp
	g++ -c -Wall -O0 -g lit_ecrit.cpp