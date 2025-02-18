#include "include/datatype.h"
#include "include/function.h"

int choice;
bool FileState = true;

int main(void) {
    load_file("data/category.bin", "rb");
    load_file("data/product.bin", "rb");
    Sleep(2000);
    //system("cls");

    //log_in_menu();
    entry_menu();
    return 0;
}
