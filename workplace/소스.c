#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	char s[999];
	while (1) {
		int count = 0;
		printf("Enter a parens>> ");
		scanf_s("%s", &s, 999);
		if (!strcmp(s, "quit")) break;
		for (int i = 0; s[i] != '\0'; i++) {
			if (count < 0) break;
			if (s[i] == '(') {
				count++;
			}
			else if (s[i] == ')') {
				count--;
			}
		}
		if (count == 0) printf("Result >> Matched\n");
		else printf("Result >> Unmatched\n");
	}
}