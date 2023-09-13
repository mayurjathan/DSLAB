//Only sparse matrix is implemented

#include<stdio.h>

int main()
{
    int ROW,COL;
    printf("Enter no of rows : ");
    scanf("%d",&ROW);
    printf("Enter no of coloumn : ");
    scanf("%d",&COL);
    int sparse[ROW][COL];
    printf("Enter numbers : ");
    for(int i=0; i<ROW; i++)
    {

        for(int j=0; j<COL; j++)
        {
            scanf("%d",&sparse[i][j]);
        }
    }
    printf("ROW COL VAR\n");
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            if(sparse[i][j] != 0)
            {
                printf(" %d    %d   %d \n",i,j,sparse[i][j]);
            }
        }

    }

    return 0;
}

