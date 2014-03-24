#include <iostream>
#include <string>
using namespace std;

string sZoneName[32]={"UTC","GMT","BST","IST","WET","WEST","CET","CEST","EET","EEST","MSK","MSD","AST","ADT","NST","NDT","EST","EDT","CST","CDT","MST","MDT","PST","PDT","HST","AKST","AKDT","AEST","AEDT","ACST","ACDT","AWST"};
float  nTimeDiff[32] = {0,0,1,1,0,1,1,2,2,3,3,4,-4,-3,-3.5,-2.5,-5,-4,-6,-5,-7,-6,-8,-7,-10,-9,-8,10,11,9.5,10.5,8};

int main()
{ 
    int n;
    string sTime, sAmPm, sZone1, sZone2;
    
    cin>>n;
    while (n--) {
        int nHour1, nMinute1, nHour2, nMinute2;
        int nZone1, nZone2;
        cin>>sTime;
        if (sTime == "noon") {
            nHour1   = 12;
            nMinute1 = 0;
            sAmPm = "p.m.";
        }
        else if( sTime == "midnight") {
            nHour1   = 0;
            nMinute1 = 0;
            sAmPm = "a.m.";
        }
        else {
            sscanf(sTime.c_str(),"%d:%d", &nHour1, &nMinute1);
            cin>>sAmPm;
        }
        nHour1 %= 12;//注意-1
        if (sAmPm[0] == 'p') 
            nHour1 += 12;

        cin>>sZone1>>sZone2;
        //查找连个时区与UTC时区的时间差
        for (int i = 0; i < 32; ++i) {
            if (sZoneName[i] == sZone1) 
                nZone1 = i;
            if (sZoneName[i] == sZone2) 
                nZone2 = i;
        }     
        
        int newTime = nHour1*60+nMinute1+(nTimeDiff[nZone2]*1.0 - nTimeDiff[nZone1]*1.0)*60;
        newTime = (newTime + 1440)%1440; //注意-2        
        
        if (newTime == 0) 
            cout<<"midnight"<<endl;
        else if (newTime == 720) 
            cout<<"noon"<<endl;
        else {
            nHour2   = newTime/60;
            nMinute2 = newTime%60;
            if (nHour2 >= 0 && nHour2 <12) {
                if (nHour2 == 0)   nHour2 =12;
                printf("%d:%02d a.m.\n", nHour2, nMinute2);
            }//if
            else if (nHour2 >= 12 && nHour2 <24) {
                if (nHour2 != 12)  nHour2 -= 12;           
                printf("%d:%02d p.m.\n", nHour2, nMinute2);
            }//else-if
        } //else      
    }//while
    return 0;
}
