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
#include <time.h>
#include<functional>
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif


typedef bool (*Hash_fun_equal)(const void * pval1 , const void *pval2);
typedef int (*Hash_fun_key)(const void *pval) ;

class Node {
public:
    Node():next(-1) {
    }
    int next;
    int pos;
};

class Hash_table {
public:
    Hash_table():hash_bucket(NULL),fun_equal(NULL),hash_key(NULL),heap(NULL) {
    }

    ~Hash_table() {
        destroy();
    }

    /*
    bucket_len 桶的大小
    node_num   节点个数
    node_size   一个节点的大小
    */
    int init(int bucket_len  , int node_num   ,int node_size, Hash_fun_equal fun_equal, Hash_fun_key hash_key) {
        this->fun_equal = fun_equal;
        this->hash_key = hash_key;
        this->bucket_len = bucket_len ;
        this->node_size = node_size ;
        this->node_num = node_num ;

        if(bucket_len < 5 || node_num < 10 || node_size <= 0) {
            return -1 ;
        }

        if(malloc_bucket() == -1) {
            return -1;
        }

        if(malloc_queue() == -1) {
            free_bucket();
            return -1;
        }
        initQueue();
    }

    /*
    1 not find
    0 find
    -1 error

    1 exit
    0 sucess
    -1 error
    */
    int query(void const * pkey) {

        if(pkey == NULL) {
            return -1;
        }

        int key = hash_key(pkey);


        if (key >= bucket_len ) {
            return -1 ;
        }

        int pos = (hash_bucket + key)->next;

        void const* now ;
        while(pos != -1) {
            now = (void*)(heapNode(pos) + 1);
            if(fun_equal(now, pkey) == true) {
                return 0;
            } else {
                pos = heapNode(pos)->next;
            }
        }
        return 1;
    }

    /*
    1 exit
    0 sucess
    -1 error
    */
    int insert(void const * pkey) {

        int ret = query(pkey);
        if(ret == 0) {
            return 1;
        }
        if(ret == -1) {
            return -1;
        }

        int key = hash_key(pkey);
        Node* now  = hash_bucket + key;

        int pos = malloc_node();
        if(pos == -1) {
            return -1;
        }

        heapNode(pos)->next = now->next;
        now->next = pos;
        memcpy ((void*)(heapNode(pos) +1 ), pkey, node_size);

        return 0;
    }

    /*
    1 not exit
    0 sucess
    -1 error
    */
    int del(void const * pkey) {
        if(pkey == NULL) {
            return -1;
        }
        int key = hash_key(pkey);

        if (key >= bucket_len ) {
            return -1 ;
        }

        Node* pre = hash_bucket + key;
        int pos = pre->next;
        void const* now ;

        while(pos != -1) {
            now = (void*)(heapNode(pos) + 1);
            if(fun_equal(now, pkey)  == true) {
                pre->next = heapNode(pos)->next;
                free_node(pos);
                return 0;
            } else {
                pre = heapNode(pos);
                pos = pre->next;
            }
        }

        return 1;
    }

    void reset() {
        memset(hash_bucket , -1 ,sizeof(Node) * bucket_len);
        initQueue();
    }

    void destroy() {
        free_bucket();
        free_queue();
        bucket_len = 0;
        node_size = 0;
        node_num = 0;
        fun_equal = NULL;
        hash_key = NULL;
    }
    
    
private:

    int free_node(int pos) {
        if(head != -1) {
            heapNode(pos)->next = head;
        }
        head = pos;
    }

    int malloc_node() {
        if(head == -1) {
            return -1;
        }
        Node* newNode = heapNode(head);
        head = heapNode(newNode->next)->pos;
        return newNode->pos;
    }

    void free_bucket() {
        free(hash_bucket);
        hash_bucket = NULL;
    }

    int malloc_bucket() {
        hash_bucket  = (Node  *)malloc(sizeof(Node) * bucket_len);
        memset(hash_bucket , -1 ,sizeof(Node) * bucket_len);

        if (!hash_bucket) {
            return -1 ;
        }
        return 0;
    }

    void free_queue() {
        free(heap);
        heap = NULL;
        head = -1;
    }

    int malloc_queue() {
        heap = malloc((sizeof(Node) + node_size) * node_num);
        if (!heap) {
            return -1;
        }
        return 0;
    }

    void initQueue() {
        head = 0;

        for (int i=0; i < node_num - 1; ++i) {
            heapNode(i)->pos = i;
            heapNode(i)->next = i + 1;
        }
        heapNode(node_num - 1)->pos = node_num - 1;
        heapNode(node_num - 1)->next = -1;

    }

    Node* heapNode(int i) {
        if(i >= node_num || i < 0) {
            return NULL;
        }
        return (Node*)(((char*)heap) + (sizeof(Node) + node_size) * i);
    }



private:
    int     bucket_len ;
    int     node_size ;
    int     node_num ;

    Node  * hash_bucket ;
    void* heap;
    int head;
    Hash_fun_equal fun_equal;
    Hash_fun_key hash_key;
};

typedef bool (*Hash_fun_equal)(const void * pval1 , const void *pval2);
typedef int (*Hash_fun_key)(const void *pval) ;

bool equal(const void * pval1 , const void *pval2) {
    return *((int const*)pval1) == *((int const*)pval2);
}

int hash(const void *pval) {
    return (*((int const*)pval)) % 17;
}

int main() {
    Hash_table hashTable;
    hashTable.init(17, 15, sizeof(int), equal, hash);

    srand (time(NULL));
    int a,ret;

    printf("---------------------------------\n");
    printf("1 exit\n");
    printf("0 find\n");
    printf("-1 error\n");

    for(int i=0; i<10; i++) {
        a =  rand()%17;
        ret = hashTable.insert(&a);
        printf("i=%d a=%d %d ret=%d\n",i, a, a%17, ret);
    }
    printf("\n");
    printf("---------------------------------\n");
    printf("1 not exit\n");
    printf("0 sucess\n");
    printf("-1 error\n");
    for(int i=0; i<5; i++) {
        a =  rand()%17;
        ret = hashTable.query(&a);
        printf("i=%d a=%d %d ret=%d\n",i, a, a%17, ret);
    }
    printf("\n");
    printf("---------------------------------\n");
    printf("1 not exit\n");
    printf("0 sucess\n");
    printf("-1 error\n");
    for(int i=0; i<5; i++) {
        a =  rand()%17;
        ret = hashTable.del(&a);
        printf("i=%d a=%d %d ret=%d\n",i, a, a%17, ret);
    }

    return 0;
}
