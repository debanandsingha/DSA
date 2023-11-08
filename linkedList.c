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
    printf("New node? [1]Yes & [0]No: ");
    scanf("%d", &choice);
    }
}

void displayLinkedList(){
    struct node *temp;
    
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void main(){

    createLinkedList();

    printf("Linked list: ");
    displayLinkedList();

}