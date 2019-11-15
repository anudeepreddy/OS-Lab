#include<bits/stdc++.h>
//#include "boost/multiprecision/cpp_int.hpp"; //ignore this line or remove it
using namespace std;
struct jobs{
    int p;
    int bt;
};
int cmp(const void *a,const void *b){
    return ((struct jobs *)a)->bt-((struct jobs *)b)->bt;
}
int main(){
    int n;
    cout<<"Enter number of processes:";
    cin>>n;
    struct jobs job[n];
    for(int i=0;i<n;i++){
        cin>>job[i].p>>job[i].bt;
    }
    qsort(job,n,sizeof(jobs),cmp);
    for(int i=0;i<n;i++){
        cout<<"job:"<<job[i].p<<"\n";
    }
    int wt[n],ct[n];
    wt[0]=0,ct[0]=job[0].bt;
    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+job[i-1].bt;
        ct[i]=wt[i]+job[i].bt;
    }
    for(int i=0;i<n;i++){
        cout<<job[i].p<<" "<<job[i].bt<<" "<<wt[i]<<" "<<ct[i]<<endl;
    }
}