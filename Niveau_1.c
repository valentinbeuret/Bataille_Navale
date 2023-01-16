#include <stdio.h> 

int size = 0;
int bateaux = 0;
int matrice_A;
int matrice_B;

void lire_taille()
{
    scanf("%d",&size);
}

void lire_nb_bateau()
{
    scanf("%d",&bateaux);
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
    if(joueur == "A")
    {
        matrice_A[x][y] = 0;
    }
    else 
    {
        matrice_B[x][y] = 0;        
    }
}

char verifier_gagnant(matice_A, matrice_B)
{
    int somme = 0;
}

int main()
{
    int i, x, y;
    char joueur;
    printf("debut");
    //./Test.exe < P1.dat
    lire_taille();
    lire_nb_bateau();
    caractere_special();
    for(i=0; i<2;i++)
    {
        joueur = scan_joueur();
        scan_matrice(joueur);
        caractere_special();
    }

    char premier_joueur = scan_joueur();
    caractere_special();

    joueur = premier_joueur;
    while (1 == 1)
    {
        scanf("%d",&x);
        printf("valeur de x %d",&x);
        if (x == -1)
        {
            printf("Coordonnée inexistante \n %d n'existe pas", &x);
            break;
        }
        
        if(x > size)
        {
            printf("Coup en dehors du plateau \n %d n'existe pas", &x);
            break;
        } 

        scanf("%d",&y);
        printf("valeur de y %d",&y);

        if(y > size)
        {
            printf("Coup en dehors du plateau \n %d n'existe pas", &y);
            break;
        } 

        envoyer_bombe(x, y, joueur);
        joueur = change_joueur(joueur);
    }

    /*
    scan du joueur (A ou B)
    scan la matrice et l'attribuer au joueur en question
    refaire la meme chose
    lire qui commence 
    lancement des étape 
    donc remplacement du 0 par 0 et du 1 par 0 quand il en croise un 
    jusqu'au -1
    vérifier si il y a un gagnant donc somme des matrice est égale à un 0 = gagnant
    retourner joueur A ou joueur B 
    vérifier si il y a un coup en dehors du plateau 
    problème avec le -1 si il le croise deux fois 
    conteur pour retourner le nombre de coup 

    mettre toutes les coordonnées dans un tableau et puis voir si il y a un élément après le -1
    */
    printf("fin");
    return 0;
}