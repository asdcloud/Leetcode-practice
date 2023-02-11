#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int impossiblenum = 99999;
        int row = grid.size();
        int col = grid[0].size();
        int ans = -1;
        int max = 0;
        int ones = 0;
        int zeros = 0;
        queue<int> q;
        for (int a = 0; a < row; a++) {
            for (int b = 0; b < col; b++) {
                if (grid[a][b] == 1) {
                    ones = 1;
                    q.push(a * 100 + b);
                }
                if (grid[a][b] == 0) {
                    zeros = 1;
                }
            }
        }
        if (ones == 0) {
            return -1;
        }
        if (zeros == 0) {
            return -1;
        }
        int distance[row][col];
        for (int a = 0; a < row; a++) {
            for (int b = 0; b < col; b++) {
                distance[a][b] = impossiblenum;
                if (grid[a][b] == 1) {
                    distance[a][b] = 0;
                }
            }
        }
        while(!q.empty()) {
            int tempnum = q.front();
            q.pop();
            int x = tempnum % 100;
            int y = tempnum / 100;
            int right = x + 1;
            int left = x - 1;
            int up = y + 1;
            int down = y - 1;
            if (up < row) {
                if (distance[y][x] + 1 < distance[up][x]) {
                    if (distance[up][x] == impossiblenum) {
                        q.push(up * 100 + x);
                    }
                    distance[up][x] = distance[y][x] + 1;
                }
            }
            if (right < col) {
                if (distance[y][x] + 1 < distance[y][right]) {
                    if (distance[y][right] == impossiblenum) {
                        q.push(y * 100 + right);
                    }
                    distance[y][right] = distance[y][x] + 1;
                }
            }
            if (down >= 0) {
                if (distance[y][x] + 1 < distance[down][x] && down >= 0) {
                    if (distance[down][x] == impossiblenum) {
                        q.push(down * 100 + x);
                    }
                    distance[down][x] = distance[y][x] + 1;
                }
            }
            if (left >= 0) {
                if (distance[y][x] + 1 < distance[y][left] && left >= 0) {
                    if (distance[y][left] == impossiblenum) {
                        q.push(y * 100 + left);
                    }
                    distance[y][left] = distance[y][x] + 1;
                }  

            } 
        }
        for (int a = 0; a < row; a++) {
            for (int b = 0; b < col; b++) {
                if (distance[a][b] > max) {
                    max = distance[a][b];
                }
            }
        }
        return max;
    }
};

int main() {

}