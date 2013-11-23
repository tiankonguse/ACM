
#include<stdio.h>
#include<string.h>

const int N=130;
struct T{
	int id,len;
	struct T* next[N];
};

int C,A,id,keyid;
char** exp;

void init(T* p)
{
	p->id=0;
	p->len=0;
	memset(p->next,0,sizeof(p->next));
	return;
}

char upchar(char c){

	if(c<'a' || c>'z') return c;

	return c-32;
}

void intput_c(T* root)
{
    int j,k;
    char tc,tmp[200];
    T   *p1,*p2,*p3;
    bool f1, f2, f3;
		while(C--){

        p1=p3=p2=root;
        f1=f2=f3=false;

        gets(tmp);

        for(j=1;tmp[j]!='\"';j++){

            if(!p1->next[tmp[j]]){
                p1->next[tmp[j]]=new T;
                init(p1->next[tmp[j]]);
                p1->next[tmp[j]]->len=p1->len+1;
            }

            p1=p1->next[tmp[j]];

            tc=upchar(tmp[j]);
            if(!p2->next[tc]){
                p2->next[tc]=new T;
                init(p2->next[tc]);
                p2->next[tc]->len=p2->len+1;
            }
            p2=p2->next[tc];

            tc=((j==1)?upchar(tmp[j]):tmp[j]);
            if(!p3->next[tc]){
                p3->next[tc]=new T;
                init(p3->next[tc]);
                p3->next[tc]->len=p3->len+1;
            }
            p3=p3->next[tc];

        }

        if(p1->id)f1=true;
        else p1->id=++id;

        if(p2->id)f2=true;
        else p2->id=++id;

        if(p3->id)f3=true;
        else p3->id=++id;

        while(tmp[++j]!='\"');

        k=j+1;

        for(j=0;tmp[k]!='\"';++j,++k){
            if(!f1)exp[p1->id][j]=tmp[k];
            if(!f2)exp[p2->id][j]=upchar(tmp[k]);
            if(!f3)exp[p3->id][j]=(j==0)?upchar(tmp[k]):tmp[k];
        }

        if(!f1){exp[p1->id][j]='\0';    }
        if(!f2){exp[p2->id][j]='\0';     }
        if(!f3){exp[p3->id][j]='\0';      }
    }
	
}
void intput_a(T* root)
{
struct T * p1;
bool f1;	
char tmp[81];
int j,k;
		while(A--)    {
		    p1=root;
		    f1=false;

		    gets(tmp);

		    for(j=1;tmp[j]!='\"';j++){
		        if(!p1->next[tmp[j]]){
		            p1->next[tmp[j]]=new T;
		            init(p1->next[tmp[j]]);
		            p1->next[tmp[j]]->len=p1->len+1;
		        }

		        p1=p1->next[tmp[j]];
		    }

		    if(p1->id)f1=true;
		    else p1->id=++id;

		    if(!f1)
		    {
		        while(tmp[++j]!='\"');

		        k=j+1;

            //    printf("%d %s\n",p1->id,&tmp[k]);

                for(j=0;tmp[k]!='\"';++j,++k){
                    exp[p1->id][j]=tmp[k];
                }

		      //  printf("%s\n",&tmp[k]);
		        exp[p1->id][j++]=32;
		        exp[p1->id][j++]='(';

		        for(k=1;tmp[k]!='\"';k++){
		            exp[p1->id][j++]=tmp[k];
		        }
		        exp[p1->id][j++]=')';
		        exp[p1->id][j]='\0';
				//printf("p=%s\n",exp[p1->id]);
		    }

    }	
} 
void intputword(T* root){
	intput_c(root);
    keyid=id;
	intput_a(root);	
}

void intputtxet(T* root){
    int i,j,k;
    char map[81];
    bool *f=new bool[id+1];

    for(i=keyid+1;i<=id;i++){
        f[i]=false;
    }

    while(gets(map)){
        for(i=0;map[i];i++){
            if(map[i]=='#' && map[i+1]=='\0'){

                putchar('#');

                for(k=keyid+1;k<=id;k++){

                    f[k]=false;

                }

                break;
            }

            T * p=root;

            if(!p->next[map[i]])
            {
                putchar(map[i]);
                continue;
            }

            for(j=i;!p->id;j++)
            {
                if(p->next[map[j]])p=p->next[map[j]];
                else break;
            }

            if(p->id!=0){
                if(p->id<=keyid){
                    printf("%s",exp[p->id]);
                    i+=p->len-1;
                }
                else if(!f[p->id]){
                    f[p->id]=true;
                    printf("%s",exp[p->id]);
                    i+=p->len-1;
                }
                else{
                    putchar(map[i]);
                }

            }
            else{
                putchar(map[i]);
            }
        }
        putchar('\n');

    }

    delete[] f;

}


void solve()
{
    id=0;
    T* root=new T;
    init(root);
    exp=new char*[C*3+A+5];

    for(int i=0;i<C*3+A+5;i++)
    {
        exp[i]=new char[88];
    }

    intputword(root);

    intputtxet(root);

    for(int i=0;i<C*3+A+5;i++)
    {
        delete[] exp[i];
    }
    delete[] exp;
}

int main()
{

    scanf("%d %d",&C,&A);
    getchar();
    solve();
    return 0;
}