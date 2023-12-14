#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5
#define TOP_EMPTY -1
int top = TOP_EMPTY;
int stack_array[MAX];
int data; // silinen değeri saklayan değişken
// fonksiyon tanımları
bool isFull();
void push();
int pop();
void peek();
void show();

int main()
{
    int choice;

    while (1)
    {
        printf("\n***Hangi işlemi yapmak istersiniz ? ***\n");
        printf(" {0} programdan çıkmak \n {1} eleman eklemek \n {2} eleman silmek \n {3} en son elemanın değeri? \n {4} stack dolu mu ? \n {5} Tüm elemanları göster\n ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(EXIT_SUCCESS);
            break;
        case 1:
            push();
            break;
        case 2:
            data = pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            isFull();
            break;
        case 5:
            show();
            break;

        default:
            printf("Lütfen doğru değer giriniz");
            break;
        }
    }
}
bool isFull()
{
    if (top == MAX - 1)
    {
        printf("Stack dolu");
        return true;
    }
    else{
        printf("Stack boş");
                return false;

    }
}

void push()
{
    if (top == MAX - 1) // isFull fonks parametre olarak verdiğimde stack boşken stack dolu uyarısı veriyor bunun sebebini açıklar mısınız ? 
    {
        printf("Stack overflow \n");
        return;
    }
    else
    {
        top++;
        printf("Hangi değeri girmek istersiniz \t:");
        scanf("%d",&data);
        stack_array[top] = data;
        printf("Eleman eklendi = %d",data);
    }
}
int pop()
{
    if (top == TOP_EMPTY)
    {
        printf("Stack underflow");
        exit(EXIT_FAILURE);
    }
    else
    {
        data = stack_array[top];
        top--;
        return data; // silinen data
        printf("Eleman silindi = %d",data);
    }
}
void peek(){
    printf("En son elemanın değeri = %d \n",stack_array[top]);
}
void show(){
    for (int i = top; i>= 0; i--)
    {
        printf("%d\n",stack_array[i]);
    }
    
}
