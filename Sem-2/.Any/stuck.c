#include <stdio.h>
#include <string.h>

void isempty(){
    if (top==0){
        return 1;
    }else{
        return 0;
    }
    
    
}
void displayStuck(){
    char data[100];
    if (isfull()){
        printf("data kosong");
    }else{
        // for (int i = top; i > 0; i--)
        // {
            printf("Masukan Data : ");
            scanf (" %[^\n]",&data);
            strcpy(datastack[top],data);
            top++;
            printf("DATA BERHASIL DIMASUKAN");
        // }   
    }
}

void pop(){
    if (isempty()){
        printf("Data Kosong, Masukan Data");
    }else
    {
        strcpy(datastack[top-1],"");
        top--;
        printf("Data Berhasil Dihapus");
    }
    
    
}

void peek(){
    int posisi,index;
    if (isempty()){
        printf("Data Kosong, Masukan Data");
    }else
    {
        displaystack();
        printf("Masukan Posisi Data : ");
        scanf("%d",&posisi);
        if (posisi>top){
            printf("Posisi Melebihi Data");
        }else{
            index=top;
            for (int i = 0; i < posisi; i++){
                index--;
            }
            printf("Posisi ke %d adalagh %s",posisi,datastack[index]);
        }
        
        
    }
    
}

void change(){
    int posisi,index;
    char datapengganti[100];
    if (isempty()){
        printf("Data Kosong, Masukan Data");
    }else{
        displaystack();
        printf("Masukan POsisi Data");
        scanf("%d",posisi);
        printf("Masukan Data Pengganti");
        scanf (" %[^\n]",&datapengganti);
        if (posisi>top){
            printf("Invalid Data");
        }else
        {
            /* code */
        }
        
        
    }
}

void count(){

}

void push(){

}

void restore(){
    
}

int main(){

}