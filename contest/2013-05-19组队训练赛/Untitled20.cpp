#include<cstdio>
#include<cstring>

char str[][500]={"","","3 is Mersenne prime."
,"7 is Mersenne prime."
,"15 is NOT Mersenne prime.\n3 5"
,"31 is Mersenne prime."
,"63 is NOT Mersenne prime.\n3 7"
,"127 is Mersenne prime."
,"255 is NOT Mersenne prime.\n3 5 17"
,"511 is NOT Mersenne prime.\n7 73"
,"1023 is NOT Mersenne prime.\n3 11 31"
,"2047 is NOT Mersenne prime.\n23 89"
,"4095 is NOT Mersenne prime.\n3 5 7 13"
,"8191 is Mersenne prime."
,"16383 is NOT Mersenne prime.\n3 43 127"
,"32767 is NOT Mersenne prime.\n7 31 151"
,"65535 is NOT Mersenne prime.\n3 5 17 257"
,"131071 is Mersenne prime."
,"262143 is NOT Mersenne prime.\n3 7 19 73"
,"524287 is Mersenne prime."
,"1048575 is NOT Mersenne prime.\n3 5 11 31 41"
,"2097151 is NOT Mersenne prime.\n7 127 337"
,"4194303 is NOT Mersenne prime.\n3 23 89 683"
,"8388607 is NOT Mersenne prime.\n47 178481"
,"16777215 is NOT Mersenne prime.\n3 5 7 13 17 241"
,"33554431 is NOT Mersenne prime.\n31 601 1801"
,"67108863 is NOT Mersenne prime.\n3 2731 8191"
,"134217727 is NOT Mersenne prime.\n7 73 262657"
,"268435455 is NOT Mersenne prime.\n3 5 29 43 113 127"
,"536870911 is NOT Mersenne prime.\n233 1103 2089"
,"1073741823 is NOT Mersenne prime.\n3 7 11 31 151 331"
,"2147483647 is Mersenne prime."
,"4294967295 is NOT Mersenne prime.\n3 5 17 257 65537"
,"8589934591 is NOT Mersenne prime.\n7 23 89 599479"
,"17179869183 is NOT Mersenne prime.\n3 43691 131071"
,"34359738367 is NOT Mersenne prime.\n31 71 127 122921"
,"68719476735 is NOT Mersenne prime.\n3 5 7 13 19 37 73 109"
,"137438953471 is NOT Mersenne prime.\n223 616318177"
,"274877906943 is NOT Mersenne prime.\n3 174763 524287"
,"549755813887 is NOT Mersenne prime.\n7 79 8191 121369"
,"1099511627775 is NOT Mersenne prime.\n3 5 11 17 31 41 61681"
,"2199023255551 is NOT Mersenne prime.\n13367 164511353"
,"4398046511103 is NOT Mersenne prime.\n3 7 43 127 337 5419"
,"8796093022207 is NOT Mersenne prime.\n431 9719 2099863"
,"17592186044415 is NOT Mersenne prime.\n3 5 23 89 397 683 2113"
,"35184372088831 is NOT Mersenne prime.\n7 31 73 151 631 23311"
,"70368744177663 is NOT Mersenne prime.\n3 47 178481 2796203"
,"140737488355327 is NOT Mersenne prime.\n2351 4513 13264529"
,"281474976710655 is NOT Mersenne prime.\n3 5 7 13 17 97 241 257 673"
,"562949953421311 is NOT Mersenne prime.\n127 4432676798593"
,"1125899906842623 is NOT Mersenne prime.\n3 11 31 251 601 1801 4051"
,"2251799813685247 is NOT Mersenne prime.\n7 103 2143 11119 131071"
,"4503599627370495 is NOT Mersenne prime.\n3 5 53 157 1613 2731 8191"
,"9007199254740991 is NOT Mersenne prime.\n6361 69431 20394401"
,"18014398509481983 is NOT Mersenne prime.\n3 7 19 73 87211 262657"
,"36028797018963967 is NOT Mersenne prime.\n23 31 89 881 3191 201961"
,"72057594037927935 is NOT Mersenne prime.\n3 5 17 29 43 113 127 15790321"
,"144115188075855871 is NOT Mersenne prime.\n7 32377 524287 1212847"
,"288230376151711743 is NOT Mersenne prime.\n3 59 233 1103 2089 3033169"
,"576460752303423487 is NOT Mersenne prime.\n179951 3203431780337"
,"1152921504606846975 is NOT Mersenne prime.\n3 5 7 11 13 31 41 61 151 331 1321"
,"2305843009213693951 is Mersenne prime."
,"4611686018427387903 is NOT Mersenne prime.\n3 715827883 2147483647"
,"9223372036854775807 is NOT Mersenne prime.\n7 73 127 337 92737 649657"
,"18446744073709551615 is NOT Mersenne prime.\n3 5 17 257 641 65537 6700417"

};

int main(){
    int j;
    while(~scanf("%d",&j)){
            printf("%s\n",str[j]);
//        puts(str[j]);
    }
}


