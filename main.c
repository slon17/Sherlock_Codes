#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*#include "variables.h"
#include "exceptions.h"
#include "repeated.h"
#include "magicNumbers.h"*/
#include "sherlock.h"

#define MAXCHAR 13000
int main(int argc, char *argv[])
{
       char * files[] = {"tombola.java", "end"};
       //fileCounter(files);
       /*variableCounter("tombola.java");
       magicNumbersCounter("tombola.java");
       exceptionsCounter("tombola.java");
       repetitionsCounter(files);*/
       
       int clues[4];
       sherlockData(files, clues);
       sherlockGenetic(clues);
       system("PAUSE");
    
}
