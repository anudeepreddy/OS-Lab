#include<bits/stdc++.h>
const int TOTAL_SPACE=1024;
using namespace std;
int isfree(int *mem,int initBlock,int fileSize){
    if(mem[initBlock]){
        return 0;
    }
    else{
        for(int i=initBlock;i<initBlock+fileSize;i++){
            if(mem[i])
                return 0;
        }
        for(int i=initBlock;i<initBlock+fileSize;i++)
        mem[i]=1;
    }
    return 1;
}
int main(){

    int mem[TOTAL_SPACE];
    memset(mem,0,sizeof(mem));
    int initBlock,fileSize;
    char c;
    do{
        cout<<"Enter the starting block and legth of files:";
        cin>>initBlock>>fileSize;
        if(isfree(mem,initBlock,fileSize)){
            cout<<"File is allocated memory:";
            for(int i=initBlock;i<initBlock+fileSize;i++)
            cout<<i<<" ";
        }
        else{
            cout<<"File cannot be allocated memory from block:"<<initBlock;
        }
        cout<<"\nDo you want to enter more files(Y/N):";
        cin>>c;
    }while(c=='y'||c=='Y');

}