#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>


// Déclaration des fonctions fournies
void initPlateau(char** p, int n, int m, int nbRochers);
int entierAleatoire(int min, int max);
void afficherPlateau(char** p, int n, int m);

// Déclarations des fonctions à compléter
char** creerPlateau(int n, int m);
int nbRochers(char** p, int n, int m);
void placerUnRocher(char** p, int n, int m);
bool supprimerColonne(char*** p, int n, int *m, int colonne);
bool supprimerLigne(char*** p, int *n, int m, int ligne);

//*********************
// PROGRAMME PRINCIPAL
//*********************

int main (int argc, char* argv[]) {
    // Vérification des arguments du programme
    if (argc != 3) {
        printf("Erreur: les deux dimensions du plateau de jeu doivent être fournis en arguments\n");
        exit(1);
    }

    // Récupération des dimensions du plateau de jeu

    int nl = atoi( argv[1] );
    int nc = atoi( argv[2] );
    
    // Lecture du pseudonyme du joueur
    
    printf( "Entrez votre pseudo : " );

    int longueurPseudoMax = 15;
    char* pseudo = (char*) calloc( longueurPseudoMax, sizeof( char ) );

    if ( pseudo == NULL ) {

        perror( "Erreur : pseudo calloc.\n" );
        exit(1);

    }

    fgets( pseudo, longueurPseudoMax, stdin );

    int longueurPseudo = strlen( pseudo );

    longueurPseudo--;

    pseudo[longueurPseudo] = '\0';
    
    // Création du plateau de jeu

    char** plateau = creerPlateau( nl, nc );

    if ( plateau == NULL ) {

        perror( "Erreur : allocation mémoire du plateau.\n" );
        exit(1);

    }
    
    // Initialisation du plateau en plaçant nl*nc/3-1 rochers aléatoires 'R'
    srand((unsigned) time(NULL));

    int nombreRochersAAjouter = ((nl * nc) / 3) - 1;

    initPlateau( plateau, nl, nc, nombreRochersAAjouter );
        
    // Boucle de jeu

    int nombreBombesPlacees = 0;
    int nombreRochersActuel = nbRochers( plateau, nl, nc );
    int nombreRochersDetruits = 0;
    
    while ( nombreRochersActuel > 0 && nl >= 3 && nc >= 3 ) {
        // Placement d'un rocher aléatoire 'R'
        printf("Ajout d'un rocher sur le plateau:\n");

        placerUnRocher( plateau, nl, nc );

        afficherPlateau( plateau, nl, nc );

        nombreRochersActuel = nbRochers( plateau, nl, nc );

        if ( nombreRochersActuel == ( nl * nc ) ) {

            break;

        }

        // Saisie des coordonnées de la bombe
        printf("Entrez les coordonnées de votre bombe: ");

        int posX = 0;
        int posY = 0;

        if ( scanf( "%d %d", &posX, &posY ) == EOF ) {

            break;

        }

        int indexX = posX - 1;
        int indexY = posY - 1;
        
        // Placement de la bombe 'X'

        if ( plateau[indexX][indexY] == 'R' ) {

            printf( "La case est occupée par un rocher\n" );
            continue;

        };

        plateau[indexX][indexY] = 'X';

        nombreBombesPlacees++;

        afficherPlateau( plateau, nl, nc );

        // Supprimer les rochers de la colonne de la bombe

        for ( int i=0; i<nc; i++ ) {

            if ( plateau[indexX][i] == 'R' ) {

                plateau[indexX][i] = ' ';
                nombreRochersDetruits++;

            }

        }

        // Supprimer les rochers de la ligne de la bombe

        for ( int i=0; i<nl; i++ ) {

            if ( plateau[i][indexY] == 'R' ) {

                plateau[i][indexY] = ' ';
                nombreRochersDetruits++;

            }

        }

        plateau[indexX][indexY] = ' ';

        printf( "Après explosion de la bombe :\n" );

        supprimerLigne( &plateau, &nl, nc, indexX );
        supprimerColonne( &plateau, nl, &nc, indexY );

        afficherPlateau( plateau, nl, nc );

        nombreRochersActuel = nbRochers( plateau, nl, nc );
        
    }

    // Affichage des statistiques

    if ( nombreRochersActuel == 0 ) {

        printf( "Bravo %s, tu as gagné !\n", pseudo );

    } else {

        printf( "Perdu !\n" );

    }

    printf( "\n" );

    printf( "Nombre de bombes placées : %d\n", nombreBombesPlacees );
    printf( "Nombre de rochers détruits : %d\n", nombreRochersDetruits );
    printf( "Nombre de rochers restants : %d\n", nombreRochersActuel );

    // Libération de la mémoire

    for ( int i=0; i<nl; i++ ) {

        free( plateau[i] );

    }

    free( plateau );

    free( pseudo );

}


//***********************
// FONCTIONS A COMPLETER
//***********************

/**
 * PRE: n,m: entiers positifs
 * RES: renvoie un tableau de dimensions n x m où les éléments sont 
 *      initialisés avec des espaces ; NULL si une erreur s'est produite
 *      (le tableau renvoyé est dynamique et devra être libéré)
 */
char** creerPlateau (int n, int m) {

    char** plateau = (char**) calloc( n, sizeof( char* ) );

    if ( plateau == NULL ) {

        return NULL;

    }

    for ( int i=0; i<n; i++ ) {

        plateau[i] = (char*) calloc( m, sizeof( char ) );

        if ( plateau[i] == NULL ) {

            return NULL;

        }

        for ( int j=0; j<m; j++ ) {

            plateau[i][j] = ' ';

        }

    }

    return plateau;

}

