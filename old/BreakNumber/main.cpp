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

int func(int N)
{
    if(N==1)return 1;
    std::vector<int> X;
    for (int i = 1; i <= N; i++)
    {
        X.push_back(i);
    }

    int ans = 0;
    int cnt_max = 0;
    for (int i = 0; i < X.size(); i++)
    {
        int cnt = 0;
        while (X[i] % 2 == 0)
        {
            //std::cout << "x[" << i << "]: " << X[i] << std::endl;
            X[i] = X[i] / 2;
            cnt++;
            if(cnt>=cnt_max){
                cnt_max = cnt;
                ans = i+1;
            }
        }
    }
    //std::cout<<"---------"<<std::endl;
    return ans;
}

#ifndef DEBUG
int main(int argc, char **argv)
{
    int N;
    std::cin>>N;
    std::cout << func(N) << '\n';

    return 0;
}
#endif

#ifdef DEBUG
#include "lest/lest.hpp"
int main(int argc, char *argv[])
{
    const lest::test specification[] = {
        CASE("#1"){
            EXPECT(4 == func(7));
        }, 
        CASE("#2"){
            EXPECT(32 == func(32));
        }, 
        CASE("#3"){
            EXPECT(1 == func(1));
        }, 
        CASE("#4"){
            EXPECT(64 == func(100));
        }, 
};
    return lest::run(specification, argc, argv);
}
#endif