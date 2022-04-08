#include<stdio.h>
#include<conio.h>

int main(){
    int ms, bs, nob, ef, n, mp[10], tif = 0;
    int i, p = 0;

    printf("Enter The Total memory available (in Bytes) -- ");
    scanf("%d", &ms);
    printf("Enter The Block Size (in Bytes) -- ");
    scanf("%d", &bs);

    nob = ms/bs;
    ef = ms - nob*bs;

    printf("Enter The Number of Process -- ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("Enter memory required for process %d (in Bytes) --", i + 1);
        scanf("%d", &mp[i]);
    }

    printf("\nNo. of Blocks available in Memory -- %d", nob);
    printf("\n\nPROCESS\tMEMORY_REQUIRED\t\tALLOCATED\tINTERNAL_FRAGMENTATION");
    for(i = 0; i < n && p < nob; i++){
        printf("\n%d\t\t%d", i + 1, mp[i]);
        if(mp[i] > bs)
            printf("\t\tNO\t\t---");
        else{
            printf("\t\tYES\t\t%d", bs - mp[i]);
            tif = tif + bs - mp[i];
            p++;
        }
    }

    if(i < n)
        printf("\nMemory is Full, Remaining Process cannot be accomodated");
        printf("\n\nTotal Internal Fragmentation is %d", tif);
        printf("\nTotal External Fragmentation is %d", ef);
        getch();
}
