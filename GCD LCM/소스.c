#include <stdio.h>
#include <stdlib.h>

int count;

int* pn(int n) {
	printf("Prime numbers: ");
	int arr[999];
	int pn[999];
	count = 0;
	arr[0] = arr[1] = 0;
	for (int i = 0; i <= n; i++) {
		if (arr[i]) {
			printf("%d ", i);
			pn[count] = i;
			count++;
			for (int j = i; j <= n; j += i) {
				arr[j] = 0;
			}
		}
	}
	printf("\n");
	return pn;
}

int devi(int* pn, int a, int b) {
	int n = 1;
	printf("(%d, %d, %d) ", n, a, b);
	for (int i = 0; i < count; i++) {
		while (a % pn[i] == 0 && b % pn[i] == 0) {
			a /= pn[i];
			b /= pn[i];
			n *= pn[i];
			printf("(%d, %d, %d) ", n, a, b);
		}
	}
	printf("\n");
	return n;
}

int LCM(int a, int b) {
	int n = (a < b) ? a : b;
	int d = 0;
	while (!((d % a == 0 && d % b == 0) && (n <= d)))
	{
		d++;
	}
	return d;
}

void main() {
	while (1) {
		int a, b;
		printf("Enter two integers>> ");
		scanf_s("%d %d", &a, &b);
		if (a == 0 && b == 0) break;
		printf("GCD=%d, LCM=%d\n\n", devi(pn((a < b) ? a : b), a, b), LCM(a, b));
	}

}