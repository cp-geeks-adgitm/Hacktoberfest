//Program to insert a node at beginning in linked list 
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
  

void addFirst(struct node **head, int val)
{
      //create a new node
      struct node *newNode = malloc(sizeof(struct node));
      newNode->data = val;

      newNode->next = *head;

      *head = newNode;
}

void printList(struct node *head)
{
    struct node *temp = head;

    //iterate the entire linked list and print the data
    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}
//Driver code
int main()
{
     struct node *head = NULL;

     addFirst(&head,10);
     addFirst(&head,20);
     addFirst(&head,30);

     printList(head);

     return 0;
}
