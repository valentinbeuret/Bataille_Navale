#include <stdio.h> 

int size = 0;
int bateaux = 0;
int matrice_A;
int matrice_B;

void lire_taille()
{
    scanf("%d",&size);
    double nb_case = size * size;
    printf("Le plateau de jeu est de %lf \n",&nb_case);
}

void lire_nb_bateau()
{
    scanf("%d",&bateaux);
    printf("Il y a %d sur le plateau de jeu \n",&bateaux);
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

void scan_matrice(scan_joueur)
{
    int matrice;
    int i, j;

	for(i=0; i<size; i++)
		for(j=0; j<size; j++)
		{
			scanf("%d", &matrice[&i][&j]);
		}

    if (scan_joueur == "A") 
    {
        matrice_A = matrice;
    } 
    else
    {
        matrice_B = matrice;
    }    
}

char change_joueur(joueur)
{
    if (joueur == "A")
    {
        return "B";
    }
    else 
    {
        return "A";
    }
}

void envoyer_bombe(x, y, joueur)
{
    int nb_coup_A;
    int nb_coup_B;

    if(joueur == "A")
    {
        if (matrice_A[x][y] != 0)
        {
            if (matrice_A[x][y] == 1)
            {
                matrice_A[x][y] = 2;
                printf("Touché");
            }
            if (matrice_A[x][y] == 1 && matrice_A[x-1][y] == 2)
            {
                matrice_A[x][y] = 0;
                matrice_A[x-1][y] = 0;
                printf("Coulé");
            }
            if (matrice_A[x][y] == 1 && matrice_A[x+1][y] == 2)
            {
                matrice_A[x][y] = 0;
                matrice_A[x+1][y] = 0;
                printf("Coulé");
            }
        }
        else
        {
            matrice_A[x][y] = 0;
        }
        nb_coup_B++;
    }
    else 
    {
        if (matrice_B[x][y] != 0)
        {
            if (matrice_B[x][y] == 1)
            {
                matrice_B[x][y] = 2;
                printf("Touché");
            }
            if (matrice_B[x][y] == 1 && matrice_B[x-1][y] == 2)
            {
                matrice_B[x][y] = 0;
                matrice_B[x-1][y] = 0;
                printf("Coulé");
            }
            if (matrice_B[x][y] == 1 && matrice_B[x+1][y] == 2)
            {
                matrice_B[x][y] = 0;
                matrice_B[x+1][y] = 0;
                printf("Coulé");
            }
        }
        else
        {
            matrice_B[x][y] = 0;
        }
        nb_coup_A++;
    }
}

char verifier_bateau(size, nb_bateau, matice_A, matrice_B)
{
    int somme_A = 0;
    int somme_B = 0;
    int i, j;

    for (i=0; i<size; ++i) 
    {
        for (j=0; j<size; ++j) 
        {
            somme_A += matrice_A[i][j];
        }
    }

    for (i=0; i<size; ++i) 
    {
        for (j=0; j<size; ++j) 
        {
            somme_B += matrice_B[i][j];
        }
    }

    if (somme_A < nb_bateau)
    {
        printf("Alice a triché en posant moins de bateau");
        break;
    }
    if (somme_A > nb_bateau)
    {
        printf("Alice n'a pas respecté les règle et a posé plus de bateau que le nombre demandé");
        break;
    }

    if (somme_B < nb_bateau)
    {
        printf("Bernard a triché en posant moins de bateau");
        break;
    }
    if (somme_B > nb_bateau)
    {
        printf("Bernard n'a pas respecté les règle et a posé plus de bateau que le nombre demandé");
        break;
    }
}

void verifier_nb_coup(envoyer_bombe)
{
    if (nb_coup_A < nb_coup_B)
    {
        printf("Alice a eu un coup de moins que Bernard");
        break;
    }

    if (nb_coup_A > nb_coup_B)
    {
        printf("Bernard a eu un coup de moins que Alice");
        break;
    }
}

char verifier_gagnant(size, matice_A, matrice_B, envoyer_bombe)
{
    int somme_A = 0;
    int somme_B = 0;
    int i, j;

    for (i=0; i<size; ++i) 
    {
        for (j=0; j<size; ++j) 
        {
            if (matrice_A[i][j] == 2)
            {
                matrice_A[i][j] = 1;
                somme_A += matrice_A[i][j];
            }
            else
            {
                somme_A += matrice_A[i][j];
            }
        }
    }

    for (i=0; i<size; ++i) 
    {
        for (j=0; j<size; ++j) 
        {
            somme_B += matrice_B[i][j];
        }
    }

    if (somme_B == somme_A)
    {
        printf("Alice et Berard ont fait égalité \n %d : %d",&somme_A &somme_B);
        break;
    }

    if (somme_A == 0)
    {
        printf("Le gagnant est Bernard \n Il a gagné en %d coup",&nb_coup_B);
        printf("Bernard : %d Alice : %d",&somme_B &somme_A);  
        break;
    }

    if (somme_B == 0)
    {
        printf("Le gagnant est Alice \n Elle a gagné en %d coup",&nb_coup_A);
        printf("Alice : %d Bernard : %d",&somme_A &somme_B);        
        break;
    }

    if (somme_B < somme_A)
    {
        printf("Berard a gagné \n %d : %d pour Bernard", &somme_B &somme_A);
        break;
    }
    
    if (somme_A < somme_B)
    {
        printf("Alice a gagné \n %d : %d pour Alice", &somme_A &somme_B);
        break;
    } 
}


int main()
{
    // ./Niveau_1.exe < P1.dat
    int i, x, y;
    char joueur;
    printf("La partie commence");

    lire_taille();
    lire_nb_bateau();
    caractere_special();
    for(i=0; i<2;i++)
    {
        joueur = scan_joueur();
        scan_matrice(joueur);
        caractere_special();
    }
    verifier_bateau();

    char premier_joueur = scan_joueur();
    caractere_special();

    joueur = premier_joueur;
    while (1 == 1) // condition d'arret pas fini 
    {
        scanf("%d",&x);
        printf("valeur de x %d",&x);
        if (x == -1)
        {
            printf("Coordonnée inexistante \n %d n'existe pas", &x);
            break;
        }
        
        if(x > size || x < 0)
        {
            printf("Coup en dehors du plateau \n %d n'est pas une coordonnée valable",&x);
            break;
        } 

        scanf("%d",&y);
        printf("valeur de y %d",&y);

        if(y > size || y < 0)
        {
            printf("Coup en dehors du plateau \n %d n'est pas une coordonnée valable",&y);
            break;
        }

        if (y == -1)
        {
            printf("Coordonnée inexistante \n %d n'existe pas",&y);
            break;
        }

        envoyer_bombe(x, y, joueur);
        joueur = change_joueur(joueur);
    }
    verifier_nb_coup();
    verifier_gagnant();
    
    printf("La partie est fini");
    return 0;
}

