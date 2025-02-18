#include "../include/function.h"
#include <string.h>
#include "../include/datatype.h"

Category categories[MAX_LENGTH];
Product products[MAX_LENGTH];
int categoryCount;
int productCount = 0;
const char email[] = "test@gmail.com";
const char password[] = "password";
char email_in[100];
char password_in[64];
int writeCount = 0;

void load_file(const char *file_name, const char *mode) {
    FILE *file = fopen(file_name, mode);
    if (file == NULL) {
        printf("No data found. Starting fresh.\n");
        if (strcmp(file_name, "data/category.bin") == 0) {
            categoryCount = 0;
        }
        else {
            productCount = 0;
        }
        return;
    }
    if (strcmp(file_name, "data/category.bin") == 0) {
        fread(&categoryCount, sizeof(int), 1, file);
        if (categoryCount < 0 || categoryCount > MAX_LENGTH) {
            printf("Error: Invalid category count (%d). Resetting to 0.\n", categoryCount);
            categoryCount = 0;
            fclose(file);
            return;
        }

        fread(categories, sizeof(Category), categoryCount, file);
    }

    else {
        fread(&productCount, sizeof(int), 1, file);
        if (productCount < 0 || productCount > MAX_LENGTH) {
            printf("Error: Invalid product count (%d). Resetting to 0.\n", productCount);
            productCount = 0;
            fclose(file);
            return;
        }

        fread(products, sizeof(Product), productCount, file);
    }

    fclose(file);
}

void save_categories() {
    FILE *file = fopen("data/category.bin", "wb");
    if (file == NULL) {
        printf("Error: Cannot open category file for writing.\n");
        return;
    }
    fwrite(&categoryCount, sizeof(int), 1, file);
    fflush(file);
    fwrite(categories, sizeof(Category), categoryCount, file);
    fflush(file);
    fclose(file);
    printf("Categories saved successfully.\n");
}

void save_products() {
    FILE *file = fopen("data/products.bin", "wb");
    if (file == NULL) {
        printf("Error: Cannot open product file for writing.\n");
        return;
    }
    fwrite(&productCount, sizeof(int), 1, file);
    fflush(file);
    fwrite(&products, sizeof(Product), productCount, file);
    fflush(file);
    fclose(file);
    printf("Product saved successfully.\n");
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
        } else {
            authentication = true;
        }
    } while (!authentication);
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
            product_menu();
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
    printf("%-28s\n", "[99] Back to Main Menu.");
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
                break;
            case 4:
                delete_category();
                break;
            case 5:
                search_categories();
            break;
            case 6:
                categories_sort_options();
                break;
            case 99:
                entry_menu();
            break;
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
    } while ((choice < 0 || choice > 6) && choice != 99);
}

