#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    FILE *inputFile, *outputFile;
    char line[256];

    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    outputFile = fopen("hw.bin", "wb+");
    if (outputFile == NULL) {
        printf("Error creating file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile)) {
        if (strstr(line, "je    halt") != NULL) {
            unsigned char opcode[] = {0x74, 0xFE};
            fwrite(opcode, sizeof(opcode), 1, outputFile);
        } else if (strstr(line, "hlt") != NULL) {
            unsigned char opcode[] = {0xF4}; 
            fwrite(opcode, sizeof(opcode), 1, outputFile);
        } else if (strstr(line, "jmp   halt") != NULL) {
            unsigned char opcode[] = {0xEB, 0xFC}; 
            fwrite(opcode, sizeof(opcode), 1, outputFile);
        } else if (strstr(line, "movb") != NULL) {
            if (strstr(line, "al") != NULL) {
                unsigned char opcode[] = {0xB0};
                fwrite(opcode, sizeof(opcode), 1, outputFile);
            } else if (strstr(line, "ah") != NULL) {
                unsigned char opcode[] = {0xB4};
                fwrite(opcode, sizeof(opcode), 1, outputFile);
            }

            char* immediate = strchr(line, '$');
            if (immediate != NULL) {
                unsigned char value = (unsigned char)strtol(immediate + 1, NULL, 16);
                fwrite(&value, sizeof(value), 1, outputFile);
            }
            
        } else if (strstr(line, "int     $0x10") != NULL) {
            unsigned char opcode[] = {0xCD, 0x10}; 
            fwrite(opcode, sizeof(opcode), 1, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}