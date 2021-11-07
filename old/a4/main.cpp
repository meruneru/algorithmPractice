#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <cmath>

typedef long long int ll;


int func(std::vector<ll> &A)
{
    ll cur_acum = 0;
    ll maxv = 0;
    ll next_posn = 0;
    ll ans = 0;
    for(ll i=0; i<A.size(); i++){
        // i番目までの累積和
        cur_acum += A[i]; 
        
        // i番目までの累積和で最も大きい値
        maxv = std::max(maxv, cur_acum);

        //この段階で、最も進んだ場所
        ans = std::max(ans, next_posn+maxv);
        next_posn += cur_acum;
    }
    return ans;
}

#ifndef DEBUG
int main(int argc, char **argv)
{
    double a,b,c;
    std::cin >> a >> b>>c;
    double bunbo = a+b+c;
    double tmp1=(100-a)*a/bunbo;
    double tmp2=(100-b)*b/bunbo;
    double tmp3=(100-c)*c/bunbo;
    printf("%.9f\n", tmp1+tmp2+tmp3);
    return 0;
}
#endif

#ifdef DEBUG
#include "lest/lest.hpp"
int main(int argc, char *argv[])
{
    const lest::test specification[] = {
        CASE("#1"){
            std::vector<ll> tmp = {2, -1, -2};
            EXPECT(5 == func(tmp));
        }, 
        CASE("#2"){
            std::vector<ll> tmp = {-2,1,3,-1,-1};
            EXPECT(2 == func(tmp));
        }, 
        CASE("#3"){
            std::vector<ll> tmp = {-1000,-1000,-1000,-1000};
            EXPECT(0 == func(tmp));
        }, 
};
    return lest::run(specification, argc, argv);
}
#endif