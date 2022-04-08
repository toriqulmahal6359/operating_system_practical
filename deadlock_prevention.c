#include<stdio.h>
#include<conio.h>
void main(){
    int allocated[15][15], max[15][15], need[15][15], avail[15], tres[15], work[15], flag[15];
    int pno, rno, i, j, prc, count, t, total;
    count = 0;
    printf("************** Banker's Algorithm **************");
    printf("\nEnter the number of Process:\t");
    scanf("%d", &pno);

    printf("\nEnter the number of Resources:\t");
    scanf("%d", &rno);
    for(i = 1; i <= pno; i++){
        flag[i] = 0;
    }

    printf("\nEnter total numbers of each resources:\t");
    for(i = 1; i <= rno; i++)
        scanf("%d", &tres[i]);

    printf("\nEnter Max Resources for each Process:");
    for(i = 1; i <= pno; i++){
        printf("\nFor Process %d: ", i);
        for(j = 1; j <= rno; j++)
            scanf("%d", &max[i][j]);
    }

    printf("\nEnter Allocated Resources for each Process:");
    for(i = 1; i <= pno; i++){
        printf("\nFor Process %d: ", i);
        for(j = 1; j <= rno; j++)
            scanf("%d", &allocated[i][j]);
    }

    printf("\nAvailable Resources:\n");
    for(j = 1; j <= rno; j++){
        avail[j] = 0;
        total = 0;
        for(i = 1; i <= pno; i++){
            total += allocated[i][j];
        }
        avail[j] = tres[j] - total;
        work[j] = avail[j];
        printf("%d\t", work[j]);
    }

    do{
        for(i = 1; i <= pno; i++){
            for(j = 1; j <= rno; j++){
                need[i][j] = max[i][j] - allocated[i][j];
            }
        }
        printf("\nALLOCATED_MATRIX\t MAX\t NEED\t");
        for(i = 1; i <= pno; i++){
            printf("\n");
            for(j = 1; j <= rno; j++){
                printf("%4d", allocated[i][j]);
            }
            printf("|");
            for(j = 1; j <= rno; j++){
                printf("%4d", max[i][j]);
            }
            printf("|");
            for(j = 1; j <= rno; j++){
                printf("%4d", need[i][j]);
            }
        }
        prc = 0;
        for(i = 1; i <= pno; i++){
            if(flag[i] == 0){
                prc = i;
                for(j = 1; j <= rno; j++){
                    if(work[j] < need[i][j]){
                        prc = 0;
                        break;
                    }
                }
            }
            if(prc != 0)
            break;
        }
        if(prc != 0){
            printf("\nProcess %d Completed", i);
            count++;
            printf("\nAvailable Matrix:");
            for(j = 1; j <= rno; j++){
                work[j] += allocated[prc][j];
                allocated[prc][j] = 0;
                max[prc][j] = 0;
                flag[prc] = 1;
                printf("   %d", work[j]);
            }
        }
    }while(count != pno && prc != 0);

    if(count == pno)
        printf("\nThe System is in a Safe State!!");
    else
        printf("\n The System is in an Unsafe State!!");

    getch();
}
