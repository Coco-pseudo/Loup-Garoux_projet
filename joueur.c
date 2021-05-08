#include "joueur.h"

void afficheEnsJoueurs(Joueur* joueurs, int nb_joueurs){
    for (int i=0; i<nb_joueurs; i++){
        if (joueurs[i].vivant){ // on n'affiche pas les morts
            if (!joueurs[i].capitaine){
                printf("Joueur %d : %s\n", i+1, joueurs[i].nom);
            } else {
                printf("Joueur %d : %s (capitaine)\n", i+1, joueurs[i].nom);
            }
        }        
    }
}

int choixJoueur(Joueur* joueurs, int nb_joueurs){ // pour le choix du joueur à exécuter par exemple
    int choix = 0;
    while (choix == 0){
        printf("Votre choix : "); // phrase que l'on pourra changer 
        scanf("%d", &choix);
        if (choix<1 || choix>nb_joueurs){
            choix = 0; // pas besoin d'afficher d'erreur, le joueur n'existe pas, on redemande de suite un choix
        } else {
            if(!joueurs[choix - 1].vivant){
                printf("Ce joueur est déjà mort ...\n");
                choix = 0;
            }
        }
    }
    return choix;
}