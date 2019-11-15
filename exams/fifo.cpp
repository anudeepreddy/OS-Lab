#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of frames:";
    cin>>n;
    int count=0;
    char frames[n];
    bool pagefault=true;
    string refstring;
    cout<<"Enter reference string:";
    cin>>refstring;
    int j=0;
    for(int i=0;i<refstring.length();i++){
        pagefault=true;
        for(int _=0;_<n;_++){
            if(refstring[i]==frames[_])
                pagefault=false;
        }
        if(pagefault){
            count++;
            frames[j%n]=refstring[i];
            j++;
            cout<<"Page fault";
            for(int _=0;_<n;_++){
                cout<<frames[_]<<" ";
            }
            cout<<"\n";
        }
    }
    cout<<count<<"\n";
}