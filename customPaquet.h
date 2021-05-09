#include "index.h"

#ifndef CUSTOM_PAQUET
#define CUSTOM_PAQUET

    /*!
     * \fn void menuParametre()
     * \brief affiche le premier menu pour choisir si l'on personnifie les paramètre de jeu ou si on joue directement ou si on quitte
     */ 
    void menuParametre();

    /*!
     * \fn void menuPaquet(int* parametres)
     * \brief affiche le menu pour choisir les paramètres de jeu soit les cartes du paquet de départ
     */ 
    void menuPaquet(int* parametres);
    
    /*!
     * \fn void menuBooleen()
     * \brief menu pour choisir oui ou non
     */ 
    void menuBooleen();

    /*!
     * \fn int verifNbCartesPourNbJoueur(int* parametres, int nb_joueurs)
     * \brief fonction qui vérifie si le nombre de cartes (somme des paramètres) est égale au nombre de joueur et renvoit TRUE (1) ou FALSE (0)
     */ 
    int verifNbCartesPourNbJoueur(int* parametres, int nb_joueurs);

    /*!
     * \fn char* traduitBooleen(int booleen)
     * \brief pour pouvoir écrite l'équivalent du 0 ou 1 en mode texte (oui ou non)
     */ 
    char* traduitBooleen(int booleen);

    /*!
     * \fn int choixMenu(int nb_choix)
     * \brief en fonction du nombre de choix (en paramètre) du menu correspondant, demande au joueur son choix jusqu'à obtention d'un choix valide et le renvoit
     */ 
    int choixMenu(int nb_choix);

    /*! 
     * \fn int choixMenu2(int nb_choix, int role)
     * \brief en fonction du role (loup-garou ou villageois) et du nb de choix max, demande au joueur le nombre de loup-garous ou de villageois jusqu'à obtention d'un choix valide et le renvoit
     */
    int choixMenu2(int nb_choix, int role);    

    /*!
     * \fn int* parametresParDefaut(int nb_joueurs)
     * \brief initialise le nombre de carte par role en fonction du nombre de joueur pour avoir un paquet de départ approprié
     */
    int* parametresParDefaut(int nb_joueurs);

    /*!
     * \fn int* customParametre(int* parametres, int nb_joueurs)
     * \param parametres le tableau des paramètres initialisé avec des valeurs par défault définies en fonction du nombre de joueurs
     * \param nb_joueurs nombre de joueurs sans compter le meneur
     * \brief Cette fonction utilise les menu pour laisser le joueur paramétrer le paquet de départ, si le nombre de cartes final ne correspond pas au nombre de joueur, on proposes au joueur de revenir au paramètre par défaut, ou de reprendre sa customization ou de quitter
     * \return retourne le nombre de carte par role dans un tableau avec dans l'ordre : [LOUPSGAROUS, VILLAGEOIS, VOYANTE, VOLEUR, CUPIDON, CHASSEUR, SORCIERE, PETITEFILLE]
     */
    int* customParametre(int* parametres, int nb_joueurs);
#endif