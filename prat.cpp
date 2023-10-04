#include<bits/stdc++.h>
using namespace std;

int commonEl(vector<vector<int>>arr, int m, int n){
    unordered_map<int,int> mp;
    for(int i=0; i<m; i++){
        mp[arr[i][0]] = 1;
        for(int j=1; j<n; j++){
            if(arr[i][j]!=arr[i][j-1]){
                mp[arr[i][j]]++;
            }
        }
    }
    for(auto i:mp){
        if(i.second==m){
            return i.first;
        }
    }
    return -1;
}

int main(){
    // Find a common element in all rows of a given row-wise sorted matrix
    int m,n;
    cin>>m>>n;
    vector<vector<int>> arr(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<commonEl(arr,m,n);

    return 0;
}