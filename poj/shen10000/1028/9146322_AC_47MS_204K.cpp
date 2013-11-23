#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{ 
	string s;
	stack<string> s1;
	stack<string> s2;
	s1.push("http://www.acm.org/");
	
	while(cin>>s,s!="QUIT")
	{
		if(s=="BACK")
		{
			
			s=s1.top();s1.pop();
			
			if(s1.empty())
			{
				cout<<"Ignored"<<endl;	
				s1.push(s);
			}
			else
			{
				cout<<s1.top()<<endl;	
				s2.push(s);
			}	
		}
		else if(s=="FORWARD")
		{
			if(s2.empty())
			{
				cout<<"Ignored"<<endl;	
			}
			else
			{
				s=s2.top();s2.pop();
				cout<<s<<endl;
				s1.push(s);
			}
		}
		else if(s=="VISIT")
		{
			cin>>s;
			s1.push(s);
			while(!s2.empty())s2.pop();
			cout<<s<<endl;
			
		}
	}

return 0;
}
