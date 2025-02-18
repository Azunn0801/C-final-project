//
// Created by Azunn on 07/02/2025.
//

#ifndef DATATYPE_H
#define DATATYPE_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX_LENGTH 100
#define EMAIL_SIZE 50
#define PASSWORD_SIZE 50

extern int choice;
extern const char email[];
extern const char password[];
extern char email_in[50];
extern char password_in[50];

typedef struct Date {
    int month, day, year;
};

typedef struct Category {
    char CategoryId[10];
    char CategoryName[10];
} Category;

typedef struct Product {
    char productId[10];
    char categoryId[10];
    char productName[10];
    int quantity;
    int price;
} Product;

typedef struct Order {
    char orderId[10];
    char customerId[20];
    struct Date date;
    struct Product product;
};

typedef struct {
    char email[EMAIL_SIZE];
    char password[PASSWORD_SIZE];
} AuthData;

#endif //DATATYPE_H
