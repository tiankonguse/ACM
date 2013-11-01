#include<string>
#include<iostream>
using namespace std;
int w,se,sy;

bool isalpha(char c){
	if(c>='a' && c<='z')return true;
	if(c>='A' && c<='Z')return true;
	return false;
}

bool issentance(char c){
	switch(c){
		case '.':
		case '?':
		case ':':
		case ';':
		case '!':return true;
	}
	return false;
}
bool isword(char c){
	if(c==',' || c==' ')return true;
	return false; 
} 
bool isvowel(char c){
	switch(c){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'y':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
		case 'Y':return true;
	}
	return false;
}
void fun(char *p){
	bool prevowel=false;
	int wordlen=0;
	int sy1=0;
	int len=strlen(p);
	int sum=0;
	if(isalpha(p[len-1])){
		p[len]=',';
		p[len+1]='\0';
	}
	for(int i=0;p[i];i++){
		if(isalpha(p[i])){
			wordlen++;
			if(isvowel(p[i])){
				if(prevowel)continue;
				if(p[i]=='e' && !isalpha(p[i+1]))continue;
				if((p[i+1]=='d' || p[i+1]=='s' ) && !isalpha(p[i+2]))continue;
				sy++;
				sy1++;
				prevowel=true;	
			}else{
				prevowel=false;
			}
		}else if(issentance(p[i])){
			if(wordlen && wordlen<4){
				sy-=sy1;
				sy++;
			}

			sum+=sy1;
			sy1=wordlen=prevowel=0;
			w++;
			se++;
		}else if(isword(p[i])){
			if(isalpha(p[i-1])) {
				if(wordlen>0 && wordlen<4){
					sy-=sy1;
					sy++;
				}       
				sum+=sy1;
				w++;
				sy1=wordlen=prevowel=0;
			} 
		}
	}	

}

int main()
{
	se=sy=w=0;
	char tmp[1000];
	while(gets(tmp)){
		//if(tmp[0]=='1')break; 
		fun(tmp);		
	}

	
	printf("%.2f\n",206.835-((1.015*w)/se)-((84.6*sy)/w));
//scanf("%d",&w); 
return 0;
}
