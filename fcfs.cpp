#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of processes:";
    cin>>n;
    int bt[n],wt[n],tat[n];
    float awt=0,atat=0;
    wt[0]=0;
    cout<<"Enter Burst time:";
    for(int i=0;i<n;i++){
        cin>>bt[i];
    }
    for(int i=1;i<n;i++){
        wt[i]=0;
        for(int j=0;j<i;j++){
            wt[i]+=bt[j];
        }
    }
    cout<<"--------------------------------------------------------\n";
    cout<<"Process    Burst Time    Waiting Time   Turn Around Time\n";
    cout<<"--------------------------------------------------------\n";
    for(int i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
        awt+=wt[i];
        atat+=tat[i];
        cout<<"   "<<i+1<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }
    cout<<"--------------------------------------------------------\n";
    awt=awt/n;
    atat=atat/n;
    cout<<"Average waiting Time:"<<awt<<endl;
    cout<<"Average Turn around Time:"<<atat<<endl;
}