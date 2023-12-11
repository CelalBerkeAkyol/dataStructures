#include <stdio.h>
#include <stdlib.h>
int data, sira_y; // kullanıcan değer isterken atanan değişken, ve sıra
// node adında yapı oluşturuldu
struct node
{
    int data;
    struct node *next;
};
// düğüm oluşturma fonksiyonu
struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}
// düğümü yazdırma fonksiyonu
void printNode(struct node *head_ref)
{
    struct node *ptr = head_ref;
    if ( head_ref == NULL)
    {
        printf("Bu liste boş");
    }

    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
// ekleme fonksiyonları burada bulunuyor
// başa yeni eleman ekleme fonksiyonu
void basaEkle(struct node **head_ref, int data)
{
    struct node *newNode = createNode(data);
    newNode->next = *head_ref;
    *head_ref = newNode;
}
// sona eleman ekleme fonksiyonu
// ptr to ptr kullanmayınca hiç eleman yokken eleman yükleyince hata veriyordu düzeltildi
void sonaEkle(struct node **head_ref, int data)
{
    struct node *newNode = createNode(data);
    struct node *ptr = *head_ref;
    if (*head_ref == NULL)
    {
        *head_ref = newNode;
        return;
    }
    else
    {
        while (ptr->next == NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}
// araya ekleme fonksiyonu ( değer ile araya ekleme yapılıyor sıra ile değil )
void arayaEkle(struct node *head_ref, int data, int y)
{
    struct node *newNode = createNode(data);
    struct node *ptr = head_ref;
    // y değeri = hangi araya ekleneceğini belirleyen değer
    while (ptr->data != y)
    {
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}
// silme fonksiyonları burada bulunuyor
// baştan silme fonksiyonu
void bastanSil(struct node **head_ref)
{
    struct node *tmp = *head_ref;
    if (*head_ref == NULL)
    {
        printf("Bu dizi boş eleman silemezsiniz");
        return;
    }
    
    *head_ref = tmp->next;
    free(tmp);
}
// aradan silme fonksiyonu
void aradanSil(struct node *head_ref, int y)
{
    // y değeri aradan silinecek değer için referans olmakta
    struct node *tmp = head_ref;
    struct node *tmp2;
    while (tmp->next->data != y)
        tmp = tmp->next;
    tmp2 = tmp->next;
    tmp->next = tmp->next->next;
    free(tmp2);
}
void sondanSil(struct node *head_ref)
{
    struct node *tmp = head_ref;
    if (tmp == NULL)
    {
        printf("Bu dizide eleman bulunmuyor eleman silemezsiniz");
        return;
    }
    // eğer bir eleman varsa ve sondan silme fonk çağrılırsa hata verir bu yüzden baştan silme fonksiyounu çağırdım.
    else if (tmp->next == NULL)
    {
        bastanSil(&head_ref);
    }

    else
    {
        while (tmp->next->next != NULL)
            tmp = tmp->next;
        free(tmp->next);
        tmp->next = NULL;
    }
}
void tersCevir(struct node **head_ref)
{
    struct node *tmp, *tmp2, *tmp3;
    tmp = *head_ref;
    tmp2 = NULL;
    while (tmp != NULL)
    {
        tmp3 = tmp2;
        tmp2 = tmp;
        tmp = tmp->next;
        tmp2->next = tmp3;
        *head_ref = tmp2;
    }
}

int main()
{

    struct node *head = NULL; // head referansı
    int choice;
    while (1)
    {
        printf("\n***Hangi işlemi yapmak istersiniz ? ***\n");
        printf(" {0} programdan çıkmak \n {1} Başa eleman eklemek \n {2} Baştan eleman silmek \n {3} Sona eleman eklemek \n {4} Sondan eleman silmek \n {5} araya eleman eklemek\n {6} aradan eleman silmek\n {7} terse çevirmek\n {8} Elemanları listelemek\n ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(EXIT_SUCCESS);
            break;
        case 1:
            printf("Eklemek istediğiniz değer nedir ?");
            scanf("%d", &data);
            basaEkle(&head, data);
            break;
        case 2:
            bastanSil(&head);
            break;
        case 3:
            printf("Eklemek istediğiniz değer nedir ?");
            scanf("%d", &data);
            sonaEkle(&head, data);
            break;
        case 4:
            sondanSil(head);
            break;
        case 5:
            printf("Eklemek istediğiniz değer nedir ?");
            scanf("%d", &data);
            printf("Eklemek istediğiniz sıra değeri nedir ?");
            scanf("%d", &sira_y);
            arayaEkle(head, data, sira_y);
            break;
        case 6:
            aradanSil(head, sira_y);
            break;
        case 7:
            tersCevir(&head);
            break;
        case 8:
            printNode(head);
            break;

        default:
            printf("Lütfen doğru değer giriniz");
            break;
        }
    }
}
