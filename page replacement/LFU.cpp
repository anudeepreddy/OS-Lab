#include <iostream>

using namespace std;
struct Frame{
    char f;
    int frequency;
    int index;
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
    for(int i=1;i<noOfFrames;i++){
        if(frames[i].frequency<frames[index].frequency){
            index=i;
        }
        else if(frames[i].frequency==frames[index].frequency){
            if(frames[i].index<frames[index].index)
                index=i;
        }
    }
    return index;
}
int main()
{
    string refString;
    int noOfFrames,availableFrameIndex,faultPageIndex,pageFault=0;
    cout<<"Enter the number of frames:";
    cin>>noOfFrames;
    struct Frame frames[noOfFrames];
    for(int i=0;i<noOfFrames;i++){
        frames[i].f='-';
        frames[i].frequency=0;
        frames[i].index=-1;
    }
    cout<<"Enter the reference string:";
    cin>>refString;
    int len = refString.length();
    for(int i=0;i<len;i++){
        availableFrameIndex = frameAvailable(refString[i],frames,noOfFrames);
        if(availableFrameIndex!=-1){
            frames[availableFrameIndex].index=i;
            frames[availableFrameIndex].frequency+=1;
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
            frames[faultPageIndex].frequency = 1;
            frames[faultPageIndex].index=i;
            pageFault++;
        }
    }
    cout<<"No of Page Faults:"<<pageFault<<endl;
}
