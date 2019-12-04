interface : interface.o cliche.o rapport.o examen.o patient.o centre.o
	g++ -o interface interface.o cliche.o rapport.o examen.o patient.o centre.o

interface.o : interface.cpp
	g++ -c interface.cpp

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
