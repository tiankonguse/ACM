#include"iostream"
#include"string"
using namespace std;
void cal_tree(string sa, string sb)                      
{
    if(sb.length() == 0) return;
    if(sb.length() == 1) {cout << sb;return;}
    char x=sa[0];
    int mid=sb.find(x);
    string c=sb.substr(0,mid);
    string d=sb.substr(mid+1);
    cal_tree(sa.substr(1,c.length()),c);
    cal_tree(sa.substr(1+c.length()),d);
    cout<<x;
}

int main(){
    string a,b;
    while(cin>>a>>b){
        cal_tree(a,b);
        cout<<endl;
    }
    return 0;
}
