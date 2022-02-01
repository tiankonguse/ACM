#include <stdio.h>
#include <string.h>

#define base 10000
#define width 4
#define N 100
class bint{//只支持正数 
	private:
		int ln,v[N];
	public:
		char bf[N*width+2];
		bint(int r=0)            {  init(r);    }
		bint& operator = (int r) {  init(r);    }
		bint(char *buf)          {  init(buf);  }
		
		void init(int r)         {
			for(ln=0;r>0;r/=base)
				v[ln++]=r%base;
		}
		
		void init(char *buf){
			memset(this,0,sizeof(bint));
			int w,u,l=strlen(buf);
			if('0'==buf[0]&&'\0'==buf[1])return;
			for(w=1,u=0;l;){
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
		
		
		bint& operator = (const bint& r) {
			memcpy(this,&r,sizeof(bint));// !
			return *this;
		}
		bint& operator () (char* buf) {
			init(buf);
			return *this;
		}
		
        bint& operator = (char* buf) {
			init(buf);
			return *this;
		}
		char* toString(){
			int i,p=0;
			p+=sprintf(bf+p,"%d",ln==0?0:v[ln-1]);
			for(i=ln-2;i>=0;i--)
				p+=sprintf(bf+p,"%04d",v[i]);// ! 4 == width
			return bf;
		}
		bint operator + (const bint& b) const{
			bint res;
			int i,cy=0;
			for(i=0;i<ln||i<b.ln||cy>0;i++) {
				if(i<ln)cy+=v[i];
				if(i<b.ln)cy+=b.v[i];
				res.v[i]=cy%base;cy/=base;
			}
			res.ln=i;
			return res;
		}
		
		int digits(bint& a) const{ // 返回位数
			if(ln==0)return 0;
			int l=(ln-1)*4;
			for(int t=v[ln-1];t;++l,t/=10);
			return l;
		}
};

int main(){
	bint x,y;
	char bf1[100],bf2[100],bf3[100],bf4[100];
	char *p1,*p2,*p3,*p4;
	while(scanf("%s%s%s",bf1,bf2,bf3)!=EOF)
	{
    
    p1=bf1;
    p2=bf2;
    p3=bf3;
    p4=bf4;

    for(int i=4;i<=100;i++)
    {
     x=p1;
     y=p2;
     x=(x+y).toString();
     y=p3;
     strcpy(p4,(x+y).toString());  
     p1=p2;
     p2=p3;
     p3=p4;
     p4=p1; 
           
    }
printf("%s\n",p3);
}
	
	return 0;
}

