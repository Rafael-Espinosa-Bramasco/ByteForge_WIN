/*
    Byte Forge (Windows Edition)
*/

// C libraries
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

// My libraries
#include "libs/byteforge.h"
#include "libs/bfinfo.h"

/*
    Available error numbers:
        0
*/

int main(int argc, char *argv[]){
    if(argc == 1){
        // byteforge called alone
        getAppInfo();
        return 0;
    }

    char *outputFileName = NULL; // First file name in arguments
    long long int bytesNumber = -1;
    char fillerOption = 'r';

    bool patternOption = false;
    int patternVal1 = 0; // Number of bits to contemplate
    int patternVal2 = 0; // Number of combinations

    char *arg = NULL;
    for(int i = 1; i < argc; i++){
        arg = argv[i];
        // Check if is number
        if(isNumber(arg)){
            if(bytesNumber != -1){
                printf("Byte Number Error: Number of bytes to generate already defined\n");
                return 1;
            }
            bytesNumber = getIntNumber(arg);
            if(bytesNumber < 1){
                printf("Byte Number Error: Number of bytes cant be 0 or less\n");
                return 1;
            }
            continue;
        }
        // Check if is file name
        if(isFile(arg)){
            if(outputFileName != NULL){
                printf("Output File Error: Just one file name for output is valid\n");
                return 1;
            }
            outputFileName = arg;
            continue;
        }
        // Check flags
        if(isOption(arg)){
            // Filler options
            if(strcmp("-0",arg) == 0){
                fillerOption = '0';
                continue;
            }else if (strcmp("-1",arg) == 0){
                fillerOption = '1';
                continue;
            }else if (strcmp("-r",arg) == 0){
                fillerOption = 'r';
                continue;
            }

            printf("Option Error: Option %s doesn't exist\n",arg);
            return 5;
        }
    }

    // Check values
    if(bytesNumber == -1){
        printf("Byte Number Error: Number of bytes are NULL\n");
        return 1;
    }

    FILE *outFile = NULL;
    if(outputFileName == NULL){
        outFile = fopen("bytes.bin","wb");
    }else{
        outFile = fopen(outputFileName,"wb");
    }

    char number = 0;
    if(fillerOption == 'r'){
        for(long long int i = 0; i < bytesNumber; i++){
            number = rand() % 256;
            fwrite(&number,1,1,outFile);
        }
    }else{
        number = (fillerOption == '0' ? 0 : 255);
        for(long long int i = 0; i < bytesNumber; i++){
            fwrite(&number,1,1,outFile);
        }
    }

    fclose(outFile);
    return 0;
}