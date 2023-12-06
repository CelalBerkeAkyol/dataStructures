#include <stdio.h>
#include <stdlib.h>
// genel tanımlılar
int arr[20];
int top = -1;
// fonksiyonlar
void push(int data)
{
    top++;
    arr[top] = data;
}
void pop()
{
    top--;
}
void listele()
{
    for (int i = top; i >=0; i--)
    {
        printf("%d\n", arr[i]);
    }
}
int main()
{

    while (1)
    {
        printf("Hangi işlemi yapmak istersiniz ? \n {1} eleman eklemek \n {2} eleman silmek \n {3} listeyi görüntülemek\n {4} programı sonlandırmak");
        int secim;
        scanf("%d", &secim);
        switch (secim)
        {
        case 1:
            printf("Hangi değeri girmek isteersiniz");
            int deger; 
            scanf("%d",&deger);
            push(deger);
            break;
        case 2:
            pop();
            break;
        case 3:
            listele();
            break;
        case 4:
            exit(EXIT_SUCCESS); 
                        break;

        default:
            printf("Böyle bir seçenek bulunmamaktadır. ") ;
            break;
        }
    }
    return 0;
}
