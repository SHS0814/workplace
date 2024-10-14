#include <stdio.h>

void main() {
	int n;
	while (1) {
		scanf_s("%d", &n);
		if (n == 0) break;
		for (int i = 2; i <= n; i++) {
			int x = 0;
			while (n % i == 0) {
				n /= i;
				x++;
			}
			if (x != 0) {
				printf("%d^%d", i, x);
				if (n != 1) printf("*");
			}
		}
		printf("\n");
	}

}