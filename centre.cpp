#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include"centre.hpp"

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

list<Examen> Centre::importExamFromFile(){
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
    cout << "n° clichés : " << numeroCliches << endl;
    // Séparation des n° de clichés (code un peu volé sur un forum)
    list<Cliche> l;
    string delim = ",";
    size_t pos = 0;
    string token;
    while ((pos = numeroCliches.find(delim)) != std::string::npos) {
    token = numeroCliches.substr(0, pos);
    cout << "token : " << token << endl;
    Cliche c = Cliche(token);
    l.push_back(c);
    numeroCliches.erase(0, pos + delim.length());
    }

    Rapport r = Rapport(contentRapport, mdpRapport);
    Examen ex = Examen(numeroExam, typeExam, dateExam, etatExam, l, r);
    cout << "Examen bien créé" << endl;

    ex.ajouter_Examen(listExam);

    file.close();
    return listExam;
}

void Centre::exportExamToFile(std::list<Examen> listExamen){
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
void Centre::importPatientFromFile(){
    string filename;
    cout << "Donnez le nom du fichier de patient depuis lequel importer" << endl;
    cin >> filename;
    ifstream file(filename);

    string line;
    getline(file,line);
    string n = line;    // nom
    getline(file, line);
    string fn = line;    // prenom
    getline(file, line);
    string a = line;
    int age = stoi(a);  // age (converted from string)
    getline(file, line);
    string s = line;  // sexe
    getline(file, line);
    string lineE = line;

    list<Examen>E;
    // Ensuite c'est l'initialisation de la lecture n° par n° sur la liste avec la virgule comme délimiteur
    // J'ai clairement cherché sur internet et volé sur les forums, considère juste que "token" c'est le n°
    // de chaque exam sur la liste tour à tour...
    string delim = ",";
    size_t pos = 0;
    string token;
    int verif = 0;  // pour un contôle en fin de boucle
    while ((pos = lineE.find(delim)) != std::string::npos) {
        token = lineE.substr(0, pos);
        cout << "token 2 : " << token << endl;
        Examen e;  // Initialisation maintenant, si on le fait dans la boucle le E.push_back() ne marche pas
        auto ee = this->get_Examens(); // pour que la boucle 'for' ne fasse pas segmentation fault
        // Le this de la ligne du dessus c'est le centre du coup comme c'est Centre::
        for(auto i=ee.begin(); i!=ee.end(); i++){  // on itère dans la liste d'exams du centre
            if(i->get_NoExam()==token){  // quand on trouve l'exam qui correspond à celui qu'on vient de lire sur la ligne du patient
                e = Examen(i->get_NoExam(),i->get_Type(),i->get_Date(),i->get_Etat(),i->get_Cliches(),i->get_Rapport());
                // On remplit l'exam qu'on va mettre dans la liste d'exams du patients avec les éléments de l'exam, qu'on va chercher dans la base du centre
            }
        }
        E.push_back(e); // On met l'examen en question dans la liste du patient
        verif+=1;
        cout << "Taille de la liste d'exams à mettre dans le patient : " << E.size() << endl;
        lineE.erase(0, pos + delim.length()); // Je sais pas trop mais c'est pour faire boucler le while
    }
    if(verif!=E.size()){
      cout << "Attention, problème potentiel dans la liste d'Examens de ce patient" << endl;
    } else {
      cout << "Informations d'examens du patient bien enregistrées" << endl;
    }

    // Appel du constructeur du Patient pour remplir les champs :
    Patient P = Patient(n, fn, age, s, E);
    this->patients.push_back(P); // On ajoute le patient dans la liste de patients du centre
    cout << "Patient bien enregistré" << endl;
}

Centre::~Centre(){}
