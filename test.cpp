#include<iostream>
#include<string>
#include<list>
#include"centre.hpp"

using namespace std;

int main(void){
    list<Cliche> C;
    Cliche cl = Cliche(25);
    Cliche cll = Cliche(50);
    cout << "Taille : " << C.size() << endl;
    cl.ajouter_Cliche(C);
    cll.ajouter_Cliche(C);
    cout << "Taille : " << C.size() << endl;
    cl.supprimer_Cliche(C);
    cout << "Taille : " << C.size() << endl;
    
    return EXIT_SUCCESS;
}