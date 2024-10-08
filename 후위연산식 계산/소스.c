#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void main() {
	while (1) {
		char s[999];
		float stack[999];
		int count = 0;
		printf("Enter a postfix expression>> ");
		fgets(s, 999, stdin);
		s[strcspn(s, "\n")] = '\0';
		if (!strcmp(s, "0")) break;
		int i;
		for (i = 0; s[i] != '\0'; i++) {
			if (s[i] == ' ')continue;
			else if (isdigit(s[i])) {
				int n = 0;
				while (isdigit(s[i])) {
					n *= 10;
					n += (s[i] - '0');
					i++;
				}
				i--;
				stack[count] = n;
				count++;
			}
			else {
				if (count < 2) goto END;
				count--;
				float a = stack[count];
				count--;
				float b = stack[count];
				switch (s[i])
				{
				case '+': stack[count] = a + b; break;
				case '-': stack[count] = a - b; break;
				case '*': stack[count] = a * b; break;
				case '/': stack[count] = a / b; break;
				}
				count++;
			}
		}
		if (count > 1) END: printf("Invaild expression\n");
		else printf("%f\n", stack[count - 1]);
	}
}