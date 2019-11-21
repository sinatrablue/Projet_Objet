#include"examen.hpp"

// Définition de la classe Patient
class Patient
{
    private:
    std::string nom;
    std::string prenom;
    int age;
    char sexe;      // en un seul caractère, par exemple : 'H' ou 'F'
    std::list<Examen> examenss;
    public:
    std::string get_Name();
    std::string get_FirstName();
    std::list<Examen> get_Examenss();
    int get_Age();
    char get_Sexe();
    void set_Name(std::string nom);
    void set_Prenom(std::string prenom);
    void set_Age(int age);
    void set_Sexe(char sexe);
    void set_Examenss(std::list<Examen> examenss);
    void affiche();
    //virtual void ajouter();
    //virtual void supprimer();
    Patient(std::string, std::string, int, char, std::list<Examen>);
    ~Patient();
};