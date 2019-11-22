// Création de la classe rapport
class Rapport
{
    private:
    std::string content;     // attribut contenant le corps du rapport en format texte
    std::string mdp;         // mot de passe nécessaire à l'ouverture du rapport
    public:
    std::string get_Rapport();
    std::string ask_Mdp();
    void set_Rapport(std::string content);
    void set_Mdp(std::string mdp);
    Rapport(std::string, std::string);
    Rapport();
    ~Rapport();
    //bool operator==(const Rapport &r);
    void ajouter_Rapport(std::list<Rapport>&);
    void supprimer_Rapport(std::list<Rapport>&);
};