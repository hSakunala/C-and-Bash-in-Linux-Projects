#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start, *end = NULL;

void insertNode(int number)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = number;
    newNode->next = NULL;

    if (start == NULL)
    {
        start = newNode;
        end = newNode;
    }
    else
    {
        end->next = newNode;
        end = newNode;
    }
}

void bubbleSort(struct node *begin) 
{ 
    typedef enum{false,true} bool;
    bool flag = true;
    struct node *p1; 
    struct node *leftp = NULL; 
    
    while (flag){ 
        flag = false; 
        p1 = begin; 
  
        while (p1->next != leftp) { 
            if (p1->data > p1->next->data) 
            { 
                swap(p1, p1->next); 
                flag = true;
            }
            p1 = p1->next; 
        } 
        leftp = p1; 
    }  
} 
  
void swap(struct node *num1, struct node *num2) 
{ 
    int t = num1->data; 
    num1->data = num2->data; 
    num2->data = t; 
} 

int main()
{
    typedef enum{false,true} bool;
    int num;
    bool flag = true;
    printf("Enter numbers for a Sorted List using Bubble Sort(CTRL+D TO STOP)\n");
    int x;
    x=1;
    printf("Input data for node %d: ", x);
    while (flag)
    {
        x++;
        if (scanf("%d", &num) == EOF)
        {
            flag = false;
        }
        else
        {
            printf("Input data for node %d: ", x);
            insertNode(num);
        }
    }
    if (start == NULL){
        printf("\nLinked List is empty\n");
    }
    else{
        printf("\n\nOrdered List with Bubble Sort: \n");
        bubbleSort(start);
        struct node *marked = start;
        while (marked != NULL)
        {
            printf("%d \n", marked->data);
            marked = marked->next;
        }
    }
}