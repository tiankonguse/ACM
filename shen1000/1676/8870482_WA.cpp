#include<iostream>
using namespace std;
int m=12,a1,a2,b1,b2;
int y1,y2,y3,y4,x1,x2,x3,x4,z1,z2,z3,z4;
char cstr1[3][12],cstr2[3][12];
int istr1[4][10],istr2[4][10],istr3[3][12]; 
 char str[10][3][4]={{" _ ","| |","|_|"},
                     {"   ","  |","  |"},  
                     {" _ "," _|","|_ "},  
                     {" _ "," _|"," _|"},
					 {"   ","|_|","  |"},
					 {" _ ","|_ "," _|"},
					 {" _ ","|_ ","|_|"},
					 {" _ ","  |","  |"},
					 {" _ ","|_|","|_|"},
					 {" _ ","|_|"," _|"}
					};  
   
 void f_cin()//输入 
 {
  int i,j;
  for(j=0;j<3;j++)
  {
        for(i=0;i<m;i++)cstr1[j][i]=getchar();         
getchar();          
     for(i=0;i<m;i++)cstr2[j][i]=getchar();         
getchar();  
  }                 
 }

 void f_cout1()//输出所有输入的 
 {
int i,j;

	for(i=0;i<3;i++)
	for(j=0;j<12;j++)
	{
		cout<<cstr1[i][j];
		if(j==11)cout<<endl;		
	}
			
	for(i=0;i<3;i++)
	for(j=0;j<12;j++)
	{
		cout<<cstr2[i][j];
		if(j==11)cout<<endl;		
	}				
}


 void  f_cout2()//判断表的正误 
 {
int i,j,k;

	for(i=0;i<10;i++)
	for(j=0;j<3;j++)
	for(k=0;k<3;k++)
	{
		cout<<str[i][j][k];
		if(k==2)cout<<endl;	
	}				
}
 
 void f_fun1()//计算正确时间 
 {
	int i,j,k;
			
	int istr[12]; 
	  memset(istr,1,sizeof(istr));  
 
	 for(int p=0,j=0;j<12;j++)
	  {
	  
		  for(i=0;i<3;i++)
		     for(k=0;k<10;k++)
		        if(istr[k] && (cstr1[i][j]!=32)&&(str[k][i][j%3]==32) )
		           istr[k]=0;
					
		 if(p==0)for(int n=3;n<10;n++)istr[n]=0;
		 if(p==2)for(int n=6;n<10;n++)istr[n]=0;
		 
		  if(j%3==2)
		 {
		   int i,j=0;
		   for(i=0;i<10;i++)
		       if(istr[i]){j++;istr1[p][j]=i;}		
		   istr1[p][0]=j;
		   p++;	
		   memset(istr,1,sizeof(istr));	
		 }
	  }				
}
 void f_fun2()//计算慢15分的时间 
 {
	int i,j,k;		
	int istr[12]; 
	memset(istr,1,sizeof(istr)); 
	 
	  for(int p=0,j=0;j<12;j++)
	  {
	  
		  for(i=0;i<3;i++)
		     for(k=0;k<10;k++)
		        if(istr[k] && (cstr2[i][j]!=32)&&(str[k][i][j%3]==32) )
		           istr[k]=0;
						
		 if(p==0)for(int n=3;n<10;n++)istr[n]=0;
		 if(p==2)for(int n=6;n<10;n++)istr[n]=0;
	 
		  if(j%3==2)
		 {
		   int i,j=0;
		   for(i=0;i<10;i++)
		   if(istr[i]){j++;istr3[p][j]=i;istr2[p][i]=i;}
           istr3[p][0]=j;		
		   p++;	
		   memset(istr,1,sizeof(istr));	
		 }
	  }		
}
		   
	
void f_cout3()//输出计算的结果 
{
     
	int i,j,k;
	for(i=0;i<4;i++)
	{
		k=istr1[i][0];
		for(j=0;j<=k;j++)
		printf("%d ",istr1[i][j]);
		printf("\n");		
	}
	cout<<'\n';
	for(i=0;i<4;i++)
	{
		k=istr3[i][0];
		for(j=0;j<=k;j++)
		printf("%d ",istr3[i][j]);
		printf("\n");		
	}
		cout<<'\n';
	for(i=0;i<4;i++)
	{
		for(j=0;j<10;j++)
		printf("%d ",istr2[i][j]);
		printf("\n");	
		
	}	
    	cout<<'\n';	
}

