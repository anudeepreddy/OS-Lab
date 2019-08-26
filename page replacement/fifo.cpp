#include<bits/stdc++.h>
using namespace std;
int frameAvailable(char frame,char frames[],int noOfFrames){
    for(int i=0;i<noOfFrames;i++){
        if(frame==frames[i])
            return 1;
    }
    return 0;
}
int main(){
    string refString;
    int noOfFrames,pageFault=0,faultPageIndex=0;
    cout<<"Enter the number of Frames:";
    cin>>noOfFrames;
    char frames[noOfFrames];
    memset(frames,'-',sizeof(frames));
    cout<<"Enter Reference String:";
    cin>>refString;
    int len = refString.length();
    for(int i=0;i<len;i++){
        if(frameAvailable(refString[i],frames,noOfFrames))  continue;
        pageFault++;
        cout<<"Page Fault:\n";
        for(int j=0;j<noOfFrames;j++){
            if(j==faultPageIndex%noOfFrames){
                cout<<frames[j]<<"->"<<refString[i]<<endl;
            }
            else{
                cout<<frames[j]<<"   "<<frames[j]<<endl;
            }
        }
        frames[faultPageIndex%noOfFrames]=refString[i];
        faultPageIndex++;
    }
    cout<<"No of Page Faults:"<<pageFault<<endl;
}
/* 70120304230321201701 */
