#include <bits/stdc++.h>
using namespace std;
// Recursion
int solve(int index1, int index2, string s, string t)
{
    if (index1 < 0 || index2 < 0)
        return 0;
    if (s[index1] == t[index2])
    {
        return 1 + solve(index1 - 1, index2 - 1, s, t);
    }
    else
    {
        return 0 + max(solve(index1 - 1, index2, s, t), solve(index1, index2 - 1, s, t));
    }
}
int lcs(string s, string t)
{
    // Write your code here
    return solve(s.length() - 1, t.length() - 1, s, t);
}

// MEMOIZATION

int solve(int index1, int index2, string s, string t, vector<vector<int>> &dp)
{
    if (index1 < 0 || index2 < 0)
        return 0;

    if (dp[index1][index2] != -1)
        return dp[index1][index2];
    if (s[index1] == t[index2])
    {
        return dp[index1][index2] = 1 + solve(index1 - 1, index2 - 1, s, t, dp);
    }
    else
    {
        return dp[index1][index2] = 0 + max(solve(index1 - 1, index2, s, t, dp), solve(index1, index2 - 1, s, t, dp));
    }
}
int lcs(string s, string t)
{
    // Write your code here
    vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
    return solve(s.length() - 1, t.length() - 1, s, t, dp);
}

// TABULATION

int lcs(string s, string t)
{
    // Write your code here
    vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, 0));
    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 1; j <= t.length(); j++)
        {
            if (s[i - 1] == t[j - 1])
            {

                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                int left = dp[i - 1][j];
                int right = dp[i][j - 1];
                dp[i][j] = 0 + max(left, right);
            }
        }
    }
    return dp[s.length()][t.length()];
}

// space optimised
int lcs(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
            }
            else
            {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }
    return prev[m];
}
int main()
{

    return 0;
}