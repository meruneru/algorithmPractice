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

int func(int K, std::vector<int> &X)
{
    int N = X.size();
    int cost = X[0] - X[N - 1] + K;
    for(int i=1; i<N-1; i++){
        cost = std::max(cost, X[i+1]-X[i]);
    }
    return K-cost;
}

#ifndef DEBUG
int main(int argc, char **argv)
{
    int K,N;
    std::cin>>K>>N;
    std::vector<int> X(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> X[i];
    }

    std::cout << func(K,X) << '\n';

    return 0;
}
#endif

#ifdef DEBUG
#include "lest/lest.hpp"
int main(int argc, char *argv[])
{
    const lest::test specification[] = {
        CASE("#1"){
            int K = 20;
            std::vector<int> X = {5,10,15};
            EXPECT(10 == func(K, X));
        }, 
        CASE("#2"){
            int K = 20;
            std::vector<int> X = {0,5,15};
            EXPECT(10 == func(K, X));
        }, 
};
    return lest::run(specification, argc, argv);
}
#endif