#include "../include/function.h"

#include <string.h>

#include "../include/datatype.h"

struct Category categories[MAX_CATEGORIES];
int categoryCount = 0;
char email[] = "test@gmail.com";
char password[] = "password";
char email_in[100];
char password_in[64];

void admin_menu() {
    printf("***Store Management System Using C***\n");
    printf("\n");
    printf("%28s\n", "============================");
    printf("%15s\n", "MENU");
    printf("%-28s\n", "[1] Add category.");
    printf("%-28s\n", "[2] View category.");
    printf("%-28s\n", "[3] Edit category.");
    printf("%-28s\n", "[0] Exit the Program.");
    printf("%28s\n", "============================");
    printf("%20s", "Enter The Choice: ");
    scanf("%d", &choice);
    printf("\n");
    fflush(stdin);
    do {
        switch (choice) {
            case 1:
                add_category();
                break;
            case 2:
                viewCategories();
                case 3:
            case 0:
                exit_program();
            break;
            default:
                printf("Invalid Choice, try again: ");
                scanf("%d", &choice);
                printf("\n");
        }
    }while(choice < 0 || choice > 3);
}

void log_in_menu() {
    printf("***Store Management System Using C***\n");
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

void add_category() {
    if (categoryCount >= MAX_CATEGORIES) {
        printf("Too many Categories, please delete one!\n");
        return;
    }

    struct Category newCategory;
    printf("Enter the ID of the Category: ");
    fgets(newCategory.CategoryId, sizeof(newCategory.CategoryId), stdin);
    newCategory.CategoryId[strcspn(newCategory.CategoryId, "\n")] = 0; // Xóa dấu xuống dòng

    printf("Enter the Name of the Category: ");
    fgets(newCategory.CategoryName, sizeof(newCategory.CategoryName), stdin);
    newCategory.CategoryName[strcspn(newCategory.CategoryName, "\n")] = 0; // Xóa dấu xuống dòng

    categories[categoryCount] = newCategory;
    categoryCount++;
    printf("Category added successfully!\n");
    printf("Going back to main menu");
    admin_menu();
}

void viewCategories() {
    printf("\n=== CATEGORY LIST ===\n");
    if (categoryCount == 0) {
        printf("No categories available.\n");
    } else {
        printf("+------------+------------+\n");
        printf("| CategoryID | Name       |\n");
        printf("+------------+------------+\n");
        for (int i = 0; i < categoryCount; i++) {
            printf("| %-10s | %-10s |\n", categories[i].CategoryId, categories[i].CategoryName);
        }
        printf("+------------+------------+\n");
    }
}