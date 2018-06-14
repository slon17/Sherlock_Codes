#include "variables.h"
#include "exceptions.h"
#include "repeated.h"
#include "magicNumbers.h"
#include "math.h"

#define MAXVAR 14416
#define MAXMAGIC 26212
#define MAXEXCEP 42596
#define MAXREPET 65535



void intToBinary(unsigned int in, int out[]){
    unsigned int mask = 1U << (16-1);
    int i;
    for (i = 0; i < 16; i++) {
        out[i] = (in & mask) ? 1 : 0;
        //printf("%d",out[i]);
        in <<= 1;
    }
    //printf("\n");
}

int binaryToInt(int bNumber[]){
    int i;
    int result = 0;
    int position = 0;
    for(i = 15; i>=0; i--){
          if(bNumber[position]==1)
                                  result+=pow(2,i);
          position++;
          //printf("%d",result);
          }
          //printf("\n");
    return result;
}

sherlockData(char * files[]){
                  //variableCounter(files);
                  //magicNumbersCounter(files);
                  //exceptionsCounter(files);
                  repetitionsCounter(files);
}

sherlockGenetic(int clues[]){
                    time_t t;
                    srand((unsigned) time(&t));
                    
                    int population[100000];
                    int popCounter = 0;
                    int position;
                    int cluesCounter;
                    
                    int varChildrenQuantity = 0;
                    int magicChildrenQuantity = 0;
                    int exceptionChildrenQuantity = 0;
                    int repetitionChildrenQuantity = 0;
                    
                    int varChildrenTotal = 0;
                    int magicChildrenTotal = 0;
                    int exceptionChildrenTotal = 0;
                    int repetitionChildrenTotal = 0;
                    
                    for(position = 0; position<4; position++){
                                 cluesCounter = 0;
                                 while(cluesCounter <= clues[position]){
                                                    if(position == 0){
                                                                population[popCounter] = rand()%MAXVAR;
                                                                varChildrenQuantity++;
                                                                varChildrenTotal += population[popCounter];
                                                                }
                                                    else if(position == 1){
                                                                     population[popCounter] = (rand()%(MAXMAGIC - MAXVAR)) + MAXVAR; 
                                                                     magicChildrenQuantity++;
                                                                     magicChildrenTotal += population[popCounter];
                                                                     }
                                                    else if(position == 2){
                                                                     population[popCounter] = (rand()%(MAXEXCEP - MAXMAGIC)) + MAXMAGIC;
                                                                     exceptionChildrenQuantity++;
                                                                     exceptionChildrenTotal += population[popCounter];
                                                                     }
                                                    else if(position == 3){
                                                                     population[popCounter] = (rand()%(MAXREPET - MAXEXCEP)) + MAXEXCEP;
                                                                     repetitionChildrenQuantity++;
                                                                     repetitionChildrenTotal += population[popCounter];
                                                                     }
                                                    //printf("population %d \n", population[popCounter]);
                                                    popCounter++;
                                                    cluesCounter++;
                                                    }
                                 }
                                 
                    int varAverage;
                    int magicAverage;
                    int exceptionAverage;
                    int repetitionAverage;
                    
                    int varValue;
                    int magicValue;
                    int exceptionValue;
                    int repetitionValue;
                    
                    int generation;
                    
                    for(generation = 0; generation<20; generation++){
                                   varAverage = varChildrenTotal/varChildrenQuantity;
                                   magicAverage = magicChildrenTotal/magicChildrenQuantity;
                                   exceptionAverage = exceptionChildrenTotal/exceptionChildrenQuantity;
                                   repetitionAverage = repetitionChildrenTotal/repetitionChildrenQuantity;
                                   
                                   if(varAverage < (MAXVAR*33.33/100)){
                                                 varValue = 0; //minimun end
                                                 printf("var value 0");}
                                   else if(varAverage >= (MAXVAR*33.33/100) && varAverage < (MAXVAR*33.33/100)*2)
                                                 varValue = 1; //average
                                   else
                                       varValue = 2; //maximun end
                                   
                                   if(magicAverage < ((MAXMAGIC-MAXVAR)*33.33/100)+MAXVAR)
                                                   magicValue = 0;
                                   else if(magicAverage >= ((MAXMAGIC-MAXVAR)*33.33/100)+MAXVAR && magicAverage < ((MAXMAGIC-MAXVAR)*33.33/100)*2+MAXVAR)
                                                        magicValue = 1;
                                   else
                                       magicValue = 2;
                                   
                                   if(exceptionAverage < ((MAXEXCEP-MAXMAGIC)*33.33/100)+MAXMAGIC)
                                                       exceptionValue = 0;
                                   else if(exceptionAverage >= ((MAXEXCEP-MAXMAGIC)*33.33/100)+MAXMAGIC && exceptionAverage < ((MAXEXCEP-MAXMAGIC)*33.33/100)*2+MAXMAGIC)
                                                            exceptionValue = 1;
                                   else
                                       exceptionValue = 2;
                                       
                                   if(repetitionAverage < ((MAXREPET-MAXEXCEP)*33.33/100)+MAXEXCEP)
                                                        repetitionValue = 0;
                                   else if(repetitionAverage >= ((MAXREPET-MAXEXCEP)*33.33/100)+MAXEXCEP && repetitionAverage < ((MAXREPET-MAXEXCEP)*33.33/100)*2+MAXEXCEP)
                                                             repetitionValue = 1;
                                   else
                                       repetitionValue = 3;
                                   
                                   //******//
                                   int temporalPopulation[50000];
                                   int temporalParentsIndex = 0;
                                   int popIndex;
                                   printf("varValue: %d, magicValue: %d, repeatitionValue: %d \n", varValue, magicValue, repetitionValue);
                                   for(popIndex = 0; popIndex<popCounter; popIndex++){
                                                if(population[popIndex]<MAXVAR){
                                                                                if(varValue == 0){
                                                                                            if(population[popIndex]<(MAXVAR*33.33/100)){
                                                                                                                                        //printf("varvalue0"); 
                                                                                                                                       temporalPopulation[temporalParentsIndex] = population[popIndex];
                                                                                                                                       temporalParentsIndex++;
                                                                                            }
                                                                                }
                                                                                else if(varValue == 1){
                                                                                     if(population[popIndex]>=(MAXVAR*33.33/100) && population[popIndex] < (MAXVAR*33.33/100)*2){//printf("varvalue1");
                                                                                                                                 temporalPopulation[temporalParentsIndex] = population[popIndex];
                                                                                                                                 temporalParentsIndex++;
                                                                                     }
                                                                                }
                                                                                else
                                                                                    if(population[popIndex]>=(MAXVAR*33.33/100)*2){//printf("varvalue2");
                                                                                                                                  temporalPopulation[temporalParentsIndex] = population[popIndex];
                                                                                                                                  temporalParentsIndex++;
                                                                                    }
                                                                                }
                                                else if(population[popIndex]<MAXMAGIC){
                                                                                       if(magicValue == 0){
                                                                                            if(population[popIndex]<(MAXMAGIC*33.33/100)){
                                                                                                                                       temporalPopulation[temporalParentsIndex] = population[popIndex];
                                                                                                                                       temporalParentsIndex++;
                                                                                            }
                                                                                            }
                                                                                       else if(magicValue == 1){
                                                                                            if(population[popIndex]>=(MAXMAGIC*33.33/100) && population[popIndex] < (MAXMAGIC*33.33/100)*2){
                                                                                                                                          temporalPopulation[temporalParentsIndex] = population[popIndex];
                                                                                                                                          temporalParentsIndex++;
                                                                                                                                          }
                                                                                            }
                                                                                       else
                                                                                           if(population[popIndex]>=(MAXMAGIC*33.33/100)*2){
                                                                                                                                           temporalPopulation[temporalParentsIndex] = population[popIndex];
                                                                                                                                           temporalParentsIndex++;
                                                                                           }
                                                                                       }
                                                else if(population[popIndex]<MAXEXCEP){
                                                                                       if(exceptionValue == 0){
                                                                                            if(population[popIndex]<(MAXEXCEP*33.33/100)){
                                                                                                                                       temporalPopulation[temporalParentsIndex] = population[popIndex];
                                                                                                                                       temporalParentsIndex++;
                                                                                            }
                                                                                       }
                                                                                       else if(exceptionValue == 1){
                                                                                            if(population[popIndex]>=(MAXEXCEP*33.33/100) && population[popIndex] < (MAXEXCEP*33.33/100)*2){
                                                                                                                                          temporalPopulation[temporalParentsIndex] = population[popIndex];
                                                                                                                                          temporalParentsIndex++;
                                                                                            }
                                                                                       }
                                                                                       else
                                                                                           if(population[popIndex]>=(MAXEXCEP*33.33/100)*2){
                                                                                                                                           temporalPopulation[temporalParentsIndex] = population[popIndex];
                                                                                                                                           temporalParentsIndex++;
                                                                                           }                                                                                     
                                                                                       }
                                                else{
                                                     if(exceptionValue == 0){
                                                                       if(population[popIndex]<(MAXEXCEP*33.33/100)){
                                                                                                                    temporalPopulation[temporalParentsIndex] = population[popIndex];
                                                                                                                    temporalParentsIndex++;
                                                                       }
                                                     }
                                                     else if(exceptionValue == 1){
                                                                            if(population[popIndex]>=(MAXEXCEP*33.33/100) && population[popIndex] < (MAXEXCEP*33.33/100)*2){
                                                                                                                          temporalPopulation[temporalParentsIndex] = population[popIndex];
                                                                                                                          temporalParentsIndex++;
                                                                            }
                                                     }
                                                     else
                                                         if(population[popIndex]>=(MAXEXCEP*33.33/100)*2){
                                                                                                         temporalPopulation[temporalParentsIndex] = population[popIndex];
                                                                                                         temporalParentsIndex++;
                                                         }
                                                     }
                                                //printf("genotipo: %d %d \n", temporalPopulation[temporalParentsIndex-1], temporalParentsIndex-1);
                                                }
                                                //popCounter = temporalParentsIndex;
                                                printf("generacion %d \n", generation);
                                                
                                                //****//
                                                int counter;
                                                for(counter = 0; counter<temporalParentsIndex; counter++){
                                                            if(counter+1 == temporalParentsIndex && counter%2 != 0){
                                                                       printf("asd");
                                                                       }
                                                            else{
                                                                 int binaryA[16];
                                                                 int binaryB[16];
                                                                 int finalBinary[16];
                                                                 intToBinary(temporalPopulation[counter], binaryA);
                                                                 intToBinary(temporalPopulation[counter+1], binaryB);
                                                                 
                                                                 int crossPoint = rand()%16;//printf("crosspoint: %d\n",crossPoint);
                                                                 int binaryPosition;
                                                                 for(binaryPosition = 0; binaryPosition <= crossPoint; binaryPosition++){
                                                                                    finalBinary[binaryPosition] = binaryA[binaryPosition];
                                                                                    }
                                                                 for(binaryPosition; binaryPosition < 16; binaryPosition++){
                                                                                    finalBinary[binaryPosition] = binaryB[binaryPosition];
                                                                                    }
                                                                 int resultNumber = binaryToInt(finalBinary);
                                                                 population[popCounter] = resultNumber;
                                                                 printf("RESULT: %d \n", resultNumber);
                                                                 popCounter++;
                                                                                    
                                                                 //printf("%d%d%d%d",binaryA[0],binaryA[1],binaryA[2],binaryA[3]);
                                                                 }
                                                            }
                                   
                                   }
                    int populationFinalCounter;
                    int varFinalCounter;
                    int magicFinalCounter;
                    int exceptionFinalCounter;
                    int repetitionsFinalCounter;               
                    for(populationFinalCounter = 0; populationFinalCounter<popCounter; populationFinalCounter++){
                                               if(population[populationFinalCounter] < MAXVAR)
                                                                                     varFinalCounter++;
                                               else if(population[populationFinalCounter] < MAXMAGIC)
                                                                                          magicFinalCounter++;
                                               else if(population[populationFinalCounter] < MAXEXCEP)
                                                                                          exceptionFinalCounter++;
                                               else
                                                   repetitionsFinalCounter++;
                                                                                     
                                               }
                    printf("********** La cantidad de varibles poco significativas total es: %d\n", varFinalCounter);
                    printf("********** La cantidad de magic numbers total es: %d\n", magicFinalCounter);
                    printf("********** La cantidad de excepciones no capturadas total es: %d\n", exceptionFinalCounter);
                    printf("********** La cantidad de repeticiones total es: %d\n", repetitionsFinalCounter);
                                   

                    
}

