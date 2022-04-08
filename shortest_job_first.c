#include<stdio.h>
#include<conio.h>
#include<string.h>

void main(){
    int et[20], at[20], temp, st[20], ft[10], wt[10], ta[10], n, i, j;
    int totwt = 0, totta = 0;
    float awt, ata;
    char pn[10][10], t[10];
    //clrscr();

    printf("Enter The number of the Process:");
    scanf("%d", &n);

    for(i =0; i <n; i++){
        printf("Enter Process name, arrival time & execution time:");
        //flushall();
        scanf("%s%d%d", &pn[i], &at[i], &et[i]);
    }

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++){
            if(et[i] < et[j]){
               temp = at[i];
               at[i] = at[j];
               at[j] = temp;

               temp = et[i];
               et[i] = et[j];
               et[j] = temp;

               strcpy(t, pn[i]);
               strcpy(pn[i], pn[j]);
               strcpy(pn[j], t);
            }
        }

        for(i = 0; i < n; i++){
            if(i == 0)
                st[i] = at[i];
            else
                st[i] = ft[i - 1];
                wt[i] = st[i] - at[i];
                ft[i] = st[i] + et[i];
                ta[i] = ft[i] - at[i];

                totwt += wt[i];
                totta += ta[i];
        }
        awt = (float)totwt/n;
        ata = (float)totta/n;
        printf("\nPROCESS_NAME\tARRIVAL_TIME\tEXECUTION_TIME\tWAITING_TIME\tTURN_AROUND_TIME");
        for(i = 0; i < n; i++)
            printf("\n%s\t\t%5d\t\t%5d\t\t%5d\t\t%5d", pn[i], at[i], et[i], wt[i], ta[i]);
            printf("\nAverage Waiting Time: %f", awt);
            printf("\nAverage Turn Around Time: %f", ata);
        getch();
}
