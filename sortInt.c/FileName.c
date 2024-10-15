#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(int argc, char* argv[]) {
	int arr[99];
	int tmp;
	for (int i = 1; i < argc; i++) arr[i] = atoi(argv[i]);
	for (int i = 1; i < argc; i++) {
		for (int j = i; j < argc; j++) {
			if (arr[i] > arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	for (int i = 1; i < argc; i++) printf("%d ", arr[i]);
}