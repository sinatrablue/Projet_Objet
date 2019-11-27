#include<iostream>
#include<string>
#include<list>
#include<fstream>
#include"centre.hpp"

using namespace std;

int main(void){
    Centre centreTest;
    
    
    centreTest.set_Examens(centreTest.importFromFile());
    cout << "Attribut liste d'examen du centre OK" << endl;

    centreTest.exportToFile(centreTest.get_Examens());
    cout << "Fichier bien enregistré" << endl;

    centreTest.add_Patient();
    /*      Boucle de test qui ne fonctionne pas :
    auto start = centreTest.get_Patients().begin();
    auto end = centreTest.get_Patients().end();
    cout << "1 -- Patients :" << endl;
    for(auto it=start; it!=end; it++){
        cout << it->get_FirstName() << " " << it->get_Name() << " " << it->get_Age() << " ans." << endl;
    }
    */

    /*
    centreTest.car_pat("saliou","thiam",14,"M");
    cout << "2 -- Patients :" << endl;
    for(auto it=start; it!=end; it++){
        cout << it->get_FirstName() << " " << it->get_Name() << endl;
    }
    */

    return EXIT_SUCCESS;
}
