#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

struct regist{
    char user[30],pass[30];
};

void registration(){

    struct regist admin;
    
    printf("Masukkan username: "); scanf(" %[^\n]s",admin.user);
    printf("Masukkan password: "); scanf(" %[^\n]s",admin.pass);
    printf("username %s dan password %s tersimpan\n", admin.user, admin.pass);

    FILE *reg;

    reg = fopen("login.txt","a");
    if(reg == NULL)
    {
        fprintf(stderr,"\nError open file\n");
        exit (1);
    }

    fwrite(&admin,sizeof(struct regist), 1, reg);
    fclose(reg);

    if(fwrite != 0)
        printf("\nRegistration Succesfull!!!\n");
    else
        printf("Registration error!!!\n");

}

void login(){
    char username[30],password[30];
    FILE *log;
    
    struct regist admin;

    printf("Username: "); scanf(" %[^\n]s", &username);
    printf("Password: "); scanf(" %[^\n]s", &password);

    log = fopen("login.txt","r");
    fread(&admin,sizeof(struct regist), 1, log);
    if(strcmp(admin.user,username) == 0 && strcmp(admin.pass,password) == 0){
        printf("Login Berhasil\n");
    }else{
        printf("Username dan Password tidak cocok\n");
    }
    fclose(log);
}

int main()
{
    int pili;
    
    while(1){
    printf("1. Registrasi\n2. Login(Kalau belum registrasi gabisa login)\n");
    printf("Pilihan anda: ");

    scanf("%d",&pili);
        switch(pili){
            case 1:
                registration();
                break;
            case 2:{
                FILE *reg;
                reg = fopen("login.txt","r");
                if(reg == NULL)
                {
                    fprintf(stderr,"\nRegistrasi Dahulu!!!\n");
                    system("pause");
                }
                else{
                login();
                }
                break;
            }
            case 3:
            exit(0);
            default:
            printf("GAADA\n");
        }
    }
}