#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void print(int **s, int i, int j, int n)
{
    if (i > n || j > n)
    {
        return;
    }
    if (i == j)
    {
        cout << "A" << i<<" ";
    }
    else
    {
        cout << "(";
        print(s, i, s[i][j], n);
        print(s, s[i][j] + 1, j, n);
        cout << ")";
    }
}
void mcm(vector<vector<int>> v, int n)
{
    int **arr = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            arr[i][j] = 0;
        }
    }
    int **s = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        s[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            s[i][j] = 0;
        }
    }
    for (int c = 2; c < n + 1; c++)
    {
        for (int i = 1, j = c; i < n + 1 && j < n + 1; i++, j++)
        {
            int min = INT_MAX, x, index;
            for (int k = i; k < j; k++)
            {
                x = arr[i][k] + arr[k + 1][j] + v[i - 1][0] * v[k][0] * v[j][0];
                if (min > x)
                {
                    index = k;
                    min = x;
                }
            }
            arr[i][j] = min;
            s[i][j] = index;
        }
    }
    cout << arr[1][n] << endl;
    print(s, 1, 6, n);
    cout << endl;
}
int main()
{
    vector<vector<int>> v;
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        cin >> b;
        v.push_back({a, b});
    }
    v.push_back({b, b});
    cout<<"Output:"<<endl;
    mcm(v, n);
    return 0;
}