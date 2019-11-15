#include<bits/stdc++.h>
using namespace std;
int TOTAL_SPACE=1024,FREE_SPACE=1024;
struct memory{
    bool isfree;
    struct memory *next;
};
int main(){
    int n,start,size;
    cout<<"Enter the number of processes:";
    cin>>n;
    memory mem[TOTAL_SPACE];
    for(int i=0;i<TOTAL_SPACE;i++){
        mem[i].isfree=true;
    }
    for(int i=0;i<n;i++){
        cout<<"Enter the starting block and size of process "<<i<<":";
        cin>>start>>size;
        if(!mem[start].isfree){
            cout<<"The starting block is already occupied";
            continue;
        }
        if(size>FREE_SPACE){
            cout<<"No enough space to allocate memory";
            continue;
        }
        int randblock;
        mem[start].isfree=false;
        memory *tmp=&mem[start];
        cout<<"Allocated:"<<start;
        for(int j=1;j<size;){
            randblock=rand()%TOTAL_SPACE;
            if(mem[randblock].isfree){
                j++;
                mem[randblock].isfree=false;
                tmp->next=&mem[randblock];
                tmp=tmp->next;
                FREE_SPACE--;
            cout<<"->"<<randblock;
            }
        }
        cout<<"\n";
    }
}