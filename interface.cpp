#include<iostream>
#include<istream>
#include<string>
#include<list>
#include<fstream>
#include"centre.hpp"

using namespace std;

int main(){
 Centre centreTest;
 Examen examenTest;
 Patient patientTest;
 Rapport rapportTest;
 int choice, nb;
 string ajout, supp, numex_sup;

    cout << "Veuillez donner le nom de votre centre : ";
    string nomc;
    cin >> nomc;

	do {
    cout << "Bienvenu dans le centre de Radiographie : " << nomc << endl;
    cout << "###########  Menu Principal  ###########" << endl;
		cout << "[#######################################]\n0 : Quitter \n1 : Ajout d'Examen/Patient \n2 : Suppression d'Examen/Patient \n3 : Affichage des caractéristiques des Examens \n4 : Charger/Exporter la liste des radiographies \n[#######################################]" << endl;
    cout << "~>  ";
    cin >> choice;
        switch(choice){
            case 1:
            cout <<"Veuillez préparer votre fichier texte contenant les caractéristiques de l'Examen ou du Patient à ajouter." << endl;
            cout << "----------------------------------------------------------------------------------------------------------" << endl;
            cout << "Vous voulez ajouter un Examen -> appuyez sur E ; si c'est un Patient -> appuyez sur P " << endl;
            cout << "~>  ";
            cin >> ajout;
            if (ajout=="E")
            {
                centreTest.set_Examens(centreTest.importExamFromFile());
                //cout << "Examen bien enregistré" << endl;
            }
            else if (ajout=="P")
            {
                centreTest.importPatientFromFile();
                //cout << "Patient bien enregistré" << endl;
            }
            else
            {

                cout << "Vous n'avez pas saisis une lettre valable." << endl;
                cout << "#######  Retour au Menu Principal  #######" << endl;
            } break;
            case 2:
            cout << "Vous voulez supprimer un Examen -> appuyez sur E ; si c'est un Patient -> appuyez sur P " << endl;
            cout << "~>  ";
            cin >> supp;
            if (supp=="E")
            {
                cout << "Veuillez saisir le numéro d'examen a supprimer : ";
                cin >> numex_sup;
                Examen e;
                list<Examen> ee = centreTest.get_Examens();
                for(auto i=ee.begin(); i!=ee.end(); i++){
                    if(i->get_NoExam()==numex_sup){
                    e = Examen(i->get_NoExam(),i->get_Type(),i->get_Date(),i->get_Etat(),i->get_Cliches(),i->get_Rapport());
                    list<Examen> Ex;
                    Ex.push_back(e);
                    examenTest.supprimer_Examen(Ex);
                    }
                }

            }
            else if (supp=="P")
            {
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
                list<Patient> pp = centreTest.get_Patients();
                for(auto i=pp.begin(); i!=pp.end(); i++){
                    if(i->get_Name()==nom_sup && i->get_FirstName()==prenom_sup && i->get_Sexe()==sexe_supp && i->get_Age()==age_supp){
                    p = Patient(i->get_Name(),i->get_FirstName(),i->get_Age(),i->get_Sexe(),i->get_Examenss());
                    list<Patient> P;
                    P.push_back(p);
                    patientTest.supprimer_Patient(P);
                    }
                }
            }
            else
            {

                cout << "  Vous n'avez pas saisi une lettre valable.  " << endl;
                cout << "#####  Retour au Menu Principal  #####" << endl;
            } break;
            case 3:
            {
            do
            {
                cout << "##### Caractéristiques des Examens : CE ####"<<endl;
                cout << "[###########################################]\n0 : Quitter \n1 : Afficher CE par Patient \n2 : Afficher CE par numéro d'examen \n3 : Afficher CE par date \n [###########################################]" << endl;
                cout << "~>  ";
                cin>>nb;
                switch(nb){
                  case 1 :
                  {
                  string nom;
                  string prenom;
                  int age;
                  string sexe;
                  cout<<"Vous voulez afficher les CE par patient :"<<endl;
                  cout<<"Donnez le nom du patient"<<endl;
                  cout<<"~>  ";
                  cin>>nom;
                  cout<<"Donnez le prénom du patient"<<endl;
                  cout<<"~>  ";
                  cin>>prenom;
                  cout<<"Donnez l'âge du patient"<<endl;
                  cout<<"~>  ";
                  cin>>age;
                  cout<<"Donnez le sexe (H/F) du patient"<<endl;
                  cout<<"~>  ";
                  cin>>sexe;
                  centreTest.car_pat(nom,prenom,age,sexe);
                  break;
                  }
                  case 2 :
                  {
                  cout <<"Vous voules afficher les CE par numéro d'examen"<<endl;
                  cout <<"Donnez le numéro d'examen"<<endl;
                  cout<<"~>  ";
                  string num;
                  cin>>num;
                  centreTest.car_num(num);
                  break;
                  }
                  case 3:
                  {
                  cout <<"Vous voules afficher les CE par la date de l'examen"<<endl;
                  cout <<"Donnez la date de l'examen"<<endl;
                  cout<<"~>  " << endl;
                  string date;
                  cin>>date;
                  centreTest.car_date(date);
                  break;
                  }
                }
            } while (nb !=0);
          }
            break;
            case 4:
            cout <<"Vous voulez Sauvegarder un examen -> appuyez sur S , si c'est pour Charger un examen -> appuyer sur C "<<endl;
            cout << "~>  " << endl;
            string SC;
            cin>> SC;
            if (SC=="C")
            {
               centreTest.set_Examens(centreTest.importExamFromFile());
               cout<<"Chargement de l'examen bien réussi."<<endl;
            }
            else if (SC=="S")
            {
                centreTest.exportExamToFile(centreTest.get_Examens());
                cout << "Fichier bien sauvegardé." << endl;
            }
            else
            {
                cout<<"Vous n'avez pas saisis une lettre valable."<<endl;
                cout<<"######## Retour au Menu Principal ########"<<endl;
            }break;

        }

    } while (choice !=0);
    if(choice == 0){
		cout << "[ -- session ended -- ]" << endl;
    } else {
		cout << "[ -- bad choice, restart -- ]" << endl;
		exit(1);
	}

	return EXIT_SUCCESS;
}
