#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct{
    char dname[10], fname[10][10];
    int fcnt;
}dir;

void main(){
    int i, ch;
    char f[30];
    dir.fcnt = 0;
    printf("\nEnter the name of Directory -- ");
    scanf("%s", dir.dname);
    while(1){
        printf("\n\n1.CREATE_FILE\n2.DELETE_FILE\n3.SEARCH_FILE\n4.DISPLAY_FILES\n5.EXIT\n\nEnter your choice --");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("\nEnter The name of File -- ");
                scanf("%d", dir.fname[dir.fcnt]);
                dir.fcnt++;
                break;

            case 2:
                printf("\nEnter the name of the File -- ");
                scanf("%s", f);
                for(i = 0; i < dir.fcnt; i++){
                    if(strcmp(f, dir.fname[i]) == 0){
                        printf("File %s is Deleted", f);
                        strcpy(dir.fname[i], dir.fname[dir.fcnt - 1]);
                        break;
                    }
                }
                if(i == dir.fcnt)
                    printf("File %s not found", f);
                else
                    dir.fcnt--;
                    break;

            case 3:
                printf("\Enter the name of the File -- ");
                scanf("%s", f);
                for(i = 0; i < dir.fcnt; i++){
                    if(strcmp(f, dir.fname[i]) == 0){
                        printf("File %s not found", f);
                        break;
                    }
                }
                if(i == dir.fcnt)
                    printf("File %s not found", f);
                    break;

            case 4:
                if(dir.fcnt == 0)
                    printf("\nDirectory Empty");
                else{
                    printf("\nThe Files are -- ");
                    for(i = 0; i < dir.fcnt; i++)
                        printf("\t%s", dir.fname[i]);
                }
                break;

            default: exit(0);
        }
    }
    getch();
}
