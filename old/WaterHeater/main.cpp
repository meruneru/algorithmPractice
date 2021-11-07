#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <cmath>

typedef long long int ll;

int func(int N)
{
    int x = std::ceil(N / 1.08);

    if(std::floor(x*1.08) != N){
        return -1;
    }
    return x;
}

ll tmp[200100];
#ifndef DEBUG
int main(int argc, char **argv)
{
    ll N,W;
    std::cin >> N >> W;
    
    for(ll i=0; i<N; i++){
        ll s, t, p;
        std::cin >> s >> t >> p;
        tmp[s] += p;
        tmp[t] -= p;
    }
    for(ll i=0; i<N; i++){
        if(i>0)tmp[i]+=tmp[i-1];
    }
    for(ll i=0; i<N; i++){
        if(tmp[i]>W){
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout<<"Yes"<<std::endl;
    return 0;
}
#endif

#ifdef DEBUG
#include "lest/lest.hpp"
int main(int argc, char *argv[])
{
    const lest::test specification[] = {
        CASE("#1"){
            EXPECT(400 == func(432));
            EXPECT(-1 == func(1079));
            EXPECT(927 == func(1001));
        }, 
};
    return lest::run(specification, argc, argv);
}
#endif