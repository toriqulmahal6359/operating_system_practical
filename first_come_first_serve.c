#include<stdio.h>
#include<string.h>
#include<conio.h>

int main(){
    char pn[10][10], t[10];
    int arr[10], bur[10], star[10], finish[10], tat[10], wt[10], n, i, j, temp;
    int totwt = 0, tottat =0;

    printf("Enter The number of Processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("Enter the Process Name, Arrival Time and Burst Time: ");
        scanf("%s%d%d", &pn[i], &arr[i], &bur[i]);
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(arr[i] < arr[j]){
                //The Bigger process will get its priority first
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                temp = bur[i];
                bur[i] = bur[j];
                bur[j] = temp;

                //Process name will also be shifted from second to first
                strcpy(t, pn[i]);
                strcpy(pn[i], pn[j]);
                strcpy(pn[j], t);
            }
        }
    }

    for(i = 0; i < n; i++){
        if(i == 0)
            star[i] = arr[i];
        else
            star[i] = finish[i - 1];
            wt[i] = star[i] - arr[i];
            finish[i] = star[i] + bur[i];
            tat[i] = finish[i] - arr[i];

            totwt += wt[i];
            tottat += tat[i];

    }
    printf("\nPROCESS_NAME\tARRIVAL_TIME\tBURST_TIME\tWAITTING_TIME\tSTART_TIME\tTURN_AROUND_TIME\tFINISH_TIME");
    for(i = 0; i < n; i++){
        printf("\n%s\t\t%3d\t\t%3d\t\t%3d\t\t%3d\t\t%6d\t\t\t%6d", pn[i], arr[i], bur[i], wt[i], star[i], tat[i], finish[i]);
    }
    printf("\nAverage Waiting Time: %f", (float)totwt/n);
    printf("\nAverage Turn Around Time: %f", (float)tottat/n);
    getch();
    return 0;

}
