#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXCHAR 13000

int magicNumbersCounter(char * fileName){
       char textFile[MAXCHAR];
       
       FILE * javaFile;
       javaFile = fopen(fileName, "r");
       
       int magicNumbersCounter = 0;
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
                                        if(textFile[position] >= '0' && textFile[position]<= '9'){
                                                              bool spaceFlag = true;
                                                              int temporalIndex = position-1;
                                                              bool isVariable = false;
                                                              
                                                              while(textFile[temporalIndex] != ' ' || spaceFlag){
                                                              
                                                                                            if(temporalIndex == 0)
                                                                                            break;
                                                                                            if(textFile[temporalIndex] == ' ' && spaceFlag){
                                                                                                                       temporalIndex--;
                                                                                                                       continue;
                                                                                                                       }
                                                                                            if(textFile[temporalIndex] != ' '){
                                                                                                                       if(textFile[temporalIndex] == '=' /*|| textFile[temporalIndex]*/ )
                                                                                                                                                  isVariable = true;
                                                                                                                       spaceFlag = false;
                                                                                                                       temporalIndex--;
                                                                                                                       break;
                                                                                                                       }
                                                                                            temporalIndex--;
                                                                                            }
                                                              if(isVariable == false)
                                                                            magicNumbersCounter++;
                                                              
                                                              while(textFile[position] >= '0' && textFile[position] <= '9')
                                                                                       position++;
                                        
                                        }
       position++;
       }
       printf("Magic numbers: %d \n", magicNumbersCounter);
       return magicNumbersCounter;
}
