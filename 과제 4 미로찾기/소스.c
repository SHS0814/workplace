#include <stdio.h>
#include <stdlib.h>

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int num;
int n, m;

typedef struct node {
    int x, y, n;
    struct node* next;
}node;

node* front;

int empty() {
    return num;
}

void push(int x, int y, int n) {

}

void pop() {

}

void DFS(int** map) {
    int i, j;
    while (empty()) {
        int size = num;

        for (int i = 0; i < size; i++) {
            int x = front->x;
            int y = front->y;
            int count = front->n;
            pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (map[nx][ny] == 0) {
                    map[nx][ny] = 1;
                    push(nx, ny, count + 1);
                }
                else if (map[nx][ny] == 3) {
                    printf("%d\n", count + 1);
                }
            }
        }
    }

}

void BFS(int x, int y, int map[][99], int move) {
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx >= 0 && ny >= 0 && nx < m && ny < n && map[nx][ny] == 0) {
            map[nx][ny] = 1;
            BFS(nx, ny, map, move + 1);
        }
        else if (map[nx][ny] == 3) {
            printf("%d\n", move + 1);
        }
    }
}


void main() {  // 2 입구  3 출구
    int x, y;
    int map[99][99];
    scanf_s("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%d", &map[j][i]);
            if (map[j][i] == 2) {
                x = j;
                y = i;
                //push(x, y, 0);
            }
        }
    }
    //DFS(map);
    BFS(x, y, map, 0);
}