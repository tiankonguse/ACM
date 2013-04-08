#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<functional>


struct Time{
    int h,m,s;

    Time& scan(){
        scanf("%d:%d:%d",&this->h,&this->m,&this->s);
        this->h %= 12;
        if(this->h == 0)this->h = 12;
        return *this;
    }

    void print(){
        printf("%02d:%02d:%02d\n",this->h,this->m,this->s);
    }

    int get(){
        return this->h * 3600 + this->m * 60 + this->s;
    }

    Time& set(int alls){
        if(alls < 0)alls += 12 * 60 * 60;
        this->h = alls / 3600;
        this->m = (alls % 3600) / 60;
        this->s = (alls % 3600) % 60;
        return *this;
    }

}now,old,ans;

int main(){

    int cas;
    scanf("%d", &cas);
    while(cas--){
        ans.set(now.scan().get() - old.scan().get()).print();
    }
    return 0;
}
