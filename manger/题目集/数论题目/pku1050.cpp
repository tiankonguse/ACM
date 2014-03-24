
#include <iostream>
#include <limits>
using namespace std;

/*求数据A的最大子串和,n为数组长度*/
int max_sub_array(int* arr, int n) 
{ 
    int maxsum = INT_MIN, b = 0; 
    
    for (int i = 0; i < n ; i++) { 
        if (b > 0) {
            b += arr[i];
        }
        else {
            b = arr[i];
        }
        maxsum = (b > maxsum)? b : maxsum;
    } 
    return maxsum; 
} 

/*求矩阵A的最大子矩阵和,矩阵规模 m行n列*/
int max_sub_matrix(int** A, int m, int n) 
{ 
    int* B = new int[m];
    int maxsum = 0, cursum = 0; 
    
    for (int i = 0; i < m; i ++) { 
        memset(B, 0, n*sizeof(0));
        for ( int j = i; j < m; j ++) { 
            for (int k = 0; k < n; k++) {
                B[k] += A[j][k]; 
            }
            cursum = max_sub_array(B, n);
            maxsum = (cursum > maxsum)? cursum : maxsum;
        } 
    } 

    delete B;
    return maxsum; 
} 


int main()
{ 
    int n ;
    
   // cout<<"输入矩阵的行数和列数:"<<endl;
    cin>>n;    
    
    int **a = new int*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[n];
    } 
    //cout<<"请输入"<<m*n<<"个整数:"<<endl;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cin>>a[r][c];
        }
    }
    
    cout<<max_sub_matrix(a, n, n)<<endl;
    delete [] a;
    
    return 0;
}


