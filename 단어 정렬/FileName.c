#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char word[99];
    int n;
	struct node* next;
} node;

node* tail;   // tail -> next;

int push(char tmp[99]) {
	    node* newnode = (node*)malloc(sizeof(node));
		strcpy(newnode->word, tmp);
		newnode->n = 1;
	if (tail == NULL) {
		newnode->next = NULL;
		tail = newnode;
	}
	else{
		node* cur = tail;
		node* pre = NULL;
		while (1) {
			if (strcmp(cur->word, tmp) > 0) {
				 if (pre == NULL) {
					 newnode->next = cur;
					 tail = newnode;
					 return 1;
				}
				else {
					 newnode->next = cur;
					 pre->next = newnode;
					 return 1;
				}
			}
			else if (strcmp(cur->word, tmp) == 0) {
				cur->n++;
				return 1;
			}
			else if (cur == NULL) {
				newnode->next = NULL;
				pre->next = newnode;
				return 1;
		    }
			pre = cur;
			cur = cur->next;
		}	
	}
}

void main() {
	tail = NULL;
	FILE* input = fopen("data.txt", "r");
	char word[99];
	while (fscanf(input, "%s", word) != EOF) {
		push(word);
	}
	node* cur = tail;
	while (cur != NULL) {
		printf("%s(%d) ", cur->word, cur->n);
		cur = cur->next;
	}

	

}
