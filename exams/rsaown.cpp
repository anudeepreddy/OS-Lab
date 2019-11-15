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
ull encrypt(ull data){
    return fmod(pow(data,d),n);
}
ull decrypt(ull data){
    return fmod(pow(data,e),n);
}
int main(){
cin>>p>>q;
ull data;
cin>>data;
generatekeys();
cout<<encrypt(data);
cout<<"\n";
cout<<decrypt(encrypt(data));
}