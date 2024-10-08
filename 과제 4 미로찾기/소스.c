#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int num;
int n, m;
int entrance_set = 0; 
int exit_set = 0; 

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

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && (map[nx][ny] >= 0)) {
                    if (map[nx][ny] == 0 || map[nx][ny] > (count + 1)) {
                        map[nx][ny] = count + 1;
                        push(nx, ny, count + 1);

                        for (int ii = 0; ii < n; ii++) {
                            for (int iii = 0; iii < m; iii++) {
                                if (map[iii][ii] == -1) fprintf(outputFile, "1 ");
                                else if (map[iii][ii] == -2) fprintf(outputFile, "0 ");
                                else if (map[iii][ii] == -3) fprintf(outputFile, "0 ");
                                else fprintf(outputFile, "%d ", map[iii][ii]);
                            }
                            fprintf(outputFile, "\n");
                        }
                        fprintf(outputFile, "\n");
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

        if (nx >= 0 && ny >= 0 && nx < m && ny < n && map[nx][ny] >= 0) {
            if (map[nx][ny] == 0 || map[nx][ny] > (move + 1)) {
                map[nx][ny] = move + 1;
                for (int ii = 0; ii < n; ii++) {
                    for (int iii = 0; iii < m; iii++) {
                        if (map[iii][ii] == -1) fprintf(outputFile, "1 ");
                        else if (map[iii][ii] == -2) fprintf(outputFile, "0 ");
                        else if (map[iii][ii] == -3) fprintf(outputFile, "0 ");
                        else fprintf(outputFile, "%d ", map[iii][ii]);
                    }
                    fprintf(outputFile, "\n");
                }
                fprintf(outputFile, "\n");
                DFS(nx, ny, map, move + 1, outputFile);
            }
        }
        else if (map[nx][ny] == -3) {
            fprintf(outputFile, "DFS result:%d\n", move + 1);
            return 0;
        }
    }
}

int is_outer_wall(int x, int y) {
    return (x == 0 || y == 0 || x == m - 1 || y == n - 1);
}

int main(int argc, char* argv[]) { // -2 입구, -3 출구
    front = NULL;
    tail = NULL;
    num = 0;
    int x = -1, y = -1; 
    int map1[99][99];
    int map2[99][99];

    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE* outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    char line[256];
    m = 0;
    n = 0;

    while (fgets(line, sizeof(line), inputFile)) {
        if (n == 0) {
            char* token = strtok(line, " ");
            while (token != NULL) {
                m++;
                token = strtok(NULL, " ");
            }
        }
        n++; 
    }

    rewind(inputFile);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(inputFile, "%d", &map1[j][i]);

            if (map1[j][i] == 0 && is_outer_wall(j, i)) {
                if (!entrance_set) {
                    map1[j][i] = -2; 
                    x = j;  
                    y = i;
                    push(x, y, 0); 
                    entrance_set = 1;
                }
                else if (!exit_set) {
                    map1[j][i] = -3;  
                    exit_set = 1;
                }
            }
        }
    }
    fclose(inputFile);

    memcpy(map2, map1, sizeof(map1));  
    BFS(map1, outputFile);
    fprintf(outputFile, "\n");
    DFS(x, y, map2, 0, outputFile);

    fclose(outputFile);
    return 0;
}
