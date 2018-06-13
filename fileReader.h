#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXCHAR 10000

char[] fileReader(char * fileName){
       char textFile[MAXCHAR];
       
       FILE * javaFile;
       javaFile = fopen(fileName, "r");
       
       int characterCounter = 0;
       
       if(javaFile == NULL){
            printf("No pudo ser abierto el archivo %s \n", fileName);
            return 0;
            }
       else{
            char character;
            do {
                character = fgetc (javaFile);
                textFile[characterCounter] = character;
                characterCounter++;
                } while (character != EOF);
                
                textFile[characterCounter] = 0;
                fclose (javaFile);
            }
       return textFile;
}
