#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n; 
    cin>>n;
    vector<vector<int> > a(n, vector<int>(n,0) );
    int i, j; 
    for(i = 0; i < n;  ++i){
        for(j = 0; j <= i; ++j){
            cin>>a[i][j];
        }
    }
    
    for(i = n-2; i >=0;  --i){
        for(j = 0; j <= i; ++j){
            a[i][j] +=(a[i+1][j] > a[i+1][j+1])?a[i+1][j]:a[i+1][j+1];            
        }
    }
    cout<<a[0][0]<<endl;

    return 0;
}
