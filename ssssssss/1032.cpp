#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N=1010;
int m,n,k,l,d;
struct TT{
	int num,val;
}row[N],line[N];
bool cmp1(TT a,TT b){
	return a.val>b.val;
}
bool cmp2(TT a,TT b){
	return a.num<b.num;
}
int _min(int a,int b){
	return a<b?a:b;
}
void init(){
	for(int i=0;i<=m;i++)line[i].num=i;;
	for(int i=0;i<=n;i++)row[i].num=i;;
}
int x1,y1,x2,y2;
int main(){
	while(~scanf("%d%d%d%d%d",&m,&n,&k,&l,&d)){
		init();
		while(d--){
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(x1==x2){
				//printf("%d\n",_min(y1,y2));
				row[_min(y1,y2)].val++;
				
			}else if(y1==y2){
				//printf("%d\n",_min(x1,x2));
				line[_min(x1,x2)].val++;
			}
		}
		sort(line,line+m,cmp1);
		sort(line,line+k,cmp2);
		sort(row,row+n,cmp1);
		sort(row,row+l,cmp2);
		
		for(int i=0;i<k;i++){
			if(i)cout<<" ";
			cout<<(line[i].num);	
		}
		cout<<endl;
		for(int i=0;i<l;i++){
			if(i)cout<<" ";
			cout<<(row[i].num);
		}cout<<endl;
	}
	return 0;
}
