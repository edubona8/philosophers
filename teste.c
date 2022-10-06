# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <errno.h>

struct node
{
    int data;
    struct node *nextPtr;
};

struct node *firstNode;

void createCircularLinkedList(int numberOfNodes);

void displayCircularLinkedList();

int main()
{
    int numberOfNodes;

    firstNode = NULL;

    printf ("Input the number of nodes : ");
    scanf("%d", &numberOfNodes);

    createCircularLinkedList(numberOfNodes);
    displayCircularLinkedList();
    
    return 0;
}

void createCircularLinkedList(int numberOfNodes)
{
    int nodeCtr;
    int nodeData;
    struct node *previousPtr;
    struct node *newNode;

    if (numberOfNodes >= 1)
    {
        firstNode = (struct node *)malloc(sizeof(struct node));

        printf("Input data for node 1 : ");
        scanf ("%d", &nodeData);

        firstNode->data = nodeData;
        firstNode->nextPtr = NULL;

        previousPtr = firstNode;

        for (nodeCtr = 2; nodeCtr <= numberOfNodes; nodeCtr++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("input data for node %d : ", nodeCtr);
            scanf("%d", &nodeData);

            //Initialize new node
            newNode->data = nodeData;
            newNode->nextPtr = NULL;

            //Link the new node to the circular linked list
            previousPtr->nextPtr = newNode;
            previousPtr = newNode;

            //Update the previus node
            previousPtr->nextPtr = firstNode;
        } 
    }
}

 void displayCircularLinkedList()
    {
        struct node *currentNode;
        int nodeCtr = 1;

        if (firstNode == NULL)
        {
            printf("No data found in the list yet.");
        }
        else
        {
            currentNode = firstNode;

            printf("\n\n Data entered in the list are : \n");

            do
            {
                printf("Data %d = %d\n", nodeCtr, currentNode->data);

                currentNode = currentNode->nextPtr;
                nodeCtr++;
            }while(currentNode != firstNode);
        }
        
    }