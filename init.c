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

Carte* initPaquet(){ // TODO améliorer la fonction pour que le paquet dépende du nombre de joueur ... 
    Carte* paquet = malloc(NB*sizeof(Carte));
    int i = 0;
    while (i != 4){
        paquet[i].carte = LOUPGAROUS;
        i++;
    }
    while (i != 17){ // 13 villageois
        paquet[i].carte = VILLAGEOIS;
        i++;
    }
    paquet[17].carte = VOYANTE;
    paquet[18].carte = CUPIDON;
    paquet[19].carte = PETITEFILLE;
    paquet[20].carte = CHASSEUR;
    paquet[21].carte = VOLEUR;
    paquet[22].carte = SORCIERE;
    for (int j=0; j<NB; j++){
        paquet[i].dispo = TRUE;
    }
    return paquet;
}

int tireCarte(Carte* paquet){
    int choix = AUCUN, position = -1;
    while (position == -1){
        position = rand() % NB;
        if (paquet[position].dispo){
            choix = paquet[position].carte;
            paquet[position].dispo = FALSE;
        } else {
            position = -1; // carte non disponible => on repioche
        }
    }
    return choix;
}

void distribueCarte(Joueur* joueurs, int nb_joueurs){ // joueurs étant un pointeur sur l'ensemble des joueurs, pas besoin de le retourner
    Carte* paquet = initPaquet();
    for (int i=0; i<nb_joueurs; i++){
        joueurs[i].role = tireCarte(paquet);
    }
}