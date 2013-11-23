#include<iostream>
#include<string>
//#include<iomanip>
using namespace std;
string a[10000],b[10000];
int f(int m,string a[],string b[]){
    string c;
    int i;
     for(i=0;i<m;i++)
       c=c+' ';
     for(i=0;i<m;i++)
       b[i]=c+a[i];
     for(i=0;i<m;i++)
       b[i]=b[i]+c;
     for(i=m;i<2*m;i++)
       b[i]=a[i-m]+a[i-m];
       return 2*m;
    }


int main(){

 int i,j,n,m,k,p,q;
    while(cin>>m&&m){
        if(m==1){
        a[0]=" /\\";
        a[1]="/__\\";
         cout<<a[0]<<endl;
         cout<<a[1]<<endl;
          cout<<'\n'; }
        else{
        m=m-1;
        j=2;
        a[0]=" /\\ ";
        a[1]="/__\\";
        while(m--){
            j=f(j,a,b);  
            for(i=0;i<j;i++)  a[i]=b[i];
        }
        for(i=0;i<j;i++){
          for(k=0;k<j+1+i;k++) cout<<a[i][k];
         cout<<'\n';
        } 
        cout<<'\n'; 
       }    
     }
  return 0;
 }
