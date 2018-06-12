#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXCHAR 13000

int variableCounter(char * fileName){
       char textFile[MAXCHAR];
       
       FILE * javaFile;
       javaFile = fopen(fileName, "r");
       
       int variableCounter = 0;
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
       int position = 0;     
       while(position<characterCounter){
                                        if(textFile[position] == '='){
                                                              bool spaceFlag = true;
                                                              int temporalIndex = position-1;
                                                              int wordLenght = 0;
                                                              while(textFile[temporalIndex] != ' ' || spaceFlag){
                                                                                                 if(temporalIndex == 0)
                                                                                                                  break;
                                                                                                 if(textFile[temporalIndex] == ' ' && spaceFlag){
                                                                                                                           temporalIndex--;
                                                                                                                           continue;
                                                                                                                           } 
                                                                                                 if(textFile[temporalIndex] != ' '){
                                                                                                                            spaceFlag = false;
                                                                                                                            temporalIndex--;
                                                                                                                            wordLenght++;
                                                                                                                            continue;
                                                                                                                            } 
                                                                                                 wordLenght++;
                                                                                                 temporalIndex--;
                                                                                                 } //printf("wordlenght %d \n", wordLenght);printf("char %c \n", textFile[temporalIndex+1]);
                                                              if(wordLenght < 6 || wordLenght > 32)
                                                                            variableCounter++;
                                                              }
                                        position++;
                                        }
       printf("Variables poco significativas: %d \n", variableCounter);
       return variableCounter;

       
       }
