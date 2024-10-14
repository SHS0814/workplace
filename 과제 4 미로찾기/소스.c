#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int num;
int n = 0, m = 0;
int entrance = 0;
int exitance = 0;

typedef struct node {
    int x, y, n;
    struct node* next;
} node;

node* front;
node* tail;

int empty() {
    return num;
}

void push(int x, int y, int n) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->x = x;
    newnode->y = y;
    newnode->n = n;
    newnode->next = NULL;
    if (front == NULL) {
        front = newnode;
    }
    else if (front->next == NULL) {
        front->next = newnode;
    }
    else {
        tail->next = newnode;
    }
    tail = newnode;
    num++;
}

void pop() {
    node* tmp;
    tmp = front;
    front = front->next;
    free(tmp);
    num--;
}

void print(int map[][99], FILE* outputFile) {
    for (int ii = 0; ii < n; ii++) {
        for (int iii = 0; iii < m; iii++) {
            if (map[iii][ii] == -2) fprintf(outputFile, "0 ");
            else if (map[iii][ii] == -3) fprintf(outputFile, "0 ");
            else fprintf(outputFile, "%d ", map[iii][ii]);
        }
        fprintf(outputFile, "\n");
    }
    fprintf(outputFile, "\n");
}

int BFS(int map[][99], FILE* outputFile) {
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

                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    if (map[nx][ny] >= 0 || map[nx][ny] > (count + 1)) {
                        map[nx][ny] = count + 1;
                        push(nx, ny, count + 1);
                        print(map, outputFile);
                    }
                }
                else if (map[nx][ny] == -3) {
                    fprintf(outputFile, "BFS result: %d\n", count + 1);
                    return 0;
                }
            }
        }
    }
    return -1;
}

void DFS(int x, int y, int map[][99], int move, FILE* outputFile) {
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
            if (map[nx][ny] >= 0 || map[nx][ny] > (move + 1)) {
                map[nx][ny] = move + 1;
                print(map, outputFile);
                DFS(nx, ny, map, move + 1, outputFile);
            }
        }
        else if (map[nx][ny] == -3) {
            fprintf(outputFile, "DFS result:%d\n", move + 1);
        }
    }
}

int main(int argc, char* argv[]) {
    front = NULL;
    tail = NULL;
    num = 0;
    int x = -1, y = -1;
    int map1[99][99];
    int map2[99][99];

    if (argc < 3) {
        printf("%s\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("error input\n");
        return 1;
    }

    FILE* outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("error output\n");
        return 1;
    }

    char line[999];
    int n1 = 0;

    while (fgets(line, sizeof(line), inputFile)) {
        if (m == 0) {
            m = strlen(line) - 1;
        }
        n1++;
    }

    rewind(inputFile);
    n = 0;

    while (fgets(line, sizeof(line), inputFile)) {
        for (int j = 0; j < m; j++) {
            map1[j][n] = line[j] - '0';

            if (map1[j][n] == 0 && (j == 0 || n == 0 || j == m - 1 || n == n1 - 1)) {
                if (!entrance) {
                    map1[j][n] = -2;
                    x = j;
                    y = n;
                    push(x, y, 0);
                    entrance = 1;
                }
                else if (!exitance) {
                    map1[j][n] = -3;
                    exitance = 1;
                }
            }
        }
        n++;
    }

    fclose(inputFile);

    memcpy(map2, map1, sizeof(map1));
    BFS(map1, outputFile);
    fprintf(outputFile, "\n");
    DFS(x, y, map2, 0, outputFile);

    fclose(outputFile);
    return 0;
}
