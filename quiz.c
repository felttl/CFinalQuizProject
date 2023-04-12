#include <stdio.h> // entrees-sorties
#include <string.h> // formattage de chaines
#include <stdlib.h> // random, ...
#include <time.h> // time usage
#include <math.h> // math usage
typedef enum{true, false} bool ; // boolean type (don't use shit library)


// faire un système de son pour savoir
// si on a réussi ou non
// je ne possède pas al lib sur ce pc
//#include <windows.h> // a tester sur une autre machien pour tester le fonctionnement
//#include <dos.h>

/* 	Cahier Des Charges :

	voir fichier cahier des charges



*/
// nb de lignes a ne pas dépasser
static int LIGNES_MAX_FICHIER = 10;





// permet de prendre une ligne (une question)
// et la demander a l'utilisateur plus tard 
// ça marche !!
int request(int ligne, char* update_request, float pts, int niveau){
	char* result = NULL;
	int cpt = 0; // compteur ligne
	char chaine[100]; // la longueur de chaque fichier est une question donc n'exède pas 100 charactères
	FILE * fichierQuestion; // structure du contenu de fichier
	fopen("ask.txt", "r");
	while(!feof(fichierQuestion)){
    	fgets(chaine, 100, fichierQuestion);
    }
	free(result); // libère la mémoire
	return EXIT_SUCCESS;
}

// enregistre dans un fichier vide déja créé les éléments
// persistance des données
// doit ajouter dans le fichier chaque lignes qui a été saisi par le joueur ainsi que les autre infos
int enregistrerScore(char*strData, char*pseudo, int niveau, float score, char*nomFichier){

    /* Variable to store user content */
	char niveauchar[2];
	char scorestr[6]; 
	// convert data 
	sprintf(niveauchar, "%d", niveau);
	sprintf(scorestr, "%f", score);
    char data[strlen(strData)];
    /* File pointer to hold reference to our file */
    FILE * fPtr;
	// write in existing file
    fPtr = fopen(nomFichier, "w");
    /* fopen() return NULL if last operation was unsuccessful */
    if(fPtr == NULL){
        /* File not created hence exit */
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
	// escape sequence 
	strcat(niveauchar, "\n");
	strcat(scorestr, "\n");
	strcat(strData, "\n");
	strcat(pseudo, "\n");
    /* Write data to file */
    fputs(strData, fPtr);
	fputs("niveau : ", fPtr);
	fputs(pseudo, fPtr);
	fputs("score : ", fPtr);
    /* Close file to save file data */
    fclose(fPtr);
    /* Success message */
    printf("File created and saved successfully. :) \n");
    return EXIT_SUCCESS;
}

/// ça marche
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
			strcpy(getLine, displayText);
			line_num = linen;
			carry = false;
		}
		linen++;
	}
	fclose(file);
	return EXIT_SUCCESS;
}

// osx/macos (apple sys)


bool charIsInListStr(char one_char, char*list_string){
	int cpt = 0;
	bool carry = true;
	while (cpt < strlen(list_string) && carry){
		if (one_char == list_string[cpt]){
			carry = false;
		}
		cpt++;
	}
	return carry;
}

bool intIsInListints(int oneNum, int*listNum, int tailletab){
	int cpt = 0;
	bool carry = true;
	while (cpt < tailletab && carry){
		if (oneNum == listNum[cpt]){
			carry = false;
		}
		cpt++;
	}
	return carry;
}





// comparer deux chaine (avec une proportion de simillarité)
int strCompare(char*response, char*ask, float similarity){
	// les chaines n'on pas la même taille :
	int osize = strlen(response);
	// * 0.01 for each chars who correspond 1 time
	for (int i=0;i<osize;i++){
		for (int ii=0;ii<strlen(ask);ii++){
			// similarity
			if (response[i] == ask[ii]){
				// already seen
				if (response[i] == ask[i]){
					similarity += (1/osize)/2;
				} else {// never seen
					similarity += (1/osize);
				}
			} else { // not same letter
				similarity *= 101e-2;
			} // size is different we don't add points
		}
	}
	return EXIT_SUCCESS;
}



// créer un menu de sélection 
char menu(){
	char etat;
	printf("\n");
	printf("┌──────────── Menu ──────────┐\n");
	printf("│	q : quitter   	 		 │\n");
	printf("│	c : continuer 	 		 │\n");
	printf("│	s : enregistrer   		 │\n");
	printf("│	a : afficher points		 │\n");		
	printf("└────────────────────────────┘\n");
	scanf("%c", etat);
	return etat;
}

