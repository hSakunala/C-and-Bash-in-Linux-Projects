#include <stdio.h>
int main() {     
    FILE *filePtr1, *filePtr2;
    // filePtr1 = fopen("/home/HrishikeshSakunala/cs288/hw9/numbers.txt", "w");
    filePtr1 = fopen("numbers.txt", "w");
    // filePtr2 = fopen("/home/HrishikeshSakunala/cs288/hw9/numbers.bin", "wb");
    filePtr2 = fopen("numbers.bin", "wb");
    int indInp = 1, userInp;
    printf("Input data %d : ", indInp);
    while (scanf("%d", &userInp)==1){          
        int sizeInt= sizeof(userInp);
        fprintf(filePtr1, "%d ", userInp);  
        fwrite(&userInp, sizeInt, 1, filePtr2);          
        indInp++; 
        printf("Input data %d : ", indInp);     
    }
      
    fclose(filePtr1);      
    fclose(filePtr2);
    printf("\n");     
    return 0; 
}
