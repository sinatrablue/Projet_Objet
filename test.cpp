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

    centreTest.car_pat("saliou","thiam",14,"M");
    cout<<"caractéristiques de l'examen de saliou trouvé"<<endl;
    return EXIT_SUCCESS;
}
