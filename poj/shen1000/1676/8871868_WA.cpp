#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
/*
共有四位，时间范围是0000~2359,所以第一位小于3，第三位小于6.这样就能找出每位所有的可能数字 
*/
 
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
		   int i,s=0;
		   for(i=0;i<10;i++)
		   if(istr[i]){s++;istr3[p][s]=i;istr2[p][i]=i;}
		   	istr3[p][0]=s;	
		   p++;	
		   memset(istr,1,sizeof(istr));	
		 }
	  }		
}
		   
/*
共有四位，时间范围是0000~2359,
对于头两位，p1,p2;若不需借位，只需判断p1p2是否小于24且在第二个数组中存在就ok了。符合条件的记为a1,时间记为y1,y2。 
若需要借一位，先判断p1p2是否为00，是的话判断23是否在第二个数组，不是00的话，直接减一然后判断是否在第二个数组 。符合条件的记为a2,时间记为x1,x2;

对于后两位，同样道理。
若不需借位且存在不需借位的头两位，既p1p2大于等于15，直接减15，然后判断是否在第二个数组。符合条件的记为b1,时间记为y3,y4.
若需要借位且存在需借位的头两位，既p1p2小于15，那么先加60再减15，然后判断否在第二个数组。符合条件的记为b2,时间记为x3,x4.
*/	


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
		if(hhh>=24)continue; 
		
		if(istr2[0][p1]!=-1 && istr2[1][p2]!=-1){a1++;y1=p1;y2=p2;}
		if((a2==2) && (a1==2))return 0;
		if(a2==2)continue;
		
		int l=a2;
		
		if(hhh==0)
		{
           if(istr2[0][2]!=-1 && istr2[1][3]!=-1){a2++;}     
	   }
		else
        {
	        hhh-=1;
	        int p3=hhh/10;
	        int p4=hhh%10;    
	        if(istr2[0][p3]!=-1 && istr2[1][p4]!=-1){a2++;}	
        }
        
		if(l<a2){x1=p1;x2=p2;}	
			
	}
if((a2==2)&& (a1==2))return 0;
}

for(i=1;i<=istr1[2][0];i++)
{
	for(j=1;j<=istr1[3][0];j++)
	{
		if(a1*b1+a2*b2>1){return 0;}
		int p1=istr1[2][i];
		int p2=istr1[3][j];		
		hhh=p1*10+p2;
		
		if(hhh<15&&a2==1){
	    	 hhh=hhh+60-15;
			 if(istr2[2][hhh/10]!=-1 && istr2[3][hhh%10]!=-1)
			 {b2++;x3=p1;x4=p2;}		
		}
		else if(hhh>=15&&a1==1){
			hhh=hhh-15;			
			if(istr2[2][hhh/10]!=-1&&istr2[3][hhh%10]!=-1)
			 {b1++;y3=p1;y4=p2;}			
		}
		
		
    }

}	
if(a1==1&&b1==1){z1=y1;z2=y2;z3=y3;z4=y4;return 1;}
if(a2==1&&b2==1){z1=x1;z2=x2;z3=x3;z4=x4;return 1;}	
return 0;
}

int main()
{


  int n;
  scanf("%d",&n);
  getchar();
  while(n--)
  {          
	   memset(istr2,-1,sizeof(istr2));             
	   memset(istr1,-1,sizeof(istr1));             
	   memset(istr3,-1,sizeof(istr3));             
	          
	            
	  f_cin();
	
	
	  f_fun1();
	
	  f_fun2();

	  if(f_fun4())
	  {
	    printf("%d%d%d%d\n",z1,z2,z3,z4);
	  }
	  else
	  {
		printf("Not Sure\n");   
	   }
  }
getchar();getchar();
return 0;    
}
