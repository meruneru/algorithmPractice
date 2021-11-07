#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;
int func(int K, std::vector<int> &X)
{
    int N = X.size();
    int sum = 0;
    for (int i = 0; i < N; i++){
        int cost = std::min(X[i], std::abs(X[i]-K));
        sum += cost*2;
    }
    
    return sum;
}

#ifndef DEBUG
int main(int argc, char **argv)
{
    int N,K;
    std::cin>>N >>K;
    std::vector<int> X(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> X[i];
    }

    std::cout << func(K, X) << '\n';

    return 0;
}
#endif

#ifdef DEBUG
#include "lest/lest.hpp"
int main(int argc, char *argv[])
{
    const lest::test specification[] = {
        CASE("#1"){
            std::vector<int> X = {2};
            EXPECT(4 == func(10, X));
        }, 
        CASE("#2"){
            std::vector<int> X = {3, 6};
            EXPECT(12 == func(9, X));
        }, 
};
    return lest::run(specification, argc, argv);
}
#endif