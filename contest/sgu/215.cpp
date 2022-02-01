#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <map>

using namespace std ;

/*Operator Description*/
/*
    0 : (
    1 : )
    2 : !
    3 : +
    4 : -
    5 : *
    6 : /
    7 : ^
    8 : %
*/
const int priority[9][9]=
    { //(  )  ~  +  -  *  /  ^  %
        0, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 1, 1, 1, 1, 1, 1,
        0, 1, 0, 1, 1, 0, 0, 0, 0,
        0, 1, 0, 1, 1, 0, 0, 0, 0,
        0, 1, 0, 1, 1, 1, 1, 0, 1,
        0, 1, 0, 1, 1, 1, 1, 0, 1,
        0, 1, 0, 1, 1, 1, 1, 0, 1,
        0, 1, 0, 1, 1, 1, 1, 0, 1
    };

map <string, string> _map;

inline int sign(int a)
{
    if(a < 0)return -1;
    if(a == 0)return 0;
    return 1;
}

inline int abs(int a)
{
    if(a < 0)return -a;
    return a;
}

void handle(string &s, string &r1, string &r2)
{
    if(s[0] == 'p')
    {
        r1= s;
        for(; r1[0] != ' '; r1.erase(0, 1));
        for(int i(0); i< r1.size(); ++ i)
            if(r1[i] == ' ')
                r1.erase(i --, 1);
    }else
    {
        int pos= 0, len;

        for(; s[pos] != ' '; ++ pos);

        len= s.size();

        for(++ pos; s[pos] != ' '; ++ pos)
            r1+= s[pos];
        for(++ pos; s[pos] != ' ' && pos < len; ++ pos)
            r2+= s[pos];
    }
}

string get_father(string &s)
{
    if(_map.find(s) == _map.end())
        return s;
    return (_map[s]= get_father(_map[s]));
}

inline bool is_operator(char x)
{
    return (x=='^' || x=='+' || x=='-' || x=='*' || x=='/' || x=='%' || x=='(' || x==')');
}

int str2int(string a)
{
    int res= 0;
    a= get_father(a);

    for(int i(0), len(a.size()); i< len; ++ i)
    {
        if(!(a[i] >= '0' && a[i] <= '9'))
            return 0;
        res= res * 10 + (a[i] - '0');
    }
    return res;
}

int power(int a, int b)
{
    int res = 1;
    while (b) {
        if (b & 1)
            res *= a;
        a *= a , b >>= 1;
    }
    return res;
}

bool calc(stack<int> &stk_num, stack<int> &stk_opt)
{
    int opt= stk_opt.top();
    int tmp= stk_num.top(), tmp2;

    if(opt != 0)
    {
        stk_num.pop();
        if(opt != 2)
            tmp2= stk_num.top();
    }
    switch(opt)
    {
        case 0:
            stk_opt.pop(); return 0;
        case 2:
            stk_num.push(0 - tmp); break;
        case 3:
            stk_num.top()= tmp2 + tmp; break;
        case 4:
            stk_num.top()= tmp2 - tmp; break;
        case 5:
            stk_num.top()= tmp2 * tmp; break;
        case 6:
            stk_num.top()= tmp2 / tmp; break;
        case 7:
            if(tmp2 == 1)
                stk_num.top()= 1;
            else
                stk_num.top()= power(tmp2, tmp);
            break;
        case 8:
            stk_num.top()= sign(tmp2) * sign(tmp) * (abs(tmp2) % abs(tmp));
            break;
    }
    stk_opt.pop();
    return 1;
}

int explain(string &opt)
{
    string now;
    stack<int> stk_num, stk_opt;

    for(int pos = 0 , len(opt.size()); pos < len; ++ pos)
    {
        if(!is_operator(opt[pos]))
        {
            now+= opt[pos];
            continue;
        }
        if(now != "")
        {
            stk_num.push(str2int(now));
            now= "";
        }

        int res= -1;
        switch(opt[pos])
        {
            case'(':
                res= 0; break;
            case')':
                res= 1; break;
            case'-':
                if(pos == 0 || (is_operator(opt[pos - 1]) && opt[pos - 1] != ')'))
                {
                    res= 2;
                    break;
                }
                res= 4; break;
            case'+':
                if(pos == 0 || (is_operator(opt[pos - 1]) && opt[pos - 1] != ')'))
                    break;
                res= 3; break;
            case'*':
                res= 5; break;
            case'/':
                res= 6; break;
            case'^':
                res= 7; break;
            case'%':
                res= 8; break;
        }
        if(res == -1) continue;
        while(!stk_opt.empty() && priority[stk_opt.top()][res])
            if(!calc(stk_num, stk_opt))
                break;
        if(res != 1)stk_opt.push(res);
    }
    if(now != "")
        stk_num.push(str2int(now));
    while(!stk_opt.empty())
        calc(stk_num, stk_opt);
    return stk_num.top();
}

void user_define(string &t1, string &t2)
{
    string r2= get_father(t2);
    if(_map.find(t1) == _map.end() && r2 != t1)
        _map[t1]= r2;
}

int main()
{
    while(!cin.eof())
    {
        string opt, t1, t2;
        getline(cin, opt);
        for(int i = 0 , len(opt.size()); i< len; ++ i)
            opt[i]= tolower(opt[i]);
        switch(opt[0])
        {
            case'p':
                handle(opt, t1, t2);
                cout << explain(t1) << endl;
                break;
            case'd':
                handle(opt, t1, t2);
                user_define(t1, t2);
                break;
        }
    }
    return 0 ;
}
