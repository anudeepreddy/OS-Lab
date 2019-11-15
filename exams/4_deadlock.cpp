#include<bits/stdc++.h>
using namespace std;
int main(){
    int nr,np;
    vector<int> safesequence;
    cout<<"Enter the number of resources:";
    cin>>nr;
    cout<<"Enter the number of processes:";
    cin>>np;
    int alloc[np][nr],need[np][nr],available[nr],max[np][nr];
    for(int i=0;i<np;i++){
        cout<<"process"<<i<<":";
        for(int j=0;j<nr;j++){
            cin>>alloc[i][j];
        }
        for(int j=0;j<nr;j++){
            cin>>max[i][j];
        }
        for(int j=0;j<nr;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    for(int i=0;i<nr;i++){
        cin>>available[i];
    }
    
    int isdone[np],flag=0;
    memset(isdone,0,sizeof(isdone));
    for(int _=0;_<np;_++){
        //cout<<"yes1\n";
        for(int i=0;i<np;i++){
            //cout<<"yes2\n";
            flag=0;
            if(isdone[i])   continue;
            for(int j=0;j<nr;j++){
                //cout<<"yes3\n";
                if(need[i][j]>available[j]){
                    flag=1;
                    break;
                }
            }
            if(flag){
                continue;
            }
            //cout<<"no\n";
            safesequence.push_back(i);
            isdone[i]=1;
            for(int j=0;j<nr;j++){
                //cout<<"yes4\n";
                available[j]+=alloc[i][j];
            }
        }
    }
    //cout<<safesequence.size();
    for(int i=0;i<safesequence.size();i++){
        cout<<safesequence[i]<<" ";
    }
}