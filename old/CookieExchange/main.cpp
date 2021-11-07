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

int func(int A, int B, int C)
{
    int ans = 0;
    //std::cout<<A<<" "<<B<<" "<<C<<std::endl;
    while (A % 2 == 0 && B % 2 == 0 && C % 2 == 0)
    {
        int A2 = (B / 2) + (C / 2);
        int B2 = (A / 2) + (C / 2);
        int C2 = (A / 2) + (B / 2);
        if (A == A2 && B == B2 && C==C2)
        {
            return -1;
        }
        //std::cout<<A2<<" "<<B2<<" "<<C2<<std::endl;
        A=A2;
        B=B2;
        C=C2;
        ans++;
    }
    return ans;
}

#ifndef DEBUG
int main(int argc, char **argv)
{
    int A,B,C;
    std::cin>>A>>B>>C;

    std::cout << func(A,B,C) << '\n';

    return 0;
}
#endif

#ifdef DEBUG
#include "lest/lest.hpp"
int main(int argc, char *argv[])
{
    const lest::test specification[] = {
        CASE("#1"){
            EXPECT(3 == func(4,12,20));
        }, 
        CASE("#2"){
            EXPECT(-1 == func(14,14,14));
        }, 
        CASE("#3"){
            EXPECT(1 == func(454,414,444));
        }, 
};
    return lest::run(specification, argc, argv);
}
#endif