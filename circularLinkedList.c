#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;

void create();
void display();

void insertBEG();

void main(){

    create();
    display();
    insertBEG();
    display();

}

void create(){
    struct node *new, *temp;
    
    int choice;
    while(choice!=0){
        new=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&new->data);
        new->next=NULL;

        if(head==NULL){
            head=new;
            temp=head;
        }else{
            temp->next=new;
            temp=temp->next;
            temp->next=head;
        }

        printf("Create Node Again? Yes[1]/No[0]: ");
        scanf("%d",&choice);
    }
    // printf("%d",temp->next->data);   //verification of CLL
}

void display(){
    struct node *temp=head;

    printf("Circular Linked List: ");
    while(temp->next != head){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);    //accessing the data of last node
    printf("\n\n");
}

void insertBEG(){
    struct node *new, *temp=head;

    printf("\nEnter node at beg\n");

    if(head==NULL){
        create();
    }else{
        new=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&new->data);
        
        while(temp->next != head)
            temp=temp->next;
    
        new->next=head;
        head=new;
        temp->next=new;

        printf("Node inserted at Beginning!\n");
    }
}