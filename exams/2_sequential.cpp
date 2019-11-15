#include<bits/stdc++.h>
using namespace std;
int mem[1024];
int main(){
char c='Y';
int start,size;
bool flag=true;
memset(mem,0,sizeof(mem));
do{flag=true;
    cout<<"Enter the starting block and size of the file:";
    cin>>start>>size;
    if(mem[start]!=0){
        cout<<"The initial block is already occupied\n";
        flag=false;
        continue;
    }
    else{
        for(int i=start;i<start+size;i++){
            if(mem[i]!=0){
                cout<<"Cannot allocate consecutive blocks\n";
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<"Allocated blocks:";
            for(int i=start;i<start+size;i++){
                mem[i]=1;
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    cout<<"Do you want to enter more files(y/n):";
    cin>>c;
}while(c=='y'||c=='Y');
}