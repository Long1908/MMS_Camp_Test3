#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char product_type_arr[4] = {'A', 'B', 'C', 'D'};
char* product_name_arr[] = {"prodOne", "prodTwoo", "prodThree"};

typedef struct Product {
    double old_price; //sizeof(double) = 8
    double new_price;
    unsigned int id; //sizeof(int) = 4
    char product_type;//sizeof(char) = 1
    char product_name[11];// 24 - (8 + 8 + 4 + 1) = 3;
} Product;

int compare_products(const void* product1, const void* product2) {
    const Product *prod1, *prod2;
    prod1 = product1;
    prod2 = product2;
    double difference_in_price = (prod2->new_price - prod2->old_price) - (prod1->new_price - prod1->old_price);
    if(fabs(difference_in_price < 0.01))
    {
        double difference_in_types = (int)prod2->product_type - (int)prod1->product_type;
        if(difference_in_price == 0)
        {
            double difference_in_names = strlen(prod2->product_name) - strlen(prod1->product_name);
            if(difference_in_names == 0)
            {
                return prod2->id - prod1->id;
            }
            return difference_in_names;
        }
        return difference_in_types;
    }
    return difference_in_price;
}

int main()
{
    Product productsArr[40];
    for(int i = 0; i < 40; i++)
    {
        (productsArr + i)->old_price = (499 +  rand() % (10045 - 499));
        (productsArr + i)->new_price = (499 +  rand() % (10045 - 499));
        (productsArr + i)->product_type = product_type_arr[rand() % 4];
        strcpy((productsArr + i)->product_name, product_name_arr[rand() % 3]);
        (productsArr + i)->id = i;
    }
    for(int i = 0; i < 40; i++)
    {
        printf("Product id: %u, name: %s, type: %c, with old price: %0.2lf and new price: %0.2lf\n", 
        (productsArr + i)->id, (productsArr + i)->product_name, (productsArr + i)->product_type, (productsArr + i)->old_price / 100, (productsArr + i)->new_price / 100);
    }
    int (*myComparator) (const void*, const void*);
    myComparator = compare_products;
    qsort(productsArr, 40, sizeof(Product),myComparator);
    printf("Sorted list of products: \n");
    for(int i = 0; i < 40; i++)
    {
        printf("Product id: %u, name: %s, type: %c, with old price: %0.2lf and new price: %0.2lf\n", 
        (productsArr + i)->id, (productsArr + i)->product_name, (productsArr + i)->product_type, (productsArr + i)->old_price / 100, (productsArr + i)->new_price / 100);
    }
    return 0;
}