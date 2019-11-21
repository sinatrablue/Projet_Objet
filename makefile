test : test.o cliche.o rapport.o examen.o patient.o centre.o
	g++ -o test test.o cliche.o rapport.o examen.o patient.o centre.o

test.o : test.cpp
	g++ -c test.cpp

cliche.o : cliche.cpp
	g++ -c cliche.cpp

rapport.o : rapport.cpp
	g++ -c rapport.cpp

examen.o : examen.cpp
	g++ -c examen.cpp

patient.o : patient.cpp
	g++ -c patient.cpp

centre.o : centre.cpp
	g++ -c centre.cpp
