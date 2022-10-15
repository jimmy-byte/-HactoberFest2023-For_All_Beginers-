//Made By: Vishesh Gupta(Pre-Final Year at IIT BHU)
#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector< vector<ll> > v;
vector< bool > visited;

void dfs(ll node,ll parent){

	visited[node]=true;
	cout<< node <<" --> ";

	for(ll child : v[node]){

		if( !visited[child] ){
			dfs( child , node );// recusively called dfs for child if not visited in graph
		}
	}
}

int main()
{
	ll n , k ;
	cout <<"Enter Number of nodes in graph: ";
	cin >> n;
	cout << "Enter Number of edges in graph: ";
	cin >> k;

	v.resize( n+1);    // nodes+1 is taken to avoid out of bound
	visited.resize( n+1,false);   // For checking node traversed previously or not

	//Inputting the graph
	cout <<"Enter the pair of nodes containing edge with spaces in next "<<k<<" line :\n";
	for(ll i = 1 ; i <= k ; i++ ){
		ll x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
		//for directed edges you just need to comment one of these above line
	}

	ll source;
	cout << "\nEnter Source where the dfs starts from : ";
	cin>>source;

	cout <<"\nDFS Traversal is : ";
	dfs(source,-1);//since there is no parent of source so taken -1

	return 0;
}