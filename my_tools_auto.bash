
#
# Script pour automatiser la compilation et l'interprétation de fichier en c
#       demande un fichier en entrée avec l'extension en c
#       compile en binaire (pas de .sh ou d'.exe)
#            en utilisant gcc file_entrée.c -o file_sortie
#       lance le fichier file_sortie
#           si le fichier file_sortie est donné il portera ce nom
#           sinon le fichier créé sera aléatoire et sera ensuite lancé

#      Attention les erreurs ne sont pas traités (la partie code s'affichera ainsi
#           que les autres problèmes rencontrés lors d'une execution normale)

# Comment installer gcc :

# to install gcc :  sudo yum install gcc
#       or          sudo apt install gcc
#       or      any different system instead of sudo or yum


# compilation d'un fichier en c le nom de sortie est a.sh
simple_compilation_interpretation(){
    clear
    # input file $1 (name into variable)  # compilation
    gcc -c $( echo "$1") 
    # exec now out namefile.o # shell de 
    # linux donc .sh avec windows : .exe
    gcc $( echo "${1/.c/'.o'}") -o $( echo "${1/.c/'.sh'}") 
    # ./a.sh  # lancement du fichier (interpretation) 
    # (interprete avec le nom donné en 
    # paramètre suivie de l'extension .sh)
    "./$( echo "${1/.c/'.sh'}")"    
}
simple_compilation_interpretation $1






# C compiler and interpreter after bin transform
error_no_gcc=2
error_no_filename=11
error_no_outfile=12
# compil and interpret :
compilC () {
    ERROr=0 # init
    filename=$1
    fileout=$2
    tempout="$(openssl rand -hex 5)" # random name
    # "f$("$filename" | sed 's/^.//')$(openssl rand -hex 5)" # compex 
    if [[ $1 = "-h" ]]; then
        echo -e " commande pour interpréter du code en C (pour l'instant)
                    OPTIONS PRINCIPALES :
            -h                  permet d'afficher l'aide

            nomfichier.c        permet de compiler un fichier et d'afficher le rendu
                    OPTIONS :
                -no             permet de ne pas détruire le fichié compilé 
                                l'execution de la commande  
        

            exemple : 
                ->  ./my_to* filetest.c  
                ->  ./my_to* -h
                ->  ./my_to* *3*3* compilc3e3 -no 
                    (un fichier contenant 3 et 3 extention .c 
                    sans destruction du fichier compilé)
    "
    else
        if [[ filename = "" ]]; then
            errorr=$error_no_filename
            echo "Error no file in"
        fi
        if [[ "$fileout" == "" ]]; then
            # pas de sortie
            echo "nom nouveau fichier : $tempout"
            fileout=$tempout # random name start by f
        elif  $(find . -name $fileout) ; then 
            # the random can be same to the the file
            echo -e "\n\tCOMPILE:\nle nom de fichier existe déja gcc va donc se charger l'ecuter uniquement\n"
        fi
        # fileout not given or fileinput
        gcc "$filename" -o "$fileout"   
        if [ $? -eq 0 ]; then
            echo -e "compilation réussie ♥\n\n\n"
            ./$fileout # execute file
        else
            echo "compilation échouée -_-" 
        fi
        if [[ $3 != "-no" ]];then
            rm $fileout # clear after usage
        fi
        echo -e "\n\n\nexecution done ♥"   
    fi
    return $errorr
}

#compilC $@  # compil by callable file

    # add file to path : (use command anywhere)
    # mv command.sh /usr/local/bin/
    #             or
    # mv command.sh ~/bin



is_in_list() {
    # return true if something in foud in a list else false
    elementtofind=$1
    thelist=$2
    res=1
    for i in $thelist; do
        if [[ $elementtofind = $i ]]; then
            res=0
            break # deprecated here must use while (reason to do this : no time)
        fi
    done
    return $res
}


compil_any () {
    all_files=$@ # multi-files to edit
    extention=""
    rext=false # cannot get extension if not comma passed
    borbidenlist=("c" "h" 'tex' 'text' 'docx' "mm" "dll" "bin" "hex")
    thelist=("py" "sh" "yash" "exe" "js" "json" "cpp" "c#" "q#" "t#" "r" "rust" "ruby") # too huge
    for i in $all_files;do
        for j in $i;do
            if [[ j == "." ]]; then
                rext=true
            elif [[ rext == true ]]; then
                extention+=$j # add chars
            fi
        done
        if is_in_list $extention $thelist ; then
            "$extention ./$i\n" # run all files with our extention
            if [[ $? -eq 0 ]];then echo "job done"; fi
        elif is_in_list $extention forbidenlist ; then
            echo "you ask forbiden files : $i"
        else
            echo "file $i not allowed here, ext : $extention not recognize or doesn't exist"
        fi
        extention="" # re-init at 0
    done

}



# end page