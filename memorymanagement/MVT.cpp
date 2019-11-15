#include<iostream>
using namespace std;
struct block{
    int processId;
    int sizeOfProcess;
    struct block* next;
};
int main(){
int noOfProcesses,TOTALDISKSPACE,AVAILABLEDISKSPACE,processId,sizeOfProcess;
int externalFragmentation=0;
cout<<"Enter the Total Disk space:";
cin>>TOTALDISKSPACE;
AVAILABLEDISKSPACE = TOTALDISKSPACE;
cout<<"Enter the number of Processes:";
cin>>noOfProcesses;
struct block *head=NULL,*tmp;

for(int i=0;i<noOfProcesses;i++){
    cout<<"Enter the process Id and size of the process:";
    cin>>processId>>sizeOfProcess;
    if(sizeOfProcess>AVAILABLEDISKSPACE){
        cout<<"Process cannot be allocated memory!!!\n";
    }
    else{
        if(head==NULL){
            head = new block;
            head->processId=processId;
            head->sizeOfProcess=sizeOfProcess;
            head->next=NULL;
            tmp=head;
        }
        else{
            tmp->next=new block;
            tmp=tmp->next;
            tmp->processId=processId;
            tmp->sizeOfProcess=sizeOfProcess;
            tmp->next=NULL;
        }

        AVAILABLEDISKSPACE -= (sizeOfProcess);
    }
}
cout<<"Total Disk space:"<<TOTALDISKSPACE;
cout<<"\nExternal Fragmentation:"<<AVAILABLEDISKSPACE;
}
