#include"iostream"
#include"cstdlib"
#include"algorithm"
using namespace std;
struct node{
       int id,cnt;
       bool operator<(const node &b)const{
            return cnt<b.cnt;
       }
}nodes[101];
template<typename T>
void Merge(T *data,int left,int middle,int right,T *cache,int &count){
   int i,j,sp=0;
   for(i=left,j=middle+1;i<=middle && j<=right;){
       if(data[i]>data[j]){
          count+=(middle-i+1);
          cache[sp++]=data[j++];
       }
       else cache[sp++]=data[i++];
   }
   while(i<=middle)cache[sp++]=data[i++];
   while(j<=right)cache[sp++]=data[j++];
   for(i=0;i<sp;i++)data[left+i]=cache[i];
}
template<typename T>
void MergeSort(T *data,int left,int right,T *cache,int &count){
   if(right>left){
       int middle=(left+right)/2;
       MergeSort(data,left,middle,cache,count);
       MergeSort(data,middle+1,right,cache,count);
       Merge(data,left,middle,right,cache,count);
   }
}
int main(){
    int n,m,count;
    char data[51];
    char cache[51];
    char dat[101][51];
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
       for(int j=0;j<n;j++){
          scanf(" %c",&data[j]);
       }
       nodes[i].id=i;
       count=0;
       memcpy(dat[i],data,n);
       MergeSort<char>(data,0,n-1,cache,count);
       nodes[i].cnt=count;
    }
    sort(nodes,nodes+m);
    
    for(int i=0;i<m;i++){
       for(int j=0;j<n;j++)printf("%c",dat[nodes[i].id][j]);
       printf("\n");
    }
    return 0;
}
