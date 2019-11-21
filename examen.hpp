#include"cliche.hpp"
#include"rapport.hpp"

// Définition de la classe Examen
class Examen
{
    private:
    std::string no_exam;    // Identifiant

    // Changer le type avec 1/2/3 pour ensuite faire une condition dessus
    std::string type;    // Radio, Échographie, IRM...
    std::string date;    // Date à laquelle l'examen a été fait par le patient, ou sa réservation
    bool etat;    // Examen passé ou pas encore (juste plannifié)
    std::list<Cliche> cliches;
    Rapport rapp;
    public:
    std::string get_NoExam();
    std::string get_Type();
    std::string get_Date();
    std::list<Cliche> get_Cliches();
    Rapport get_Rapport();
    bool get_Etat();
    void set_NoExam(std::string no_exam);
    void set_Type(std::string type);
    void set_Date(std::string date); 
    void set_Etat(bool etat);
    void set_Cliches(std::list<Cliche> cliches);
    void set_Rapport(Rapport rapp);
    Examen(std::string, std::string, std::string, bool, std::list<Cliche>, Rapport);
    ~Examen();
    void affiche();
    void supprimer();
    void ajouter();
    bool operator==(const Examen &e);
    void ajouter_Examen(std::list<Examen>&);
    void supprimer_Examen(std::list<Examen>&);
};