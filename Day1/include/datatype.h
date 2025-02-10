//
// Created by Azunn on 07/02/2025.
//

#ifndef DATATYPE_H
#define DATATYPE_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CATEGORIES 10

extern int choice;
extern char email[];
extern char password[];
extern char email_in[100];
extern char password_in[64];

extern struct Date {
    int month, day, year;
};

extern struct Category {
    char CategoryId[10];
    char CategoryName[10];
};

extern struct Product {
    char productId[10];
    char categoryId[10];
    char productName[10];
    int quantity;
    int price;
};

extern struct Order {
    char orderId[10];
    char customerId[20];
    struct Date date;
    struct Product product;
};
#endif //DATATYPE_H
