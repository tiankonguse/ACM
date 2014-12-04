#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<unistd.h>
#include <time.h>
#include<stdarg.h>
using namespace std;

#ifdef __int64
typedef __int64 LL;
typedef  unsigned __int64  ULL;
#define LLDF		"%I64d"
#define LLUF		"%I64u"
#else
typedef long long LL;
typedef unsigned long long ULL;
#define LLDF		"%lld"
#define LLUF		"%llu"
#endif
//printf ("hello "LLUF, 1LLU);

typedef unsigned int DWORD;

/// fat hit, which is actually stored in VLN index
struct CSphFatHit {
    CSphFatHit() {
        m_iDocID=m_iWordID=m_iWordPos=0;
        m_iGroupID=m_iTimestamp=1;
    }
    DWORD	m_iDocID;		///< document ID
    DWORD	m_iGroupID;		///< documents group ID
    DWORD	m_iTimestamp;	///< document timestamp
    DWORD	m_iWordID;		///< word ID in current dictionary
    DWORD	m_iWordPos;		///< word position in current document
    void init(DWORD word, DWORD doc, DWORD pos) {
        m_iWordID = word;
        m_iDocID = doc;
        m_iWordPos = pos;
    }
} m_tLastHit;



struct CSphWriter_VLN {
    int	m_iPos;
    vector<DWORD> array;
    CSphWriter_VLN():m_iPos(0) {
    }
    void ZipInt ( DWORD val ) {
        m_iPos++;
        array.push_back(val);
    }
    void ZipOffsets (vector<DWORD>& m_dDoclist) {
        for(int i=0; i<m_dDoclist.size(); i++) {
            ZipInt(m_dDoclist[i]);
        }
    }
    void print() {
        for(int i=0; i<m_iPos; i++) {
            printf(" %d",array[i]);
        }
        printf("\n");
    }
} fdData,fdIndex;


vector<DWORD> m_dDoclist;
DWORD m_iLastDoclistPos = 0;
DWORD m_iLastWordHits = 0;
DWORD m_iLastPageID = 0;
DWORD m_iLastHitlistPos = 0;
DWORD m_iLastWordDocs = 0;
DWORD SPH_CLOG_BITS_PAGE = 10;

void  cidxHit ( CSphFatHit * hit ) {
    // next word
    if ( m_tLastHit.m_iWordID!=hit->m_iWordID ) {
        // close prev hitlist, if any
        if ( m_tLastHit.m_iWordPos ) {
            fdData.ZipInt ( 0 );
            m_tLastHit.m_iWordPos = 0;
        }

        // flush prev doclist, if any
        if ( m_dDoclist.size()) {
            // finish writing wordlist entry
            printf(" %d %d\n",fdData.m_iPos,m_iLastDoclistPos);
            fdIndex.ZipInt ( fdData.m_iPos - m_iLastDoclistPos );
            fdIndex.ZipInt ( m_iLastWordDocs );
            fdIndex.ZipInt ( m_iLastWordHits );

            m_iLastDoclistPos = fdData.m_iPos;
            m_iLastWordDocs = 0;
            m_iLastWordHits = 0;

            // write doclist
            fdData.ZipOffsets ( m_dDoclist );
            fdData.ZipInt ( 0 );
            m_dDoclist.clear();

            // restart doclist deltas
            m_tLastHit.m_iDocID = 0;
            m_iLastHitlistPos = 0;
        }

        if ( !hit->m_iWordPos ) {
            fdIndex.ZipInt ( 0 );
            return;
        }

        fdIndex.ZipInt ( hit->m_iWordID - m_tLastHit.m_iWordID );
        m_tLastHit.m_iWordID = hit->m_iWordID;
    }

    // next doc
    if ( m_tLastHit.m_iDocID!=hit->m_iDocID ) {
        if ( m_tLastHit.m_iWordPos ) {
            fdData.ZipInt ( 0 );
            m_tLastHit.m_iWordPos = 0;
        }

        m_dDoclist.push_back ( hit->m_iDocID - m_tLastHit.m_iDocID );
        m_dDoclist.push_back ( hit->m_iGroupID ); // R&D: maybe some delta-coding would help here too
        m_dDoclist.push_back ( hit->m_iTimestamp );
        m_dDoclist.push_back ( fdData.m_iPos - m_iLastHitlistPos );

        m_tLastHit.m_iDocID = hit->m_iDocID;
        m_iLastHitlistPos = fdData.m_iPos;

        // update per-word stats
        m_iLastWordDocs++;
    }

    // the hit
    // add hit delta
    fdData.ZipInt ( hit->m_iWordPos - m_tLastHit.m_iWordPos );
    m_tLastHit.m_iWordPos = hit->m_iWordPos;
    m_iLastWordHits++;
}

int main() {
    CSphFatHit hits[10];
    hits[0].init(1,1,2);
    hits[1].init(1,1,3);
    hits[2].init(1,2,3);
    hits[3].init(1,3,4);
    hits[4].init(2,1,1);
    hits[5].init(0,0,0);
    for(int i=0; i<6; i++) {
        cidxHit(hits+i);
    }
    printf("data: ");
    fdData.print();
    printf("index: ");
    fdIndex.print();


    return 0;
}
