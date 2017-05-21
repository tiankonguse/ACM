#include"iostream"
#define MAXN 1001
using namespace std;
int a[MAXN],c[MAXN];
__int64 cnt;
void MergeSort(int l, int r){
int mid, i, j, tmp;
  if( r > l+1 ){
      mid = (l+r)/2;
      MergeSort(l, mid);
      MergeSort(mid, r);
      tmp = l;
      for( i=l, j=mid; i < mid && j < r; ){
          if( a[i] > a[j] ){
              c[tmp++] = a[j++];
              cnt += mid-i; 
          }
          else c[tmp++] = a[i++];
      }
      if( j < r ) for( ; j < r; ++j ) c[tmp++] = a[j];
      else for( ; i < mid; ++i ) c[tmp++] = a[i];
      for ( i=l; i < r; ++i ) a[i] = c[i];
  }
}
int main(){
    int T,N;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%d",&N);
        for(int j=0;j<N;j++)scanf("%d",&a[j]);
        cnt=0;
        MergeSort(0,N);
        printf("Scenario #%d:\n%I64d\n\n",i,cnt);
    }
  //  system("pause");
    return 0;
}
