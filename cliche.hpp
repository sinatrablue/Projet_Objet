#include<list>
#include<string>

// Définition de la classe cliché
class Cliche
{
    private:
    std::string no_cliche;      // Seul argument : le numéro du cliché
    public:
    std::string get_NoCliche();
    void set_NoCliche(std::string no_cliche);
    void affiche();
    Cliche(std::string);
    Cliche();
    ~Cliche();

    // surcharge ==
    bool operator==(const Cliche &c);

    void ajouter_Cliche(std::list<Cliche>&);
    void supprimer_Cliche(std::list<Cliche>&);
};