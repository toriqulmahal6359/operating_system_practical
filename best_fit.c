#include<stdio.h>
#include<conio.h>
#define max 25

void main(){
    int frag[max], b[max], f[max], i, j, nb, nf, temp, lowest = 10000;
    static int bf[max], ff[max];

    printf("\n\tMemory Management Scheme - Best Fit\n");

    printf("\nEnter the number of Blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of Files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the Blocks:\n");
    for(i = 1; i <= nb; i++){
        printf("Block %d:", i);
        scanf("%d", &b[i]);
    }

    printf("\nEnter the size of the Files:\n");
    for(i = 1; i <= nf; i++){
        printf("Files %d:", i);
        scanf("%d", &f[i]);
    }

    for(i = 1; i <= nf; i++){
        for(j = 1; j <= nb; j++){
            if(bf[j] != 1){
                temp = b[j] - f[i];
                if(temp >= 0)
                if(lowest > temp){
                    ff[i] = j;
                    lowest = temp;
                }
            }
        }
        frag[i] = lowest;
        bf[ff[i]] = 1;
        lowest = 10000;
    }
    printf("\nFILE_NO.\tFILE_SIZE\tBLOCK_NO.\tBLOCK_SIZE\tFRAGMENT");
    for(i = 1; i <= nf && ff[i] != 0; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
        getch();
}
