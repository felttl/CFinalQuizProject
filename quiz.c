#include <stdio.h> // entrees-sorties
#include <string.h> // formattage de chaines
#include <stdlib.h> // random, ...
#include <time.h> // time usage
#include <math.h> // math usage
typedef enum{true, false} bool ; // boolean type (don't use shit library)


// faire un système de son pour savoir
// si on a réussi ou non
#include <windows.h>
#include <dos.h>

/* 	Cahier Des Charges :

	voir fichier cahier des charges



*/
// nb de lignes a ne pas dépasser
static int LIGNES_MAX_FICHIER = 11;



// permet de prendre une ligne (une question)
// et la demander a l'utilisateur plus tard 
int request(int ligne, char* update_request, float pts, int niveau){
	char* result = NULL;
	int cpt = 0; // compteur ligne
	char chaine[100]; // la longueur de chaque fichier est une question donc n'exède pas 100 charactères
	FILE * fichier_question; // structure du contenu de fichier


	fopen("ask.txt", "r");
	while(!feof(monfichier)){
    	fgets(chaine, 100, monfichier);
    }
	

	free(result); // libère la mémoire
	return EXIT_SUCCESS;
}

// enregistre dans un fichier vide déja créé les éléments
// persistance des données
int enregistrer_score(char* str_data){

    /* Variable to store user content */
    char data[DATA_SIZE];
    /* File pointer to hold reference to our file */
    FILE * fPtr;
    /* 
     * Open file in w (write) mode. 
     * "data/file1.txt" is complete path to create file
     */
    fPtr = fopen("save.txt", "w");
    /* fopen() return NULL if last operation was unsuccessful */
    if(fPtr == NULL){
        /* File not created hence exit */
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    /* Write data to file */
    fputs(str_data, fPtr);
    /* Close file to save file data */
    fclose(fPtr);
    /* Success message */
    printf("File created and saved successfully. :) \n");
    return 0;

}

// lire un fichier et afficher la ligne lue
int readOneLine(char*filepath,int line_num,char* getLine){
	printf("demande ouverture fichier : %s\n",filepath);
	int linen = 0;
	FILE * file;
	char displayText[100];
	bool carry = true;
	file = fopen(filepath, "r");
	if(file == NULL){
		printf("echec ouverture\n");
	}
	while(!feof(file) && carry){
		/*
		 warning: the `gets' function is dangerous and should not be used.
		*/
		fgets(displayText, 100, file);
		// afichage si vrai :
		if (linen == line_num){
			printf("%s\n", displayText);
			strcpy(getLine, displayText)
			line_num = linen;
			carry = false;
		}
		linen++;
	}
	fclose(file);
	return EXIT_SUCCESS;
}

// osx/macos (apple sys)


int is_in_list(char one_char, char*list_string){
	int res = false;
	int cpt = 0;
	bool carry = true;
	while (cpt < strlen(list_string) && carry){
		if (one_char == list_string[cpt]){
			carry = false;
			res = true;
		}
		cpt++;
	}
	return res;
}


// comparer deux chaine (avec une proportion de simillarité)
int strCompare(char*response, char*ask, float similarity){
	// les chaines n'on pas la même taille :
	int a = strlen(response), b = strlen(ask);
	char samechars[( a > b) ? a : b];  // commun chars tab
	int osize = strlen(response);
	// * 0.01 for each chars who correspond 1 time
	for (int i=0;i<a;i++){
		for (int ii=0;ii<b;ii++){
			// similarity
			if (response[i] == ask[ii]){
				// already seen
				if (is_in_list(response[i], samechars)){
					similarity += (1/osize)/2;
				} else {// never seen
					similarity += (1/osize);
				}
			} else { // not same letter
				similarity *= 101e-2;
			}
		}
	}
	return EXIT_SUCCESS;
}


// load saved date if exists :
int load_saved(char*fileNameyPath,float level, char* nb_questions){
    fPtr = fopen(fileNameyPath, "w");
    /* fopen() return NULL if last operation was unsuccessful */
    if(fPtr == NULL){
        /* File not created hence exit */
        printf("can't create file ! \n");
        exit(EXIT_FAILURE);
    } else {
		// insert data

    	// must use parameters to store data in them
    }
    return EXIT_SUCCESS;
}


// créer un menu de sélection 
char menu(){
	char etat;
	printf("\n");
	printf("┌────────── Menu ────────────┐\n");
	printf("│	q : quitter   	 		 │\n");
	printf("│	c : continuer 	 		 │\n");
	printf("│	s : enregistrer   		 │\n");
	printf("│	a : afficher points		 │\n");	
	printf("│	l : changer de niveau	 │\n");		
	printf("└────────────────────────────┘\n");
	scanf("%c", etat);+
	return etat;
}

// resize the filesize at input keyboard (From : Google) not require initiasize
char*inputString(FILE* fp, size_t size){
//The size is extended by the input with the value of the provisional
	const FILE*fp= stdin; // get stdinput
	size_t size=10; // unknow

    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(*str)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(*str)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(*str)*len);
}

