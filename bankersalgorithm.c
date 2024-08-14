#include<stdio.h>
int main()
{
    int np,nr;
    int i,j,k,l;
    int index=0;
    printf("Enter Number of Process: ");
    scanf("%d",&np);
    printf("Enter Number of Resources: ");
    scanf("%d",&nr);

    int max[np][nr];
    int allocation[np][nr];
    int need [np][nr];
    int available[nr];
    int safeseq[np];
    int pcompleted[np];

    printf("Enter the Allocation Matrix:\n");
    for(i=0; i<np; i++)
    {
        for(j=0; j<nr; j++)
        {
            scanf("%d",&allocation[i][j]);
        }
    }

     printf("Enter the Maximum Matrix:\n");
    for(i=0; i<np; i++)
    {
        for(j=0; j<nr; j++)
        {
            scanf("%d",&max[i][j]);
            need[i][j]=max[i][j]-allocation[i][j];
        }
        pcompleted[i]=0;
    }

    printf("Enter the available resources:\n");
    for(i=0; i<nr; i++)
    {
    scanf("%d",&available[i]);
    }

    for(i=0; i<np; i++)
    {
        for(j=0; j<nr; j++)
        {
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    }
    
    for(k=0; k<np; k++)
    {
        for(i=0; i<np; i++)
        {
            if(pcompleted[i]==0)
            {
                int flag=0;
                for(j=0; j<nr; j++)

                {
                    if(need[i][j]>available[j])
                    {
                        flag=1;
                        break;
                    }
                }

                if(flag==0)
                {
                    safeseq[index++]=i;
                    for(l=0; l<nr; l++)
                    {
                        available[l]=available[l]+allocation[i][l];
                    }
                    pcompleted[i]=1;
                }
            }
        }
    }

    for(i=0; i<np; i++)
    {
        if(pcompleted[i]==0)
        {
            printf("It is in Unsafe state");
            return 0;
        }
    }


    for(i=0; i<np; i++)
    {
        printf("P%d ->",safeseq[i]);
    }

    return 0;
}