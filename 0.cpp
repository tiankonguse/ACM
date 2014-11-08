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
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

#define rot(x,k) (((x)<<(k)) ^ ((x)>>(32-(k))))

#define mix(a,b,c) \
{ \
  a -= c;  a ^= rot(c, 4);  c += b; \
  b -= a;  b ^= rot(a, 6);  a += c; \
  c -= b;  c ^= rot(b, 8);  b += a; \
  a -= c;  a ^= rot(c,16);  c += b; \
  b -= a;  b ^= rot(a,19);  a += c; \
  c -= b;  c ^= rot(b, 4);  b += a; \
}

#define final(a,b,c) \
{ \
  c ^= b; c -= rot(b,14); \
  a ^= c; a -= rot(c,11); \
  b ^= a; b -= rot(a,25); \
  c ^= b; c -= rot(b,16); \
  a ^= c; a -= rot(c,4);  \
  b ^= a; b -= rot(a,14); \
  c ^= b; c -= rot(b,24); \
}

uint32_t jenkins_hash( const void *key, size_t length) {
    uint32_t a,b,c;
    a = b = c = 0xdeadbeef + ((uint32_t)length) + 0;

    const char *k = (const char *)key;
    while (length > 12) {
        a += ((uint32_t)k[0])<<24;
        a += ((uint32_t)k[1])<<16;
        a += ((uint32_t)k[2])<<8;
        a += ((uint32_t)k[3]);
        b += ((uint32_t)k[4])<<24;
        b += ((uint32_t)k[5])<<16;
        b += ((uint32_t)k[6])<<8;
        b += ((uint32_t)k[7]);
        c += ((uint32_t)k[8])<<24;
        c += ((uint32_t)k[9])<<16;
        c += ((uint32_t)k[10])<<8;
        c += ((uint32_t)k[11]);
        mix(a,b,c);
        length -= 12;
        k += 12;
    }
    switch(length) {
    case 12:
        c+=k[11];
    case 11:
        c+=((uint32_t)k[10])<<8;
    case 10:
        c+=((uint32_t)k[9])<<16;
    case 9 :
        c+=((uint32_t)k[8])<<24;
    case 8 :
        b+=k[7];
    case 7 :
        b+=((uint32_t)k[6])<<8;
    case 6 :
        b+=((uint32_t)k[5])<<16;
    case 5 :
        b+=((uint32_t)k[4])<<24;
    case 4 :
        a+=k[3];
    case 3 :
        a+=((uint32_t)k[2])<<8;
    case 2 :
        a+=((uint32_t)k[1])<<16;
    case 1 :
        a+=((uint32_t)k[0])<<24;
        break;
    case 0 :
        return c;
    }

    final(a,b,c);
    return c;
}

#define    FORCE_INLINE inline __attribute__((always_inline))

static inline uint32_t ROTL32 ( uint32_t x, int8_t r ) {
    return (x << r) | (x >> (32 - r));
}
static FORCE_INLINE uint32_t getblock32 ( const uint32_t * p, int i ) {
    return p[i];
}
static FORCE_INLINE uint32_t fmix32 ( uint32_t h ) {
    h ^= h >> 16;
    h *= 0x85ebca6b;
    h ^= h >> 13;
    h *= 0xc2b2ae35;
    h ^= h >> 16;

    return h;
}

uint32_t MurmurHash3_x86_32 ( const void * key, size_t length) {
    const uint8_t * data = (const uint8_t*)key;
    const int nblocks = length / 4;

    uint32_t h1 = 0;

    uint32_t c1 = 0xcc9e2d51;
    uint32_t c2 = 0x1b873593;

    const uint32_t * blocks = (const uint32_t *)(data + nblocks*4);

    for(int i = -nblocks; i; i++) {
        uint32_t k1 = getblock32(blocks,i);

        k1 *= c1;
        k1 = ROTL32(k1,15);
        k1 *= c2;

        h1 ^= k1;
        h1 = ROTL32(h1,13);
        h1 = h1*5+0xe6546b64;
    }

    const uint8_t * tail = (const uint8_t*)(data + nblocks*4);

    uint32_t k1 = 0;

    switch(length & 3) {
    case 3:
        k1 ^= tail[2] << 16;
    case 2:
        k1 ^= tail[1] << 8;
    case 1:
        k1 ^= tail[0];
        k1 *= c1;
        k1 = ROTL32(k1,15);
        k1 *= c2;
        h1 ^= k1;
    };

    h1 ^= length;

    h1 = fmix32(h1);

    return h1;
}

int main() {
    char str[1312];
    while(scanf("%s",str)) {
        printf("%u : %s\n",jenkins_hash(str,strlen(str)), str);
    }
    return 0;
}