/**
 * Compte le nombre de rochers dans le plateau
 * PRE: p: plateau de dimensions n x m
 * RES: renvoie le nombre de cases du plateau p qui sont occupées 
 *      par un rocher 'R'
 */
int nbRochers (char** p, int n, int m) {

    int nombreRochers = 0;

    for ( int i=0; i<n; i++ ) {

        for ( int j=0; j<m; j++ ) {

            if ( p[i][j] == 'R' ) nombreRochers++;
        
        }

    }

    return nombreRochers;
}

/**
 * Place aléatoirement un rocher dans le plateau
 * PRE: p: plateau de dimensions n x m contenant au moins une case vide
 *         (càd différente de 'R')
 * POST: un rocher 'R' a été placé aléatoirement dans une case vide de p
 */
void placerUnRocher (char** p, int n, int m) {

    int posX = entierAleatoire( 0, m - 1 );
    int posY = entierAleatoire( 0, n - 1 );

    while ( p[posX][posY] == 'R' ) {

        posX = entierAleatoire( 0, m - 1 );
        posY = entierAleatoire( 0, n - 1 );

    }

    p[posX][posY] = 'R';
}

/**
 * Supprime une ligne du plateau
 * PRE: p: plateau contenant n lignes, t.q. n > 1
 *      ligne: indice de ligne t.q. 0 <= ligne < n
 * POST: la ligne d'indice ligne de p a été supprimée et n décrémenté de 1;
 *       p comporte n lignes physiquement en mémoire (taille physique = taille logique)
 * RES: renvoie vrai si la taille physique du tableau a bien été modifiée; faux sinon
 */

bool supprimerLigne(char*** p, int *n, int m, int ligne) {

    char* ligneASupprimer = (*p)[ligne];

    if ( ligneASupprimer == NULL ) return false;

    free( ligneASupprimer );

    for ( int i=ligne; i<(*n)-1; i++ ) {

        (*p)[i] = realloc( (*p)[i+1], m * sizeof( char ) );

        if ( (*p)[i] == NULL ) return false;
    }

    (*n)--;

    *p = realloc( *p, (*n) * sizeof( char* ) );

    if ( (*p) == NULL ) return false;

    return true;
}


/**
 * Supprime une colonne du tableau
 * PRE : p: plateau contenant m colonne, t.q. m > 1
 *       colonne: indice de colonne t.q. 0 <= colonne < m
 * POST : la colonne d'indice colonne de p a été supprimée et m décrémenté de 1;
 *       p comporte m colonnes physiquement en mémoire (taille physique = taille logique)
 * RES : renvoie vrai si la taille physique du tableau a bien été modifiée ; faux sinon
 */
bool supprimerColonne (char*** p, int n, int *m, int colonne) {
    (*m)--;
    for (int i=0; i<n; i++) {
        // Suppression de la colonne d'indice colonne dans la ligne i
        for (int j=colonne; j<*m; j++)
            (*p)[i][j] = (*p)[i][j+1];
        // Mise à jour des dimensions physiques de la ligne i
        (*p)[i] = realloc((*p)[i], *m * sizeof(char));
        if ((*p)[i] == NULL)
            return false;
    }
    return true;
}


//*************************************
// FONCTIONS FOURNIES (NE PAS MODIFIER)
//*************************************

/**
 * Place aléatoirement un rocher dans le plateau
 * PRE: p: plateau de dimensions n x m contenant au moins nbR cases vides
 *         (càd différente de 'R')
 *      nbR: le nombre de rochers à placer dans le plateau p
 * POST: nbR rochers 'R' ont été placés aléatoirement dans des cases vides de p
 */
void initPlateau (char** p, int n, int m, int nbR) {
    for (int i=0; i<nbR; i++)
        placerUnRocher(p,n,m);
}

/**
 * Génère une valeur entière aléatoire dans un intervalle
 * PRE: min, max: valeurs entières t.q. min < max
 * RES: renvoie une valeur entière aléatoire dans l'intervalle [min,max]
 */
int entierAleatoire (int min, int max) {
    return min + (int)(rand()/(RAND_MAX+1.0)*(max-min+1));
}

enum {BLACK_TEXT=30,RED_TEXT,GREEN_TEXT,YELLOW_TEXT,BLUE_TEXT,PURPLE_TEXT,CYAN_TEXT,WHITE_TEXT};
#define colorOn(mode,textColor) printf("\033[%d;%dm",mode,textColor)   // mode: 0 normal ; 1 bold
#define colorOff() printf("\033[0m");  // text color reset

/**
 * Affiche le plateau de jeu
 * PRE: p: plateau de dimensions n x m
 * POST: p a été affiché en indiquant les numéros des lignes et des colonnes
 */
void afficherPlateau (char** p, int n, int m) {
    colorOn(1,PURPLE_TEXT);
    printf("\n    ");
    for (int c=0; c<m; c++)
        printf("%3i", c+1);
    printf("\n     ");
    for (int c=0; c<m; c++)
        printf("---");
    printf("\n");
    for (int l=0; l<n; l++) {
        printf("%3i |", l+1);
        colorOn(1,CYAN_TEXT);
        for (int c=0; c<m; c++) {
            if (p[l][c] == 'X') {
                colorOn(1,YELLOW_TEXT);
                printf(" %c ", p[l][c]);
                colorOn(1,CYAN_TEXT);
            }
            else {
                printf(" %c ", p[l][c]);
            }
        }
        colorOn(1,PURPLE_TEXT);
        printf("| %i\n", l+1);
    }
    printf("     ");
    for (int c=0; c<m; c++)
        printf("---");
    printf("\n    ");
    for (int c=0; c<m; c++)
        printf("%3i", c+1);
    printf("\n\n");
    colorOff();
}
