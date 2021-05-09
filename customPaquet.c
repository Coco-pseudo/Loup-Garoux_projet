#include "customPaquet.h"

// Juste après choix du nombre de joueurs :
void menuParametre(){
    printf("1. Choisir les parametres de depart pour votre jeu !\n");
    printf("2. Passer au jeu avec les parametres par defaut.\n");
    printf("0. Quitter\n");
}

void menuPaquet(int* parametres){ // dans paramètres ensemble d'entier définissant le paquet -> pour initPaquet
    printf("1. Nombre de loups-garous (%d)\n", parametres[0]); // 1 à 4
    printf("2. Nombre de villageois (%d)\n", parametres[1]); // 1 à 13
    printf("3. Voyante ? (%s)\n", traduitBooleen(parametres[2]));
    printf("4. Voleur ? (%s)\n", traduitBooleen(parametres[3]));
    printf("5. Cupidon ? (%s)\n", traduitBooleen(parametres[4]));
    printf("6. Chasseur ? (%s)\n", traduitBooleen(parametres[5]));
    printf("7. Sorcière ? (%s)\n", traduitBooleen(parametres[6]));
    printf("8. Petite fille ? (%s)\n", traduitBooleen(parametres[7]));
    printf("0. Confirmer\n");
}

void menuBooleen(){
    printf("1. oui\n");
    printf("2. non\n");
    printf("0. Retour\n");
}

int verifNbCartesPourNbJoueur(int* parametres, int nb_joueurs){
    int somme = 0;
    for(int i=0; i<8; i++){
        somme += parametres[i];
    }
    if(somme == nb_joueurs){
        return TRUE;
    } else {
        printf("Votre paquet n'est pas valide par rapport au nombre de joueur !!\n"); 
        return FALSE;
    }
}

char* traduitBooleen(int booleen){
    if(booleen){
        return "oui";
    } else {
        return "non";
    }
}

int choixMenu(int nb_choix){
    int choix = -1;
    while (choix == -1){
        printf("Votre choix : ");
        scanf("%d", &choix);
        if (choix<0 || choix>nb_choix){
            choix = -1;
        }
    }
    return choix;
}

int choixMenu2(int nb_choix, int role){
    int choix = 0;
    if (role == LOUPGAROUS){
        printf("Combien de loups-garous voulez-vous ? (1 à %d)\n", nb_choix);
    } else {
        printf("Combien de villageois voulez-vous ? (1 à %d)\n", nb_choix); 
    }
    while (choix == 0){
        printf("Votre choix : ");
        scanf("%d", &choix);
        if (choix<1 || choix>nb_choix){
            choix = 0;
        }
    }
    return choix;
}

// ----------------------------------------------------------------------------------------------
// fonctions init... pour la fonction d'en dessous -> pas besoin de les mettre dans le header :
int initNbLoup(int nb_joueurs){
    if (nb_joueurs > 18){
        return 4;
    } else {
        if (nb_joueurs > 11){
            return 3;
        } else {
            return 2;
        }
    }
}

int initNbVillageois(int nb_joueurs){
    switch (nb_joueurs){
        case 23:
            return 13;
        case 22 :
            return 12;
        case 21 :
            return 11;
        case 20 : 
            return 10;
        case 19 :
        case 18 :
            return 9;
        case 17 :
            return 8;
        case 16 :
            return 7;
        case 15 :
        case 14 :
            return 6;
        case 13 :
        case 12 :
        case 11 :
            return 5;
        case 10 : 
            return 4;
        default: // case 9 et 8
            return 3;
    }
}

int initPresenceVoleur(int nb_joueurs){
    if (nb_joueurs > 12){
        return TRUE;
    } else {
        return FALSE;
    }
}

int initPresenceCupidon(int nb_joueurs){
    if (nb_joueurs > 8){
        return TRUE;
    } else {
        return FALSE;
    }
}

int initPresencePetiteFille(int nb_joueurs){
    if (nb_joueurs > 14){
        return TRUE;
    } else {
        return FALSE;
    }
}
// -----------------------------------------------------------------------------------------------

int* parametresParDefaut(int nb_joueurs){ // nb_joueurs : nombre de joueurs sans compter le meneur
    int* parametre = malloc(8*sizeof(int));
    parametre[0] = initNbLoup(nb_joueurs);
    parametre[1] = initNbVillageois(nb_joueurs);
    parametre[2] = TRUE; // VOYANTE
    parametre[3] = initPresenceVoleur(nb_joueurs);
    parametre[4] = initPresenceCupidon(nb_joueurs);
    parametre[5] = TRUE; // CHASSEUR
    parametre[6] = TRUE; // SORCIERE
    parametre[7] = initPresencePetiteFille(nb_joueurs);
    return parametre;
}

void appliqueMenuPaquet(int choix, int* parametres, int nb_joueurs){ 
    int choix2;
    if (choix == 1){
        choix2 = choixMenu2(4, LOUPGAROUS);
        parametres[0] = choix2;
    } else {
        if (choix == 2){
            int nb_max = (13 > nb_joueurs) ? nb_joueurs : 13; // si 8 joueurs, on peut pas atteindre 13 ... 
            choix2 = choixMenu2(nb_max, VILLAGEOIS);
            parametres[0] = choix2;
        } else { // c'est un booléen
            printf("\n");
            menuBooleen();
            choix2 = choixMenu(2);
            if (choix2 == 1){
                parametres[choix-1] = TRUE;
            } else {
                parametres[choix-1] = FALSE;
            }
        }
    }
}

void menuErreur(int nb_joueurs){
    printf("Vous devez avoir %d cartes en tout. Vous preferez :\n", nb_joueurs);
    printf("1. Revenir sur le menu precedent et corriger.\n");
    printf("2. Retablir les paramètres par default et jouer.\n");
    printf("0. Quitter\n");
}

// si 1. est choisi sur le premier menu
int* customParametre(int* parametres, int nb_joueurs){
    int choix = -1;
    while (choix != 0){ // => fin de customization des paramètres
        printf("\n");
        menuPaquet(parametres);
        choix = choixMenu(8);
        appliqueMenuPaquet(choix, parametres, nb_joueurs);
    }
    int boo = verifNbCartesPourNbJoueur(parametres, nb_joueurs);
    if (boo){
        return parametres;
    } else {
        menuErreur(nb_joueurs);
        choix = choixMenu(2);
        switch (choix){
            case 1 : 
                parametres = customParametre(parametres, nb_joueurs); // on repart du même point avec les mêmes paramètres
                break;
            case 2 : 
                free(parametres); // on libère l'ancien tableau avant d'en créer un nouveau ^^
                parametres = parametresParDefaut(nb_joueurs);
                break;
            default :
                free(parametres);
                parametres = NULL; // verif à faire après, si NULL -> on quitte le jeu -> on sort de la fonction principale ^^
                break;
        }
    }
    return parametres;
}