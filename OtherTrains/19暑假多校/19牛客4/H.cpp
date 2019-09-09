#include <bits/stdc++.h>

using namespace std;

typedef unsigned int u32;
typedef unsigned long long u64;
struct RNG {
    virtual void srand(u32 seed)=0;
    virtual bool gen()=0;
};
struct RNG0: RNG {
    u32 x;
    void srand(u32 seed) {x=seed;}
    bool gen() {
        x=x*214013u+2531011u;
        return (x>>28)&1;
    }
};
struct RNG1: RNG {
    int index;
    u32 mt[624];
    void srand(u32 seed) {
        mt[0]=seed; index=624;
        for(int i=1;i<624;++i)
            mt[i]=1812433253u*(mt[i-1]^(mt[i-1]>>30))+i;
    }
    void twist() {
        for(int i=0;i<624;++i) {
            u32 y=(mt[i]&0x80000000u)+
                  (mt[(i+1)%624]&0x7fffffffu);
            mt[i]=mt[(i+397)%624]^(y>>1);
            if(y&1) mt[i]^=0x9908b0df;
        }
        index=0;
    }
    bool gen() {
        if(index>=624) twist();
        u32 y=mt[index]; y^=y>>11;
        y^=(y<<7)&2636928640u;
        y^=(y<<15)&4022730752u;
        y^=y>>18; ++index;
        return (y>>16)&1;
    }
};
struct RNG2: RNG {
    u64 x;
    void srand(u32 seed) {x=seed;}
    bool gen() {
        x^=x<<13; x^=x>>7; x^=x<<17;
        return (x>>16)&1;
    }
};
RNG *rng[3]={new RNG0(),new RNG1(),new RNG2()};

int main() {
    srand(time(NULL));
    for (int k = 0; k < 3; k ++) {
        printf("! %d\n", k);
        for (int i = 0; i < 3; i ++) {
            rng[k] -> srand(rand());
            int c1 = 0, maxlen = 0;
            for (int j = 0; j < 2000; j ++) {
                int x = rng[k] -> gen();
                if (x) c1 ++, maxlen = max(maxlen, c1);
                else c1 = 0;
            }
            cout << maxlen << endl;
        }
    }
    
}