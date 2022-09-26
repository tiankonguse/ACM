//C简单一点的做法
#include <bits/stdc++.h>
using namespace std ;

void solve(){
  string s ;
  cin >> s ;
  for( int i = 0 ;i < s.size() ;i ++ ){
    if( s[i] > s[s.size()-i-1] ){
      cout << 0 << endl ;
      return ;
    }
    if( s[i] < s[s.size()-i-1] ){
      break ;
    }
  }
  set<char> S( s.begin() ,s.end() ) ;
  if( S.size() == 1 ){
    cout << "Impossible" << endl ;
    return ;
  }
  string t = s ;
  reverse( t.begin() ,t.end() ) ;
  s += t ;
  int k = 0, j = 1;
  int n = s.size() ;
  while( k < n / 2 && j < n / 2 ){
    if( s[k] == s[j+k] ) k ++ ;
    else{
      if( s[k] > s[j+k] ){
        cout << 1 << endl ;
        return ;
      }
      j = j + k + 1 ;
      k = 0 ;
    }
  }
  cout << 2 << endl ;
}

int main(){
  solve() ;
}