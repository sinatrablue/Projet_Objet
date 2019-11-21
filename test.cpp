#include<iostream>
#include<string>
#include<list>
#include"centre.hpp"
//#include"cliche.hpp"
//#include"examen.hpp"
//#include"patient.hpp"
//#include"rapport.hpp"

using namespace std;

int main(void){
    Examen ex1 = Examen(3, "Radio", "12 novembre 2005", true);
    list<Examen> E;
    E.push_back(ex1);

    Patient patient1 = Patient("Saliou", "Thiam", 21, 'H', E);
    Patient patient2 = Patient("Rosalia", "Med", 35, 'F', E);
    list<Patient> P;
    P.push_back(patient1);

    Centre A = Centre("Centre1", "10A6435TY", "5 rue Oussalah", P, E);
    A.affiche();

    cout << "Finished" << endl;

    return EXIT_SUCCESS;
}