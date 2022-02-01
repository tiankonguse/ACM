#include <stdio.h>
#include <string.h>

#define base 10000
#define width 4
#define N 10000
class bint{//只支持正数 
	private:
		int ln,v[N];
	public:
		char bf[N*width+2];	     
	    void init(char *);
		void operator = (char*);
        void operator + ( bint);
        char* toString() ;	
};
	void bint::init(char *buf){
			memset(this,0,sizeof(bint));
			int w,u,l=strlen(buf);
			if('0'==buf[0]&&'\0'==buf[1])return;
			for(w=1,u=0;l;)
			{
				u+=(buf[--l]-'0')*w;
				if(w*10==base){
				
					v[ln++]=u;
					u=0,w=1;
				}
				else w*=10;
			}
			if(w!=1)v[ln++]=u;
			while(v[ln-1]==0&&ln>1)
            ln--;
		}
	
        void bint::operator = (char* buf) {
			init(buf);
		}
		
	char* bint::toString(){
	
			int i,p=0;
			p+=sprintf(bf+p,"%d",v[ln-1]);
	
			for(i=ln-2;i>=0;i--)
				p+=sprintf(bf+p,"%04d",v[i]);
			return bf;
		}
		
		void bint::operator + ( bint b) { 
		   
			int res[2000];
			int i,j,k,cy=0;

			for(i=ln-1,j=b.ln-1,k=0;k<ln||k<b.ln||cy;i--,j--,k++)
			{
            if(i>=0)cy+=v[k];
            if(j>=0)cy+=b.v[k];
            res[k]=cy%base;
            cy/=base;    
            }
            ln=k;
            for(i=0;i<k;i++)v[i]=res[i];
 		 

		}
		
int main(){

    bint a;
    char str1[5000],str2[5000];
    scanf("%s",str1);
    a=str1;
    
    while(scanf("%s",str2))
    {if((str2[0]=='0')&&(str2[1]=='\0'))break;
    bint b;
    b=str2;
    a+b;
   // printf("%s\n",a.toString());
    memset(str2,0,sizeof(str2));
    }
    printf("%s\n",a.toString());

getchar();getchar();
	return 0;
}
