#include <string.h>

#include "../include/datatype.h"
char email[] = "test@gmail.com";
char password[] = "password";
char email_in[100];
char password_in[64];

void display()
{
    printf("***Student Management System Using C***\n");
    printf("\n");
    printf("%26s", "CHOOSE YOUR ROLE\n");
    printf("\n");
    printf("%32s\n", "================================");
    printf("%15s\n", "[1] Admin.");
    printf("%17s\n", "[2] Student.");
    printf("%17s\n", "[3] Teacher.");
    printf("%26s\n", "[0] Exit the Program.");
    printf("%32s\n", "================================");
    printf("%2s", "Enter The Choice: ");
}

void admin_menu() {
    printf("***Student Management System Using C***\n");
    printf("\n");
    printf("%32s", "============================\n");
    printf("%15s\n", "MENU");
    printf("%17s\n", "[1] Students management.");
    printf("%17s\n", "[2] Classrooms management.");
    printf("%17s\n", "[3] Teachers management.");
    printf("%17s\n", "[4] User Guideline.");
    printf("%17s\n", "[5] About Us.");
    printf("%17s\n", "[0] Exit the Program.");
    printf("%32s", "============================\n");
    printf("%15s", "Enter The Choice: ");
    scanf("%d", &choice);
    printf("\n");
}

void log_in_menu() {
    printf("***Student Management System Using C***\n");
    printf("%20s\n", "LOGIN");
    printf("%32s", "============================\n");
    bool authentication = true;
    do {
        printf("%10s", "Email: ");
        fflush(stdin);
        fgets(email_in, sizeof(email_in), stdin);
        email_in[strcspn(email_in, "\n")] = '\0';
        printf("%13s", "Password: ");
        fgets(password_in, sizeof(password_in), stdin);
        password_in[strcspn(password_in, "\n")] = '\0';
        printf("%32s", "============================\n");
        if (strcmp(password_in, password) != 0 || strcmp(email_in, email) != 0) {
            authentication = false;
            printf("Wrong Password or Email, try again!\n");
        }
        else {
            authentication = true;
        }
    }while (!authentication);
    admin_menu();
}

void exit_program() {
    printf("========================================\n");
    printf("%22s\n", "Thank You");
    printf("========================================\n");
    printf("%24s\n", "See You Soon");
    printf("========================================\n");
    exit(1);
}

void entry_choice() {
    scanf("%d", &choice);
    do {
        switch(choice) {
            case 1:
                //system("cls");
                    log_in_menu();
            break;
            case 2:
            case 3:

            case 0:
                exit_program();
            default:
                printf("Invalid Choice, try again\n");
            scanf("%d", &choice);
        }
    }while(choice < 0 || choice > 3);
}