// fonction qui renvoie une chaine de charactère dont la paramètre est concaténé
// la la suite d'une chaine de base (permet de naviguer dans une
// arborescence en limitant le nombre d'intérations)
char* shortcat(char*base, int lenbase, char*stack, int lenstack){
	char*strresult[lenbase+lenstack]=base;
	strcat(strresult, stack);
	return strresult;
}



// programme principal
int main(){
	// initialisation fonction aléatoire :
	srand(time(null));
	// choix ligne aléatoire pour la question
	int choixLigne; 
	char pseudo[25];
	float points = 0.0; 
	bool carry = true;
	char saisie_user;
	// ne dois pas dépasser le nombre de question dans le fichier
	int nbTours = 0; 
	bool gagne = false; 
	int level; // store player level
	// ne pas recommencer 2 fois la même question
	// allocation dynamique : (tableau d'entiers pour le n° de lignes)
	int*questionsFaites = NULL; // store all checked lines numbers
	questionsFaites = (int *) malloc( 1 ); 
	const char chemin[19] = "./level_ask/"; // filepath navigation
	char tempChemin[9] = "";
	char*reponseJoueur[10]; // stocke 10 chaines de charactères
	char*bonneReponse[10]; // stocke 10 chaines de charactères
	printf("Bienvenu dans le Quizz sur l'informatique\n");

	printf("entrez votre pseudo : \n");
	stringInput(pseudo);
	prtinf("choisir le niveau : (facile, moyen, difficile)\n");
	printf("avec les touches respectives 1, 2, et 3 : \n");
	scanf("%d", level);

	// on saisie le niveau qu'une seule fois
    if (level <= 3 && level >= 1){
    	sprintf(tempChemin, "%d", level);  
    	strcat(tempChemin, "/ask.txt");
    	strcat(chemin, temp);
    } else { // saisie invalide
        printf("saisie non valide\n");
        carry = false;
    }


	while(carry){
		choixLigne = rand() % LIGNES_MAX_FICHIER;
		saisie_user = menu();
		// je déteste les switch désolé
		if (saisie_user == 'c'){
			// on continue de jouer
			printf("répondez a la question suivate :\n");
			readOneLine(chemin, choixLigne, bonneReponse);
			&reponseJoueur[nbTours] = inputString();
			// ajouter points 
			strCompare(bonneReponse, &reponseJoueur, level);
			// ajouter la ligne parcourue 
			questionsFaites[n] = choixLigne;
		} else if (saisie_user == 's'){
			// on enregistre dans un fichier toutes
			// les saisies précédentes 
			saveText("userQuestions.txt")
	
		} else if (saisie_user == 'q'){
			// on part sans enregistrer
			carry = false
		} else if (saisie_user == 'a'){
			// afficher les points 
		} else if (gagne){
			// gagné !!!
			printf("vous avez gagné\n");
			carry = false;
		} else {
			// mauvaise saisie
			printf("vous avez mal répondu !!!\n");
			carry = false;
		}
		nbTours++;

		questionsFaites = (int*)realloc(n * sizeof(int));

	}
	printf("au revoir\n");

	free(questionsFaites);
	free(&reponseJoueur);
	free(bonneReponse);

	return EXIT_SUCCESS;
}








// end page