#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N = 100010;
struct NODE{
int b, e; // Çø¼ä[b, e]
int l, r; // ×óÓÒ×Ó½ÚµãÏÂ±ê
int number;// Çø¼äÄÚµÄ×î´óÆµÂÊÖµ
int last; // ÒÔdata[e] ½áÎ²ÇÒÓëdata[e] ÏàÍ¬µÄ¸öÊý:data[e-last+1]...data[e]
}node[N*2+1];
int len, data[N];
int build(int a, int b){ // ½¨Á¢Ïß¶ÎÊ÷
int temp = len, mid = (a+b)/2;
node[temp].b = a, node[temp].e = b;
len++;
if( a == b ){
node[temp].number = 1;
node[temp].last = 1; //
return temp;
}
node[temp].l = build(a, mid);
node[temp].r = build(mid+1, b);
int left_c=node[temp].l, right_c=node[temp].r, p,
lcount=0, rcount=0, rec, max=0;
rec = data[mid]; p = mid;
while( p >= a && data[p] == rec ) { p--, lcount++; }
node[left_c].last = lcount; //
rec = data[mid+1]; p = mid+1;
while( p <= b && data[p] == rec ) { p++, rcount++; }
node[right_c].last = rcount;//
if( data[mid] == data[mid+1] ) max = lcount+rcount;
if( node[left_c].number > max ) max =
node[left_c].number;
if( node[right_c].number > max ) max =
node[right_c].number;
node[temp].number = max;
return temp;
}
int query(int index, int a, int b){
int begin=node[index].b, end=node[index].e,
mid=(begin+end)/2;
if( a == begin && b == end ) return node[index].number;
if( a > mid ) return query(node[index].r, a, b);
if( b < mid+1 ) return query(node[index].l, a, b);
int temp1, temp2, max;
if( node[index].l > 0 ) temp1 = query(node[index].l,
a, mid);
if( node[index].r > 0 ) temp2 = query(node[index].r,
mid+1, b);
max = temp1 > temp2 ? temp1 : temp2;
if( data[mid] != data[mid+1] ) return max;
temp1 = node[ node[index].l ].last > (mid-a+1) ?
(mid-a+1) : node[ node[index].l ].last;
temp2 = node[ node[index].r ].last > (b-mid) ? (b-mid) :
node[ node[index].r ].last;
if( max < temp1+temp2 ) max = temp1+temp2;
return max;
}

int main(){
int n;
while( scanf("%d", &n), n ){
int i, q, a, b;
scanf("%d", &q);
for( i=0; i < n; i++ ) scanf("%d", &data[i]);
len = 0; // ÏÂ±ê
build(0, n-1);
while( q-- ){
scanf("%d%d", &a, &b);
printf("%d\n", query(0, a-1, b-1)); // Êä³öÇø¼äµÄ×î´óÆµÂÊÖµ,¶ø·Çdata[]
}
}
return 0;
}
