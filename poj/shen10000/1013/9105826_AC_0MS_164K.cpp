#include <stdio.h>
#include <string.h>

char left[3][7],right[3][7],result[3][7];
bool Heavy(char);
bool Light(char);

int main()
{
	int n;
	int i;

	scanf("%d",&n);
	while(n--)
	{
		for(i=0;i<3;i++)
		scanf("%s%s%s",left[i],right[i],result[i]);

		for(i='A';i<='L';i++){
			if(Light(i)){
				printf("%c is the counterfeit coin and it is light.\n",i);
				break;
			}
			if(Heavy(i)){
				printf("%c is the counterfeit coin and it is heavy.\n",i);
				break;
			}
		}
	}
	return 0;
}

bool Light(char x) 
{
	for(int i=0;i<3;i++)  
		switch(result[i][0])
		{
		case 'u':
			if(strchr(right[i],x)==NULL) 
				return false;
			break;
		case 'e':
			if(strchr(right[i],x)!=NULL || strchr(left[i],x) !=NULL)
				return false;
			break;
		case 'd':
			if(strchr(left[i],x)==NULL)
				return false;
			break;
		}	

	return true;
}

bool Heavy(char x) 
{
	for(int i=0;i<3;i++)  
		switch(result[i][0])
		{
		case 'u':
			if(strchr(left[i],x)==NULL) 
				return false;
			break;
		case 'e':
			if(strchr(right[i],x)!=NULL || strchr(left[i],x) !=NULL)
				return false;
			break;
		case 'd':
			if(strchr(right[i],x)==NULL)
				return false;
			break;
		}	
	return true;
}
