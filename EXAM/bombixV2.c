#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define MAX_PSEUDO_LENGTH 40


// Déclaration des fonctions fournies
void initPlateau(char** p, int n, int m, int nbRochers);
int entierAleatoire(int min, int max);
void afficherPlateau(char** p, int n, int m);

// Déclarations des fonctions à compléter
char** creerPlateau(int n, int m);
int nbRochers(char** p, int n, int m);
void placerUnRocher(char** p, int n, int m);
bool supprimerColonne(char*** p, int n, int *m, int colonne);
bool supprimerLigne( char*** p, int *n, int m, int ligne );


//*********************
// PROGRAMME PRINCIPAL
//*********************

int main (int argc, char* argv[]) {
    // Vérification des arguments du programme
    if (argc != 3) {
        printf("Erreur: les deux dimensions du plateau de jeu doivent être fournis en arguments\n");
        exit(1);
    }

    int nl = atoi( argv[1] );
    int nc = atoi( argv[2] );

    printf( "Veuillez entrer votre pseudo : " );

    char* pseudo = (char*) calloc( MAX_PSEUDO_LENGTH+1, sizeof(char) );

    if ( pseudo == NULL ) {
        perror( "Pseudo : erreur lors de l'allocation de la mémoire dynamique" );
        exit(1);
    }

    fgets( pseudo, MAX_PSEUDO_LENGTH, stdin );

    pseudo[strlen(pseudo)-1] = '\0';
    
    char** plateau = creerPlateau( nl, nc );

    if ( plateau == NULL ) {
        perror( "Pseudo : erreur lors de l'allocation de la mémoire dynamique" );
        exit(1);
    }
    
    // Initialisation du plateau en plaçant nl*nc/3-1 rochers aléatoires 'R'
    srand((unsigned) time(NULL));

    int nbRochetsAleatoire = nl*nc/3-1;
    initPlateau ( plateau, nl, nc, nbRochetsAleatoire );

    int nbRochersRestant = nbRochers( plateau, nl, nc );
    int nbCases = nl * nc;
    int nbBombesPlacees = 0;
    int nbRochersDetruits = 0;
    
    while ( nbRochersRestant > 0 && nc >= 3 && nl >= 3 && nbRochersRestant != nbCases ) {
        // Placement d'un rocher aléatoire 'R'
        printf("Ajout d'un rocher sur le plateau:\n");

        placerUnRocher( plateau, nl, nc );

        afficherPlateau( plateau, nl, nc );

        nbRochersRestant = nbRochers( plateau, nl, nc );

        if ( nbRochersRestant == nbCases ) break;

        // Saisie des coordonnées de la bombe
        printf("Entrez les coordonnées de votre bombe: ");

        int ligneChoisie;
        int colonneChoisie;

        if ( scanf( "%d %d", &ligneChoisie, &colonneChoisie ) == EOF ) {

            break;

        }

        char caseBombe = plateau[ligneChoisie-1][colonneChoisie-1];

        if ( caseBombe == 'R' ) {

            printf( "La case est occupée par un rocher.\n" );
            continue;

        }

        plateau[ligneChoisie-1][colonneChoisie-1] = 'X';

        nbBombesPlacees++;

        afficherPlateau( plateau, nl, nc );

        for ( int i=0; i<nl; i++ ) {

            if ( plateau[i][colonneChoisie-1] == 'R' ) nbRochersDetruits++;
            
        }

        for ( int i=0; i<nc; i++ ) {

            if ( plateau[ligneChoisie-1][i] == 'R' ) nbRochersDetruits++;
            
        }

        plateau[ligneChoisie-1][colonneChoisie-1] = ' ';

        bool supLigne = supprimerLigne( &plateau, &nl, nc, ligneChoisie-1 );

        if ( supLigne == false ) {
            perror( "Supprimer ligne : erreur de réallocation.\n" );
            exit(1);
        }

        bool supColonne = supprimerColonne( &plateau, nl, &nc, colonneChoisie-1 );

        if ( supColonne == false ) {
            perror( "Supprimer colonne : erreur de réallocation.\n" );
            exit(1);
        }

        nbRochersRestant = nbRochers( plateau, nl, nc );
        nbCases = nl * nc;
        
        printf("Après explosion de la bombe:\n");

        afficherPlateau( plateau, nl, nc );
        
    }

    if ( nbRochersRestant > 0 ) {

        printf( "\nPerdu !\n" );
    
    } else {

        printf( "Bravo %s, tu as gagné !\n", pseudo );

    }

    printf( "Statistiques :\n\n" );

    printf( "Nombre de bombes placées : %d\n", nbBombesPlacees );
    printf( "Nombre de rochers détruits : %d\n", nbRochersDetruits );
    printf( "Nombre de rochers restant : %d\n", nbRochersRestant );

    free( pseudo );

    for ( int i=0; i<nl; i++ ) {
        free( plateau[i] );
    }

    free( plateau );

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

    char** plateau = (char**) calloc( n, sizeof(char*) );

    if ( plateau == NULL ) return NULL;

    for ( int i=0; i<n; i++ ) {

        plateau[i] = (char*) calloc( m+1, sizeof(char) );

        if ( plateau[i] == NULL ) return NULL;

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

    int nbRochers = 0;

    for (int l=0; l<n; l++) {
        for (int c=0; c<m; c++) {
            if (p[l][c] == 'R') {
                nbRochers++;
            }
        }
    }

    return nbRochers;

}

/**
 * Place aléatoirement un rocher dans le plateau
 * PRE: p: plateau de dimensions n x m contenant au moins une case vide
 *         (càd différente de 'R')
 * POST: un rocher 'R' a été placé aléatoirement dans une case vide de p
 */
void placerUnRocher (char** p, int n, int m) {

    int ligneAleatoire = entierAleatoire( 0, n-1 );
    int colonneAleatoire = entierAleatoire( 0, m-1 );

    char caseAleatoire = p[ligneAleatoire][colonneAleatoire];

    while ( caseAleatoire == 'R' ) {

        ligneAleatoire = entierAleatoire( 0, n-1 );
        colonneAleatoire = entierAleatoire( 0, m-1 );

        caseAleatoire = p[ligneAleatoire][colonneAleatoire];

    }

    p[ligneAleatoire][colonneAleatoire] = 'R';

}

/**
 * Supprime une ligne du plateau
 * PRE: p: plateau contenant n lignes, t.q. n > 1
 *      ligne: indice de ligne t.q. 0 <= ligne < n
 * POST: la ligne d'indice ligne de p a été supprimée et n décrémenté de 1;
 *       p comporte n lignes physiquement en mémoire (taille physique = taille logique)
 * RES: renvoie vrai si la taille physique du tableau a bien été modifiée; faux sinon
 */
bool supprimerLigne( char*** p, int *n, int m, int ligne ) {

    free( (*p)[ligne] );

    for ( int i=ligne; i<(*n)-1; i++ ) {

        (*p)[i] = (*p)[i+1];

    }

    (*n)--;

    (*p) = (char**) realloc( (*p), (*n) * sizeof(char*) );

    if ( (*p) == NULL ) {

        perror( "supprimerLigne : erreur lors de la réallocation.\n" );
        exit(1);
    }

    return true;

}

/**
 * Supprime une colonne du tableau
 * PRE : plateau contenant n lignes et m colonnes
 * POST : la ligne d'indice colonne a été supprimée et m a été décrémenté de 1
 *        chaque ligne de p comporte une colonne en moins
 * RES : renvoie vrai si la colonne a bien été supprimée; faux sinon
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
