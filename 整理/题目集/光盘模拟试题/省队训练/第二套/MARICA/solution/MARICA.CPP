
// Izborne pripreme 2001 - Drugi izborni ispit
// Zadatak MARICA
// Autor rjesenja Bojan Antolovic
// Nesluzbeno rjesenje

#include <fstream>
#include <iostream.h>
#include <set>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 1000

int n;
int veza[MAXN][MAXN]; // -1 ako nema veze
int rez;

struct brid
{
    int v1, v2;
    brid(int nv1, int nv2)
    	{ if (v1<v2) { v1=nv1; v2=nv2; } else { v1=nv2; v2=nv1; } }
    inline bool operator < (const brid &drugi) const
    	{ return (v1<drugi.v1 || (v1==drugi.v1 && v2<drugi.v2)); }
};
class bridovi: public set<brid> {};
bridovi zaobraditi, novi, pom;


vector<bool> obraden;
vector<bool> potencijalan;
vector<int> udaljenost;

class vrhovi: public vector<int>
{
	friend ostream & operator << (ostream & output, const vrhovi &v)
    {
        for (vrhovi::const_iterator i=v.begin(); i!=v.end(); i++)
        	output << (*i)+1 << " ";
        output << "\n";
        return output;
    }
};
vrhovi put;


class dijvrh
{
public:
	int broj;
    dijvrh(int nbroj) { broj=nbroj; };
    bool operator < ( const dijvrh &drugi) const { return udaljenost[broj] < udaljenost[drugi.broj]; }
};

void calc_najkraci_put()
{
	obraden.resize(n);
    potencijalan.resize(n);
    udaljenost.resize(n);
	list<dijvrh> potencijalni;
	for (int i=0; i<n; i++) obraden[i] = false;
	for (int i=0; i<n; i++) potencijalan[i] = false;
	for (int i=0; i<n; i++) udaljenost[i] = -1;

    potencijalni.push_back(dijvrh(0));
    udaljenost[0] = 0;
    potencijalan[0] = true;

    while (!potencijalni.empty())
    {
        list<dijvrh>::iterator naj;
        naj = min_element(potencijalni.begin(), potencijalni.end());
        int najud = udaljenost[naj->broj];
        int najvrh = naj->broj;
        potencijalni.erase(naj);
        potencijalan[najvrh] = false;
        obraden[najvrh] = true;

        if (najvrh==n-1)
        	break;

        for (int i=0; i<n; i++)
        	if (veza[najvrh][i]!=-1)
        	if (!obraden[i])
            	if (udaljenost[i]==-1 || udaljenost[i]>udaljenost[najvrh]+veza[najvrh][i])
                {
                    int a = udaljenost[i] = udaljenost[najvrh]+veza[najvrh][i];
                    if (!potencijalan[i])
                    {
	                    potencijalni.push_back(dijvrh(i));
                        potencijalan[i] = true;
                    }
                }
    }
/*
    cout << "dijkstra ";
    for (int i=0; i<n; i++)
        cout << i+1 << ":" << udaljenost[i] << " ";
    cout << "\n";
*/
    put.clear();
    if (udaljenost[n-1]==-1)
    	return;

    int p = n-1;
    put.insert(put.end(), p);
    do
    {
        int i, mini;
        mini = -1;
        for (i=0; i<n; i++)
            if (udaljenost[i]!=-1)
            if (veza[p][i]!=-1)
            	if (mini==-1 || udaljenost[i]+veza[p][i]<udaljenost[mini]+veza[p][mini])
                	mini = i;
         p = mini;
         put.insert(put.end(), p);
    } while (p!=0);
    reverse(put.begin(), put.end());
}

void calc_najkraci_put_bez_brida(brid &b)
{
    int staro = veza[b.v1][b.v2];
    veza[b.v1][b.v2] = veza[b.v2][b.v1] = -1;
    calc_najkraci_put();
    veza[b.v1][b.v2] = veza[b.v2][b.v1] = staro;
}

void citaj()
{
    ifstream f("marica.in");
    int k, i, a, b, c;
    f >> n >> k;
    for (a=0; a<n; a++)
        for (b=0; b<n; b++)
            veza[a][b] = veza[b][a] = -1;
    for (i=0; i<k; i++)
    {
        f >> a >> b >> c;
        veza[a-1][b-1] = veza[b-1][a-1] = c;
    }
    put.reserve(n);
}

void rijesi()
{
    brid b(0,0);
    rez = -1;
    calc_najkraci_put();
    int dir;
    dir = udaljenost[n-1];
    for (int i=0; i<int(put.size())-1; i++)
        zaobraditi.insert(brid(put[i], put[i+1]));

    while (!zaobraditi.empty())
    {
        // nadi najkraci put bez brida
        b = *zaobraditi.begin();
        zaobraditi.erase(zaobraditi.begin());
        calc_najkraci_put_bez_brida(b);

        // ako nema, nema rjesenja
        if (put.size()<2)
        {
           rez = -1;
           break;
        }

        // ako je gori, zapamti ga
        if (rez==-1 || udaljenost[n-1]>rez)
        {
	   rez = udaljenost[n-1];
        }

        if (udaljenost[n-1]>dir)
            cout << "(" << put.size()-1 << ")" << udaljenost[n-1] << " ";
/*
        // ukloni suvisne iz zaobraditi
        novi.clear();
        for (int i=0; i<int(put.size())-1; i++)
            novi.insert(brid(put[i], put[i+1]));
        pom.clear();
        insert_iterator<bridovi> ii(pom, pom.begin());
        set_intersection( zaobraditi.begin(), zaobraditi.end(),
                          novi.begin(), novi.end(),
                          ii);
        zaobraditi = pom;
*/
    }
    cout << "\n";
}

void pisi()
{
    ofstream f("marica.out");
    if (rez==-1)
    	f << "NEMOGUCE\n";
    else
    	f << rez << "\n";
}

int main()
{
    citaj();
    rijesi();
    pisi();
}