int f_fun4()//综合计算 
{
	int i,j,hhh;
	a1=0;a2=0;b1=0;b2=0;
for(i=1;i<=istr1[0][0];i++)
{
	for(j=1;j<=istr1[1][0];j++)
	{
		int p1=istr1[0][i];
		int p2=istr1[1][j];
		hhh=p1*10+p2;
		if(istr2[0][p1]!=-1 && istr2[1][p2]!=-1&&hhh<24){a1++;y1=p1;y2=p2;}
		
		if(a2>1)continue;
		int l=a2;
		if(p2==0)
		{
			if(      p1==0 && istr2[0][5]!=-1 && istr2[1][9]!=-1)a2++;	
			else if	(p1==1 && istr2[0][0]!=-1 && istr2[1][9]!=-1)a2++;
			else if	(p1==2 && istr2[0][1]!=-1 && istr2[1][9]!=-1)a2++;
		}	
		else
		{
			if(istr2[0][p1]!=-1 && istr2[1][p2-1]!=-1&&hhh<24)a2++;		
		}
		if(l<a2){x1=p1;x2=p2;}		
	}
if(a2>1 && a1>1)return 0;
}

for(i=1;i<=istr1[2][0];i++)
{
	for(j=1;j<=istr1[3][0];j++)
	{
		int p1=istr1[2][i];
		int p2=istr1[3][j];		
		int hhh=p1*10+p2;
		
		if(hhh<15&&a2)
		{
    		hhh=hhh+60-15;
    		int p3=hhh/10;
    		int p4=hhh%10;			

		 if(istr2[2][p3]!=-1 && istr2[3][p4]!=-1){b2++;x3=p1;x4=p2;}		
		}
		else if(hhh>=15&&a1)
		{
		hhh=hhh-15;
		int p3=hhh/10;
		int p4=hhh%10;			
		if(istr2[2][p3]!=-1&&istr2[3][p4]!=-1){b1++;y3=p1;y4=p2;}			
		}
    }
if(a1*b1+a2*b2>1)return 0;
}	
if(a1==1&&b1==1){z1=y1;z2=y2;z3=y3;z4=y4;return 1;}
if(a2==1&&b2==1){z1=x1;z2=x2;z3=x3;z4=x4;return 1;}	
}

int main()
{


  int n;
  cin>>n;
  getchar();
  while(n--)
  {
 x1=0,x2=0,x3=0,x4=0;
y1=0,y2=0,y3=0,y4=0;
z1=0,z2=0,z3=0,z4=0;           
   memset(istr2,-1,sizeof(istr2));             
   memset(istr1,-1,sizeof(istr1));             
    memset(istr3,-1,sizeof(istr3));             
 
 //f_cout2();               
  f_cin();
//f_cout1();

  f_fun1();


  f_fun2();
 //f_cout3();
//continue;
  if(f_fun4())
    printf("%d%d%d%d\n",z1,z2,z3,z4);
  else
	printf("Not Sure\n");   
  }
  
  
  //  getchar();getchar();
return 0;    
}

/*
 _  _  _  _   _  _     _ 
| || || || |  _| _||_||_ 
|_||_||_||_| |_  _|  | _|
                 _  _  _ 
  |  |  |  |   || ||_ |_|
| | _|  |  |   ||_| _||_|
    _  _  _      _     _ 
  | _  _||       _   ||  
  | _ |_   |   | _    |_|
    _  _  _   _  _     _ 
  ||_  _||       _|  ||  
  | _ |_   |   ||     |_|



*/
