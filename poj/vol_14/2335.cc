#include"iostream"
#include"cmath"
using namespace std;
const double eps=6e-3;
const double eps2=1e-6;
const double pi=acos(-1.0);
double fgcd(double a,double b){
   if(b<eps)return a;
   else return fgcd(b,fmod(a,b));
}
/*double fmod(double x, double y)
{
 return x-floor(x/y)*y;
}
double fgcd(double a, double b)
{
 double t;
 if(a>b)  //a>b
 {
  t=a;
  a=b;
  b=t;
 }
 if(fabs(a)<1e-6) return b;
 return fgcd(fmod(b,a),a);
}*/


double cal_center_x(double x1,double y1,double x2,double y2,double x3,double y3){   
    return((y1*(y2*y2+x2*x2-y3*y3-x3*x3) - y2*(y1*y1 - y3*y3 + x1*x1 - x3*x3) + y3*(y1*y1-y2*y2+x1*x1-x2*x2))/(2*(-x1*y2 + x1*y3 + x2*y1 - x2*y3 - x3*y1 + x3*y2)));   
}   
double cal_center_y(double x_out,double x1,double y1,double x2,double y2,double x3,double y3){   
    if(y1||y2)return ((x2-x1)/(y1-y2)*x_out + (y1*y1-y2*y2+x1*x1-x2*x2)/2/(y1-y2));   
    else return ((x3-x1)/(y1-y3)*x_out + (y1*y1-y3*y3+x1*x1-x3*x3)/2/(y1-y3)); 
} 
double dist(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double arcline(double x,double y,double x1,double y1,double x2,double y2){
    double d1=dist(x,y,x1,y1);
    double d2=dist(x,y,(x1+x2)/2.0,(y1+y2)/2.0);
    return acos(d2/d1);
}
double a[4];
bool check(int i)
{
  int k;
	double deg=2*pi/i;
	double t,p1,p2;
	for(k=1;k<4;++k)
	{
		t=a[k]/deg;
		p1=t-floor(t);
		p2=ceil(t)-t;
		if(p1>1e-5&&p2>1e-5)
			return false;
	}
	return true;

}

int main(){
  //  freopen("1018in.txt","r",stdin);
  //  freopen("1018out.txt","w",stdout);
    int T;
    double x,y,x1,y1,x2,y2,x3,y3,a1,a2,a3,ag,l1,l2,l3;
    scanf("%d",&T);
    while(T--){
       scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
       x=cal_center_x(x1,y1,x2,y2,x3,y3);
       y=cal_center_y(x,x1,y1,x2,y2,x3,y3);
       a[1]=arcline(x,y,x1,y1,x2,y2);
       a[2]=arcline(x,y,x1,y1,x3,y3);
       a[3]=arcline(x,y,x2,y2,x3,y3);
    //  printf("%.16lf\n",a[1]);
       ag=fgcd(a[1],fgcd(a[2],fgcd(pi,a[3])));
      //   ag=fgcd(a1,a3);
    //   cout<<x<<","<<y<<endl;
       //cout<<a[1]<<","<<a[2]<<","<<a[3]<<endl;
       //cout<<ag<<endl;
       //printf("%.16lf\n",ag);
       printf("%d\n",(int)(pi/ag+eps2));
     //  int x;
	 //   for(x=3;x<=200;++x)
	//		if(check(x))
	//			break;
	//	printf("%.16lf\n",2*pi/(double)x);
	//	cout<<x<<endl;
    }
   // system("pause");
    return 0;
}
