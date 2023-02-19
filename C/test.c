#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void GO(int maxrow, int maxcol, int row, int col, char (*graph)[maxcol]) {
    graph[row][col] = '1';
    if (row + 1 < maxrow && graph[row + 1][col] == '0') {
        GO(maxrow, maxcol, row + 1, col, graph);
    }
    if (col + 1 < maxcol && graph[row][col + 1] == '0') {
        GO(maxrow, maxcol, row, col + 1, graph);
    }
    if (row - 1 >= 0 && graph[row - 1][col] == '0') {
        GO(maxrow, maxcol, row - 1, col, graph);
    }
    if (col - 1 >= 0 && graph[row][col - 1] == '0') {
        GO(maxrow, maxcol, row, col - 1, graph);
    }
    return;
}


int main() {
    int row, col;
    scanf("%d %d", &row, &col);
    char graph[row][col];
    for (int a = 0; a < row; a++) {
        for (int b = 0; b < col; b++) {
            graph[a][b] = '0';
        }
    }

    for (int a = 0; a < row; a++) {
        scanf("%s", graph[a]);
    }
    
    GO(row, col, 0, 0, graph);

    if (graph[row - 1][col - 1] == '1') {
        printf("Yes\n");
    }else {
        printf("No\n");
    }
    return 0;
}