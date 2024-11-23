/*
1153 1929 2581
10988 1316 25206
28278 18258 2164
10773 9012
2745 10811 11659
26069 1037
25192 2444
*/

/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//2444  별찍기
int main() {
   int N, x = 1, i = 0;
   scanf("%d", &N);
   for (i; i < N; i++) {
      for (int j = 1; j < N-i; j++)printf(" ");
      for (int jj = 0; jj < 2*i+1; jj++)printf("*");
      printf("\n");
   }
   i--;
   i--;
   for (i; i >= 0; i--) {
      for (int j = 1; j < N-i; j++)printf(" ");
      for (int jj = 0; jj < 2*i+1; jj++)printf("*");
      if (i != 0) printf("\n");
   }
   return 0;
}*/
/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//10811 바구니 뒤집기
int main() {
   int N, M, i, j;
   int arr[999];
   scanf("%d %d", &N, &M);
   for (int x = 1; x <= N; x++) arr[x] = x;
   while (M--) {
      int tmp;
      scanf("%d %d", &i, &j);
      while (i < j) {
         tmp = arr[j];
         arr[j] = arr[i];
         arr[i] = tmp;
         i++;
         j--;
      }
   }
   for (int x = 1; x <= N; x++)printf("%d ", arr[x]);
}*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//10773 제로
int main() {
   int k, x, count=0, sum=0;
   int arr[99999];
   scanf("%d", &k);
   while (k--) {
      scanf("%d", &x);
      if (x == 0) {
         if (count == 0);
         else {
            count--;
            sum -= arr[count];
         }
         }
      else {
         sum += x;
         arr[count] = x;
         count++;
      }
   }
   printf("%d", sum);
   return 0;
}*/
/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//11659 부분합
int main() {
   int N, M, x, i, j;
   int arr[100001];
   arr[0] = 0;
   scanf("%d %d", &N, &M);
   for(int c=1; c<=N; c++) {
      scanf("%d", &x);
      arr[c] = arr[c - 1] + x;
   }
   while (M--) {
      scanf("%d %d", &i, &j);
      printf("%d\n", arr[j] - arr[i-1]);
   }
}*/

/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
  // 9012 괄호
int main() {
   int N, x;
   char arr[999];
   scanf("%d", &N);
   for (int i = 0; i < N; i++) {
      x = 0;
      scanf("%s", arr);
      for (int j = 0; arr[j] != '\0'; j++) {
         if (arr[j] == '(') {
            x++;
         }
         else if (arr[j] == ')') {
            x--;
         }
         if (x < 0) goto END;
      }
      if (x == 0) printf("YES\n");
      else END: printf("NO\n");
   }
} */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//25192 인사성 곰
int main() {
    int N;
    int x;
    char arr[99][999];
    scanf("%d", &N);
    while (N--) {
        scanf("%s", arr[x][999]);
        if (!strcmp(arr[x], "ENTER")) {
            for (int i = ; i < x - 1; i++) {
                if (strcmp(arr[x], arr[x + 1]) > 0) {

                }
            }
            x = 0;
        }
        else {
            x++;

        }
    }
}