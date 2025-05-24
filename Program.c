#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct elements{
    int info;
    struct elements *next;
};

struct elements *add ( struct elements *last, int item);
int shift (struct elements **tail, struct elements **head);

int main (){
    system ("chcp 65001");
    struct elements *head = NULL;
    struct elements *tail = NULL;

    int n;
    int button; 
    printf("Натисніть Enter -> Esc для зупинки!\n");
    while(1){
        printf("Введіть число ( після введення натисніть двічі Enter ): ");
        scanf("%d", &n);

        tail = add(tail, n);
        if(head == NULL){
            head = tail;
        }
        button = getch();
        if(button == 27){
            break;
        }
    }

    int max;
    int index = 0;
    int index_max;
    int flag = 1;
    while (head != NULL){
        int value = shift (&tail, &head);
        if(flag || value > max){
            max = value; 
            index_max = index;
            flag = 0;
        }
        index +=1;
    }
    printf("Максимальний елемент черги: %d\nНомер: %d", max, index_max+1);
    return 0;
}

struct elements *add ( struct elements *last, int item){
    struct elements *new;
    new = (struct elements*)malloc(sizeof(struct elements));
    if(new == NULL){
        printf("Помилка виділення пам'яті!");
        return NULL;
    }
    new -> info = item;
    new -> next = NULL; 
    if(last != NULL){
        last -> next = new;
    }
    return new;
}

int shift (struct elements **tail, struct elements **head){
    struct elements* first = *head; 
    int n = first -> info;
    *head = (**head).next;
    free(first);

    if(*head == NULL){
        *tail = NULL;
    }
    return n;
}