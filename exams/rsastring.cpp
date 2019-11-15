#include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;
ull modinverse(ull a,ull m){
    a=a%m;
    for(ull x=1;x<m;x++){
        if((a*x)%m==1)
            return x;
    }
    return 1;
}
ull gcd(ull a,ull b){
    ull temp;
    while(1){
        temp=a%b;
        if(temp==0)
            return b;
        a=b;
        b=temp;
    }
    return 1;
}
ull p,q,phi,e,d,n;
void generatekeys(){
n=p*q;
phi=(p-1)*(q-1);
/*for(int i=phi-1;i>0;i--){
    e=i;
    if(gcd(e,phi)==1) break;
}*/
e=(rand()%phi)+1;
while(gcd(e,phi)!=1)
    e=(rand()%phi)+1;
d=modinverse(e,phi);
}
string encrypt(string data){
    string res;
    for(int i=0;i<data.length();i++){
        res+=fmod(pow(data[i]-97,d),n);
    }
    return res;
}
string decrypt(string data){
    string res;
    for(int i=0;i<data.length();i++){
        res+=(fmod(pow(data[i],e),n)+97);
    }
    return res;
}
int main(){
cin>>p>>q;
string data;
cin>>data;
generatekeys();
string edata=encrypt(data);
for(int i=0;i<edata.size();i++){
    cout<<(int)edata[i]<<"";
}
cout<<"\n";
string ddata=decrypt(edata);
for(int i=0;i<ddata.size();i++){
    cout<<ddata[i]<<"";
}
}