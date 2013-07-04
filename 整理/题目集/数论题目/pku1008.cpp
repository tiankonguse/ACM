#include <iostream>
#include <string>
using namespace std;

string asHaabMonths1to19[19]={"pop","no","zip","zotz","tzec","xul","yoxkin",
"mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
string asTzolkinDayNames[20]={"imix","ik","akbal","kan","chicchan","cimi","manik",
"lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
int main()
{
    int t, i;
    cin>>t;
    cout<<t<<endl;

    string sNumberOfTheDay, sMonth;
    int    nNumberOfTheDay, nMonth, nYear; 
    
    while (t--) {
        cin>>sNumberOfTheDay>>sMonth>>nYear;
        nNumberOfTheDay = atoi(sNumberOfTheDay.c_str());
        for (i = 0; i < 19; ++i) {
            if (asHaabMonths1to19[i] == sMonth) {
                nMonth = i;
                break;
            }        
        }
        int nDates = nYear*365 + nMonth*20 + nNumberOfTheDay;
        printf("%d %s %d\n", 1+nDates%13, asTzolkinDayNames[nDates%20].c_str(), nDates/260);
    }
    return 0;
}