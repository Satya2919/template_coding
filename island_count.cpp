/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<bits/stdc++.h>

using namespace std;

void DFS(int **edges,int sv,int n,bool *visited){
 visited[sv] = true;
 for(int i=0;i<n;i++){
    if(i==sv){
        continue;
    }
    if(edges[sv][i]==1){
        if(visited[i]){
            continue;
        }
        DFS(edges,i,n,visited);
    }

 }
}

int DFShelper(int **edges,int n){
   bool *visited = new bool[n];
   for(int i=0;i<n;i++){
    visited[i] = false;
   }
    int count=0;
   for(int i=0;i<n;i++){
       if(!visited[i]){
           DFS(edges,i,n,visited);
           count++;
       }
   }
    return count;
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
	int **edges = new int*[n];
    for(int i=0;i<n;i++){
    	edges[i] = new int[n];
    	for(int j=0;j<n;j++){
        	edges[i][j] = 0;
    	}
   	}
    for(int i=0;i<m;i++){
        edges[(u[i]-1)][(v[i]-1)] = 1;
        edges[(v[i]-1)][(u[i]-1)] = 1;
    }
    int count = DFShelper(edges,n);
    return count;
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> u;
  vector<int> v;
  int a,b;
  for(int i=0;i<m;i++){
    cin>>a>>b;
    u.push_back(a);
    v.push_back(b);
  }

  int count = solve(n,m,u,v);
  cout<<count;
  return 0;
}

