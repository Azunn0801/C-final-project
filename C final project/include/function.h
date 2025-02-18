//
// Created by Azunn on 07/02/2025.
//

#ifndef FUNCTION_H
#define FUNCTION_H

#include "../include/datatype.h"

void exit_program();
void entry_menu();
void log_in_menu();
void category_menu();
void add_category();
void viewCategories();
void return_options();
void edit_category();
void change_category_name(int x);
void delete_category();
void read_file(const char *file_name);
void write_file(char file_name[]);
void categories_list(int count, FILE *file);
void products_list(int count, FILE *file);
void nothing_found_message();
void categories_sort_options();
void categories_sort_action(int order);
bool category_write();
void search_categories();
void searchString(Category arr[], int n, char keyword[]);
void product_menu();


//Product manangement function
void add_product();
void delete_product();
void edit_products();
void viewproducts();
void search_products();
void product_sort();
void delete_products();

// File functions
void load_file(const char *file_name, const char *mode);
void save_categories();
void save_products();

#endif //FUNCTION_H
