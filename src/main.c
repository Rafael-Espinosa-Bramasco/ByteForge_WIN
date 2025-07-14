/*
    Byte Forge (Windows Edition)
*/

// C libraries
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

    char *arg = NULL;
    for(int i = 1; i < argc; i++){
        arg = argv[i];
        // Check if is number
        if(isNumber(arg)){
            if(bytesNumber != -1){
                // Error 2: Number of bytes to generate already defined
                printf("Error 2: Number of bytes to generate already defined\n");
                return 2;
            }
            bytesNumber = getIntNumber(arg);
            if(bytesNumber < 1){
                // Error 3: Number of bytes cant be 0 or less
                printf("Error 3: Number of bytes cant be 0 or less\n");
                return 3;
            }
            continue;
        }
        // Check if is file name
        if(isFile(arg)){
            if(outputFileName != NULL){
                // Error 1: Just one file name for output is valid
                printf("Error 1: Just one file name for output is valid\n");
                return 1;
            }
            outputFileName = arg;
            continue;
        }
        // Check flags
    }

    // Check values
    if(bytesNumber == -1){
        // Error 4: Number of bytes are NULL
        printf("Error 4: Number of bytes are NULL\n");
        return 4;
    }

    FILE *outFile = NULL;
    if(outputFileName == NULL){
        outFile = fopen("bytes.bin","wb");
    }else{
        outFile = fopen(outputFileName,"wb");
    }
    char number = 0;
    for(long long int i = 0; i < bytesNumber; i++){
        number = rand() % 256;
        fwrite(&number,1,1,outFile);
    }
    fclose(outFile);
    return 0;
}