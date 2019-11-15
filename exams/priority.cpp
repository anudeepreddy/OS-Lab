#include<bits/stdc++.h>
using namespace std;
struct jobs{
    int pid;
    int bt;
    int p;
};
int cmp(const void *a,const void *b){
    return ((struct jobs*)a)->p-((struct jobs*)b)->p;
}
int main(){
    int n;
    cin>>n;
    struct jobs job[n];
    for(int i=0;i<n;i++){
        cin>>job[i].pid>>job[i].bt>>job[i].p;
    }
    qsort(job,n,sizeof(jobs),cmp);
    int wt[n],tat[n];
    wt[0]=0;
    tat[0]=job[0].bt;
    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+job[i-1].bt;
        tat[i]=wt[i]+job[i].bt;
    }
    for(int i=0;i<n;i++){
        cout<<job[i].pid<<" "<<job[i].bt<<" "<<job[i].p<<" "<<wt[i]<<" "<<tat[i]<<"\n";
    }
}