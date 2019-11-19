// Création de la classe rapport
class Rapport
{
    private:
    string rapport;     // attribut contenant le corps du rapport en format texte
    string mdp;         // mot de passe nécessaire à l'ouverture du rapport
    public:
    string get_Rapport();
    string ask_Mdp();
    void set_Rapport(string rapport);
    void set_Mdp(string mdp);
    rapport(string, string);
    ~rapport();
}