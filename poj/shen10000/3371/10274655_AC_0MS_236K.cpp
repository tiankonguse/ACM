#include<iostream>
 #include<iomanip>
 using namespace std;
 
 int word=0;     //???
 int sentance=0; //???
 int syllable=0; //???
 
 bool isalpha(char ch)  
 {
     if(ch>='A' && ch <='Z')
         return true;
     if(ch>='a' && ch <='z')
         return true;
     return false;
 }
 
 bool isvowel(char ch)  
 {
     if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='y')
         return true;
     if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || ch=='Y')
         return true;
     return false;
 }
 
 bool isword(char ch)  
 {
     if(ch==',')
         return true;
     return false;
 }
 
 bool issentance(char ch)  
 {
     if(ch=='.' || ch=='?'  || ch==':' || ch==';' || ch=='!')
         return true;
     return false;
 }
 
 int main(void)
 {
     char msg[1000];
 
     while(cin>>msg)   
     {    
         int wordlen=0;
         bool flag_frevowel=false;   
         int syl=0;  
         int i;
 
         for(i=0;msg[i];i++)
         {
             if(isalpha(msg[i]))   
             {
                 wordlen++;  
 
                 if(wordlen<=3)  
                 {
                     if(!isalpha(msg[i+1]))   
                     {
                         syllable++;     
                         syllable-=syl;   
                         syl=0;
                         continue;
                     }
                 }
 
                 if(isvowel(msg[i]))    
                 {
                     if(msg[i]=='e')
                     {
                         if(!isalpha(msg[i+1]) && msg[i-1]=='l')  
                         {
                             syllable++;
                             syl++;      
                             continue;
                         }
                         else if(!isalpha(msg[i+1]))  
                             continue;
                         else if((msg[i+1]=='d' || msg[i+1]=='s') && !isalpha(msg[i+2]))  // -ed  -es
                             continue;
                     }
 
 
                     if(!flag_frevowel) 
                     {
                         flag_frevowel=true;
                         syllable++;
                         syl++;
                         continue;
                     }
                     else     
                         continue;
                 }
 
                 flag_frevowel=false;  
             }
             else if(isword(msg[i])) 
             {
                 flag_frevowel=false;
                 wordlen=0; 
                 syl=0;
                 word++;
             }
             else if(issentance(msg[i]))   
             {
                 flag_frevowel=false;
                 wordlen=0;  
                 word++;
                 syl=0;
                 sentance++;
             }
 
         }
 
         if(isalpha(msg[i-1]))     //????????????? ??
             word++;
     }
 
     cout<<fixed<<setprecision(2)<<206.835-1.015*(double)word/(double)sentance-84.6*(double)syllable/(double)word<<endl;
     return 0;
}
