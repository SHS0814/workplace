
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int n;
    struct node* next;
} node;

node* tail;

int main() {
    while (1) {
        tail = NULL;
        int arr[999];
        int i = 0;

        while (1) {
            printf("Enter integers>> ");
            scanf_s("%d", &arr[i]);
            if (arr[i] == -1) break;
            i++;
        }
        if (i == 0 && arr[0] == -1) break;

        for (int j = 0; arr[j] != -1; j++) {
            if (tail == NULL || tail->n >= arr[j]) {
                node* newnode = (node*)malloc(sizeof(node));
                newnode->n = arr[j];
                newnode->next = tail;
                tail = newnode;
            }
            else {
                node* cur = tail;
                node* pre = NULL;
                while (cur != NULL && cur->n < arr[j]) {
                    pre = cur;
                    cur = cur->next;
                }

                node* newnode = (node*)malloc(sizeof(node));
                newnode->n = arr[j];
                newnode->next = cur;
                if (pre != NULL) {
                    pre->next = newnode;
                }
            }

            node* cur = tail;
            while (cur != NULL) {
                printf("%d(%p) ", cur->n, (void*)cur);
                cur = cur->next;
            }
            printf("\n");
        }
    }

    return 0;
}
