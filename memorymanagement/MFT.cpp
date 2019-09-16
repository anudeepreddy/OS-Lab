#include<iostream>
using namespace std;
struct block{
    int processId;
    int spaceUsed;
    int isNext;
};
int findBlocks(struct block memory[],int n,int noOfBlocks){
    int count=0;
    for(int i=0;i<noOfBlocks;i++){
        if(memory[i].processId==0){
            count++;
        }
        else{
            count=0;
        }
        if(count==n){
            return i-(n-1);
        }
    }
    return -1;
}
int main(){
int noOfProcesses,TOTALDISKSPACE,AVAILABLEDISKSPACE,blockSize,noOfBlocks,processId,sizeOfProcess,requiredBlocks;
int internalFragmentation=0,externalFragmentation=0;
cout<<"Enter the Total Disk space:";
cin>>TOTALDISKSPACE;
AVAILABLEDISKSPACE = TOTALDISKSPACE;
cout<<"Enter the number of Blocks:";
cin>>noOfBlocks;
cout<<"Enter the number of Processes:";
cin>>noOfProcesses;
blockSize = TOTALDISKSPACE/noOfBlocks;
struct block memory[noOfBlocks];
for(int i=0;i<noOfBlocks;i++){
    memory[i].processId=0;
    memory[i].spaceUsed=0;
    memory[i].isNext=0;
}
for(int i=0;i<noOfProcesses;i++){
    cout<<"Enter the process Id and size of the process:";
    cin>>processId>>sizeOfProcess;
    if(sizeOfProcess%blockSize==0){
        requiredBlocks=sizeOfProcess/blockSize;
    }
    else{
        requiredBlocks=(sizeOfProcess/blockSize)+1;
    }
    int blockIndex;
    blockIndex = findBlocks(memory,requiredBlocks,noOfBlocks);
    if(blockIndex==-1 || sizeOfProcess>AVAILABLEDISKSPACE){
        cout<<"Process cannot be allocated memory!!!\n";
    }
    else{
        AVAILABLEDISKSPACE -= (blockSize*requiredBlocks);
        if(sizeOfProcess%blockSize!=0)
        internalFragmentation += blockSize-(sizeOfProcess%blockSize);
        for(int j=blockIndex;j<blockIndex+requiredBlocks;j++){
            if(j!=blockIndex+requiredBlocks-1){
                memory[i].isNext=1;
                memory[i].spaceUsed=blockSize;
            }
            else {
            memory[i].spaceUsed=sizeOfProcess%blockSize;
            }
            memory[i].processId=processId;
        }
    }
}
cout<<"Total Disk space:"<<TOTALDISKSPACE;
cout<<"\nInternal Fragmentation:"<<internalFragmentation;
cout<<"\nExternal Fragmentation:"<<AVAILABLEDISKSPACE;
}