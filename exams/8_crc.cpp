#include<bits/stdc++.h>
using namespace std;
int main(){
    string data,gen;
    cin>>data>>gen;
    
    for(int i=0;i<gen.length()-1;i++){
        data+="0";
    }
string save=data;
    while(1){
        int i;
        for(i=0;data[i]=='0';i++);
        if(i+gen.length()>data.length())    break;
        for(int j=i;j<i+gen.length();j++){
            if(data[j]!=gen[j-i])
                data[j]='1';
            else {
                data[j]='0';
            }
        }
    }
    int i;
for(i=0;data[i]=='0';i++);
cout<<"remainder:";
for(int j=i;j<data.length();j++){
cout<<data[j];
save[j]=data[j];
}
while(1){
        int i;
        for(i=0;save[i]=='0';i++);
        if(i+gen.length()>data.length())    break;
        for(int j=i;j<i+gen.length();j++){
            if(save[j]!=gen[j-i])
                save[j]='1';
            else {
                save[j]='0';
            }
        }
    }
for(int i=0;i<save.length();i++){
    if(save[i]!='0'){
        cout<<"error has occured";
        return 0;
    }
}
cout<<"No error";
}