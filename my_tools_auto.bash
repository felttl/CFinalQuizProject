

# EN

# Script to automate compilation of c files with GCC
#     input : file in c
#     compiling in binnary with .sh or .exe
    # and run file after compiling (aoto run)


# it's possible to install a linux terminal to launch this script 
# with eaze (and be very useful)

# FR

# Script pour automatiser la compilation et l'interprétation de fichier en c
#       demande un fichier en entrée avec l'extension en c
#       compile en binaire (pas de .sh ou d'.exe)
#            en utilisant gcc file_entrée.c -o file_sortie
#       lance le fichier file_sortie
#           si le fichier file_sortie est donné il portera ce nom
#           sinon le fichier créé sera aléatoire et sera ensuite lancé




# compilation d'un fichier en c / compilning file function
# simple compilation interpretation (SCI)
sci0(){
    extensionResult=""
    # default
    if [ "$2" == "" ]; then
        $extensionResult = ".sh"
    else 
        $extensionResult = "$2"
    fi

    clear # linux / cls with windows
    # input file $1 (name into variable)  # compilation
    gcc -c $( echo "$1") 
    # exec now out namefile.o # shell de 
    # linux donc .sh avec windows : .exe
    gcc $( echo "${1/.c/'.o'}") -o $( echo "${1/.c/'$extensionResult'}") 
    # ./a.sh  # lancement du fichier (interpretation) 
    # (interprete avec le nom donné en 
    # paramètre suivie de l'extension .sh)
    "./$( echo "${1/.c/'$extensionResult'}")"    
}
# second parameter is output extension
#sci $1


sci(){
    clear
    gcc -c $( echo "$1") 
    gcc $( echo "${1/.c/'.o'}") -o $( echo "${1/.c/'.sh'}") 
    "./$( echo "${1/.c/'.sh'}")"        
}
sci $1



# end page