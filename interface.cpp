#include <iostream>
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
 int choice,nb;
 string ajout,supp,numex_sup;

    cout<<"veuillez donner le nom de votre centre svp"<<endl;
    string nomc;
    cin>>nomc;

	do {
        cout <<"Bienvenu dans le centre de Radiographie :"<<nomc<<endl;
        cout<<"###### Menu Principal ######"<<endl;
		cout << "[#################################]\n0 : quitter \n1 : ajout Examen/Patient \n2 : suppression Examen/Patient \n3 : affichage des caractéristiques des Examens \n4 : Charger/Sauvegarder la liste des radiographies \n[#################################]" << endl;
		cin >> choice;
        switch(choice){
            case 1:
            cout <<"Veuillez préparer votre fichier text contenant l'Examen a ajouté ou le Patient a ajouté"<<endl;
            cout<<"-------------------------------------------------------------------"<<endl;
            cout <<"Vous voulez ajouter un Examen appuyer sur E , si c'est un Patient appuyer su P "<<endl;
            cin>>ajout;
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
                
                cout<<"Vous n'avez pas appuyez sur la bonne lettre majuscule"<<endl;
                cout<<"###### Retour au Menu Principal ######"<<endl;
            }
            break;
            case 2:
            cout <<"Vous voulez supprimez un Examen appuyer sur E , si c'est un Patient appuyer su P "<<endl;
            cin>>supp;
            if (supp=="E")
            {
                cout<<"veuillez saisir le numéro d'examen a supprimé"<<endl;
                cin>>numex_sup;
                Examen e;
                list<Examen> ee = centreTest.get_Examens();
                for(auto i=ee.begin(); i!=ee.end(); i++){  
                    if(i->get_NoExam()==numex_sup){  
                    e = Examen(i->get_NoExam(),i->get_Type(),i->get_Date(),i->get_Etat(),i->get_Cliches(),i->get_Rapport());
                    list<Examen> Ex;
                    Ex.push_back(e);//ajouté l'examen en question dans une liste d'examen vu que notre fonction supprimer_Examen a comme argument (liste Examen) 
                    examenTest.supprimer_Examen(Ex);
                    }   
                }
                
            }
            else if (supp=="P")
            {
                cout<<"veuillez saisir le nom du patient a supprimé"<<endl;
                string nom_sup;
                cin>>nom_sup;
                cout<<"veuillez saisir le prenom du patient a supprimé"<<endl;
                string prenom_sup;
                cin>>prenom_sup;
                cout<<"veuillez saisir le sexe du patient a supprimé"<<endl;
                string sexe_supp;
                cin>> sexe_supp;
                cout<<"veuillez saisir l'age' du patient a supprimé"<<endl;
                int age_supp;
                cin>>age_supp;
                Patient p;
                list<Patient> pp = centreTest.get_Patients();
                for(auto i=pp.begin(); i!=pp.end(); i++){  
                    if(i->get_Name()==nom_sup && i->get_FirstName()==prenom_sup && i->get_Sexe()==sexe_supp && i->get_Age()==age_supp){  
                    p = Patient(i->get_Name(),i->get_FirstName(),i->get_Age(),i->get_Sexe(),i->get_Examenss());
                    list<Patient> P;
                    P.push_back(p);//ajouté l'examen en question dans une liste d'examen vu que notre fonction supprimer_Examen a comme argument (liste Examen) 
                    patientTest.supprimer_Patient(P);
                    }   
                }
            }
            else
            {
                
                cout<<"Vous n'avez pas appuyez sur la bonne lettre majuscule"<<endl;
                cout<<"###### Retour au Menu Principal ######"<<endl;
            }break;
            
            case 3:
            do
            {
                cout<<"##### Cractéristiques des Examnens : CM ####"<<endl;
                cout << "[#################################]\n0 : quitter \n1 : afficher CM par Patient \n2 : afficher CM par numéro d'examen \n3 : afficher CM par date \n [#################################]" << endl;
                cin>>nb;
                switch(nb){
                case 1 : {
                string nom;
                string prenom;
                int age;
                string sexe;
                cout<<"Vous voulez afficher les CM par patient:"<<endl;
                cout<<"Donnez le nom du patient"<<endl;
                cin>>nom;
                cout<<"Donnez le prénom du patient"<<endl;
                cin>>prenom;
                cout<<"Donnez l'âge du patient"<<endl;
                cin>>age;
                cout<<"Donnez le sexe du patient"<<endl;
                cin>>sexe;
                centreTest.car_pat(nom,prenom,age,sexe);
                

                break;}
                case 2 :{
                cout <<"Vous voules afficher les CM par numéro d'examen"<<endl;
                cout <<"Donnez le numéro d'examen"<<endl;
                string num;
                cin>>num;
                centreTest.car_num(num);
                break;}
                case 3: {
                cout <<"Vous voules afficher les CM par la date de l'examen"<<endl;
                cout <<"Donnez la date de l'examen"<<endl;
                string date;
                cin>>date;
                centreTest.car_date(date);
                break; } 

                }
            } while (nb !=0);
            


            case 4:
            cout <<"Vous voulez Sauvegarder un examen appuyer sur S , si c'est pour Charger un examen appuyer sur C "<<endl;
            string SC;
            cin>> SC;
            if (SC=="C")
            {
               centreTest.set_Examens(centreTest.importExamFromFile());
               cout<<"chargement de l'examen réussi"<<endl;
            }
            else if (SC=="S")
            {
                centreTest.exportExamToFile(centreTest.get_Examens());
                cout << "Fichier bien sauvegarder" << endl;
            }
            else
            {
                cout<<"###### Retour au Menu Principal ######"<<endl;
                cout<<"Vous n'avez pas appuyez sur la bonne lettre majuscule"<<endl;
            }break;
                                                 
        }
       
    }
    while (choice !=0); 
    if(choice == 0){
		cout << "[ -- session ended -- ]" << endl;
	} else {
		cout << "[ -- bad choice, restart -- ]" << endl;
		exit(1);
	}

	return 0;
}  




    
