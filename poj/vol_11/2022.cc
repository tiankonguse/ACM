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
#include <stack>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

using namespace std;

bool isHtml(string s);
bool isBody(string s);
bool isText(string s);
bool isString(string s);
bool isTag(string s);
bool isBold(string s);
bool isItalics(string s);
bool isLink(string s);
bool isUrl(string s);
bool isHref(string s);

bool isHtml(string s){
    int n = s.length();
    if(n < 13) return false;
    string s1 = s.substr(0, 6);
    string s2 = s.substr(n - 7);
    string s3 = s.substr(6, n - 13);
    if(s1 != "<HTML>" || s2 != "</HTML>") return false;
    else return isBody(s3);
}
bool isBody(string s){
    int n = s.length();
    if(n < 13) return false;
    string s1 = s.substr(0, 6);
    string s2 = s.substr(n - 7);
    string s3 = s.substr(6, n - 13);
    if(s1 != "<BODY>" || s2 != "</BODY>") return false;
    else return isText(s3);
}
struct node{
    int l, d;
    node(){}
    node(int _l, int _d){ l = _l, d = _d; }
}tmp;

bool isText(string s){
    int n = s.length();
    int p = 0, q, r = 0, d;
    int top = 0;
    stack <node> st;
    string s1, s2;
    bool flag = false;
    for(int i=0;i<n;i++){
        if(s[i] == '<'){
           if(top == 0){
               s1 = s.substr(p, i - p);
               if(!isString(s1)) return false;
           }
           q = i;
           while(i < n && s[i] != '>') i++;
           if(s[i] != '>') return false;
           p = i + 1;

           s1 = s.substr(q, i - q + 1);
           if(s1 == "<B>") st.push( node(q, 1) );
           else if(s1 == "<I>") st.push( node(q, 2) );
           else if(isHref(s1)) st.push( node(q, 3) );
           else if(s1 == "</B>"){
               if(st.empty()) return false;
               tmp = st.top();
               st.pop();
               s2 = s.substr(tmp.l, i - tmp.l + 1);
               if(!isBold(s2)) return false;
           }
           else if(s1 == "</I>"){
               if(st.empty()) return false;
               tmp = st.top();
               st.pop();
               s2 = s.substr(tmp.l, i - tmp.l + 1);
               if(!isItalics(s2)) return false;

           }
           else if(s1 == "</A>"){
               if(st.empty()) return false;
               tmp = st.top();
               st.pop();
               s2 = s.substr(tmp.l, i - tmp.l + 1);
               if(!isLink(s2)) return false;

           }
           else return false;
        }

    }
    if(!st.empty()) return false;
    s1 = s.substr(p);
    if(!isString(s1) && !isTag(s1)) return false;
    else return true;
}
bool isString(string s){
    int n = s.length();
    for(int i=0;i<n;i++){
        if(s[i] == '<' || s[i] == '>') return false;
    }
    return true;
}
bool isTag(string s){
    return isBold(s) || isItalics(s) || isLink(s);
}
bool isBold(string s){
    int n = s.length();
    if(n < 7) return false;
    string s1 = s.substr(0, 3);
    string s2 = s.substr(n - 4);
    string s3 = s.substr(3, n - 7);
    if(s1 != "<B>" || s2 != "</B>") return false;
    else return isText(s3);
}
bool isItalics(string s){
    int n = s.length();
    if(n < 7) return false;
    string s1 = s.substr(0, 3);
    string s2 = s.substr(n - 4);
    string s3 = s.substr(3, n - 7);
    if(s1 != "<I>" || s2 != "</I>") return false;
    else return isText(s3);
}
bool isLink(string s){
    int n = s.length();
    if(n < 13) return false;
    string s1 = s.substr(0, 8);
    string s2 = s.substr(n - 4);
    if(s1 != "<A HREF=" || s2 != "</A>") return false;
    int p;
    for(p=8;p<n-4;p++) if(s[p] == '>') break;
    string s3 = s.substr(8, p - 8);
    string s4 = s.substr(p + 1, n - p - 5);
    return isUrl(s3) && isText(s4);
}
bool isUrl(string s){
    int n = s.length();
    if(n < 11) return false;
    string s1 = s.substr(0, 7);
    string s2 = s.substr(n - 4);
    string s3 = s.substr(7, n - 11);
    if(s1 != "http://" || s2 != ".com") return false;
    else return isString(s3);
}
bool isHref(string s){
    int n = s.length();
    if(n < 9) return false;
    string s1 = s.substr(0, 8);
    string s2 = s.substr(n - 1);
    string s3 = s.substr(8, n - 9);
    if(s1 != "<A HREF=" || s2 != ">") return false;
    else return isString(s3);
}
int main(){
    int n;
    string s;
    cin>>n;
    cin.ignore();
    while(n--){
        getline(cin, s);
        if(isHtml(s)) cout<<"Syntax Included"<<endl;
        else cout<<"No Syntax Included"<<endl;
    }
    return 0;
}
