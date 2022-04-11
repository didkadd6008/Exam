#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct etw
{
    char name[10];
    int rowNumber;
    char nums[20];
}etw;


typedef struct noded {
    etw data;
    struct noded* next;
} node_dll;

void push(node_dll** head, etw data){
    node_dll* node = malloc(sizeof(node_dll));
    node->data = data;
    node->next = *head;
    *head=node;
}

void sort(node_dll* head,int n){
 node_dll* current = head;
int num1 = current->data.nums;
     int num2 = current->data.nums
  for (int i = 0; i < n; i++)
  {
     
     if (num2)
     {
         /* code */
     }
     
  }
  
}

int main(){
   node_dll* head = NULL;
    int m,n;
    scanf("%d %d\n",m,n);
    for (int i = 0; i < n; i++)
    {
        etw s;
    scanf("%s",s.name);
   scanf("d",s.rowNumber);
   if (s.rowNumber<0 || s.rowNumber>n)
   {
       printf("Invalid input!");
       return EXIT_FAILURE;
   }
   
    
    
    for (size_t i = 0; i < m; i++)
    {
        scanf("%c",s.nums[i]);
    }
    }
    
  
    return EXIT_SUCCESS;
    
}

