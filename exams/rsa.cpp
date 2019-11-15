#include<bits/stdc++.h>
using namespace std;
double n,d,e,phi;
int modInverse(int a, int m) 
{ 
    a = a%m; 
    for (int x=1; x<m; x++) 
       if ((a*x) % m == 1) 
          return x; 
    return 1;
} 
int gcd(int a, int h) 
{ 
    int temp; 
    while (1) 
    { 
        temp = a%h; 
        if (temp == 0) 
          return h; 
        a = h; 
        h = temp; 
    } 
} 
void generatekeys(double p,double q){
	n = p*q;
	phi = (p-1)*(q-1);
	for(int i=phi-1;i>=2;i--){
		e=i;
		if(gcd(e,phi)==1)
			break;
	}
	d = modInverse(e,phi);
}
double encrypt(double data){
	return fmod(pow(data,d),n);
}
double decrypt(double data){
	return fmod(pow(data,e),n);
}
int main(){
double p,q;
cout<<"Enter two prime numbers:";
cin>>p>>q;
generatekeys(p,q);
double data;
cout<<"Enter data:";
cin>>data;
double edata = encrypt(data);
cout<<"Encrypted data:"<<edata<<endl;
cout<<"Decrypted data:"<<decrypt(edata)<<"\n";
cout<<"\n";
}