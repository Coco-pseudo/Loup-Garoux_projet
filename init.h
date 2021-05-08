#include "index.h"

#ifndef INIT
#define INIT

    /*!
     * \fn Joueur* initJoueurs(int nb_joueurs)
     * \brief initialise les caractéristiques de tous les joueurs 
     */
    Joueur* initJoueurs(int nb_joueurs);

    /*!
    * \fn Carte* initPaquet()
    * \brief initialise et retourne le paquet de cartes, soit l'ensemble des cartes que les joueurs utiliserons
    */
    Carte* initPaquet(); 

    /*!
    * \fn int tireCarte(Carte* paquet)
    * \brief tire aléatoirement une carte du paquet, vérifie si elle est disponible, si oui, la rend indisponible et la retourne, sinon repioche jusqu'à retourner une carte disponible
    */
    int tireCarte(Carte* paquet);

    /*!
    * \fn void distribueCarte(Joueur* joueurs, int nb_joueur)
    * \brief initialise la caractéristique role de chaque joueur en tirant à chacun leur tour une carte du paquet
    */
    void distribueCarte(Joueur* joueurs, int nb_joueurs);
    
#endif 