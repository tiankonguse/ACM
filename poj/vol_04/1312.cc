/*
  Duze liczby z ustalana podstawa
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef unsigned long long digit;

#define MAX_DIGIT 10
#define MAX_LENGTH 1 // MAX_DIGIT=10^MAX_LENGTH

class BigNum {
public:
  vector<digit> data;

  void shrink() {
    while (data.size()>1 && !data[data.size()-1])
      data.resize(data.size()-1);
  }

    BigNum(digit i=0) {
      data.resize(1,i%MAX_DIGIT);
      i/=MAX_DIGIT;
      while (i) {
        data.resize(data.size()+1);
        data.back()=i%MAX_DIGIT;
        i/=MAX_DIGIT;
      }
    }

    explicit BigNum(const char* t) {
      int n=0,i,j,k;
      while (t[n])
        n++;
      for (i=n-1; i>=0; i-=MAX_LENGTH) {
        k=0;
        for (j=MAX_LENGTH-1; j>=0; j--)
          if (i-j>=0)
            k=10*k+t[i-j]-'0';
        data.push_back(k);
      }
      shrink();
    }

    BigNum &operator--() {
      int i=0;
      while (!data[i]) {
        data[i]=MAX_DIGIT-1;
        i++;
      }
      data[i]--;
      return *this;
    }

    BigNum &operator++() {
      int i=0;
      while (data[i]+1==MAX_DIGIT) {
        data[i]=0;
        i++;
      }
      data[i]++;
      return *this;
    }

    BigNum &operator+=(const BigNum &a) {
      digit i=0,p=0;
      while (p || i<data.size() || i<a.data.size()) {
        if (i<data.size())
          p+=data[i];
        if (i<a.data.size())
          p+=a.data[i];
        if (i>=data.size())
          data.resize(i+1);
        if (p>=MAX_DIGIT) {
          data[i]=p-MAX_DIGIT;
          p=1;
        }
        else {
          data[i]=p;
          p=0;
        }
        i++;
      }
      return *this;
    }

    BigNum &operator-=(const BigNum &a) {
      digit p=0;
      for (int i=0; i<data.size() || p; i++) {
        if (i<a.data.size())
          p+=a.data[i];
        if (p<=data[i]) {
          data[i]-=p;
          p=0;
        }
        else {
          data[i]+=MAX_DIGIT-p;
          p=1;
        }
      }
      shrink();
      return *this;
    }

    BigNum operator+(BigNum a) {
      BigNum r=*this;

      r+=a;
      return r;
    }

    BigNum operator-(BigNum a) {
      BigNum r=*this;

      r-=a;
      return r;
    }

    digit operator%(digit d) {
      digit p=0;
      for (int i=data.size()-1; i>=0; i--)
        p=(p*MAX_DIGIT+data[i])%d;
      return p;
    }

    BigNum operator*(const BigNum &a) {
      BigNum r;
      if(zero()||a.zero())return r;
      for (int i=0; i<data.size(); i++) {
        BigNum t=a;
        t*=data[i];
        t.data.resize(t.data.size()+i);
        for (int j=t.data.size()-i-1; j>=0; j--)
          t.data[j+i]=t.data[j];
        for (int j=0; j<i; j++)
          t.data[j]=0;
        r+=t;
      }
      r.shrink();
      return r;
    }

    BigNum operator/(BigNum a) {
      BigNum ans,t=*this,power=1,ta=a;

      while (ta<t) {
        power*=10;
        ta*=10;
      }
      while (!power.zero()) {
        while (ta<t || ta==t) {
          ans+=power;
          t-=ta;
        }
        power/=10;
        ta/=10;
      }
      return ans;
    }

    BigNum operator%(BigNum a) {
      return *this-(*this/a)*a;
    }

    BigNum &operator*=(digit m) {
      digit p=0;
      for (int i=0; p || i<data.size(); i++) {
        if (i<data.size())
          p+=m*data[i];
        if (i>=data.size())
          data.resize(i+1);
        data[i]=p%MAX_DIGIT;
        p/=MAX_DIGIT;
      }
      return *this;
    }

    BigNum &operator/=(digit d) {
      digit p=0;
      for (int i=data.size()-1; i>=0; i--) {
        p=p*MAX_DIGIT+data[i];
        data[i]=p/d;
        p%=d;
      }
      shrink();
      return *this;
    }

    bool operator==(const BigNum &x) const {
      if (data.size()!=x.data.size())
        return false;
      int i=0;
      while (i<data.size() && data[i]==x.data[i])
        i++;
      return i==data.size();
    }

    bool operator<(const BigNum &x) const {
      if (x.data.size()!=data.size())
        return data.size()<x.data.size();
      int i=data.size()-1;
      while (i>=0 && data[i]==x.data[i])
        i--;
      return i>=0 && data[i]<x.data[i];
    }

    bool zero() const {
      return data.size()==1 && !data[0];
    }

    friend ostream &operator<<(ostream &out,const BigNum &a) {
      out<<a.data[a.data.size()-1];
      for (int i=a.data.size()-2; i>=0; i--) {
        digit j=a.data[i]+!a.data[i];
        while (j<MAX_DIGIT/10) {
          out<<0;
          j=j*10;
        }
       out<<a.data[i];
      }
      return out;
    }
}A;

string s, res;
int main(){
    int n, m, d;
    char ch;
    while(cin>>s && s[0] != '*'){
        n = s.length();
        if(s[0] >= '0' && s[0] <= '9'){
            A = BigNum(s.c_str());
            res = "";
            m = 0;
            while(!A.zero()){
                m++;
                A = A - 1;
                ch = A % 26 + 'a';
                res = ch + res;
                A /= 26;
            }
            cout<<res;
            for(int i=m+1;i<23;i++) cout<<" ";
            for(int i=0;i<n;i++){
                cout<<s[i];
                if(i == n - 1) cout<<endl;
                else if((n - i - 1) % 3 == 0) cout<<",";
            }
        }
        else{
            A = BigNum();
            for(int i=0;i<n;i++){
                d = s[i] - 'a' + 1;
                A *= 26;
                A += d;
            }
            cout<<s;
            for(int i=n+1;i<23;i++) cout<<" ";
            m = A.data.size();
            for(int i=m-1;i>=0;i--){
                cout<<A.data[i];
                if(i == 0) cout<<endl;
                else if(i % 3 == 0) cout<<",";
            }
        }
    }
    return 0;
}
