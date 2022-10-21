#include <bits/stdc++.h>
using namespace std;

int printMazePaths(vector<vector<int>> &cost, vector<vector<int>> &dp){
    int n = cost.size();
    int m = cost[0].size();
    dp[n-1][m-1] = cost[n-1][m-1];

    for(int j = m-2; j >= 0; j--){
        dp[n-1][j] = cost[n-1][j] + dp[n-1][j+1];
    }
    for(int i = n-2; i >= 0; i--){
        dp[i][m-1] = dp[i+1][m-1] + cost[i][m-1];
    }

    for(int i = n-2; i >= 0; i--){
        for(int j = m-2; j >= 0; j--){
            dp[i][j] = cost[i][j] + min(dp[i+1][j], dp[i][j+1]);
        }
    }
    return dp[0][0];
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m, n;
    cin >> n >> m;
    vector<vector<int>> cost(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> cost[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int> (m));
    int ans = printMazePaths(cost, dp);
    cout << ans << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