void product_menu() {
    system("cls");
    printf("***Store Management System Using C***\n");
    printf("\n");
    printf("%28s\n", "============================");
    printf("%15s\n", "PRODUCT MENU");
    printf("%-28s\n", "[1] Add product.");
    printf("%-28s\n", "[2] View product.");
    printf("%-28s\n", "[3] Edit product.");
    printf("%-28s\n", "[4] Delete product.");
    printf("%-28s\n", "[5] Find product by name.");
    printf("%-28s\n", "[6] Sort product by price.");
    printf("%-28s\n", "[99] Back to Main Menu.");
    printf("%-28s\n", "[0] Exit the Program.");
    printf("%28s\n", "============================");
    printf("%20s", "Enter The Choice: ");
    scanf("%d", &choice);
    fflush(stdin);
    printf("\n");
    do {
        switch (choice) {
            case 1:
                add_product();
            break;
            case 2:
                view_products();
            break;
            case 3:
                edit_products();
            break;
            case 4:
                delete_products();
            break;
            case 5:
                search_products();
            break;
            case 6:
                products_sort();
            break;
            case 99:
                entry_menu();
            break;
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
    } while ((choice < 0 || choice > 6) && choice != 99);
}

void add_category() {
    system("cls");
    printf("***Store Management System Using C***\n");
    if (categoryCount >= MAX_LENGTH) {
        printf("Too many Categories, please delete one!\n");
        add_category();
    }

    struct Category newCategory;
    do {
        printf("Enter Category ID (Max 9 chars): ");
        fgets(newCategory.CategoryId, sizeof(newCategory.CategoryId), stdin);
        newCategory.CategoryId[strcspn(newCategory.CategoryId, "\n")] = 0;

        if (strlen(newCategory.CategoryId) == 0) {
            printf("Error: Category ID cannot be empty!\n");
        }
    } while (strlen(newCategory.CategoryId) == 0);
    for (int i = 0; i < categoryCount; i++) {
        if (strcmp(newCategory.CategoryId, categories[i].CategoryId) == 0) {
            printf("Error: Category ID already exists!\n");
            return;
        }
    }
    do {
        printf("Enter Category Name (Max 9 chars): ");
        fgets(newCategory.CategoryName, sizeof(newCategory.CategoryName), stdin);
        newCategory.CategoryName[strcspn(newCategory.CategoryName, "\n")] = 0;
        if (strlen(newCategory.CategoryName) == 0) {
            printf("Error: Category Name cannot be empty!\n");
        }
    } while (strlen(newCategory.CategoryName) == 0);
    categories[categoryCount] = newCategory;
    categoryCount++;
    return_options();
}

void viewCategories() {
    system("cls");
    printf("***Store Management System Using C***\n");
    printf("\n=== CATEGORY LIST ===\n");
    printf("+------------+------------+\n");
    printf("| CategoryID | Name       |\n");
    printf("+------------+------------+\n");
    for (int i = 0; i < categoryCount; i++) {
        printf("| %-10s | %-10s |\n", categories[i].CategoryId, categories[i].CategoryName);
        printf("+------------+------------+\n");
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
        } else {
            return_options();
        }
    }
    category_menu();
}

void change_category_name(int x) {
    char new_name[10];
    printf("Enter new name for category: ");
    fgets(new_name, sizeof(new_name), stdin);
    if (strchr(new_name, '\n') == NULL) {
        printf("Invalid length!, please enter maximum 9 characters.\n");

        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
    } else {
        new_name[strcspn(new_name, "\n")] = 0;
    }
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
            printf("Category found\n");
            printf("Are you sure you want to delete the existing category?\n");
            printf("[1] Yes\n");
            printf("[2] No\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            fflush(stdin);
            printf("\n");
            if (choice == 0) {
                printf("Aborting...\n");
                return;
            }
            flag = true;
            for (int j = i; j < categoryCount - 1; j++) {
                categories[j] = categories[j + 1];
            }
            categoryCount--;
            writeCount--;
            printf("Category deleted successfully!\n");
            break;
        }
    }
    if (flag == false) {
        printf("Category not found!\n");
    }
    return_options();
}

void categories_sort_options() {
    int SortType;

    system("cls");
    printf("***Store Management System Using C***\n");
    printf("\n========== CATEGORY SORTING =========\n");
    printf("Sort by type: \n");
    printf("\n=====================================\n");
    printf("[1] Ascending\n");
    printf("[2] Descending\n");
    printf("[0] Return\n");
    printf("Enter your choice: ");
    scanf("%d", &SortType);
    fflush(stdin);
    printf("\n");

    switch (SortType) {
        case 1:
            categories_sort_action(1);
        break;
        case 2:
            categories_sort_action(2);
        break;
        case 0:
            category_menu();
        break;
        default:
            printf("Invalid choice! Try again!\n");
            printf("Enter your choice: ");
            scanf("%d", &SortType);
            fflush(stdin);
    }
    printf("Category sorted successfully!\n");
    viewCategories();
    if (SortType == 0) {
        return;
    }
    while (SortType > 2 || SortType < 0) {
        printf("Invalid choice! Try again!\n");
        printf("Enter your choice: ");
        scanf("%d", &SortType);
        fflush(stdin);
    }
    if (categoryCount <= 0) {
        printf("No category or there's only one category to sort\n");
        return_options();
    }
    else {
        categories_sort_action(SortType);
        printf("Category sorted successfully!\n");
        viewCategories();
    }

}

