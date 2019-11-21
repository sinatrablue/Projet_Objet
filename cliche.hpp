#include<list>

// Définition de la classe cliché
class Cliche
{
    private:
    int no_cliche;      // Seul argument : le numéro du cliché
    public:
    int get_NoCliche();
    void set_NoCliche(int no_cliche);
    void affiche();
    Cliche(int);
    ~Cliche();

    // surcharge ==
    bool operator==(const Cliche &c);

    void ajouter_Cliche(std::list<Cliche>&);
};