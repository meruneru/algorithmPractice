#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

// https://stackoverflow.com/questions/21204676/modern-way-to-filter-stl-container/53268928#53268928
template <typename Cont, typename Pred>
Cont filter(const Cont &container, Pred predicate) {
    Cont result;
    std::copy_if(container.begin(), container.end(), std::back_inserter(result), predicate);
    return result;
}

int func(std::vector<int> &X)
{
    int N = X.size();
    int sum_alice  = 0;
    int sum_bob  = 0;
    std::sort(X.rbegin(), X.rend());

    int index=0;
    auto odd = filter(X, [&index](int a){return (index++)%2==0;});
    index=0;
    auto even = filter(X, [&index](int a){return (index++)%2==1;});
    return std::accumulate(odd.begin(), odd.end(),0) - std::accumulate(even.begin(), even.end(), 0) ;
}

#ifndef DEBUG
int main(int argc, char **argv)
{
    int N;
    std::cin>>N;
    std::vector<int> X(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> X[i];
    }

    std::cout << func(X) << '\n';

    return 0;
}
#endif

#ifdef DEBUG
#include "lest/lest.hpp"
int main(int argc, char *argv[])
{
    const lest::test specification[] = {
        CASE("#1"){
            std::vector<int> X = {3,1};
            EXPECT(2 == func(X));
        }, 
        CASE("#2"){
            std::vector<int> X = {2,4,7};
            EXPECT(5 == func(X));
        }, 
        CASE("#3"){
            std::vector<int> X = {20,18,2,18};
            EXPECT(18 == func(X));
        }, 
};
    return lest::run(specification, argc, argv);
}
#endif