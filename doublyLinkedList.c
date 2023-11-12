#include<stdio.h>
#include<stdlib.h>

void createList();
void displayList();
void createListWithTail();

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head, *tail;

head=NULL;
tail=NULL;

void main(){

    createList();
    displayList();    

}

void createList(){
//Creating linked list without maintaining tail pointer
    struct node *new,*temp;
    
    int choice;
    while(choice){
        new=(struct node*)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d",&new->data);

        //Initializating prev and next pointers of the new node
        new->next=new->prev=NULL;

        if(head==NULL){
            head=temp=new;
        }else{
            temp->next=new;
            new->prev=temp;
            temp=new;   //moving temp
        }

        printf("\nNew node? Yes[1] / No[0] : ");
        scanf("%d",&choice);
    }
}

void displayList(){
    struct node *temp;

    printf("\nLinked List: ");
    temp=head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
}

void createListWithTail(){
    
}