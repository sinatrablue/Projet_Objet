#include<iostream>
#include<string>
#include<list>
#include"centre.hpp"

using namespace std;

int main(void){
    Cliche c1 = Cliche(2);
    Cliche c2 = Cliche(2);
    if(c1==c2){
        cout << "Oui" << endl;
    }

    list<Examen> E;

    Patient p1 = Patient("Lilia", "Younsi", 18, 'H', E);
    Patient p2 = Patient("Oussalah", "Chabane", 75, 'H', E);
    if(p1==p2){
        cout << "Oui2" << endl;
    } else {
        cout << "NON" << endl;
    }

    return EXIT_SUCCESS;
}