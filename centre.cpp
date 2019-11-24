#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include"centre.hpp"
//#include"patient.hpp"
//#include"examen.hpp"

using namespace std;

Centre::Centre() {}

Centre::Centre(std::string nom_centre, std::string no_centre, std::string adresse, std::list<Patient> patients, std::list<Examen> examens)
{
    this->nom_centre=nom_centre;
    this->no_centre=no_centre;
    this->adresse=adresse;
    this->patients=patients;
    this->examens=examens;
}

std::string Centre::get_NumCentre(){
    return this->no_centre;
}

std::string Centre::get_NomCentre(){
    return this->nom_centre;
}

std::string Centre::get_Adresse(){
    return this->adresse;
}

std::list<Patient> Centre::get_Patients(){
    return this->patients;
}

std::list<Examen> Centre::get_Examens(){
    return this->examens;
}

void Centre::set_NumCentre(std::string no_centre){
    this->no_centre=no_centre;
}

void Centre::set_NomCentre(std::string nom_centre){
    this->nom_centre=nom_centre;
}

void Centre::set_Adresse(std::string adresse){
    this->adresse=adresse;
}

void Centre::set_Patients(std::list<Patient> patients){
    this->patients=patients;
}

void Centre::set_Examens(std::list<Examen> examens){
    this->examens=examens;
}

void Centre::affiche(){
    cout<< "Nous somme le centre " << this->nom_centre << '\n' << "Identifié " << this->no_centre << '\n' << "Domicilié au : " << this->adresse << endl;
}

list<Examen> Centre::importFromFile(){
    list<Examen> listExam;
    string filename;
    cout << "Donner le nom du fichier texte" << endl;
    cin >> filename;
    ifstream file(filename);
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
    if(line=="FAIT"){
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
    cout << "n° cliché : " << numeroCliches << endl;

    Rapport r = Rapport(contentRapport, mdpRapport);
    list<Cliche> l;
    Cliche c = Cliche(numeroCliches);
    l.push_back(c);
    cout << "Taille : " << listExam.size() << endl;
    Examen ex = Examen(numeroExam, typeExam, dateExam, etatExam, l, r);
    cout << "Examen bien créé" << endl;

    ex.ajouter_Examen(listExam);
    cout << "Examen ajouté à la liste" << endl;
    cout << "Taille : " << listExam.size() << endl;


    file.close();
    return listExam;
}

void Centre::exportToFile(std::list<Examen> listExamen){
    string filename;
    cout << "Donnez le nom du fichier dans lequel exporter" << endl;
    cin >> filename;
    ofstream file;
    file.open(filename);

    string descriptionFichier;
    cout << "Brève description de l'examen :" << endl;
    cin >> descriptionFichier;
    // écriture dans le fichier
    if(file){
        file << descriptionFichier << endl;
    } else {
        cout << "Problème de fichier" << endl;
    }
    for(auto it=listExamen.begin(); it!=listExamen.end(); it++){
        string numeroExam = it->get_NoExam();
        string typeExam = it->get_Type();
        string dateExam = it->get_Date();
        string etatExam;
        if(it->get_Etat()){
            etatExam="FAIT";
        } else {
            etatExam="NON FAIT";
        }
        string reportContent = it->get_Rapport().get_Rapport();
        string listCliche;
        auto taille_it = it->get_Cliches().size();
        cout << "Taille de la liste de Clichés : " << taille_it << endl;
        int j = 0;
        auto cc = it->get_Cliches();
        for(auto itr=cc.begin(); itr!=cc.end(); itr++){
            j+=1;
            cout << "j : " << j << endl;
            cout << "2ème test : " << itr->get_NoCliche() << endl;
            string c = itr->get_NoCliche();
            listCliche+=c;
            listCliche+=",";
        }
        // écriture dans le fichier
        file << numeroExam << endl;
        file << typeExam << endl;
        file << dateExam << endl;
        file << etatExam << endl;
        file << reportContent << endl;
        file << listCliche << endl;
        
    }
    file.close();
}

// import just a single Patient from a file
Patient add_Patient(){
    string filename;
    cout << "Donnez le nom du fichier depuis lequel importer" << endl;
    cin >> filename;
    ifstream file(filename);

    string line;
    getline(file,line);
    string n = line;    // nom
    getline(file, line);
    string fn = line;   // prenom
    getline(file, line);
    string a = line;
    int age = stoi(a);  // age (converted from string)
    getline(file, line);
    string s = line;
    char sexe = (char)s.c_str(); // sexe (converted from string)
    getline(file, line);
    list<Examen> E;
    string lineE = line;
    // convertir la ligne en la splittant pour remplir la liste d'Examens
    // ATTENTION utiliser le constructeur d'Examen pour chaque élément


    // Appel du constructeur du Patient pour remplir les champs :
    Patient P = Patient(n, fn, age, sexe, E);
    return P;
}

Centre::~Centre(){}
