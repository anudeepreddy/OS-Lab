#include<iostream>
using namespace std;
int TOTAL_SPACE=1024,FREE_SPACE=1024;
struct Block{
    int isFree,size;
    struct Block *next;
    bool isInit;
};
int main(){
    struct Block mem[TOTAL_SPACE];
    for(int i=0;i<TOTAL_SPACE;i++)
    mem[i].isFree=0;
    int initBlock,fileSize,randBlock;
    char c;
    do{
        cout<<"Enter the starting block and length of file:";
        cin>>initBlock>>fileSize;
        if(mem[initBlock].isFree){
            cout<<"File cannot be allocated memory from block:"<<initBlock;
            cout<<"\nDo you want to enter more files(Y/N):";
            cin>>c;
            continue;
        }
        else{
            if(fileSize>FREE_SPACE){
                cout<<"Not enough blocks are available";
                cout<<"\nDo you want to enter more files(Y/N):";
                cin>>c;
                continue;
            }
        }
        mem[initBlock].isInit=true;
        mem[initBlock].isFree=1;
        mem[initBlock].size=fileSize;
        cout<<"Allocated:"<<initBlock;
        struct Block *tmp=&mem[initBlock];
        for(int i=1;i<fileSize;){
            randBlock=rand()%TOTAL_SPACE;
            if(!mem[randBlock].isFree){
                i++;
                mem[randBlock].isFree=1;
                mem[randBlock].isInit=false;
                mem[randBlock].size=0;
                if(i==fileSize-1)
                mem[randBlock].next = NULL;
                else{
                    tmp->next = &mem[randBlock];
                    tmp=tmp->next;
                }
                cout<<"->"<<randBlock;
            }
        }
        FREE_SPACE-=fileSize;
        cout<<"\nDo you want to enter more files(Y/N):";
        cin>>c;
    }while(c=='y'||c=='Y');
}
