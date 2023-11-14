#include<stdio.h>

#define N 5         //Macro definition
int stack[N];       //STACK using ARRAY for <<Static Memory Allocation>>
int top = -1;       //initially top = -1

void push();
void pop();
void display();

void main(){

    int x;
    while(x){
        printf("\nStack menu |1|\t\tExit |0|\n");
        printf("Enter option: ");
        scanf("%d", &x);
        
        if(x==1){
            int choice;
            printf("\nPush |1|\tPop |2|\t\tDisplay |3|\n");
            printf("Enter option: ");
            scanf("%d",&choice);

            switch (choice)
            {
            case 1:
                push();
                break;
            
            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            default:
                printf("\nInvalid Option!!\n");
                break;
            }
        }
    }

}

void push(){
    int x;  //stores the data to be pushed into stack

    //  Check OVERFLOW
    if(top==N-1){
        printf("OVERFLOW!!!\n");
    }else{
        printf("\nEnter data: ");
        scanf("%d", &x);

        top++;
        stack[top]=x;   //pushing data into stack

        printf("Data pushed...\n");
    }
}

void pop(){
    //  Check UNDERFLOW
    if(top==-1){
        printf("UNDERFLOW!!\n");
    }else{
        int item=stack[top];    //storing the value to display it
        
        top--;

        printf("\nPoping %d ...\n", item);
    }
}

void display(){
    printf("\nStack: ");
    for(int i=top; i>=0; i--){
        printf("%d ",stack[i]);
    }
    printf("\n");
}