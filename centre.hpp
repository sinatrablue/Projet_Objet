/*
Nom des classes : commence par des majuscules et toujours singulier

Nom des attributs et des méthodes : commence par une minuscule

Nom des constantes : tout en majuscules
*/

// Création de la classe Centre
#include"patient.hpp"

class Centre
{
    private:
    std::string nom_centre;  // Nom du centre
    std::string no_centre;   // Numéro du centre
    std::string adresse;     // Adresse postale du centre
    std::list<Patient> patients; // Liste des patients du centre
    std::list<Examen> examens;  // Liste des examens réalisés par le centre
    public:
    std::string get_NumCentre();
    std::string get_NomCentre();
    std::string get_Adresse();
    std::list<Patient> get_Patients();
    std::list<Examen> get_Examens();
    void set_NumCentre(std::string no_centre);
    void set_NomCentre(std::string nom_centre);
    void set_Adresse(std::string adresse);
    void set_Patients(std::list<Patient> patients);
    void set_Examens(std::list<Examen> examens);
    std::list<Examen> importFromFile();
    void exportToFile(std::list<Examen>);
    void car_pat(std::string, std::string, int, std::string);
    void add_Patient();
    Centre(std::string, std::string, std::string, std::list<Patient>, std::list<Examen>);
    Centre();
    ~Centre();
    virtual void affiche();
};