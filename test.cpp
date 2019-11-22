#include<iostream>
#include<string>
#include<list>
#include<fstream>
#include"centre.hpp"
#include"more_functions.hpp"

using namespace std;

int main(void){
    Centre centreTest;

    list<Examen> listExamen = importFromFile();
    centreTest.set_Examens(listExamen);
    cout << "Attribut liste d'examen du centre OK" << endl;

    return EXIT_SUCCESS;
}
