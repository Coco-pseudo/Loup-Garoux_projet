


int nombrej () {
    int n;
    int k;
    printf(" Quel est le nombre de joueurs?");
    scanf ("%d",&n);
    while (n<8 && n>24 && n!=40)
        {
            printf("ce nombre n'est pas un nombre valide de joueurs pour jouer \n");
            printf("voulez vous ressaisir un nombre (0) ou quitter le jeu(1)?");
            scanf ("%d",&k);
            switch (k)
            {
                case 0:
                        if (n<8)
                        {
                            printf(" Quel est le nombre de joueurs? (minimum de 8)");
                            scanf ("%d",&n);
                        }
                        else //n>24
                        {
                            printf(" Quel est le nombre de joueurs? (minimum de 8)");
                            scanf ("%d",&n);                        
                        }
                    break;
                case 1:
                    n=40;
                    break;
                default:
                    printf("valeur non valide");
                    break;
            }

        };


    

    return n;
}