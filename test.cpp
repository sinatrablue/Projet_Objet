#include<iostream>
#include<string>
#include<list>
#include<fstream>
#include"centre.hpp"

using namespace std;

int main(void){
    ifstream file("file.txt");
    string line;
    getline(file,line); // la première ligne est une description du fichier
    getline(file,line); // la deuxième est le numéro d'exam
    string numeroExam = line;
    getline(file,line); // la toisième est le type
    string typeExam = line;
    getline(file,line); // date de l'exam
    string dateExam = line;
    getline(file, line); // etat (fait ou non)
    bool etatExam;
    if(line=="Fait"){
        etatExam = true;
    } else {
        etatExam = false;
    }
    getline(file, line); // contenu du rapport
    string contentRapport = line;
    getline(file, line); // mot de passe
    string mdpRapport = line;
    getline(file,line); // numéros de clichés, séparés par des virgules
    string numeroCliches = line;

    Rapport r = Rapport(contentRapport, mdpRapport);
    list<Cliche> l;
    Examen ex = Examen(numeroExam, typeExam, dateExam, etatExam, l, r);    

    file.close();
    return EXIT_SUCCESS;
}