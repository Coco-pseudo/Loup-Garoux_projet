#include "init.h"

Joueur* initJoueurs(int nb_joueurs){
    Joueur* joueurs = malloc(nb_joueurs*sizeof(Joueur));
    for(int i=0; i<nb_joueurs; i++){
        joueurs[i].capitaine = FALSE;
        joueurs[i].amoureux = FALSE;
        joueurs[i].vivant = TRUE;
        printf("Joueur %d, votre pseudo : ", i);
        scanf("%s", joueurs[i].nom);
        joueurs[i].role = AUCUN;
    }
    return joueurs;
}

Carte* initPaquet(int* parametres, int nb_joueurs){ 
    Carte* paquet = malloc(nb_joueurs*sizeof(Carte));
    int i = 0, semi_total = parametres[0] + parametres[1];
    while (i != parametres[0]){ // 4 loups si nb_joueurs = NB_JOUEURS_MAX = 23
        paquet[i].carte = LOUPGAROUS;
        i++;
    }
    while (i != semi_total){ // 13 villageois si nb_joueurs = NB_JOUEURS_MAX = 23
        paquet[i].carte = VILLAGEOIS;
        i++;
    }
    paquet[semi_total+0].carte = VOYANTE; // +0 juste pour l'alignement ;)
    paquet[semi_total+1].carte = VOLEUR;
    paquet[semi_total+2].carte = CUPIDON;
    paquet[semi_total+3].carte = CHASSEUR;
    paquet[semi_total+4].carte = SORCIERE;
    paquet[semi_total+5].carte = PETITEFILLE;
    for (int j=0; j<semi_total; j++){
        paquet[i].dispo = TRUE;
    }
    for (int j=2; j<8; j++){
        if (!parametres[i]){
            paquet[i+semi_total].dispo = FALSE;
        }
    }
    return paquet;
}

int tireCarte(Carte* paquet, int nb_joueurs){
    int choix = AUCUN, position = -1;
    while (position == -1){
        position = rand() % nb_joueurs;
        if (paquet[position].dispo){
            choix = paquet[position].carte;
            paquet[position].dispo = FALSE;
        } else {
            position = -1; // carte non disponible => on repioche
        }
    }
    return choix;
}

void distribueCarte(Joueur* joueurs, int* parametres, int nb_joueurs){ // joueurs étant un pointeur sur l'ensemble des joueurs, pas besoin de le retourner
    Carte* paquet = initPaquet(parametres, nb_joueurs);
    for (int i=0; i<nb_joueurs; i++){
        joueurs[i].role = tireCarte(paquet, nb_joueurs);
    }
}