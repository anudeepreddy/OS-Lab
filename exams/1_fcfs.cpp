#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of processes:";
    cin>>n;
    int p[n],bt[n],wt[n],tat[n];
    for(int i=0;i<n;i++){
        cin>>p[i]>>bt[i];
    }
    wt[0]=0;
    tat[0]=bt[0];
    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=wt[i]+bt[i];
    }
    for(int i=0;i<n;i++){
        cout<<p[i]<<" "<<bt[i]<<" "<<wt[i]<<" "<<tat[i]<<"\n";
    }
}
