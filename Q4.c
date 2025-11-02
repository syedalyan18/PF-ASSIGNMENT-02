#include<stdio.h>
void push(int stack[], int *top, int maxSize){
if(*top==maxSize-1){
 printf("Stack overflow!\n");
return;
}
printf("Enter the value: ");
(*top)++;
scanf("%d",&stack[*top]);

return;
}
void pop(int stack[], int *top){
if(*top==-1){
    printf("Stack underflow!\n");
    return;
}
  printf("Poped element =%d\n",stack[*top]);
  (*top)--;
  if(*top==-1){
    printf("Stack is empty now!\n");
  }
  printf("Top element is removed now!\n");
  return;
}

void peek(int stack[], int *top){
    if(*top==-1){
        printf("Stack is empty!\n");
        return;
    }
printf("Top element is %d\n",stack[*top]);
}
void display(int stack[], int *top){
    int i=0;
    printf("--------------whole stack--------------\n");
    for(i=(*top);i>=0;i--){
        printf("|     %d     |\n",stack[i]);
    }
    printf("______________\n");
    return;

}
int main(){
    
    int stack[4];
   int top=-1;
   int maxSize=4;
   int choice=-1;
  while(choice!=0){
   printf("Enter your choice:\n1)Push\n2)Pop\n3)Peek\n4)Display\n5)Exit\n");
   scanf("%d",&choice);
        switch(choice){
            case 1:
            push(stack,&top,maxSize);
             break;
             case 2:
             pop(stack,&top);
             break;
             case 3:
             peek(stack,&top);
             break;
             case 4:
             display(stack,&top);
             break;
             case 5:
             printf("exiting.................");
             return;
             break;
             default:
             printf("invalid!");
             break;
}
}
}