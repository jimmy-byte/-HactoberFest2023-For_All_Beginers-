
#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct MyComp {
   bool operator()(
        pair<int, vector<int>> const& a,
        pair<int, vector<int>> const& b)
    {
        if(a.first!=b.first)
      return a.first<b.first;
    else
        return a.second[1]>b.second[1];

    }
};
int main()
{
long long int n;
cout<<"Enter no.of processes: ";
cin>>n;
vector<pair<int,int>>ab;
priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>a;
priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,MyComp>r;
cout<<"Enter arrival time and burst time of processes: ";
int target=0;
for(int i=0;i<n;i++)
{
    int x,y;
    cin>>x>>y;
    ab.push_back({x,y});
    a.push({x,{y,i}});
    target+=y;
}
map<int,int>vis;
int ct=0;
int mn=-1;
map<int,int>c;
while(ct<target)
{
    while(!a.empty()&&a.top().first<=ct)
    {
        r.push({a.top().second[0],{a.top().first,a.top().second[1]}});
        if(mn=-1)
            target+=a.top().first;
      cout<<a.top().second[1]<<" tt "<<ct<<endl;
        a.pop();
    }
    if(!r.empty())
    {
        int at=r.top().second[0];
        int bt=r.top().first;
        int id=r.top().second[1];
        r.pop();
        bt--;
        ct++;
cout<<id<<" "<<ct<<endl;
        if(bt>0)
        {
            r.push({bt,{at,id}});
        }
        else{
            c[id]=ct;
        }
    }
    else{
        ct++;
    }
}
cout<<"Pid       AT       BT        CT"<<endl;
for(int i=0;i<n;i++)
{
    cout<<i<<"           "<<ab[i].first<<"            "<<ab[i].second<<"          "<<c[i]<<endl;}


return 0;
}

