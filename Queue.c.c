#include <stdio.h>

void main()
{
    int max;
    printf("enter maximum size of queue:");
    scanf("%d",&max);
    int queue[max];
    int front=-1;
    int back=-1;
    while(2>0)
    {
        printf("Enter 1 for enqueue, 2 for dequeue, 3 for display : ");
        int c;
        scanf("%d",&c);
        if(c==1)
        {
            if(back==(max-1))
            {
                printf("Queue is full\n");
            }
            else
            {
                printf("Enter element:");
                int v;
                scanf("%d",&v);
                if ((front==-1)&&(back==-1))
                {
                    front++;
                    queue[++back]=v;
                }
                else
                    queue[++back]=v;
            }
        }
        else if(c==2)
        {
            if ((front==-1)&&(back==-1))
            {
                printf("queue is empty\n");
            }
            else{
                front++;
                if((front==(max-1))&&(back==(max-1)))
                {
                    front=-1;
                    back=-1;
                }
            }
        }
        else if(c==3)
        {
            if ((front==-1)&&(back==-1))
            {
                printf("queue is empty\n");
            }
            else
            {
                for(int i=front; i<=back;i++)
                {
                    printf("%d ",queue[i]);
                }
                printf("\n");
            }
        }
        else
            break;
    }
}