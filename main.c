#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void homePageAdmin(){
    int page;
    printf("\n=== Admin Page ===\n");
    printf("1. Ganti Username\n");
    printf("2. Ganti Password\n");
    printf("0. Logout\n");
    printf("Pilih opsi: ");
    scanf("%d", &page);

    switch (page) {
        case 1:
            printf("Masukkan username baru: ");
            printf("Username berhasil diubah menjadi: \n");
            break;
        case 2:
            printf("Masukkan password baru: ");
            printf("Password berhasil diubah.\n");
            break;
        case 0:
            system("clear");
            break;
        default:
            printf("Pilihan tidak valid.\n");
    }

}

void homePage(){
    int page;
    printf("\n=== User Page ===\n");
    printf("1. Ganti Username\n");
    printf("2. Ganti Password\n");
    printf("0. Logout\n");
    printf("Pilih opsi: ");
    scanf("%d", &page);

    switch (page) {
        case 1:
            printf("Masukkan username baru: ");
            printf("Username berhasil diubah menjadi: \n");
            break;
        case 2:
            printf("Masukkan password baru: ");
            printf("Password berhasil diubah.\n");
            break;
        case 0:
            system("clear");
            break;
        default:
            printf("Pilihan tidak valid.\n");
    }

}

int main(){
    // Login Site
    int login;
    
    char usr1[] = "admin";
    char psw1[] = "admin";
    char usr2[] = "user";
    char psw2[] = "user";

    char inusr[20];
    char inpsw[20];

    do{
    printf("=== SUGAR RATE ===\n");
    printf("Masukkan Username : ");
    gets(inusr);
    printf("Masukkan Password : ");
    gets(inpsw);

    if (strcmp(inusr, usr1)==0 && strcmp(inpsw, psw1)==0){
        system("clear");
        homePageAdmin();
    } else if(strcmp(inusr, usr2)==0 && strcmp(inpsw, psw2)==0){
        system("clear");
        homePage();
    } else{
        system("clear");
        printf("\nUsername atau Password salah silahkan masukan ulang!\n\n");
    }
      
    }while (!login);
    
    
}

