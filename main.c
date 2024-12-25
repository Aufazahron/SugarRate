#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <direct.h>

#define MAX_USERNAME_LEN 50
#define MAX_PASSWORD_LEN 50
#define CREDENTIALS_FILE "C:\\Users\\lenovo\\Desktop\\Projek Aplikasi\\credentials.txt"
#define PRODUCT_LIST "C:\\Users\\lenovo\\Desktop\\Projek Aplikasi\\daftarProduk.txt"

// Function to read input with a length limit
void get_input(char *input, int length) {
    fgets(input, length, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character if present
}

// Function to register a new user
void register_user() {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
    //char cwd[1024];
    FILE *file;

    // Prompt for username
    printf("Enter a new username: ");
    get_input(username, MAX_USERNAME_LEN);

    // Prompt for password
    printf("Enter a new password: ");
    get_input(password, MAX_PASSWORD_LEN);

    // Open file in write mode to store the new username and password
    file = fopen(CREDENTIALS_FILE, "a");
    if (file == NULL) {
        printf("Error opening file to register credentials.\n");
        return;
    }

    // Store username and password in the file
    fprintf(file, "%s %s\n", username, password);
    fclose(file);

    printf("User registered successfully!\n");
}

// Function to display the admin menu
void admin_menu() {
    int pil_menu_admin, pil_tambah_produk;
    double isiBersih, gula, persenGula;
    char prdct[100];
    printf("\n--- Menu Admin ---\n");
    printf("1. Tambahkan Produk\n");
    printf("2. Logout\n");
    printf("Enter your choice: ");
    scanf("%d", &pil_menu_admin);
    getchar(); // Consume newline character

    switch (pil_menu_admin) {
        case 1:
            printf("Nama Produk: \n");
            scanf("%s", &prdct);
            printf("Isi Bersih(mL): \n");
            scanf("%lf", &isiBersih);
            printf("Kandungan Gula(g): \n");
            scanf("%lf", &gula);

            // Menghitung persentase gula
            persenGula = (gula / isiBersih) * 100;
            printf("Persentase Gula adalah: %.2lf\n", persenGula);

            // Menentukan grade minuman
            char grade[2];// Menyimpan grade
            if (persenGula <= 1)
            {
                sprintf(grade, "A");
            } else if (persenGula > 1 && persenGula <5)
            {
                sprintf(grade, "B");
            } else if (persenGula > 5 && persenGula < 10)
            {
                sprintf(grade, "C");
            } else if (persenGula >= 10)
            {
                sprintf(grade, "D");
            }
            printf("Grade minuman %s adalah: %s\n", prdct, grade);

            // Menyimpan data
            FILE *file = fopen(PRODUCT_LIST, "a"); // Buka file
            if (file != NULL) {
                fprintf(file, "Nama Produk: %s\n", prdct);
                fprintf(file, "Isi Bersih: %.2lf mL\n", isiBersih);
                fprintf(file, "Kandungan Gula: %.2lf\n", gula);
                fprintf(file, "Persentase Gula: %.2lf%%\n", persenGula);
                fprintf(file, "Grade: %s\n\n", grade);
                fclose(file);
                printf("Data produk berhasil disimpan.\n\n");
            } else {
                printf("Error tidak dapat membuka file untuk menyimpan data.");
            }

            printf("Apakah Ingin Tambah Produk?\n");
            printf("1. Ya\n");
            printf("2. Tidak\n");
            printf("Masukkan Pilihan: \n");
            scanf("%d", &pil_tambah_produk);

            switch (pil_tambah_produk)
            {
            case 1:
                admin_menu();
                break;
            case 2:
                printf("Logging out...\n");
                return;
            }
        case 2:
            printf("Logging out...\n");
            return;
        default:
            printf("Invalid choice.\n");
    }
    admin_menu(); // Loop back to the admin menu
}

// Function to login admin
void login_user() {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
    char stored_username[MAX_USERNAME_LEN];
    char stored_password[MAX_PASSWORD_LEN];
    FILE *file;

    // Prompt for username
    printf("Enter username: ");
    get_input(username, MAX_USERNAME_LEN);

    // Prompt for password
    printf("Enter password: ");
    get_input(password, MAX_PASSWORD_LEN);

    // Open the credentials file to check for matching credentials
    file = fopen(CREDENTIALS_FILE, "r");
    if (file == NULL) {
        printf("Error opening file to check credentials.\n");
        return;
    }

    int found = 0;
    // Read through the file and compare the entered credentials
    while (fscanf(file, "%s %s", stored_username, stored_password) != EOF) {
        if (strcmp(username, stored_username) == 0 && strcmp(password, stored_password) == 0) {
            found = 1;  // Match found
            break;
        }
    }
    fclose(file);

    if (found) {
        printf("Login successful!\n");
        admin_menu(); // Move to admin menu
    } else {
        printf("Invalid username or password.\n");
    }
}

int main() {
    int choice;

    printf("============================\n");
    printf("Selamat Datang di Sugar-Rate\n");
    printf("============================\n");
    printf("1. SignUp\n");
    printf("2. Login\n");
    printf("Masukkan Pilihan: ");
    scanf("%d", &choice);
    getchar();  // To consume the newline character left by scanf

    if (choice == 1) {
        register_user();
    } else if (choice == 2) {
        login_user();
    } else {
        printf("Pilihan Tidak Valid.\n");
    }

    return 0;
}
