prog: main.o utilitaires.o operations.o lit_ecrit.o
	g++ -o prog main.o utilitaires.o operations.o lit_ecrit.o

main.o: main.cpp
	g++ -c main.cpp

utilitaires.o : utilitaires.cpp 
	g++ -c utilitaires.cpp

operations.o: operations.cpp
	g++ -c operations.cpp 

lit_ecrit.o: lit_ecrit.cpp
	g++ -c lit_ecrit.cpp