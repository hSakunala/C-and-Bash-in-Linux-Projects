#include <stdio.h>
#include <stdlib.h>

void radixsort(int array[], int size, int numBits)
{
    int arr0[size];
    int arr1[size];
    for(int d=0;d<numBits;d++){
        int a0=0;
        int a1=0;
        for(int i=0;i<size; i++){
            int temp= array[i]>>d;
            if (temp&1){
                arr1[a1]=array[i];
                a1++;
            }
            else{
                arr0[a0]=array[i];
                a0++;
            }
        }
        for(int x=0;x<a0;x++){
                array[x]=arr0[x];
        }

        for(int y=a0;y<size;y++){
                array[y]=arr1[y-a0];
        }
    }

    for(int z=0; z<size; z++){
        printf("%d\t", array[z]);
    }
    printf("\n");
}

int main()
{
    int len;
    printf("Enter a lenght of array: ");
    scanf("%d", &len);
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        printf("Index - %d : ",i);
        scanf("%d", &arr[i]);
    }
    
    radixsort(arr, len, 32);
}