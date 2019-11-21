#include<iostream>
#include<string>
#include<list>
#include"centre.hpp"

using namespace std;

int main(void){
    list<Cliche> C;
    Cliche cl = Cliche(25);
    cout << "Taille : " << C.size() << endl;
    cl.ajouter_Cliche(C);
    cout << "Taille : " << C.size() << endl;

    return EXIT_SUCCESS;
}