
#include<stdio.h>
#include<math.h>

struct Point{
	double x,y,z;
}p0,p1;
double angle;
double mat[3][3];

void init(struct Point &p){
	double len=sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
	p.x/=len,p.y/=len,p.z/=len;
}

int read(struct Point &p){
	return scanf("%lf%lf%lf",&p.x,&p.y,&p.z);
}

void RM(double x,double y,double z,double a){
	double c=cos(a),s=sin(a);
	mat[0][0]=x*x+(1-x*x)*c;
	mat[1][1]=y*y+(1-y*y)*c;
	mat[2][2]=z*z+(1-z*z)*c;

	mat[0][1]=x*y*(1-c)-z*s;
	mat[1][2]=y*z*(1-c)-x*s;
	mat[2][0]=z*x*(1-c)-y*s;

	mat[0][2]=x*z*(1-c)+y*s;
	mat[1][0]=x*y*(1-c)+z*s;
	mat[2][1]=y*z*(1-c)+x*s;
}


int main(){

	while(~read(p0)){
		read(p1);
		scanf("%lf",&angle);
		init(p1);
		RM(p1.x,p1.y,p1.z,angle);

		double ans[3];
		for(int i=0;i<3;i++){
			ans[i]=0;
			ans[i]+=p0.x*mat[i][0];
			ans[i]+=p0.y*mat[i][1];
			ans[i]+=p0.z*mat[i][2];
		}

		printf("%.3f %.3f %.3f\n",ans[0],ans[1],ans[2]);

	}

	return 0;
}


