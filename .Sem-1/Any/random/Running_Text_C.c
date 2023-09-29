#include <stdio.h>
#include <windows.h>

int main (){


    char any[12]=" 0987677541";
    
    char any1[14]=" Running Text";
    

    int i;
    int j;
    char tempn;
    char temph;
    while (1){

        system("cls");
        // left to right
        tempn=any[0];
        for (i=0;i<11;i++){
            any[i]=any[i+1];
        }
        any[10]=tempn;
        for(i=0;i<=11;i++){
            printf("%c",any[i]);
        }
        printf("\n");

        //right to left
        temph=any1[12] ;
        for (i=12;i>0;i--){
        any1[i]=any1[i-1];
        }
        any1[0]=temph;
        for(i=0;i<=12;i++){
        printf("%c",any1[i]);
        }


        for (i=1;i<=60000;i++)
			for (j=1;j<=10000;j++);
    }
}
