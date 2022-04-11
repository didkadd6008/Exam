#include <stdio.h>
#include <stdint.h>

#define CNT 3


typedef struct Item
{
    int16_t number;
    char description[250];
    double weight;
    double price;
}Item;

typedef struct noded {
    Item data;
    struct noded* next;
} node_dll;

void push(node_dll** head, Item data){
    node_dll* node = malloc(sizeof(node_dll));
    node->data = data;
    node->next = *head;
    *head=node;
}


node_dll *minPriceItem(node_dll*,node_dll**);

double getPrice(){
     double price[]={10.0,2.5,7.86,9.0,13.8,12.99,3.50,4.0,9.75,11};
    double price1 = price[rand()%10+0];
    return price1;
}

double getWeight(){
     double weight[]={10.0,2.5,7.86,9.0,13.8,12.99,3.50,4.0,9.75,11};
    double weight1 = weight[rand()%10+0];
    return weight1;
}
int main(){
    node_dll* head = NULL;
    for (int i = 0; i < CNT; i++)
    {
        Item item;
        item.price = getPrice();
        item.weight = getWeight();

        push(&head,item);


    }
    



}



double totalItemsWeight(node_dll* items){
double sum = 0;
double num = items->data.weight;
for (int i = 0; i < CNT; i++)
{
    sum += num;
    num=items->next->data.weight;
    
}
return sum;
}

node_dll *minPriceItem(node_dll* items,node_dll** head){
    
    node_dll* minprice;
    node_dll* current = head;
    node_dll* next = items->next;
    double first = current->data.price;
    double second = current->next->data.price;
    for (int i = 0; i < CNT; i++)
    {
        if (first < second)
        {
            minprice = &current;
        }else{
            minprice= &next;
        }
        

        first = items->next->data.price;
        second = items->next->next->data.price;
        current= current->next;
        next = next->next->next;
    }
    return minprice;
}