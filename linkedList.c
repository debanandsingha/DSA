#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;

void createLinkedList(){
    struct node *new, *temp;

    int choice;
    while(choice){

        printf("***Creating new node***\n");

        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &new->data);

        if(head==NULL){
            head=temp=new;
        }else{
            temp->next=new;
            temp=new;
            new->next=NULL;
        }
        printf("\nNew node? [1]Yes & [0]No: ");
        scanf("%d", &choice);
    }
}

void displayLinkedList(){
    struct node *temp;
    
    printf("\n\nLinked List: ");

    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void insertBeg(){
    struct node *new;

    printf("\nInerst node at beginning\n");

    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&new->data);

    //Updating pointers
    new->next=head;
    head=new;

    printf("\nNode inserted!");
}

void insertEnd(){
    struct node *new, *temp;

    printf("\n\nInsert node at END\n");

    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &new->data);

    temp=head;
    while (temp->next != NULL)
    {
        temp=temp->next;
    }

    temp->next=new;
    
    new->next=NULL; // setting the value of last node to NULL, undefined by default

    printf("\nNode Inserted!");
    
}

void insertPos(){

}

int getLength(){
    struct node *temp;
    temp=head;

    int length=0;
    while(temp != NULL){
        length++;
        temp=temp->next;    //updating temp
    }

    return length;
}

void main(){

    createLinkedList();     //creating linked list

    insertBeg();    //inserting node in the beginning

    insertEnd();    //inserting node at the end

    displayLinkedList();    //displaying the linked list

}