void categories_sort_action(int order) {
    struct Category temp;
    for (int i = 0; i < categoryCount; i++) {
        for (int j = 0; j < categoryCount - i - 1; j++) {
            if (order == 1) {
                if (strcmp(categories[j].CategoryName, categories[j + 1].CategoryName) > 0) {
                    temp = categories[j];
                    categories[j] = categories[j + 1];
                    categories[j + 1] = temp;
                }
            }
            if (order == 2) {
                if (strcmp(categories[j].CategoryName, categories[j + 1].CategoryName) < 0) {
                    temp = categories[j];
                    categories[j] = categories[j + 1];
                    categories[j + 1] = temp;
                }
            }
        }
    }
}

void search_categories() {
    system("cls");
    char keyword[100];

    printf("***Store Management System Using C***\n");
    printf("\nEnter keyword: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = 0;

    searchString(categories, MAX_LENGTH, keyword);

    return_options();

}

void searchString(struct Category arr[], int n, char keyword[]) {
    int found = 0;
    printf("\nResult of keyword \"%s\":\n", keyword);
    printf("\n=== CATEGORY LIST ===\n");
    printf("+------------+------------+\n");
    printf("| CategoryID | Name       |\n");
    printf("+------------+------------+\n");
    for (int i = 0; i < n; i++) {
        if (strstr(arr[i].CategoryName, keyword) != NULL) {
            printf("| %-10s | %-10s |\n", categories[i].CategoryId, categories[i].CategoryName);
            printf("+------------+------------+\n");
            found = 1;
        }
    }
    if (!found) {
        printf("Cannot find any category that match the keyword \"%s\".\n", keyword);
    }
}

void return_options() {
    printf("\n=====================================\n");
    printf("[0] Exit\n");
    printf("[99] Return\n");
    printf("%20s", "Enter The Choice: ");
    scanf("%d", &choice);
    fflush(stdin);
    printf("\n");
    switch (choice) {
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

void add_product() {
    system("cls");
    printf("***Store Management System Using C***\n");
    printf("\n=====================================\n");
    printf("===========PRODUCT ADDING============\n");
    if (productCount >= MAX_LENGTH) {
        printf("Too many Products, please delete one!\n");
        return;
    }
    Product newProduct;
    do {
        printf("Enter Product ID (Max 9 chars): ");
        fgets(newProduct.productId, sizeof(newProduct.productId), stdin);
        newProduct.productId[strcspn(newProduct.productId, "\n")] = 0;

        if (strlen(newProduct.productId) == 0) {
            printf("Error: Product ID cannot be empty!\n");
        }
    } while (strlen(newProduct.productId) == 0);
    for (int i = 0; i < productCount; i++) {
        if (strcmp(newProduct.productId, products[i].productId) == 0) {
            printf("Error: Product ID already exists!\n");
            return;
        }
    }
    do {
        printf("Enter Category ID (Max 9 chars): ");
        fgets(newProduct.categoryId, sizeof(newProduct.categoryId), stdin);
        newProduct.categoryId[strcspn(newProduct.categoryId, "\n")] = 0;

        if (strlen(newProduct.categoryId) == 0) {
            printf("Error: Category ID cannot be empty!\n");
        }
    } while (strlen(newProduct.categoryId) == 0);
    bool categoryExists = false;
    for (int i = 0; i < categoryCount; i++) {
        if (strcmp(newProduct.categoryId, categories[i].CategoryId) == 0) {
            categoryExists = true;
            break;
        }
    }

    if (!categoryExists) {
        printf("Error: Category ID does not exist!\n");
        return;
    }
    do {
        printf("Enter Product Name (Max 9 chars): ");
        fgets(newProduct.productName, sizeof(newProduct.productName), stdin);
        newProduct.productName[strcspn(newProduct.productName, "\n")] = 0;

        if (strlen(newProduct.productName) == 0) {
            printf("Error: Product Name cannot be empty!\n");
        }
    } while (strlen(newProduct.productName) == 0);
    do {
        printf("Enter Quantity: ");
        scanf("%d", &newProduct.quantity);
        fflush(stdin);

        if (newProduct.quantity <= 0) {
            printf("Error: Quantity must be greater than 0!\n");
        }
    } while (newProduct.quantity <= 0);
    do {
        printf("Enter Price: ");
        scanf("%d", &newProduct.price);
        fflush(stdin);

        if (newProduct.price <= 0) {
            printf("Error: Price must be greater than 0!\n");
        }
    } while (newProduct.price <= 0);

    products[productCount] = newProduct;
    productCount++;

    printf("Product added successfully!\n");
    return_options();
}

void view_products() {
    system("cls");
    printf("***Store Management System Using C***\n");
    printf("\n======================== PRODUCT LIST ========================\n");
    printf("+------------+------------+------------+----------+--------+\n");
    printf("| ProductID  | CategoryID | ProductName | Quantity | Price  |\n");
    printf("+------------+------------+------------+----------+--------+\n");
    for (int i = 0; i < productCount; i++) {
        printf("| %-10s | %-10s | %-10s | %-8d | %-6d |\n",
               products[i].productId, products[i].categoryId, products[i].productName,
               products[i].quantity, products[i].price);
        printf("+------------+------------+------------+----------+--------+\n");
    }
    return_options();
}

void edit_products() {
    system("cls");
    char find_CategoryID[10];
    bool flag = false;
    printf("***Store Management System Using C***\n");
    printf("\n====== PRODUCT EDITOR ======\n");
    printf("Enter the Category ID of the Product: ");
    fgets(find_CategoryID, sizeof(find_CategoryID), stdin);
    find_CategoryID[strcspn(find_CategoryID, "\n")] = '\0';

    for (int i = 0; i < productCount; i++) {
        if (strcmp(find_CategoryID, products[i].categoryId) == 0) {
            flag = true;
            printf("Product found!\n");
            printf("+------------+------------+------------+----------+--------+\n");
            printf("| ProductID  | CategoryID | ProductName | Quantity | Price  |\n");
            printf("+------------+------------+------------+----------+--------+\n");
            printf("| %-10s | %-10s | %-10s | %-8d | %-6d |\n",
                   products[i].productId, products[i].categoryId, products[i].productName,
                   products[i].quantity, products[i].price);
            printf("+------------+------------+------------+----------+--------+\n");

            change_product_details(i);
            break;
        }
    }
    if (flag == false) {
        printf("Category ID not found! Press 1 to try again, 0 to exit to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        printf("\n");
        if (choice == 1) {
            edit_products();
        } else {
            return_options();
        }
    }
    product_menu();
}

void change_product_details(int index) {
    char newName[10];
    char newCategoryId[10];
    int newQuantity, newPrice;
    do {
        printf("Enter new Product Name (Max 9 chars): ");
        fgets(newName, sizeof(newName), stdin);
        newName[strcspn(newName, "\n")] = 0;

        if (strlen(newName) == 0) {
            printf("Error: Product Name cannot be empty!\n");
        }
    } while (strlen(newName) == 0);
    strcpy(products[index].productName, newName);
    do {
        printf("Enter new Category ID (Max 9 chars): ");
        fgets(newCategoryId, sizeof(newCategoryId), stdin);
        newCategoryId[strcspn(newCategoryId, "\n")] = 0;

        if (strlen(newCategoryId) == 0) {
            printf("Error: Category ID cannot be empty!\n");
            continue;
        }
        bool categoryExists = false;
        for (int i = 0; i < categoryCount; i++) {
            if (strcmp(newCategoryId, categories[i].CategoryId) == 0) {
                categoryExists = true;
                break;
            }
        }
        if (!categoryExists) {
            printf("Category ID not found!\n");
            printf("[1] Add new Category\n");
            printf("[2] Enter another Category ID\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            fflush(stdin);

            if (choice == 1) {
                add_category();
            } else if (choice == 2) {
                continue;
            }
        } else {
            strcpy(products[index].categoryId, newCategoryId);
            break;
        }
    } while (true);
    do {
        printf("Enter new Quantity (Positive number): ");
        scanf("%d", &newQuantity);
        fflush(stdin);

        if (newQuantity < 0) {
            printf("Error: Quantity cannot be negative!\n");
        }
    } while (newQuantity < 0);
    products[index].quantity = newQuantity;
    do {
        printf("Enter new Price (Positive number): ");
        scanf("%d", &newPrice);
        fflush(stdin);

        if (newPrice < 0) {
            printf("Error: Price cannot be negative!\n");
        }
    } while (newPrice < 0);
    products[index].price = newPrice;

    printf("Product details updated successfully!\n");
}

void delete_products() {
    system("cls");
    char find_ID[10];
    bool flag = false;
    printf("***Store Management System Using C***\n");
    printf("\n====== PRODUCT DELETE ======\n");
    printf("Enter the ID of the Product: ");
    fgets(find_ID, sizeof(find_ID), stdin);
    find_ID[strcspn(find_ID, "\n")] = '\0';

    for (int i = 0; i < productCount; i++) {
        if (strcmp(find_ID, products[i].productId) == 0) {
            printf("Product found\n");
            printf("Are you sure you want to delete the existing product?\n");
            printf("[1] Yes\n");
            printf("[2] No\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            fflush(stdin);
            printf("\n");

            if (choice == 2) {
                printf("Aborting...\n");
                return;
            }

            flag = true;
            for (int j = i; j < productCount - 1; j++) {
                products[j] = products[j + 1];
            }
            productCount--;

            printf("Product deleted successfully!\n");
            break;
        }
    }
    if (flag == false) {
        printf("Product not found!\n");
    }
    return_options();
}

void search_products() {
    system("cls");
    char keyword[100];
    bool found = false;

    printf("***Store Management System Using C***\n");
    printf("\n====== PRODUCT SEARCH ======\n");
    printf("Enter keyword to search for Product Name: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = 0;
    for (int i = 0; keyword[i]; i++) {
        keyword[i] = tolower(keyword[i]);
    }
    printf("\n======================== SEARCH RESULTS ========================\n");
    printf("+------------+------------+------------+----------+--------+\n");
    printf("| ProductID  | CategoryID | ProductName | Quantity | Price  |\n");
    printf("+------------+------------+------------+----------+--------+\n");
    for (int i = 0; i < productCount; i++) {
        char lowerName[sizeof(products[i].productName)];
        strcpy(lowerName, products[i].productName);
        for (int j = 0; lowerName[j]; j++) {
            lowerName[j] = tolower(lowerName[j]);
        }

        if (strstr(lowerName, keyword) != NULL) {
            printf("| %-10s | %-10s | %-10s | %-8d | %-6d |\n",
                   products[i].productId, products[i].categoryId, products[i].productName,
                   products[i].quantity, products[i].price);
            printf("+------------+------------+------------+----------+--------+\n");
            found = true;
        }
    }

    if (!found) {
        printf("| %-55s |\n", "No products found with the given keyword.");
        printf("+-------------------------------------------------------------+\n");
    }

    printf("================================================================\n");
    return_options();
}

void products_sort() {
    int SortType;

    system("cls");
    printf("***Store Management System Using C***\n");
    printf("\n========== PRODUCT PRICE SORTING =========\n");
    printf("Sort products by Price: \n");
    printf("\n==========================================\n");
    printf("[1] Ascending (Low to High)\n");
    printf("[2] Descending (High to Low)\n");
    printf("[0] Return\n");
    printf("Enter your choice: ");
    scanf("%d", &SortType);
    fflush(stdin);
    printf("\n");

    switch (SortType) {
        case 1:
            products_sort_action(1);
        break;
        case 2:
            products_sort_action(2);
        break;
        case 0:
            return_options();
        break;
        default:
            printf("Invalid choice! Try again!\n");
            products_sort();
    }

    printf("Products sorted successfully!\n");
    view_products();
}

void products_sort_action(int order) {
    Product temp;
    for (int i = 0; i < productCount; i++) {
        for (int j = 0; j < productCount - i - 1; j++) {
            if (order == 1 && products[j].price > products[j + 1].price) {
                temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
            if (order == 2 && products[j].price < products[j + 1].price) {
                temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
}

void exit_program() {
    save_categories();
    save_products();
    system("cls");
    printf("========================================\n");
    printf("%22s\n", "Thank You");
    printf("========================================\n");
    printf("%24s\n", "See You Soon");
    printf("========================================\n");
    Sleep(2000);
    exit(1);
}
