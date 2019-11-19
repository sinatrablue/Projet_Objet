// Définition de la classe Examen
class Exam
{
    private:
    int no_exam;    // Identifiant
    string type;    // Radio, Échographie, IRM...
    string date;    // Date à laquelle l'examen a été fait par le patient, ou sa réservation
    bool etat;    // Examen passé ou pas encore (juste plannifié)
    list<int> cliches;
    list<int> rapports;
    public:
    int get_NoExam();
    string get_Type();
    string get_Date();
    list<int> get_Cliches();
    list<int> get_Rapports();
    bool get_Etat();
    void set_NoExam(int no_exam);
    void set_Type(string type);
    void set_Date(string date);
    void set_Etat(bool etat);
    void set_Cliches(list<int> cliches);
    void set_Rapports(list<int> rapports);
    exam(int, string, string, bool);
    ~exam();
    void affiche();
    void supprimer();
    void ajouter();
}