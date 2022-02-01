#include<stdio.h>
#include<queue>
using namespace std;

typedef struct {
	int x,y,num;
}P;

int main()
{
    P a,t;
    int d1,d2;
    char str1[3],str2[3];
    int x,y;
	const int str3[8][2]={
    { 1,2},{ 1,-2},{ 2,1},{ 2,-1},
    {-1,2},{-1,-2},{-2,1},{-2,-1}       
    };
    
 	queue<P> que;
	bool map[8][8]={false}; 		     

 
    while(scanf("%s%s",str1,str2)!=EOF)
    {
		
     for(int i=0;i<8;i++)
	 for(int j=0;j<8;j++)
	     map[i][j]=false;
	 
	 while(!que.empty())que.pop();
	 
	    a.x=str1[0]-'a';
		a.y=str1[1]-'1';
		a.num=0;
	    que.push(a);		
		
		d1=str2[0]-'a';
		d2=str2[1]-'1';         

	    
		while(!que.empty())
		{
			t=que.front();
			que.pop();
				
			if(t.x==d1 && t.y==d2)
			{
				printf("To get from %s to %s takes %d knight moves.\n",str1,str2,t.num);
				break;	
		    }
		    
		    for(int i=0;i<8;i++)
		    {
				x=t.x+str3[i][0];
				y=t.y+str3[i][1];
					
				if(x<0||y<0||x>=8||y>=8)continue;
				if(map[x][y])continue;
				
				a.x=x;
				a.y=y;
				a.num=t.num+1;
				map[x][y]=true;	
					
				que.push(a);	
					
			}
		    
		    
		    
		    
	    }                                   
                                       
    }
    
    getchar();getchar();
return 0;    
}
