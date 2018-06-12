#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAXCHAR 13000
#define CODESIZE 256

int repetitionsCounter(char * fileName[]){
       int filesCounter = fileCounter(fileName);
       char textFile[MAXCHAR*20];
       char * claves[] = {"if", "else", "while", "for", "do", "try", "catch", "{", "}", "*", "/", "+", "-", "%"};
       
       time_t t;
       srand((unsigned) time(&t));
       
       FILE * javaFile;
       
       int repetitionsCounter = 0;
       int characterCounter = 0;
       int i;
       for(i = 0; i<filesCounter; i++){
               javaFile = fopen(fileName[i], "r");
               if(javaFile == NULL){
                           printf("No pudo ser abierto el archivo %s \n", fileName);
                           continue;
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
       }
       
       int sampleCounter = characterCounter*40/100/256;
       int samples[406][64];
       int samplePosition = 0;
       
       int position = 0;
       
       while(sampleCounter != 0){
                           int innerSamplePosition = 0;
                           position = rand()%(characterCounter-256);
                           //printf("position %d \n", position);
                           while(true){
                                       if(textFile[position] == 'i' && textFile[position+1] == 'f')
                                                             break;
                                       else if(textFile[position] == '{')
                                                                  break;
                                       else if(textFile[position] == 'w' && textFile[position+1] == 'h' && textFile[position+2] == 'i' && textFile[position+3] == 'l' && textFile[position+4] == 'e')
                                                                  break;
                                       else if(textFile[position] == 'f' && textFile[position+1] == 'o' && textFile[position+2] == 'r')
                                                                  break;
                                       position++;
                                 }
                           int sampleSizeCounter = 0; 
                           while(sampleSizeCounter <= 256){
                                                   //printf("entro %d %d %d\n", sampleSizeCounter, position, characterCounter);
                                                   if(sampleSizeCounter == 256 || sampleSizeCounter == characterCounter){
                                                                        samples[samplePosition][innerSamplePosition] = -1;
                                                                        sampleSizeCounter = 0;
                                                                        break;
                                                                        }
                                                   int result = compare(textFile, position);
                                                   if(result == -1){
                                                             position++;
                                                             sampleSizeCounter++;
                                                             continue;
                                                   }
                                                   else if(result == 1)
                                                                  samples[samplePosition][innerSamplePosition] = 1;
                                                   else if(result == 2)
                                                                  samples[samplePosition][innerSamplePosition] = 2;
                                                   else if(result == 3)
                                                                  samples[samplePosition][innerSamplePosition] = 3;
                                                   else if(result == 4)
                                                                  samples[samplePosition][innerSamplePosition] = 4;
                                                   else if(result == 5)
                                                                  samples[samplePosition][innerSamplePosition] = 5;
                                                   else if(result == 6)
                                                                  samples[samplePosition][innerSamplePosition] = 6;
                                                   else if(result == 7)
                                                                  samples[samplePosition][innerSamplePosition] = 7;
                                                   else if(result == 8)
                                                                  samples[samplePosition][innerSamplePosition] = 8;
                                                   else if(result == 9)
                                                                  samples[samplePosition][innerSamplePosition] = 9;
                                                   else if(result == 10)
                                                                  samples[samplePosition][innerSamplePosition] = 10;
                                                   else if(result == 11)
                                                                  samples[samplePosition][innerSamplePosition] = 11;
                                                   else if(result == 12)
                                                                  samples[samplePosition][innerSamplePosition] = 12;
                                                   else if(result == 13)
                                                                  samples[samplePosition][innerSamplePosition] = 13;
                                                   innerSamplePosition++;
                                                   sampleSizeCounter++;
                                                   position++;
                                                   }//printf("salgo %d\n", position);
                           
                           sampleCounter--;
                           samplePosition++;
                           }
        
       repetitionsCounter = compareSamples(samples, samplePosition);
       printf("Repetitions: %d \n", repetitionsCounter);
       return repetitionsCounter;
}

int fileCounter(char * fileName[]){
    int fileCounter = 0;
    int position = 0;
    while(fileName[position] != "end"){
                             fileCounter++;
                             position++;
                             }
    return fileCounter;
}

int compareIf(char textFile[], int position){
    if(textFile[position] == 'i' && textFile[position+1] == 'f')
                          return 0;
    return -1;
}

int compareElse(char textFile[], int position){
    if(textFile[position] == 'e' && textFile[position+1] == 'l' && textFile[position+2] == 's' && textFile[position+3] == 'e')
                          return 1;
    return -1;
}

int compareWhile(char textFile[], int position){
    if(textFile[position] == 'w' && textFile[position+1] == 'h' && textFile[position+2] == 'i' && textFile[position+3] == 'l' && textFile[position+4] == 'e')
                          return 2;
    return -1;
}

int compareFor(char textFile[], int position){
    if(textFile[position] == 'f' && textFile[position+1] == 'o' && textFile[position+2] == 'r')
                          return 3;
    return -1;
}

int compareDo(char textFile[], int position){
    if(textFile[position] == 'd' && textFile[position+1] == 'o')
                          return 4;
    return -1;
}

int compareTry(char textFile[], int position){
    if(textFile[position] == 't' && textFile[position+1] == 'r' && textFile[position+2] == 'y')
                          return 5;
    return -1;
}

int compareCatch(char textFile[], int position){
    if(textFile[position] == 'c' && textFile[position+1] == 'a' && textFile[position+2] == 't' && textFile[position+3] == 'c' && textFile[position+2] == 'h')
                          return 6;
    return -1;
}

int compareLB(char textFile[], int position){
    if(textFile[position] == '{')
                          return 7;
    return -1;
}

int compareRB(char textFile[], int position){
    if(textFile[position] == '}')
                          return 8;
    return -1;
}

int compareMul(char textFile[], int position){
    if(textFile[position] == '*')
                          return 9;
    return -1;
}

int compareDiv(char textFile[], int position){
    if(textFile[position] == '/')
                          return 10;
    return -1;
}

int compareAdd(char textFile[], int position){
    if(textFile[position] == '+')
                          return 11;
    return -1;
}

int compareSub(char textFile[], int position){
    if(textFile[position] == '-')
                          return 12;
    return -1;
}

int compareMod(char textFile[], int position){
    if(textFile[position] == '%')
                          return 13;
    return -1;
}

int compare(char textFile[], int position){
    int result = compareIf(textFile, position);
    if (result != -1)
       return 0;
    result = compareElse(textFile, position);
    if (result != -1)
       return 1;
    result = compareWhile(textFile, position);
    if (result != -1)
       return 2;
    result = compareFor(textFile, position);
    if (result != -1)
       return 3;
    result = compareDo(textFile, position);
    if (result != -1)
       return 4;
    result = compareTry(textFile, position);
    if (result != -1)
       return 5;
    result = compareCatch(textFile, position);
    if (result != -1)
       return 6;
    result = compareLB(textFile, position);
    if (result != -1)
       return 7;
    result = compareRB(textFile, position);
    if (result != -1)
       return 8;
    result = compareMul(textFile, position);
    if (result != -1)
       return 9;
    result = compareDiv(textFile, position);
    if (result != -1)
       return 10;
    result = compareAdd(textFile, position);
    if (result != -1)
       return 11;
    result = compareSub(textFile, position);
    if (result != -1)
       return 12;
    result = compareMod(textFile, position);
    if (result != -1)
       return 13;
    else return -1;
}

int compareSamples(int samples[152][64], int samplesQuantity){
    int i;
    int j;
    int innerSampleA;
    int innerSampleB;
    int matches;
    int repetitionsCounter = 0;
    for(i = 0; i<samplesQuantity; i++){
            for(j=i+1; j<samplesQuantity; j++){
                     innerSampleA = 0;
                     innerSampleB = 0;
                     matches = 0;
                     while(samples[i][innerSampleA] != samples[j][innerSampleB]){//printf("hola %d %d\n", samples[i][innerSampleA], samples[j][innerSampleB]);
                                                   innerSampleA++;}
                     while(samples[i][innerSampleA] != -1){
                                                   if(samples[i][innerSampleA] == samples[j][innerSampleB])
                                                                              matches++;//printf("%d \n", matches);
                                                   else
                                                        innerSampleA++;                                                     
                                                   innerSampleA++;
                                                   innerSampleB++;
                                                   }
            }
            int minimunPercentage = innerSampleA*75/100;
            if(matches >= minimunPercentage)
                       repetitionsCounter++;
    }
    return repetitionsCounter;
}
//{"if", "else", "while", "for", "do", "try", "catch", "{", "}", "*", "/", "+", "-", "%"}
