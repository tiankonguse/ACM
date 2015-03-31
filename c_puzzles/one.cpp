#include <stdio.h>

struct helper {
    unsigned int    type : 4;
    unsigned int    tag : 4;
} __attribute__((packed));


int main() {

    struct helper x;
    printf("sizeof = %d\n", sizeof(struct helper));
    printf("sizeof = %d\n", sizeof(x));
    x.tag = 0;
    x.type = 0;
    printf("tag=%d type=%d\n", x.tag, x.type);
    x.tag = 256;
    printf("tag=%d type=%d\n", x.tag, x.type);

    x.tag = 0;
    x.type = 0;
    printf("tag=%d type=%d\n", x.tag, x.type);
    x.type = 256;
    printf("tag=%d type=%d\n", x.tag, x.type);


    x.tag = 0;
    x.type = 0;
    printf("tag=%d type=%d\n", x.tag, x.type);
    x.type = 255;
    printf("tag=%d type=%d\n", x.tag, x.type);
    return 0;
}
