#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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
};

typedef struct Stjoueur
{
    char[10] nom; /*nom / pseudo*/
    int role;
    int status; /*mort ou vivant, mort = 0, vivant = 1 */
}Joueur;
