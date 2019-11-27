#include"examen.hpp"

// Définition de la classe Patient
class Patient
{
    private:
    std::string nom;
    std::string prenom;
    int age;
    std::string sexe;      // en un seul caractère, par exemple : 'H' ou 'F'
    std::list<Examen> examenss;
    public:
    std::string get_Name();
    std::string get_FirstName();
    std::list<Examen> get_Examenss();
    int get_Age();
    std::string get_Sexe();
    void set_Name(std::string nom);
    void set_Prenom(std::string prenom);
    void set_Age(int age);
    void set_Sexe(std::string sexe);
    void set_Examenss(std::list<Examen> examenss);
    void affiche();
    void car_pat(std::string, std::string, int, std::string);
    //virtual void ajouter();
    //virtual void supprimer();
    Patient(std::string, std::string, int, std::string, std::list<Examen>);
    Patient();
    ~Patient();
    // surcharge ==
    bool operator==(const Patient &p);
    void ajouter_Patient(std::list<Patient>&);
    void supprimer_Patient(std::list<Patient>&);
};