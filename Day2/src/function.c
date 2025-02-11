#include "../include/function.h"

#include <string.h>

#include "../include/datatype.h"

struct Category categories[MAX_CATEGORIES];
int categoryCount = 0;
const char email[] = "test@gmail.com";
const char password[] = "password";
char email_in[100];
char password_in[64];

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
}

void entry_menu() {
    system("cls");
    printf("***Store Management System Using C***\n");
    printf("%32s", "============================\n");
    printf("%20s\n", "MENU");
    printf("%13s", "=============================\n");
    printf("%-28s\n", "[1] Category management.");
    printf("%-28s\n", "[2] Product management.");
    printf("%-28s\n", "[0] Exit the Program.");
    printf("%-28s\n", "=============================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    fflush(stdin);
    switch (choice) {
        case 1:
            category_menu();
        break;
        case 2:
        case 0:
            exit_program();
        default:
            printf("Invalid Choice, try again: ");
            scanf("%d", &choice);
            fflush(stdin);
            printf("\n");
    }
}

void category_menu() {
    system("cls");
    printf("***Store Management System Using C***\n");
    printf("\n");
    printf("%28s\n", "============================");
    printf("%15s\n", "MENU");
    printf("%-28s\n", "[1] Add category.");
    printf("%-28s\n", "[2] View category.");
    printf("%-28s\n", "[3] Edit category.");
    printf("%-28s\n", "[4] Delete category.");
    printf("%-28s\n", "[5] Find category by name.");
    printf("%-28s\n", "[6] Sort categories.");
    printf("%-28s\n", "[0] Exit the Program.");
    printf("%28s\n", "============================");
    printf("%20s", "Enter The Choice: ");
    scanf("%d", &choice);
    fflush(stdin);
    printf("\n");
    do {
        switch (choice) {
            case 1:
                add_category();
            break;
            case 2:
                viewCategories();
            break;
                case 3:
                    edit_category();
            case 0:
                system("cls");
                exit_program();
            break;
            default:
                printf("Invalid Choice, try again: ");
                scanf("%d", &choice);
                fflush(stdin);
                printf("\n");
        }
    }while(choice < 0 || choice > 3);
}

void add_category() {
    system("cls");
    printf("***Store Management System Using C***\n");
    if (categoryCount >= MAX_CATEGORIES) {
        printf("Too many Categories, please delete one!\n");
        return;
    }

    struct Category newCategory;
    printf("Enter the ID of the Category: ");
    fgets(newCategory.CategoryId, sizeof(newCategory.CategoryId), stdin);
    newCategory.CategoryId[strcspn(newCategory.CategoryId, "\n")] = 0;
    for (int i = 0; i < categoryCount; i++) {
        if (strcmp(newCategory.CategoryId, categories[i].CategoryId) == 0) {
            printf("Category ID already exists!\n");
            add_category();
        }
    }

    printf("Enter the Name of the Category: ");
    fgets(newCategory.CategoryName, sizeof(newCategory.CategoryName), stdin);
    newCategory.CategoryName[strcspn(newCategory.CategoryName, "\n")] = 0;
    for (int i = 0; i < categoryCount; i++) {
        if (strcmp(newCategory.CategoryName, categories[i].CategoryName) == 0) {
            printf("Category Name already exists!\n");
            add_category();
        }
    }

    categories[categoryCount] = newCategory;
    categoryCount++;
    printf("Category added successfully!\n");
    return_options();
}

void viewCategories() {
    system("cls");
    printf("***Store Management System Using C***\n");
    printf("\n=== CATEGORY LIST ===\n");
    if (categoryCount == 0) {
        printf("No categories available.\n");
    } else {
        printf("+------------+------------+\n");
        printf("| CategoryID | Name       |\n");
        printf("+------------+------------+\n");
        for (int i = 0; i < categoryCount; i++) {
            printf("| %-10s | %-10s |\n", categories[i].CategoryId, categories[i].CategoryName);
            printf("+------------+------------+\n");
        }
    }
    return_options();
}

void edit_category() {
    system("cls");
    char find_ID[10];
    bool flag = false;
    printf("***Store Management System Using C***\n");
    printf("\n====== CATEGORY EDITOR ======\n");
    printf("Enter the ID of the Category: ");
    fgets(find_ID, sizeof(find_ID), stdin);
    find_ID[strcspn(find_ID, "\n")] = '\0';
    for (int i = 0; i < categoryCount; i++) {
        if (strcmp(find_ID, categories[i].CategoryId) == 0) {
            flag = true;
            printf("Category found!\n");
            printf("+------------+------------+\n");
            printf("| CategoryID | Name       |\n");
            printf("+------------+------------+\n");
            printf("| %-10s | %-10s |\n", categories[i].CategoryId, categories[i].CategoryName);
            printf("+------------+------------+\n");
            change_category_name(i);
            break;
        }
    }
    if (flag == false) {
        printf("Category ID not found! Press 1 to process again, 0 to exit to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        printf("\n");
        if (choice == 1) {
            edit_category();
        }
        else {
            return_options();
        }
    }
    category_menu();
}

void change_category_name(int x) {
    char new_name[10];
    printf("Enter new name for category: ");
    fgets(new_name, sizeof(new_name), stdin);
    new_name[strcspn(new_name, "\n")] = '\0';
    strcpy(categories[x].CategoryName, new_name);
}

void delete_category() {
    system("cls");
    char find_ID[10];
    bool flag = false;
    printf("***Store Management System Using C***\n");
    printf("\n====== CATEGORY DELETE ======\n");
    printf("Enter the ID of the Category: ");
    fgets(find_ID, sizeof(find_ID), stdin);
    find_ID[strcspn(find_ID, "\n")] = '\0';
    for (int i = 0; i < categoryCount; i++) {
        if (strcmp(find_ID, categories[i].CategoryId) == 0) {
            printf("Deleting Category\n");
            flag = true;
            for (int j = i; j < categoryCount - 1; j++) {
                categories[j] = categories[j + 1];
            }
            categoryCount--;
            printf("Category deleted successfully!\n");
            break;
        }
    }
    if (flag == false) {
        printf("Category not found! Try again!\n");
        delete_category();
    }
    return_options();
}

void return_options() {
    //system("cls");
    printf("\n=====================================\n");
    printf("[99] Main menu\n");
    printf("[0] Exit\n");
    printf("%20s", "Enter The Choice: ");
    scanf("%d", &choice);
    fflush(stdin);
    printf("\n");
    switch(choice) {
        case 0:
            exit_program();
        case 99:
            category_menu();
        default:
            printf("Invalid Choice, try again!\n");
        printf("%20s", "Enter The Choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        printf("\n");
        fflush(stdin);
    }
}

void exit_program() {
    system("cls");
    printf("========================================\n");
    printf("%22s\n", "Thank You");
    printf("========================================\n");
    printf("%24s\n", "See You Soon");
    printf("========================================\n");
    exit(1);
}