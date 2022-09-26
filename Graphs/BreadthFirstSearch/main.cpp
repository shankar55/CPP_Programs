#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
int adj[20][20];
void breadth_first_search(int vertex)
{
    list<int> q;
    vector<bool> visited(n,false);
    visited[vertex]=true;
    q.push_back(vertex);
    while(!q.empty())
    {
        vertex=q.front();
        cout<<vertex<<"\t";
        q.pop_front();
        for(auto adjacent:adj[vertex])
        {
            if(!visited[adjacent])
            {
                visited[adjacent]=true;
                q.push_back(adjacent);
            }
        }
    }
}
int main()
{
    int vertex;
    cout<<"Enter no of vertices: ";
    cin>>n;
    cout<<"Enter Adjacency Matrix:\n";
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            cin>>adj[i][j];
        }
    }
    cout<<"\n Enter vertex: ";
    breadth_first_search(vertex);
    return 0;
}
