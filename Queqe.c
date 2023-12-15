#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// kuyruk için sanal yapı oluşturuldu
struct Queqe
{
    int front, rear, size;
    unsigned capacity;
    int *array;
};
// yapıcı fonksiyon
struct Queqe *create(unsigned capacity)
{
    struct Queqe *q = (struct Queqe *)malloc(sizeof(struct Queqe));
    q->size = 0;
    q->capacity = capacity;
    q->front = 0;
    q->rear = capacity - 1;
    q->array = (int *)malloc(q->capacity * sizeof(int));
    return q;
}
int isFull(struct Queqe *qNesnesi)
{
    return (qNesnesi->capacity == qNesnesi->size);
    // kapasite size a eşitse 1 döndürür yani fulldür
}
int isEmpty(struct Queqe *qNesnesi)
{
    return (qNesnesi->size == 0);
    // eşitse 1 döndürür yani true (boştur)
    // eşit değilse 0 döndürür yani false (doludur )
}

// fonksiyonlar
void enque(struct Queqe *qNesnesi, int data)
{
    if (isFull(qNesnesi))
    {
        printf("Kuyruk full ekleme yapılamamaktadır");
        return;
    }
    // full değilse uygulanacak işlemler
    qNesnesi->rear = (qNesnesi->rear + 1) % qNesnesi->capacity;
    qNesnesi->array[qNesnesi->rear] = data; // datalar reardan eklenir fronttan çıkar
    qNesnesi->size = qNesnesi->size + 1;    // işlem tamamlandı
     printf("%d enqueued to queue\n", data);
    // adımlar : 1 - kuyruk dolu mu kontrol edilir 2- kuyruk boş ise ne kadar boş yer kaldığı bulunur 3- boş olan yerler data ile doldurulur 4- büyüklük 1 arttırılır
}
int deque(struct Queqe *qNesnesi)
{
    if (isEmpty(qNesnesi))
    {
        printf("Kuyruk boş bir eleman silinemez");
        return INT_MIN; 
    }
    int silinenDeger = qNesnesi->array[qNesnesi->front]; // öndeki eleman silinir 
    qNesnesi->front = (qNesnesi->front +1 ) % qNesnesi->capacity;
    qNesnesi->size = qNesnesi->size -1; 
    return silinenDeger; 
    // adımlar : 1- Kuyrukta eleman var mı kontrol edilir. 2- En baştaki eleman silinir 3-   4- size 2 azaltılır 5- silinen değer döndürülür 
    
}

int front(struct Queqe *qNesnesi)
{
    if (isEmpty(qNesnesi))
    {
        printf("Boş");
        return INT_MIN;
    }
    return qNesnesi->array[qNesnesi->front];
}
int rear(struct Queqe *qNesnesi)
{
    if (isEmpty(qNesnesi))
    {
        printf("Boş");
        return INT_MIN;
    }
    return qNesnesi->array[qNesnesi->rear];
    
}


int main()
{
     struct Queqe *que = create(20);
    enque(que,10);
    enque(que,20);
    enque(que,30);
    enque(que,40);
    printf("%d dequeued from queue\n\n",deque(que));
    printf("Front item is %d\n", front(que));
    printf("Rear item is %d\n", rear(que));
}
