#include<iostream>
using namespace std;
int main(){
    int n,q;
    cout<<"Enter the number of processes:";
    cin>>n;
    int p[n],bt[n],rem_bt[n],wt[n];
    cout<<"Enter the processes and burst time:";
    for(int i=0;i<n;i++){
        cin>>p[i]>>bt[i];
        rem_bt[i]=bt[i];
    }
    cout<<"Enter time quantum:";
    cin>>q;
    int t=0;
    bool isdone=true;
    while(1){
        isdone=true;
        for(int i=0;i<n;i++){
            if(rem_bt[i]!=0){
                isdone=false;
                if(rem_bt[i]>q){
                    t+=q;
                    rem_bt[i]-=q;
                }
                else{
                    t+=rem_bt[i];
                    wt[i]=t-bt[i];
                    rem_bt[i]=0;
                }
            }
        }
        if(isdone)
        break;
    }
    int tat[n],avgtat=0,avgwt=0;
    for(int i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
        avgtat+=tat[i];
        avgwt+=wt[i];
    }
    avgtat/=n;
    avgwt/=n;
    for(int i=0;i<n;i++){
        cout<<p[i]<<" "<<bt[i]<<" "<<wt[i]<<" "<<tat[i]<<endl;
    }
    cout<<avgtat<<" "<<avgwt;
}