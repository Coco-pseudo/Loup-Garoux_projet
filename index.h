#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifndef INDEX
#define INDEX

    // pour aider à définir le nombre de joueur et facilité le changement de règle
    #define NB_JOUEUR_MAX 23
    #define NB_JOUEUR_MIN 8

    // pour simuler l'utilisation de booléens
    #define TRUE 1
    #define FALSE 0

    // implanter des cartes d'extensions? le best of?( meilleures cartes choisies par la commu )
    enum roles {
        AUCUN,
        SORCIERE,
        LOUPGAROUS,
        VOYANTE,
        VILLAGEOIS,
        CUPIDON,
        PETITEFILLE,
        CHASSEUR,
        VOLEUR, 
        VILLAGE,
        AMOUREUX,
    };

    typedef struct Stjoueur
    {
        char* nom; /*nom / pseudo*/
        int role;
        int capitaine; /* oui = 1, non = 0 */
        int amoureux; /* oui = 1, non = 0 */
        int vivant; /*mort ou vivant, mort = 0, vivant = 1 */
    } Joueur;

    typedef struct Carte {
        int carte; // sera le role du joueur, dépend de l'énumération
        int dispo; // 1 : dans le paquet, 0 : dans la main d'un joueur
    } Carte;

#endif