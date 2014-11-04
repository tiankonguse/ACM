#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cmath>
#include <cassert>
#include <queue>
#include <bitset>
#include <map>
#include <set>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <time.h>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

#ifdef ALIGN_DATA
#   define __aligned__ __attribute__((aligned(16)))
#else
#   define __aligned__
#endif

#define MAX_CHUNKS 32768

uint8_t buffer[16*MAX_CHUNKS] __aligned__;

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int64 mod = 2184057LL;

uint64 a[64][(218 * 1000) / 64];
uint64 b[64][(218 * 1000) / 64];

char buf[512 * 1000];

// lookup for SSE
uint8_t POPCOUNT_4bit[16] __aligned__ = {
    /* 0 */ 0,
    /* 1 */ 1,
    /* 2 */ 1,
    /* 3 */ 2,
    /* 4 */ 1,
    /* 5 */ 2,
    /* 6 */ 2,
    /* 7 */ 3,
    /* 8 */ 1,
    /* 9 */ 2,
    /* a */ 2,
    /* b */ 3,
    /* c */ 2,
    /* d */ 3,
    /* e */ 3,
    /* f */ 4
};

uint32_t ssse3_popcount3(uint8_t* buffer, int chunks16) {
    static char MASK_4bit[16] = {0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf};

    uint32_t result;

#ifdef DEBUG
    assert(chunks16 % 4 == 0);
#endif

    __asm__ volatile ("movdqu (%%eax), %%xmm7" : : "a" (POPCOUNT_4bit));
    __asm__ volatile ("movdqu (%%eax), %%xmm6" : : "a" (MASK_4bit));
    __asm__ volatile ("pxor    %%xmm5, %%xmm5" : : ); // xmm5 -- global accumulator

    result = 0;

    int k, n, i;

    i = 0;
    while (chunks16 > 0) {
        // max(POPCOUNT_8bit) = 8, thus byte-wise addition could be done
        // for floor(255/8) = 31 iterations
#define MAX (7*4)
        if (chunks16 > MAX) {
            k = MAX;
            chunks16 -= MAX;
        } else {
            k = chunks16;
            chunks16 = 0;
        }
#undef MAX
        __asm__ volatile ("pxor %xmm4, %xmm4"); // xmm4 -- local accumulator
        for (n=0; n < k; n+=4) {
#define body(index) \
            __asm__ volatile( \
                "movdqa   (%%eax), %%xmm0   \n" \
                "movdqa    %%xmm0, %%xmm1   \n" \
                "psrlw         $4, %%xmm1   \n" \
                "pand      %%xmm6, %%xmm0   \n" \
                "pand      %%xmm6, %%xmm1   \n" \
                "movdqa    %%xmm7, %%xmm2   \n" \
                "movdqa    %%xmm7, %%xmm3   \n" \
                "pshufb    %%xmm0, %%xmm2   \n" \
                "pshufb    %%xmm1, %%xmm3   \n" \
                "paddb     %%xmm2, %%xmm4   \n" \
                "paddb     %%xmm3, %%xmm4   \n" \
                : : "a" (&buffer[index]));

            body(i);
            body(i + 1*16);
            body(i + 2*16);
            body(i + 3*16);
#undef body
            i += 4*16;
        }

        // update global accumulator (two 32-bits counters)
        __asm__ volatile (
            "pxor   %xmm0, %xmm0        \n"
            "psadbw %xmm0, %xmm4        \n"
            "paddd  %xmm4, %xmm5        \n"
        );
    }

    // finally add together 32-bits counters stored in global accumulator
    __asm__ volatile (
        "movhlps   %%xmm5, %%xmm0   \n"
        "paddd     %%xmm5, %%xmm0   \n"
        "movd      %%xmm0, %%eax    \n"
        : "=a" (result)
    );

    return result;
}



int main() {
    string sa, sb;
    scanf("%s", buf);
    sa = string(buf);
    scanf("%s", buf);
    sb = string(buf);
//  for (int i = 0; i < 64 * 1000; ++i) sa += '0' + (rand() % 2);
//  for (int i = 0; i < 32 * 1000 + 3; ++i) sb += '0' + (rand() % 2);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int shift = 0; shift < 64; ++shift) {
        for (int i = 0; shift + i < sz(sa); ++i) {
            uint64 bit = ((uint64) 1) << (uint64) (i % 64);
            int bucket = i / 64;
            if (sa[i + shift] == '1') {
                a[shift][bucket] |= bit;
            }
        }
        for (int i = 0; shift + i < sz(sb); ++i) {
            uint64 bit = ((uint64) 1) << (uint64) (i % 64);
            int bucket = i / 64;
            if (sb[i + shift] == '1') {
                b[shift][bucket] |= bit;
            }
        }
    }
    int m;
    scanf("%d", &m);
//  m = 10000;
    int prevP1 = -1, prevP2 = -1, prevL = -1, prevRes = -1;
    for (int it = 0; it < m; ++it) {
        int p1, p2, l;
        scanf("%d%d%d", &p1, &p2, &l);
//    p1 = rand() % (sz(sa) - 10), p2 = rand() % (sz(sb) - 10);
//    l = rand() % min(sz(sa) - p1, sz(sb) - p2);
        //p1 = 32; p2 = 32; l = 200 * 1000 - 64;
        if (p1 == prevP1 && p2 == prevP2 && l == prevL) {
            printf("%d\n", prevRes);
            continue;
        }
        prevP1 = p1;
        prevP2 = p2;
        prevL = l;
        int shift1 = p1 % 64;
        int shift2 = p2 % 64;
        int start1 = p1 / 64;
        int start2 = p2 / 64;
        int res = 0;
        uint64* A = a[shift1];
        uint64* B = b[shift1];
        A += start1;
        B += start2;
        int UP = l / 64 - 1;
        uint64* buff = (uint64*) buffer;
        for (int i = 0; i <= UP; ++i) {
            buff[i] = a[shift1][start1 + i] ^ b[shift2][start2 + i];
        }
        uint64 mask = (((uint64) 1) << (uint64) (l % 64)) - (uint64) 1;
        buff[UP + 1] = ((a[shift1][start1 + l / 64] ^ b[shift2][start2 + l / 64]) & mask);
        for (int i = 0; i < 16; ++i) buff[UP + i + 2] = 0;
//    for (int i = 0; i <= l / 64 + 1; ++i) res += __builtin_popcountll(buff[i]);
        res = ssse3_popcount3(buffer, l / (8 * 16) + 1);
        /*    for (int i = 0; i <= UP; ++i) {
              res += __builtin_popcountll(a[shift1][start1 + i] ^ b[shift2][start2 + i]);
            }
            uint64 mask = (((uint64) 1) << (uint64) (l % 64)) - (uint64) 1;
            res += __builtin_popcountll((a[shift1][start1 + l / 64] ^ b[shift2][start2 + l / 64]) & mask);*/
        /*    for (int i = 0; i < l % 64; ++i) {
              if (sa[p1 + l - l % 64 + i] != sb[p2 + l - l % 64 + i])
                ++res;
            }*/
        printf("%d\n", res);
        prevRes = res;

        /*    int ans = 0;
            for (int i = 0; i < l; ++i) if (sa[p1 + i] != sb[p2 + i]) ++ans;
            if (ans != res) cerr << "AAA " << ans << " " << res << " " << l << "\n";*/
    }
    return 0;
}
