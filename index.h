#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifndef INDEX
#define INDEX

    #define NB 23
    #define TRUE 1
    #define FALSE 0

    // implanter des cartes d'extensions? le best of?( meilleures cartes choisies par la commu )
    enum cartes {
        AUCUN,
        SORCIERE,
        LOUPGAROUS,
        VOYANTE,
        VILLAGEOIS,
        CUPIDON,
        PETITEFILLE,
        CHASSEUR,
        VOLEUR, 
    };

    typedef struct Stjoueur
    {
        char[10] nom; /*nom / pseudo*/
        int role;
        int capitaine; /* oui = 1, non = 0 */
        int status; /*mort ou vivant, mort = 0, vivant = 1 */
    } Joueur;

    typedef struct Carte {
        int carte; // sera le role du joueur, dépend de l'énumération
        int dispo; // 1 : dans le paquet, 0 : dans la main d'un joueur
    } Carte;

#endif