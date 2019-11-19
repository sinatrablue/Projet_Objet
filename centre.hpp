/*
Nom des classes : commence par des majuscules et toujours singulier

Nom des attributs et des méthodes : commence par une minuscule

Nom des constantes : tout en majuscules
*/

// Création de la classe Centre
class Centre
{
    private:
    string nom_centre;  // Nom du centre
    string no_centre;   // Numéro du centre
    string adresse;     // Adresse postale du centre
    list<int> patients; // Liste des patients du centre
    list<int> examens;  // Liste des examens réalisés par le centre
    public:
    string get_NumCentre();
    string get_NomCentre();
    string get_Adresse();
    list<int> get_Patients();
    list<int> get_Examens();
    void set_NumCentre(string no_centre);
    void set_NomCentre(string nom_centre);
    void set_Adresse(string adresse);
    void set_Patients(list<int> patients);
    void set_Examens(list<int> examens);
    centre(string, string, string);
    ~centre();
    virtual void affiche();
}
