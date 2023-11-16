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
void insertEND();

void deleteBEG();
void deleteEND();

void search();

void main(){

    create();
    display();

    insertBEG();
    display();

    insertEND();
    display();

    deleteBEG();
    display();

    deleteEND();
    display();

    search();

}

void create(){
    struct node *new, *temp;
    
    printf("Creating Circular Linked List...\n");

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

    if(head==NULL){
        create();
    }else{

        printf("\nInsert node at Beginning...\n");
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

void insertEND(){

    if(head==NULL)
        create();
    else{
        struct node *new, *temp;
        temp=head;

        printf("Insert node at END...\n");

        new=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&new->data);

        while(temp->next!=head)
            temp=temp->next;

        temp->next=new;
        new->next=head;

        printf("Node inserted at END!\n");
    }
}

void deleteBEG(){
    if(head==NULL)
        printf("UNDERFLOW!\n");
    else if(head->next==head){
        free(head);
        head=NULL;
    }else{
        struct node *temp=head;
        
        while(temp->next!=head)
            temp=temp->next;

       temp->next=head->next;
       free(head);
       head=temp->next;
       
       printf("1st Node Deleted!\n");    
    }
}

void deleteEND(){
    if(head==NULL)
        printf("UNDERFLOW!\n");
    else if(head->next==head){
        free(head);
        head=NULL;
    }else{
        struct node *temp=head, *temp1;

        while(temp->next!=head){
            temp1=temp;
            temp=temp->next;
        }

        temp1->next=head;
        temp->next=NULL;
        free(temp);

        printf("Last node deleted!\n");
    }
}

void search(){
    if(head==NULL){
        printf("Empty List!\n");
    }else{
        struct node *temp=head;
        int item, node=1, count;

        printf("Enter item to search: ");
        scanf("%d",&item);

        while(temp->next!=head){
            if(temp->data==item){
                printf("Item found at node %d\n", node);
                count=0;    //  Set value of count = 0 everytime the item is found
                break;
            }else{
                count++;
            }

            node++;
            temp=temp->next;
        }

        if(temp->next==head && temp->data==item){
            printf("Item Found at Node %d", node);
            count=0;
        }
        if(count!=0){
            printf("Item Not Found!\n");
        }
    }
}