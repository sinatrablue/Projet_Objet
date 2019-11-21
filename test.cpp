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

    return EXIT_SUCCESS;
}