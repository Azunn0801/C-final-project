//
// Created by Azunn on 07/02/2025.
//

#ifndef FUNCTION_H
#define FUNCTION_H

#include "../include/datatype.h"

//Menu interfaces
void exit_program();
void entry_menu();
void log_in_menu();
void category_menu();
void product_menu();

//Category management functions
void add_category();
void viewCategories();
void return_options(void (*callback)());
void edit_category();
void change_category_name(int x);
void delete_category();
void categories_sort_options();
void categories_sort_action(int order);
void search_categories();
void searchString(Category arr[], int n, char keyword[]);


//Product manangement function
void add_product();
void edit_products();
void view_products();
void search_products();
void products_sort();
void delete_products();
void products_sort_action(int order);
void change_product_details(int index);

// File functions
void load_file(const char *file_name, const char *mode);
void save_categories();
void save_products();
void load_account();
void load_auth_data();
void save_auth_data();

#endif //FUNCTION_H
