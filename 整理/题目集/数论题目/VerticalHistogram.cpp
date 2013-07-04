#pragma warning(disable:4786) 
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string sLine;
    int a[26] = {0};
    for(int lines = 1; lines <= 4; ++lines) 
    {
        getline(cin, sLine);
        for(int i = 0; i < sLine.size(); ++i)
        {
            if( isupper(sLine[i]) )
            {
                a[sLine[i]-'A']++;
            }
        }
    }
    
    int max_r = *max_element(a, a+26);
    vector<string> chars(max_r, string(26, ' '));
    
    int r, c, x;
    
    for(c = 0; c < 26; ++c){
        for(x = 1; x <= a[c]; ++x) 
        {
            chars[max_r-x][c] = '*' ;
        }
    }
    
    for(r = 0; r < max_r; ++r)
    {
        chars[r] = chars[r].substr(0,chars[r].find_last_not_of(' ')+1);
    }
    
    for(r = 0; r < max_r; ++r)
    {
        for(c = 0; c < chars[r].size()-1; ++c)
        {
            cout<<chars[r][c]<<" ";      
        }
          cout<<chars[r][chars[r].size()-1]<<endl;

    }
    cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z"<<endl;
    return 0;
}
