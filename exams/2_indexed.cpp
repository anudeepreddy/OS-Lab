#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int TOTAL_SPACE=1024,FREE_SPACE=1024;
struct memory{
    bool isfree;
    struct memory *next[1024];
};
int main(){
    int n,start,size;
    cin>>n;
    memory mem[TOTAL_SPACE];
    for(int i=0;i<TOTAL_SPACE;i++){
        mem[i].isfree=true;
    }
    for(int i=0;i<n;i++){
        cin>>start>>size;
        if(mem[start].isfree!=true){
            cout<<"already occupied";
            continue;
        }
        if(size>FREE_SPACE){
            cout<<"No enough space";
            continue;
        }
        int randblock;
        FREE_SPACE--;
        cout<<"Allocated:"<<start;
        mem[start].isfree=false;
        for(int j=1;j<size;){
            randblock=rand()%TOTAL_SPACE;
            if(mem[randblock].isfree){
                cout<<"->"<<randblock;
                mem[start].next[j-1]=&mem[randblock];
                mem[randblock].isfree=false;
            }
        }
    }
}