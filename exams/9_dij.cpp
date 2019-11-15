#include<bits/stdc++.h>
#include <climits>
using namespace std;
int main(){
int n,src;
    cout<<"Enter number of vertices in the graph:";
    cin>>n;
    int graph[n][n];
    cout<<"Enter the graph:";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>graph[i][j];
    cout<<"Enter the source vertex:";
    cin>>src;
    int dist[n],isvisited[n],v;
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
        isvisited[i]=0;
    }
    dist[src]=0;
    int min=INT_MAX;
    for(int _=0;_<n;_++){
        min=INT_MAX;
        for(int i=0;i<n;i++){
            if(isvisited[i]==0&&dist[i]<min){
                v=i;
                min=dist[i];
            }
        }
        isvisited[v]=1;
        for(int i=0;i<n;i++){
            if(isvisited[i]!=1&&graph[v][i]&&graph[v][i]!=INT_MAX&&dist[v]+graph[v][i]<dist[i])
            dist[i]=dist[v]+graph[v][i];
        }
    }
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
}