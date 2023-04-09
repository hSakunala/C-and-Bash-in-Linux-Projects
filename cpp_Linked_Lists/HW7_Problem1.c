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
void reverse(struct node *marker)
{
    if (marker->next == NULL)
    {
        printf("Data = %d \n", marker->data);
        return;
    }

    reverse(marker->next);
    printf("Data = %d \n", marker->data);
}

int main()
{
    typedef enum
    {
        false,
        true
    } bool;
    int num;
    bool flag = true;
    printf("Enter numbers for a reverse list and ordered list(CTRL+D TO STOP)\n");
    int x;
    x = 1;
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
    if (start == NULL)
    {
        printf("\nLinked List is empty\n");
    }
    else
    {
        printf("\n");
        printf("\nData entered in the list are:\n");
        struct node *marked = start;
        while (marked != NULL)
        {
            printf("Data = %d \n", marked->data);
            marked = marked->next;
        }

        printf("\nThe list in reverse are:\n");
        reverse(start);
        printf("\n");
    }
}