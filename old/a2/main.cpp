#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <cmath>

typedef long long int ll;

#ifndef DEBUG
int main(int argc, char **argv)
{
    ll N, X;
    std::string S;
    std::cin >> N >> X;
    std::cin >> S;
    for(int i=0; i<N; i++){
        if(S[i]=='o'){
            X++;
        }else{
            if(X>0)X--;
        }
    }
    std::cout<<X<<std::endl;
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