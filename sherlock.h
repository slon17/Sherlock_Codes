/*#include "variables.h"
#include "exceptions.h"
#include "repeated.h"
#include "magicNumbers.h"*/

#define MAXVAR 14416
#define MAXMAGIC 26212
#define MAXEXCEP 42596
#define MAXREPET 65535

sherlockData(char * files[]){
                  //variableCounter(files);
                  //magicNumbersCounter(files);
                  //exceptionsCounter(files);
                  repetitionsCounter(files);
}

sherlockGenetic(int clues[]){
                    time_t t;
                    srand((unsigned) time(&t));
                    
                    int population[5000];
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
                                   int temporalParentsIndex = 0;
                                   int popIndex;
                                   printf("varValue: %d, magicValue: %d, repeatitionValue: %d \n", varValue, magicValue, repetitionValue);
                                   for(popIndex = 0; popIndex<popCounter; popIndex++){
                                                if(population[popIndex]<MAXVAR){
                                                                                if(varValue == 0){
                                                                                            if(population[popIndex]<(MAXVAR*33.33/100)){
                                                                                                                                        //printf("varvalue0"); 
                                                                                                                                       population[temporalParentsIndex] = population[popIndex];
                                                                                                                                       temporalParentsIndex++;
                                                                                            }
                                                                                }
                                                                                else if(varValue == 1){
                                                                                     if(population[popIndex]>=(MAXVAR*33.33/100) && population[popIndex] < (MAXVAR*33.33/100)*2){//printf("varvalue1");
                                                                                                                                 population[temporalParentsIndex] = population[popIndex];
                                                                                                                                 temporalParentsIndex++;
                                                                                     }
                                                                                }
                                                                                else
                                                                                    if(population[popIndex]>=(MAXVAR*33.33/100)*2){//printf("varvalue2");
                                                                                                                                  population[temporalParentsIndex] = population[popIndex];
                                                                                                                                  temporalParentsIndex++;
                                                                                    }
                                                                                }
                                                else if(population[popIndex]<MAXMAGIC){
                                                                                       if(magicValue == 0){
                                                                                            if(population[popIndex]<(MAXMAGIC*33.33/100)){
                                                                                                                                       population[temporalParentsIndex] = population[popIndex];
                                                                                                                                       temporalParentsIndex++;
                                                                                            }
                                                                                            }
                                                                                       else if(magicValue == 1){
                                                                                            if(population[popIndex]>=(MAXMAGIC*33.33/100) && population[popIndex] < (MAXMAGIC*33.33/100)*2){
                                                                                                                                          population[temporalParentsIndex] = population[popIndex];
                                                                                                                                          temporalParentsIndex++;
                                                                                                                                          }
                                                                                            }
                                                                                       else
                                                                                           if(population[popIndex]>=(MAXMAGIC*33.33/100)*2){
                                                                                                                                           population[temporalParentsIndex] = population[popIndex];
                                                                                                                                           temporalParentsIndex++;
                                                                                           }
                                                                                       }
                                                else if(population[popIndex]<MAXEXCEP){
                                                                                       if(exceptionValue == 0){
                                                                                            if(population[popIndex]<(MAXEXCEP*33.33/100)){
                                                                                                                                       population[temporalParentsIndex] = population[popIndex];
                                                                                                                                       temporalParentsIndex++;
                                                                                            }
                                                                                       }
                                                                                       else if(exceptionValue == 1){
                                                                                            if(population[popIndex]>=(MAXEXCEP*33.33/100) && population[popIndex] < (MAXEXCEP*33.33/100)*2){
                                                                                                                                          population[temporalParentsIndex] = population[popIndex];
                                                                                                                                          temporalParentsIndex++;
                                                                                            }
                                                                                       }
                                                                                       else
                                                                                           if(population[popIndex]>=(MAXEXCEP*33.33/100)*2){
                                                                                                                                           population[temporalParentsIndex] = population[popIndex];
                                                                                                                                           temporalParentsIndex++;
                                                                                           }                                                                                     
                                                                                       }
                                                else{
                                                     if(exceptionValue == 0){
                                                                       if(population[popIndex]<(MAXEXCEP*33.33/100)){
                                                                                                                    population[temporalParentsIndex] = population[popIndex];
                                                                                                                    temporalParentsIndex++;
                                                                       }
                                                     }
                                                     else if(exceptionValue == 1){
                                                                            if(population[popIndex]>=(MAXEXCEP*33.33/100) && population[popIndex] < (MAXEXCEP*33.33/100)*2){
                                                                                                                          population[temporalParentsIndex] = population[popIndex];
                                                                                                                          temporalParentsIndex++;
                                                                            }
                                                     }
                                                     else
                                                         if(population[popIndex]>=(MAXEXCEP*33.33/100)*2){
                                                                                                         population[temporalParentsIndex] = population[popIndex];
                                                                                                         temporalParentsIndex++;
                                                         }
                                                     }
                                                printf("genotipo: %d %d \n", population[popIndex], popIndex);
                                                }
                                                popCounter = temporalParentsIndex;
                                                //printf("generacion %d \n", generation);
                                                
                                                //****//
                                                
                                   
                                   }
                                   

                    
}
