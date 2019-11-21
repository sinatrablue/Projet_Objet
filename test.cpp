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
    Cliche cliche1 = Cliche(24545425);
    list<Cliche> C;
    C.push_back(cliche1);
    cout << "====================" << endl;

    Rapport rapport1 = Rapport("Rien à signaler sur la radio", "motdepasse");
    list<Rapport> R;
    R.push_back(rapport1);
    cout << "====================" << endl;

    Examen ex1 = Examen(3, "Radio", "12 novembre 2005", true, C, R);
    list<Examen> E;
    E.push_back(ex1);
    cout << "====================" << endl;

    Patient patient1 = Patient("Saliou", "Thiam", 21, 'H', E);
    Patient patient2 = Patient("Rosalia", "Med", 35, 'F', E);
    list<Patient> P;
    P.push_back(patient1);
    cout << "====================" << endl;

    Centre A = Centre("Centre1", "10A6435TY", "5 rue Oussalah", P, E);
    A.affiche();
    cout << "====================" << endl;

    cout << "Finished" << endl;

    return EXIT_SUCCESS;
}