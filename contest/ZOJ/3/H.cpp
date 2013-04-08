/**************************************************************************
 **      File Name: H.cpp
 **      Author: tiankonguse
 **      Mail: shen10000shen@gmail.com
 **      Created Time: 2013/3/31 12:08:57
/**************************************************************************/

//#include<iostream>
#include<stdio.h>
//using namespace std;

int main(){
    int n,k,p;
    long long  w;
    while(cin>>n>>w>>k){
        n+=2;
        if(k==1 || w == 0){
            //cout<<"0.00"<<endl;
            printf("0.00\n");
        }else{
            p= n- n/k;
            if(!(p&1)){
                //cout<<((p>>1)*w)<<".00"<<endl;
                //printf("p=%d\n",p);

                printf("%d.00\n",(p>>1)*w);
            }else if(!(w&1)){
                cout<<((w>>1)*p)<<".00"<<endl;
               // printf("w=%d\n",w);
               // printf("%d.00\n",(w>>1)*p);
            }else{
                cout<<((p*w)>>1)<<".50"<<endl;
                //printf("w=%d p=%d\n",w,p);
              //  printf("%d.50\n", (p*w)>>1);
            }

        }

    }
    return 0;
}
