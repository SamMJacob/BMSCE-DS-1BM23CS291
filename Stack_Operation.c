#include <stdio.h>

int main() {
    int max;
    printf("enter the max size of stack");
    scanf("%d",&max);
    int stack[max];
    int top=-1;
    int value;
    int opt=0;
    
    while(opt!=6)
    {
      printf("enter 1 to PUSH, 2 to POP, 3 to SEEK, 4 to check IfEmpty and 5 to check IfFull and 6 to exit");
      scanf("%d",&opt);
      
      if (opt==1)
      {
          if (top==max-1)
          {
              printf("stack overflow\n");
          }
          else 
          {
              printf("enter value to be pushed");
              scanf("%d",&value);
              top=top+1;
              stack[top]=value;
          }
      }
      else if (opt==2)
      {   
          if (top==-1)
          {
              printf("stack underflow\n");
          }
          else 
          {
              value= stack[top];
              top=top-1;
              printf("%d was popped\n",value);
          }
          
      }
      
      else if(opt==3)
      {   
          if(top==-1)
          {
              printf("stack is empty\n");
          }
          else
          {
              value = stack[top];
              printf("top- most element is %d \n",value);
          }
      }
      else if (opt==4)
      {
          if(top==-1)
          {
              printf("stack is empty\n");
          }
          else
          {
              printf("stack is not empty\n");
          }
      }
      else if (opt==5)
      {
           if (top==max-1)
          {
              printf("stack is full\n");
          }
          else 
          printf("stack is not full\n");
      }
    }
}