// resize the filesize at input keyboard (From : Google) not require initiasize
char*inputString(){
//The size is extended by the input with the value of the provisional
	FILE*fp= stdin; // get stdinput
	size_t size=10; // unknow

    char *str;
    int ch;
    size_t len = 0;
	//size is start size
    str = realloc(NULL, sizeof(*str)*size);
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




/// VERIFIEE !! (ça marche)
// permet de mettre a jour le chemin de navigation temporaire
// si un utilisateur veut changer de niveau en cours de partie
int updateNav(char*toUpdate, int rank, char*base, char*endfilepath){
	// onvertir l'entier en chaine ici 
	char tempconvert[9] = " ";
	// copie la partie gauche du chemin d'accés 
	// doit écraser les données précédentes
	strcpy(toUpdate, base); 
	sprintf(tempconvert, "%d", rank);
	// concat le milieu (partie changeante)
	strcat(toUpdate, tempconvert);
	// concat la partie de fin (droite et aussi partie changeante)
	strcat(toUpdate, endfilepath);
	return EXIT_SUCCESS;
}



// programme principal
int main(){
	// initialisation fonction aléatoire :
	srand(time(NULL));
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
	char chemin[19] = "./level_ask/"; // filepath navigation
	char tempChemin[9] = ""; // stockage du nombre saisi par l'utilisateur convertit en chaine
	char navChemin[19] = "./level_ask/"; // chaine pour le déplacement (modifiable)
	char reponseJoueur[10][30]; // une liste de 10 chaines de caractères de 30 caractères
	char bonneReponse[10]; // chaine de 10 charactères
	int choixniveau;  // saisi utilisateur
	int listNumNiveaux[10]; // stocker toutes les réponse (n°lignes) déja faites pour chaque niveau 
	printf("Bienvenu dans le Quizz sur l'informatique\n");

	printf("entrez votre pseudo : (25 caractères max)\n");
	strcpy(pseudo, inputString());
	printf("choisir le niveau : (facile, moyen, difficile)\n");
	printf("avec les touches respectives 1, 2, et 3 : \n");
	scanf("%d", choixniveau);
	printf("ça a planté !!!");
	// on saisie le niveau qu'une seule fois (sauf si le joueur veut changer)
    if (choixniveau <= 3 && choixniveau >= 1){
		updateNav(navChemin, choixniveau, chemin, "/ask.txt");
		printf("done");
    } else { // saisie invalide
        printf("saisie non valide\n");
        carry = false;
    }


	while(carry){
		// on fait un nouveau aléatoire tant que qu'il est déja présent dans la liste
		// on aurait pu aussi faire une liste des éléments autorisés et les supprimer au fur et a mesure
		// que le joueur choisi des choix et faire un nombre aléatoire des index de cette liste (éviter le while)
		while (intIsInListints(choixLigne, listNumNiveaux, nbTours+1)){
			choixLigne = rand() % LIGNES_MAX_FICHIER;
		}
		saisie_user = menu();
		// je déteste les switch désolé
		if (saisie_user == 'c'){
			// on continue de jouer
			printf("répondez a la question suivate :\n");
			readOneLine(navChemin, choixLigne, bonneReponse);
			// pour l'enregistrement des données
			strcpy(reponseJoueur[nbTours], inputString()); 
			// ajouter points 
			strCompare(bonneReponse, reponseJoueur[nbTours], points);
			// ajouter la ligne parcourue (pour pas reposer la même question)
			listNumNiveaux[nbTours] = choixLigne; // un entier dans un entier


		} else if (saisie_user == 's'){
			// on enregistre dans un fichier toutes les saisies précédentes 
			//enregistrerScore(char* strData, char*pseudo, int niveau, float score, char*nomFichier)
			char tempStartTrame[378] = "-----------------------------------------------------------------\n";
			strcat(tempStartTrame, "QUESTIONS : \n");
			char tempsLineNumberChar[2];
			// pour toutes les question on les stack dans le fichier :
			for (int i=0; i<11;i++){
				sprintf(tempsLineNumberChar, "%d", i); // delete last psintf
				strcat(tempStartTrame, "question n°");
				strcat(tempStartTrame, tempsLineNumberChar);
			}
			
			enregistrerScore(tempStartTrame, pseudo, level, points, "userQuestions.txt");
		} else if (saisie_user == 'q'){
			// on part sans enregistrer
			carry = false;
		} else if (saisie_user == 'a'){
			// afficher les points 
			printf("vous avez : %.4f\t points.\n", points);
		} else if (points >= 8.0){
			// gagné !!!
			// rappel : 1 poit par bonne réponses 
			// pour gagner il faut 8 points (et on joue un son)
			printf("vous avez gagné\n");
			// jouer un son...
			carry = false;
		} else if (nbTours == 10){
			// tt les questions terminées
			printf("vous avez fait toutes les questions\n");
			carry = false;			
		} else {
			// mauvaise saisie
			printf("vous avez mal répondu !!!\n");
			carry = false;
		}
		nbTours++;
	}
	printf("au revoir\n");
	return EXIT_SUCCESS;
}








// end page