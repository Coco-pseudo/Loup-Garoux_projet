#include "index.h"

#ifndef JOUEUR
#define JOUEUR

    /*!
     * \fn void afficheEnsJoueurs(Joueur* joueurs, int nb_joueurs)
     * \brief affiche l'ensemble des joueurs vivants (joueur i : pseudo)
     */
    void afficheEnsJoueurs(Joueur* joueurs, int nb_joueurs);

    /*!
     * \fn int choixJoueur(Joueur* joueurs, int nb_joueurs)
     * \brief demande et retourne le numéro d'un joueur parmi les joueurs vivants
     */ 
    int choixJoueur(Joueur* joueurs, int nb_joueurs);

#endif 