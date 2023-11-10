#include<stdio.h>
#include<stdlib.h>

void createLinkedList();
void displayLinkedList();
int getLength();

void insertBeg();
void insertEnd();
void insertPos();

void deleteBeg();
void deleteEnd();
void deletePos();

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;


void main(){

    createLinkedList();
    insertBeg();
    insertEnd();
    insertPos();
    displayLinkedList();

    deleteBeg();
    deleteEnd();
    deletePos();

    displayLinkedList();

}


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
            head->next=NULL;
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

    printf("\nNode Inserted!\n");
    
}

void insertPos(){

    int pos;
    printf("\nEnter position after which node is to be inserted: ");
    scanf("%d", &pos);

    //check if the given position is valid
    if(pos>getLength()){
        printf("Invalid Position!");
    }else{
        struct node *new, *temp;

        //Creating node
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &new->data);

        //Traverse to the postion after which the new node is to be inserted
        temp=head;
        int i=1;
        while(i<pos){
            temp=temp->next;
            i++;
        }

        new->next = temp->next; //setting the pointer of the new node to the node which will be after it
        temp->next = new; // pointing the node to the new node

        printf("Node inserted! ");
    }
}

void deleteBeg(){
    struct node *temp;

    temp=head;
    head=head->next;
    free(temp);
}

void deleteEnd(){
    struct node *temp, *prev;

    temp=head;
    while(temp->next != NULL){
        prev=temp;  //store temp pointer in prev pointer
        temp=temp->next; //update temp which is point to next node
    }

    if(temp==head){
        head=NULL;
    }else{
        prev->next=NULL;
    }
    
    free(temp);
}

void deletePos(){
    struct node *temp, *prev;

    int pos;
    printf("\n\nEnter position of node to delete: ");
    scanf("%d",&pos);

    temp=head;

    if(pos>getLength()){
        printf("Invalid Position!");
    }else if(pos==1){
        deleteBeg();
    }else{
        int i=1;
        while(i<pos){
            prev=temp;
            temp=temp->next;

            i++;
        }

        prev->next=temp->next;
        free(temp);
    }
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
