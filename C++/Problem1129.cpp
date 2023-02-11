#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        int impossiblenum = 99999;
        vector<vector<int>> dis(2, vector<int> (n));
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < n; b++) {
                dis[a][b] = impossiblenum;//0 is red, 1 is blue
            }
        }
        dis[0][0] = 0;
        dis[1][0] = 0;

        queue<int> q;
        int red[n][n];
        int blue[n][n];
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                red[a][b] = 0;
                blue[a][b] = 0;
            }
        }

        for (int a = 0; a < redEdges.size(); a++) {
            red[redEdges[a][0]][redEdges[a][1]] = 1;
        }

        for (int a = 0; a < blueEdges.size(); a++) {
            blue[blueEdges[a][0]][blueEdges[a][1]] = 1;
        }
        q.push(0);
        while(!q.empty()) {
            int tempnum = q.front();
            q.pop();
            for (int b = 0; b < n; b++)  {
                int changed = 0;
                //printf("red %d blue %d disred %d disblue %d\n", red[tempnum][b], blue[tempnum][b], dis[0][tempnum], dis[0][b]);
                if (red[tempnum][b] == 1 && dis[1][tempnum] + 1 < dis[0][b]) {
                    //printf("red\n");
                    dis[0][b] = dis[1][tempnum] + 1;
                    changed = 1;
                }
                if (blue[tempnum][b] == 1 && dis[0][tempnum] + 1 < dis[1][b]) {
                    //printf("blue\n");
                    dis[1][b] = dis[0][tempnum] + 1;
                    changed = 1;
                }
                if (changed == 1) {
                    q.push(b);
                }
            }
        }
        //vector<vector<int>> dis(2, vector<int> (n));
        vector<int> result(n);
        for (int a = 0; a < n; a++) {
            if (dis[0][a] < dis[1][a]) {
                result[a] = dis[0][a];
            }else if (dis[1][a] < dis[0][a]){
                result[a] = dis[1][a];
            }else if (dis[1][a] == dis[0][a]) {
                result[a] = dis[1][a];
            }
            if (dis[1][a] == dis[0][a] && dis[1][a] == impossiblenum) {
                result[a] = -1;
            }
        }
        return result;
    }
};


int main() {

}