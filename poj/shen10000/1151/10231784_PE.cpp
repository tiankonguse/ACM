#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
struct node
{
int st, ed, c; //c : Çø¼ä±»¸²¸ÇµÄ²ãÊý, m: Çø¼äµÄ²â¶È
double m;
}ST[802];
struct line
{
double x,y1,y2; //×Ý·½ÏòÖ±Ïß, x:Ö±Ïßºá×ø±ê, y1 y2:Ö±ÏßÉÏµÄÏÂÃæÓëÉÏÃæµÄÁ½¸ö×Ý×ø±ê
bool s; //s = 1 : Ö±ÏßÎª¾ØÐÎµÄ×ó±ß, s = 0:Ö±ÏßÎª¾ØÐÎµÄÓÒ±ß
}Line[205];
double y[205],ty[205]; //y[] ÕûÊýÓë¸¡µãÊýµÄ¶ÔÓ¦Êý×é; ty[]:ÓÃÀ´Çóy[]µÄ¸¨ÖúÊý×é
void build(int root, int st, int ed)
{
ST[root].st = st;
ST[root].ed = ed;
ST[root].c = 0;
ST[root].m = 0;
if(ed - st > 1){
int mid = (st+ed)/2;
build(root*2, st, mid);
build(root*2+1, mid, ed);
}
}
inline void updata(int root){
if(ST[root].c > 0)
//½«Ïß¶ÎÊ÷ÉÏÇø¼äµÄ¶Ëµã·Ö±ðÓ³Éäµ½y[]Êý×éËù¶ÔÓ¦µÄ¸¡µãÊýÉÏ,ÓÉ´Ë¼ÆËã³ö²â¶È
ST[root].m = y[ST[root].ed-1] - y[ST[root].st-1];
else if(ST[root].ed - ST[root].st == 1)
ST[root].m = 0;
else ST[root].m = ST[root*2].m + ST[root*2+1].m;
}
void insert(int root, int st, int ed){
if(st <= ST[root].st && ST[root].ed <= ed){
ST[root].c++;
updata(root);
return ;
}
if(ST[root].ed - ST[root].st == 1)return ;//²»³ö´íµÄ»°Õâ¾ä»°¾ÍÊÇÈßÓàµÄ
int mid = (ST[root].ed + ST[root].st)/2;
if(st < mid) insert(root*2, st, ed);
if(ed > mid) insert(root*2+1, st, ed);
updata(root);
}
void Delete(int root, int st, int ed){
if(st <= ST[root].st && ST[root].ed <= ed){
ST[root].c--; updata(root);
return ;
}
if(ST[root].ed - ST[root].st == 1)return ; //²»³ö´íµÄ»°Õâ¾ä»°¾ÍÊÇÈßÓàµÄ
int mid = (ST[root].st + ST[root].ed)/2;
if(st < mid) Delete(root*2, st, ed);
if(ed > mid) Delete(root*2+1, st, ed);
updata(root);
}
int Correspond(int n, double t){
//¶þ·Ö²éÕÒ³ö¸¡µãÊýt ÔÚÊý×éy[]ÖÐµÄÎ»ÖÃ(´Ë¼´ËùÎ½µÄÓ³Éä¹ØÏµ)
int low,high,mid;
low = 0; high = n-1;
while(low < high){
mid = (low+high)/2;
if(t > y[mid])
low = mid + 1;
else high = mid;
}
return high+1;
}
bool cmp(line l1, line l2){
return l1.x < l2.x;
}
int main()
{
int n,i,num,l,r,c=0;
double area,x1,x2,y1,y2;
while(cin>>n, n){
for(i = 0; i < n; i++){
cin>>x1>>y1>>x2>>y2;
Line[2*i].x = x1; Line[2*i].y1 = y1;
Line[2*i].y2 = y2; Line[2*i].s = 1;
Line[2*i+1].x = x2; Line[2*i+1].y1 = y1;
Line[2*i+1].y2 = y2; Line[2*i+1].s = 0;
ty[2*i] = y1; ty[2*i+1] = y2;
}
n <<= 1;
sort(Line, Line+n, cmp);
sort(ty, ty+n);
y[0] = ty[0];
//´¦ÀíÊý×éty[]Ê¹Ö®²»º¬ÖØ¸²ÔªËØ,µÃµ½ÐÂµÄÊý×é´æ·Åµ½Êý×éy[]ÖÐ
for(i=num=1; i < n; i++)
if(ty[i] != ty[i-1])
y[num++] = ty[i];
build(1, 1, num); //Ê÷µÄÒ¶×Ó½ÚµãÓëÊý×éy[]ÖÐµÄÔªËØ¸öÊýÏàÍ¬,ÒÔ±ã½¨Á¢Ò»Ò»¶ÔÓ¦µÄ¹ØÏµ
area = 0;
for(i = 0; i < n-1; i++){
//ÓÉ¶ÔÓ¦¹ØÏµ¼ÆËã³öÏß¶ÎÁ½¶ËÔÚÊ÷ÖÐµÄÎ»ÖÃ
l = Correspond(num, Line[i].y1);
r = Correspond(num, Line[i].y2);
if(Line[i].s) //²åÈë¾ØÐÎµÄ×ó±ß
insert(1, l, r);
else //É¾³ý¾ØÐÎµÄÓÒ±ß
Delete(1, l, r);
area += ST[1].m * (Line[i+1].x -
Line[i].x);
}
printf("Test case #%d\n",++c);
printf("Totalexplored area: %.2f\n\n",area);	
}
return 0;
}
