#include<bits/stdc++.h>
using namespace std;
struct Frame{
    char f;
    int counter;
};
int frameAvailable(char frame,struct Frame frames[],int noOfFrames){
    for(int i=0;i<noOfFrames;i++){
        if(frame==frames[i].f)
            return i;
    }
    return -1;
}
int findFaultPage(struct Frame frames[],int noOfFrames){
    int index=0;
    for(int i=0;i<noOfFrames;i++){
        if(frames[i].counter>frames[index].counter)
            index=i;
    }
    return index;
}
int main(){
    string refString;
    int noOfFrames,pageFault=0,faultPageIndex=0;
    cout<<"Enter the number of Frames:";
    cin>>noOfFrames;
    struct Frame frames[noOfFrames];
    for(int i=0;i<noOfFrames;i++){
        frames[i].f='-';
        frames[i].counter=0;
    }
    cout<<"Enter Reference String:";
    cin>>refString;
    int len = refString.length();
    for(int i=0;i<len;i++){
        for(int j=0;j<noOfFrames;j++){
            frames[j].counter++;
        }
        int index = frameAvailable(refString[i],frames,noOfFrames);
        if(index != -1){
            frames[index].counter=0;
        }
        else{
            faultPageIndex = findFaultPage(frames,noOfFrames);
            cout<<"Page Fault:\n";
            for(int j=0;j<noOfFrames;j++){
            if(j==faultPageIndex){
                cout<<frames[j].f<<"-> "<<refString[i]<<endl;
            }
            else{
                cout<<frames[j].f<<"   "<<frames[j].f<<endl;
            }
        }
            frames[faultPageIndex].f = refString[i];
            frames[faultPageIndex].counter = 0;
            pageFault++;
        }
    }
    cout<<"No of Page Faults:"<<pageFault<<endl;
}
