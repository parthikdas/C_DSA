#include <stdio.h>
#include<stdlib.h>

int mutex = 1;
int full = 0;
int empty;
int *item;
int i=0;
void producer()
{
    mutex--;
    empty--;
    full++;
    // for(int i=0;i<empty;i++){
      printf("Enter item : ");
      scanf("%d",&item[i]);
    printf("\nProduced item %d\n", item[i++]);
      // }
    mutex++;
}
void consumer()
{
    mutex--;
    empty++;
    full--;
  // for(int i=empty-1;i>=0;i--){
    printf("\nConsumed item %d\n", item[--i]);
    // }
    mutex++;
}
int main()
{
    int choice;
        printf("Enter the stack size : ");
        scanf("%d", &empty);
    item = (int*)malloc(empty*sizeof(int)); 
    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (mutex == 1 && empty != 0)
            {
                producer();
            }
            else if(mutex==0 && empty !=0)
            {
               printf("A process is already                         running");
            }
            else{
               printf("\nStack is Full\n");
            }
            break;
        case 2:
            if (mutex == 1 && full != 0)
            {
                consumer();
            }
              else if(mutex==0 && full !=0)
            {
               printf("A process is already                         running");
            }
            else
            {
                printf("\nStack is Empty, no item Produced\n");
            }
            break;
        case 3:
            return 0;
        default:
            printf("\nPlease enter valid input");
            break;
        }
    }

    return 0;
}