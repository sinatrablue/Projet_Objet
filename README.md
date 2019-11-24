# Projet_Objet

Choses restantes :

1°) Trouver comment enfin split() les strings de la ligne avec tous les no_Cliches pour pouvoir en mettre plein

(Pas sûr) Faire une classe date, qu'on peut appeler directement pour définir une date.

2°)
Ajouter les fonctions de recherche et d'affichage par patient, par date d'exam et par numéro d'exam.
> Notre essai un peu algo :
> patient = oussalah
>for i in list patient:
>    if (i == patient)
>        cout << i.affiche()
>        for j in list exams du patient
>            cout j.affiche()
>date=machin


C'est tout bon ça en principe :
Ajouter une fonction pour charger/sauvegarder des listes de radios depuis ou vers un fichier texte aussi pour Patient. De sorte qu'on ai 2 méthodes, ajouter manuellement 1 seul patient ou ajoute rune liste depuis un fichier source.
> Problèmes avec ça : j'ai réglé le soucis de la liste de clichés vides, il fallait appeler le constructeur et
> pas la fonction set_noCliche() alors qu'on a initialisé un cliché vide.
> J'ai aussi réglé le problème de la boucle, en fait mettre itr=it->machin.truc dedans faisait qu'elle se
> réinitialisait à chaque fois qu'on entrait dedans donc c'était boucle infinie.