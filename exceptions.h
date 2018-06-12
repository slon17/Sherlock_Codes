#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXCHAR 13000

int exceptionsCounter(char * fileName){
       char textFile[MAXCHAR];
       
       FILE * javaFile;
       javaFile = fopen(fileName, "r");
       
       int exceptionsCounter = 0;
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
                                        if(textFile[position] == 'p' && position+5 < characterCounter && textFile[position+1] == 'u' && textFile[position+2] == 'b' && textFile[position+3] == 'l' && textFile[position+4] == 'i' && textFile[position+5] == 'c'){
                                                              bool bracketFlag = true;
                                                              bool exceptionFlag = false; //if exception flag is true at the end of if, exceptionsCounter++
                                                              int temporalIndex = position+6;
                                                              int leftBracketCounter = 1;
                                                              int rightBracketCounter = 0;
                                                              
                                                              while(leftBracketCounter>rightBracketCounter){
                                                                                                            if(temporalIndex>characterCounter)
                                                                                                                                      break;
                                                                                                            else if(textFile[temporalIndex] == '{'){
                                                                                                                                       if(bracketFlag)
                                                                                                                                                      bracketFlag = false;
                                                                                                                                       else
                                                                                                                                           leftBracketCounter++;
                                                                                                            }
                                                                                                            else if(textFile[temporalIndex] == '}')
                                                                                                                                       rightBracketCounter++;
                                                                                                            else if(textFile[temporalIndex] == 't' && textFile[temporalIndex+1] == 'r' && textFile[temporalIndex+2] == 'y'){
                                                                                                                                            exceptionFlag = true;
                                                                                                            }
                                                              //printf("%c", textFile[temporalIndex]);
                                                              temporalIndex++;
                                                              }
                                                              if(exceptionFlag == false)
                                                                               exceptionsCounter++;
                                        }
       position++;
       }
       printf("Excepciones no capturadas: %d \n", exceptionsCounter);
       return exceptionsCounter;
}
