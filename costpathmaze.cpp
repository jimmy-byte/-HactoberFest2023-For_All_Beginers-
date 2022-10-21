#include <bits/stdc++.h>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string asf, vector<vector<int>> &cost, int ans){
    ans += cost[sr][sc];
    if(sr == dr && sc == dc){
        cout << asf << " " << ans << endl;
        return;
    }
    if(sc + 1 <= dc){
        printMazePaths(sr, sc + 1, dr, dc, asf + "h", cost, ans);
    }
    if(sr + 1 <= dr){
        printMazePaths(sr + 1, sc, dr, dc, asf + "v", cost, ans);
    }
    // cout << "HELLO" << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> maze(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> maze[i][j];
        }
    }
    printMazePaths(0, 0, n-1, m-1, "", maze, 0);
    return 0;
}
