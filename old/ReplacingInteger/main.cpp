#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
typedef long long ll;
using namespace std;

// https://stackoverflow.com/questions/21204676/modern-way-to-filter-stl-container/53268928#53268928
template <typename Cont, typename Pred>
Cont filter(const Cont &container, Pred predicate) {
    Cont result;
    std::copy_if(container.begin(), container.end(), std::back_inserter(result), predicate);
    return result;
}

ll func(ll N, ll K)
{
    return std::min(N%K, K-N%K);
}

#ifndef DEBUG
int main(int argc, char **argv)
{
    ll N,K;
    std::cin>>N>>K;

    std::cout << func(N,K) << '\n';

    return 0;
}
#endif

#ifdef DEBUG
#include "lest/lest.hpp"
int main(int argc, char *argv[])
{
    const lest::test specification[] = {
        CASE("#1"){
            EXPECT(1 == func(7,4));
        }, 
        CASE("#2"){
            EXPECT(2 == func(2,6));
        }, 
        CASE("#3"){
            EXPECT(0 == func(1000000000000000000,1));
        }, 
        CASE("#4"){
            EXPECT(1 == func(1000000000000000000,3));
        }, 
};
    return lest::run(specification, argc, argv);
}
#endif