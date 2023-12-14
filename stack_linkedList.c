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
struct node *createNode()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Eklemek istediğiniz değer nedir ? ");
    int userİnput;
    scanf("%d", &userİnput);
    newNode->data = userİnput;
    newNode->next = NULL; // yeni düğüm tanımlandı
    return newNode;
}
void push()
{
    struct node *newNodeForPush = createNode(); // bu fonksiyonu kullanmak acaba doğru bir karar mı ? Yoksa bellekte fazladan bir yer mi kaplıyor ? Acaba bu fonk kullanmak yerine direkt kodları buraya yazmak daha mı mantıklı olur ?
    newNodeForPush->next = top;
    top = newNodeForPush;
}
void pop()
{
    if (top == NULL)
    {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    struct node *tmp = top;
    int value = tmp->data;
    top = top->next;
    free(tmp);
    tmp = NULL;
    printf("%d değeri silindi\n", value);
}
void show()
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    struct node *ptr = top;

    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
// En son değer gösterilir
void peek()
{
    printf("Son değer = %d \n", top->data);
}
int main()
{
    int choose;
    while (1)
    {

        printf("Aşağıdaki şıklardan birini seçiniz.");
        printf("\n [0] = Programı sonlandır \n [1] = Yeni eleman ekle \n [2] = eleman sil \n [3] = elemanları yazdır \n [4] = Son elemanı görüntüle \n \n");
        scanf("%d", &choose);
        switch (choose)
        {
        case 0:
            exit(1);
            break;
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
            peek();
            break;

        default:
            printf("Böyle bir seçenek bulunmamaktadır.");
            break;
        }
    }
}
