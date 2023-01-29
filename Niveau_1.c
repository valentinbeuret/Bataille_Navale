#include <stdio.h> 

int lire_taille()
{
    int size;
    scanf("%d",&size);
    /*
    double nb_case = size * size;
    printf("Le plateau de jeu est de %lf cases\n",&nb_case);
    */
    printf("Le plateau de jeu est de %d cases\n",size);
    if (size > 5)
    {
        printf("Le plateau ne respecte pas les règles");
    }
    return size;
}

int lire_nb_bateau()
{
    int bateaux;
    scanf("%d",&bateaux);
    printf("Il y a %d sur le plateau de jeu \n",bateaux);
    return bateaux;
}

void caractere_special()
{
    char a;
    scanf("%c",&a);
}

char scan_joueur()
{
    char joueur;
    scanf("%c",&joueur);
    return joueur;
}

void scan_matrice(char joueur,int size,int *matrice_A,int *matrice_B)
{
    int matrice;
    int i, j;

	for (i=0; i<size; i++)
		for (j=0; j<size; j++)
		{
			scanf("%d", &matrice[&i][&j]);
		}

    if (joueur == 'A') 
    {
        *matrice_A = matrice;
    } 
    else
    {
        *matrice_B = matrice;
    }
}

void change_joueur(char *joueur)
{
    if (*joueur == 'A')
    {
        *joueur = 'B';
    }
    else 
    {
        *joueur = 'A';
    }
}

void envoyer_bombe(int x, int y, char joueur, int *nb_coup_A, int *nb_coup_B, int matrice_A, int matrice_B)
{
    if (joueur == 'A')
    {
        matrice_A[&x][&y] = 0;
        *nb_coup_B++;
    }
    else 
    {
        matrice_B[&x][&y] = 0;
        *nb_coup_A++;
    }
}

char verifier_bateau(int size, int nb_bateau, int matrice_A, int matrice_B)
{
    int somme_A = 0;
    int somme_B = 0;
    int i, j;

    for (i=0; i<size; ++i) 
    {
        for (j=0; j<size; ++j) 
        {
            somme_A += matrice_A[&i][&j];
        }
    }

    for (i=0; i<size; ++i) 
    {
        for (j=0; j<size; ++j) 
        {
            somme_B += matrice_B[&i][&j];
        }
    }

    if (somme_A < nb_bateau)
    {
        printf("Alice a triché en posant moins de bateau");

    }
    if (somme_A > nb_bateau)
    {
        printf("Alice n'a pas respecté les règle et a posé plus de bateau que le nombre demandé");

    }

    if (somme_B < nb_bateau)
    {
        printf("Bernard a triché en posant moins de bateau");

    }
    if (somme_B > nb_bateau)
    {
        printf("Bernard n'a pas respecté les règle et a posé plus de bateau que le nombre demandé");
    }
}

void verifier_nb_coup(int nb_coup_A,int nb_coup_B)
{
    if (nb_coup_A < nb_coup_B)
    {
        printf("Alice a un coup de moins que Bernard");
    }

    if (nb_coup_A > nb_coup_B)
    {
        printf("Bernard a un coup de moins que Alice");
    }
}

char verifier_gagnant(int size, int matrice_A, int matrice_B, int nb_coup_A, int nb_coup_B)
{
    int somme_A = 0;
    int somme_B = 0;
    int i, j;

    for (i=0; i<size; ++i) 
    {
        for (j=0; j<size; ++j) 
        {
            somme_A += matrice_A[&i][&j];
        }
    }

    for (i=0; i<size; ++i) 
    {
        for (j=0; j<size; ++j) 
        {
            somme_B += matrice_B[&i][&j];
        }
    }

    if (somme_B == somme_A)
    {
        printf("Alice et Berard ont fait égalité \n %d : %d",somme_A, somme_B);
    }

    if (somme_A == 0)
    {
        printf("Le gagnant est Bernard \n Il a gagné en %d coup",nb_coup_B);
        printf("Bernard : %d Alice : %d",somme_B, somme_A);  
    }

    if (somme_B == 0)
    {
        printf("Le gagnant est Alice \n Elle a gagné en %d coup",nb_coup_A);
        printf("Alice : %d Bernard : %d",somme_A ,somme_B);        
    }

    if (somme_B < somme_A)
    {
        printf("Berard a gagné \n %d : %d pour Bernard", somme_B, somme_A);
    }
    
    if (somme_A < somme_B)
    {
        printf("Alice a gagné \n %d : %d pour Alice", somme_A ,somme_B);
    }    
}


int main()
{
    // ./Niveau_1.exe < P1.dat
    int i, x, y;
    char joueur;
    int size = 0;
    int bateaux = 0;
    int matrice_A;
    int matrice_B;
    int nb_coup_A;
    int nb_coup_B;

    printf("La partie commence");

    size = lire_taille();
    bateaux = lire_nb_bateau();
    caractere_special();
    for (i=0; i<2;i++)
    {
        joueur = scan_joueur();
        scan_matrice(joueur,size,&matrice_A,&matrice_B);
        caractere_special();
    }
    verifier_bateau(size, bateaux, matrice_A, matrice_B);

    char premier_joueur = scan_joueur();
    caractere_special();

    joueur = premier_joueur;
    while (x != -1 && y != ' ')
    {
        scanf("%d",&x);
        // printf("valeur de x %d",x);

        if (x == -1)
        {
            printf("Coordonnée inexistante \n %d n'existe pas", x);
            break;
        }

        if (x > size || x < 0)
        {
            printf("Coup en dehors du plateau \n %d n'est pas une coordonnée valable",x);
            break;
        } 

        scanf("%d",&y);
        // printf("valeur de y %d",y);

        if (y > size || y < 0)
        {
            printf("Coup en dehors du plateau \n %d n'est pas une coordonnée valable",y);
            break;
        }

        if (y == -1)
        {
            printf("Coordonnée inexistante \n %d n'existe pas",y);
            break;
        }

        envoyer_bombe(x, y, joueur,&nb_coup_A,&nb_coup_B,matrice_A,matrice_B);
        change_joueur(&joueur);
    }
    verifier_nb_coup(nb_coup_A,nb_coup_B);
    verifier_gagnant(size,matrice_A,matrice_B,nb_coup_A,nb_coup_B);
    
    printf("La partie est fini");
    return 0;
}
