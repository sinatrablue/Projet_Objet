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
    // Séparation des n° de clichés
    list<Cliche> l;
    string delim = ","; // délimiteur, chez nous une virgule
    size_t pos = 0; // position initiale de lecture
    string token; // variable qui prendra chaque numéro sur la ligne 1 par 1
    while ((pos = numeroCliches.find(delim)) != std::string::npos) {  // tant qu'on trouve des délimiteurs (ce qui explique que dans le fichier exam.txt on ai aussi une virgule après le dernier numéro)
    token = numeroCliches.substr(0, pos);  // le token prend la valeur du numéro de cliché n de la ligne
    //cout << "token : " << token << endl;
    Cliche c = Cliche(token); // on initialise un objet de type Cliche avec le numéro
    l.push_back(c); // On l'inclue dans la liste de clichés de l'examen
    numeroCliches.erase(0, pos + delim.length());
    }

    Rapport r = Rapport(contentRapport, mdpRapport); // initialisation d'un rapport avec les données recueillies
    Examen ex = Examen(numeroExam, typeExam, dateExam, etatExam, l, r); // initialisation de l'examen
    cout << "Examen bien créé" << endl;

    ex.ajouter_Examen(listExam); // ajout de l'examen à la liste du centre

    file.close();
    return listExam; // on retourne la liste d'Exams du centre
}

void Centre::exportExamToFile(std::list<Examen> listExamen){
    // Le même procédé et le même raisonnement que la fonction précédente mais dans le sens inverse, on prend dans la base du centre pour écrire dans le fichier
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
    // Initialisation de la lecture n° par n° sur la liste avec la virgule comme délimiteur
    string delim = ",";
    size_t pos = 0;
    string token;
    int verif = 0;  // pour un contôle en fin de boucle
    while ((pos = lineE.find(delim)) != std::string::npos) {
        token = lineE.substr(0, pos);
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
        //cout << "Taille de la liste d'exams à mettre dans le patient : " << E.size() << endl;
        lineE.erase(0, pos + delim.length());
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


void Centre ::car_pat(std::string N, std::string P, int A, std::string S){

    list <Patient> ls_p = get_Patients();
    list<Examen> E_p= get_Examens();
    if (ls_p.size() == 0 || E_p.size() == 0)
    {
        cout<<"Erreur : Il n'y a aucun Examen pour "<<N<<" "<<P<<" "<< "dans la base de donnée"<<endl;
    }
    else
    {
    for(list<Patient>::iterator it=ls_p.begin(); it!=ls_p.end(); it++){
        if (it->get_FirstName()==P && it->get_Name() ==N && it->get_Age()==A && it->get_Sexe()==S){
            list<Examen> E=it->get_Examenss();
            Patient pat_choisi(N,P,A,S,E); // on construit un patient avec les infos passées en arguments
            pat_choisi.affiche(); // on l'affiche
            cout<<"Voici les caractéristiques des examens de "<< P << endl;
            for (list<Examen>::iterator it = E.begin(); it!=E.end(); it++){
                string N_ex=it->get_NoExam();
                for (list<Examen>::iterator it = E_p.begin(); it!=E_p.end(); it++)
                {
                    if (N_ex==it->get_NoExam()); // on récupère chacun de ses examens dans la base du centre
                    {
                        string numEX= it->get_NoExam();
                        string typeEX= it->get_Type();
                        list<Cliche> clicheEX= it->get_Cliches();
                        Rapport rapportEX= it->get_Rapport();
                        string dateEX= it->get_Date();
                        bool etatEX= it->get_Etat();
                        Examen E (numEX,typeEX,dateEX,etatEX,clicheEX,rapportEX);
                        E.affiche(); // on affiche les caractéristiques de l'examen
                    }
                }
            }
        }
        else{
            cout<<"Erreur : Le patient "<<N<<" "<<P<<" n'existe pas dans la base de données"<<endl;
        }



    }
    }

}

void Centre:: car_num(std::string num){
    list <Examen> E =get_Examens();
    if (E.size()==0)
    {
        cout<<"Erreur : il n'y a aucun Examen dans la base de donnée"<<endl;
    }
    else{

    for (list<Examen>::iterator it = E.begin(); it!=E.end(); it++){
        if (num==it->get_NoExam())
        {
            string numEX= it->get_NoExam();
            string typeEX= it->get_Type();
            list<Cliche> clicheEX= it->get_Cliches();
            Rapport rapportEX= it->get_Rapport();
            string dateEX= it->get_Date();
            bool etatEX= it->get_Etat();
            Examen E (numEX,typeEX,dateEX,etatEX,clicheEX,rapportEX);
            cout<<"Voici les caractéristiques de l'Examen numéro "<< num << endl;
            E.affiche();

        }
        else{
            cout<<"le numero d'examen " <<num<< " n'existe pas dans la base de données."<<endl;
        }

    }
    }

}

void Centre:: car_date(std::string date){
     list <Examen> E =get_Examens();
     if (E.size()==0)
    {
        cout<<"Erreur : il n'y a aucun Examen dans la base de données."<<endl;
    }
    else{
      for (list<Examen>::iterator it = E.begin(); it!=E.end(); it++){
          if (date==it->get_Date())
          {
              string numEX= it->get_NoExam();
              string typeEX= it->get_Type();
              list<Cliche> clicheEX= it->get_Cliches();
              Rapport rapportEX= it->get_Rapport();
              string dateEX= it->get_Date();
              bool etatEX= it->get_Etat();
              Examen E (numEX,typeEX,dateEX,etatEX,clicheEX,rapportEX);
              cout<<"Voici les caractéristiques de l'Examen du "<< date<< endl;
              E.affiche();

          }
          else{
              cout<<"Une radiographie n'a pas été enregistré le : "<<date<<endl;
          }
      }
    }
}


list<Examen> Centre::supprimer_Examen(Centre test){
    cout << "Veuillez saisir le numéro d'examen a supprimer : "<<endl;
    string numex_sup;
    cin >> numex_sup;
    //Centre test;
    Examen e;
    list<Examen> ee = test.get_Examens();
    for(auto i=ee.begin(); i!=ee.end(); i++){
        if(i->get_NoExam()==numex_sup){
            e = Examen(i->get_NoExam(),i->get_Type(),i->get_Date(),i->get_Etat(),i->get_Cliches(),i->get_Rapport());
            i=ee.erase(i);
            test.set_Examens(ee);
            
                        
            cout<<"examen supprimé"<<endl;
           return test.get_Examens();
            
        }
    }
   
}

list<Patient> Centre :: supprimer_Patient(Centre test2){
    cout << "Veuillez saisir les informations personnelles du patient :" << endl;
    cout << "Nom : ";
    string nom_sup;
    cin >> nom_sup;
    cout << "Prénom : ";
    string prenom_sup;
    cin >> prenom_sup;
    cout << "Sexe (H/F) : ";
    string sexe_supp;
    cin >> sexe_supp;
    cout << "Âge : ";
    int age_supp;
    cin >> age_supp;
    Patient p;
    list<Patient> pp = test2.get_Patients();
    for(auto i=pp.begin(); i!=pp.end(); i++){
        if(i->get_Name()==nom_sup && i->get_FirstName()==prenom_sup && i->get_Sexe()==sexe_supp && i->get_Age()==age_supp){
        p = Patient(i->get_Name(),i->get_FirstName(),i->get_Age(),i->get_Sexe(),i->get_Examenss());
        i=pp.erase(i);
        test2.set_Patients(pp);
        cout<<"Patient bien supprimé"<<endl;
        return test2.get_Patients();
        }
    }
    
}
