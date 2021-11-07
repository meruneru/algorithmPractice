#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

typedef long long ll;
// int ans = func(H, W);
ll func(ll H, ll W)
{
    if(H==1 || W==1)return 1;

    ll ans = std::ceil(H*W/2.0);
    return ans;
}

#ifndef DEBUG
int main(int argc, char **argv)
{
    ll H,W;
    std::cin >> H >> W;

    ll ans = func(H, W);
    std::cout << ans << '\n';

    return 0;
}
#endif

#ifdef DEBUG
#include "lest/lest.hpp"
int main(int argc, char *argv[])
{
    const lest::test specification[] = {
        CASE("#1"){
            ll H = 4;
            ll W = 5;
            EXPECT(10 == func(H, W));
        }, 
        CASE("#2"){
            ll H = 7;
            ll W = 3;
            EXPECT(11 == func(H, W));
        }, 
        CASE("#3"){
            ll H = 1;
            ll W = 3;
            EXPECT(1 == func(H, W));
        }, 
        CASE("#4"){
            ll H = 3;
            ll W = 3;
            EXPECT(5 == func(H, W));
        }, 
        CASE("#5"){
            ll H = 2;
            ll W = 4;
            EXPECT(4 == func(H, W));
        }, 
        CASE("#6"){
            ll H = 4;
            ll W = 5;
            EXPECT(10 == func(H, W));
        }, 
        CASE("#7"){
            ll H = 1000000000;
            ll W = 1000000000;
            EXPECT(500000000000000000 == func(H, W));
        }, 
};
    return lest::run(specification, argc, argv);
}
#endif