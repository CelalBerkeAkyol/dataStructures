// linked list ile stack kullanımı
#include <stdio.h>
#include <stdlib.h>

// Genel yapı
struct node
{
    int data;
    struct node *next;
} *top = NULL;

// fonksiyonlar
void push()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Eklemek istediğiniz değer nedir ? ");
    int data = 0;
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = NULL;
    // top elementin güncellenmesi burada yapılıyor
    newNode->next = top;
    top = newNode;
}
void pop()
{
    struct node *tmp = top;
    int value = tmp->data;
    top = top->next;
    free(tmp);
    tmp = NULL;
    printf("%d değeri silindi\n", value);
}
void show()
{
    struct node *ptr = top;

    while (ptr !=NULL)
    {
        printf("%d\n", ptr->data);
    ptr = ptr->next;
    }
    
    
}
int main()
{
    int choose;
    while (1)
    {

        printf("Aşağıdaki şıklardan birini seçiniz.");
        printf("\n [1] = Yeni eleman ekle \n [2] = eleman sil \n [3] = elemanları yazdır \n [4] = Programı sonlandır\n");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(1);
            break;

        default:
            printf("Böyle bir seçenek bulunmamaktadır.");
            break;
        }
    }
}
