#include <stdio.h>

int main() {     
    FILE *filePtr1, *filePtr2;
    int indInp, i = 0, numInFile, binOfNum;  

    filePtr1 = fopen("numbers.txt", "r");         
    filePtr2 = fopen("numbers.bin", "rb");    
    
    printf("Input index: ");      
    scanf("%d", &indInp);     
    
    while ((i < indInp) && (fscanf(filePtr1, "%d", &numInFile) != EOF) && (fread(&binOfNum, sizeof(binOfNum), 1, filePtr2) != EOF))          
        i++;     

    fclose(filePtr1);     
    fclose(filePtr2);     
    printf("Integer saved in text file: %d\n", numInFile);     
    printf("Integer saved in binary file: %d\n", binOfNum); 
    return 0; 
}