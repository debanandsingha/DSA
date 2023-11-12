#include<stdio.h>
#include<stdlib.h>

void createList();
void displayList();
void createListWithTail();  //maintaining a tail pointer

void insertBeg();
void insertEnd();
void insertatPOS();

int length();

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL, *tail=NULL;

void main(){

    // createList();
    createListWithTail();   //linked list with maintained Tail pointer

    insertBeg();
    insertEnd();
    displayList();
    insertatPOS();
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
    struct node *new;   // no need of temp pointer coz tail will be there

    int choice;
    while(choice){
        new=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&new->data);

        new->prev=new->next=NULL;   //node → |x|data|x|

        //Adding new node to the linked list
        if(head==NULL){
            head=tail=new;  // |head| → |x|data|x| ← |tail|
        }else{
            tail->next=new; // |prev|data|next| ← |tail| => tail=prevNode
            new->prev=tail; // |tail|newNode|x|
            tail=new;   //setting tail to point to new node
        }

        printf("New node? Yes[1]/No[0]: ");
        scanf("%d",&choice);
    }
}

void insertBeg(){
    struct node *new;

    new=(struct node*)malloc(sizeof(struct node));
    printf("Insert BEGG\nEnter data: (new node): ");
    scanf("%d",&new->data);

    new->prev=new->next=NULL;

    if(head==NULL){
        head=new;
    }else{
        new->next=head;
        head->prev=new;

        head=new;
    }
}

void insertEnd(){
    struct node *new;

    new=(struct node*)malloc(sizeof(struct node));
    printf("Insert END\nEnter data: (new node): ");
    scanf("%d",&new->data);

    new->prev=new->next=NULL;

    if(head==NULL){
        insertBeg();
    }else{
        tail->next=new;
        new->prev=tail;
        tail=new;
    }
}

int length(){
    struct node *temp=head;
    int count=0;

    while(temp!=NULL){
        temp=temp->next;
        count++;
    }

    return count;
}
void insertatPOS(){
    struct node *new;

    int pos;
    printf("Enter position: ");
    scanf("%d",&pos);

    if(pos<1 || pos>length()){        
        printf("Invalid Position!");
    }else{

        printf("Insert at %d\n", pos);
        new=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&new->data);
        
        if(head==NULL&&pos==1){
            
            insertBeg();

        }else if(head!=NULL&&pos==1){

            new->next=head;
            head->prev=new;
            head=new;

        }else{
            
            struct node *temp;
            temp=head;

            int i=1;
            while(i<pos-1){
                temp=temp->next;
                i++;
            }

            new->prev=temp;
            new->next=temp->next;
            temp->next=new;
            new->next->prev=new;
        }

    }
}


