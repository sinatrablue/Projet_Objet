#include<iostream>
#include<string>
#include<list>
#include<fstream>
#include"centre.hpp"

using namespace std;

int main(void){
    Centre centreTest;

    centreTest.set_Examens(centreTest.importExamFromFile());
    cout << "Attribut liste d'examen du centre OK" << endl;

    centreTest.exportExamToFile(centreTest.get_Examens());
    cout << "Fichier bien enregistré" << endl;

    centreTest.importPatientFromFile();
    cout << "Patient bien enregistré" << endl;
   
    return EXIT_SUCCESS;
}
