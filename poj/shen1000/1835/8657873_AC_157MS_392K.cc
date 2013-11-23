#include <stdio.h>
int x,y,z,p,l,u;
 char diret[20];

int rev(int dec)
{
    switch(dec)
    {
    case 0:return 3;
    case 1:return 4;
    case 2:return 5;
    case 3:return 0;
    case 4:return 1;
    case 5:return 2;
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        x=y=z=p=0;
        l=4;
        u=2;
        int step,t,temp;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%s%d",diret,&step);
            switch(diret[0])
            {
                case 'f':break;
                case 'b':p=rev(p);l=rev(l);break;
                case 'l':temp=l;l=rev(p);p=temp;break;
                case 'r':temp=p;p=rev(l);l=temp;break;
                case 'u':temp=u;u=rev(p);p=temp;break;    
                case 'd':temp=p;p=rev(u);u=temp;break;
            }
            switch(p)
            {
                case 0:x+=step;break;
                case 1:y+=step;break;
                case 2:z+=step;break;
                case 3:x-=step;break;
                case 4:y-=step;break;
                case 5:z-=step;break;
            }   
        }  
        printf("%d %d %d %d\n",x,y,z,p);
    }

    return 0;
} 
 
