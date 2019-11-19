// Définition de la classe Patient
class Patient
{
    private:
    string nom;
    string prenom;
    int age;
    char sexe;      // en un seul caractère, par exemple : 'H' ou 'F'
    list<int> examenss;
    public:
    string get_Name();
    string get_FirstName();
    list<int> get_Examenss();
    int get_Age();
    char get_Sexe();
    void set_Name(string nom);
    void set_Prenom(string prenom);
    void set_Age(int age);
    void set_Sexe(char sexe);
    void set_Examenss(list<int> examenss);
    void affiche();
    //virtual void ajouter();
    //virtual void supprimer();
    patient(string, string, int, char);
    ~patient();
}