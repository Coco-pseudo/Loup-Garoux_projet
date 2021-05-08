#include "narrateur.h"

// suppression des accents par soucis de compatibilite avec tous les terminals 
void debut(){
    printf("C'est la nuit, tout le village s'endort, les joueurs ferment tous les yeux ! \n");
}

void appel(int role, int debut){
    switch (role){
        // roles appeles à chaque tour :
        case VILLAGE :
            if (debut){
                printf("C'est la nuit, les survivants se rendorment !\n");
            } else {
                printf("C'est le matin, le village se reveille, tout le monde se reveille et ouvre les yeux, tout le monde sauf ...\n");
            }
            break;
        case LOUPGAROUS :
            if (debut){
                printf("Les loups-garous se reveillent, se reconnaissent et designent une nouvelle victime !!!\n");
            } else {
                printf("Les loups-garous repus se rendorment et revent de prochaines victimes savoureuses !\n");
            }
            break;
        case VOYANTE :
            if (debut){
                printf("La voyante se reveille, et designe un joueur dont elle veut sonder la veritable personnalite.\n");
            } else {
                printf("La voyante se rendort.\n");
            }
            break;
        case SORCIERE :
            if (debut){
                printf("La sorciere se reveille, je lui montre la victime des Loups-Garous. Va-t-elle user de sa potion de guerison ou d'empoisonnement ?\n");
            } else {
                printf("La sorciere se rendort.\n");
            }
            break;
        // roles appeles seulement au tour de demarrage : 
        case VOLEUR :
            if (debut){
                printf("Le voleur se reveille !\n");
            } else {
                printf("Le voleur se rendort.\n");
            }
            break;
        case CUPIDON :
            if (debut){
                printf("Cupidon se reveille !\n");
            } else {
                printf("Cupidon se rendort.\n");
            }
            break;
        // roles à appeler seulement pour que le narrateur sache qui c'est ...
        case PETITEFILLE :
            if (debut){
                printf("La petite fille se reveille !\n");
            } else {
                printf("La petite fille se rendort.\n");
            }
            break;
        case CHASSEUR :
            if (debut){
                printf("Le chasseur se reveille !\n");
            } else {
                printf("Le chasseur se rendort.\n");
            }
            break;
        default : // les amoureux, apres choix de Cupidon :
            if (debut){
                printf("Les amoureux se reveillent, lentement, se reconnaissent et se rendorment ! \n"); // TODO : pause ?
            } 
    }
}


// pour test idée générale :
// à commenter quand on testera l'ensemble du projet
int main(){
    debut();
    // tour de démarrage : appel minimum voleur et cupidon puis amoureux (role = AUCUN)
    appel(VILLAGE, FALSE); printf("Personne pour cette fois. Elisons un capitaine !\n");
    // vote capitaine
    printf("\n");
    debut();
    // premier tour : dans l'ordre, VOYANTE, LOUPS, SORCIERE, reveil
    appel(VILLAGE, FALSE);
    // tous les tours jusqu'à camp gagnant 
    return 0;
}