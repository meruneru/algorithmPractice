#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <cmath>
int func(int N)
{
    if(N<0)return 0;

    return N;
}

#ifndef DEBUG
int main(int argc, char **argv)
{
    int N;
    std::cin >> N;
    int ans = func(N);
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
            EXPECT(1 == func(1));
            EXPECT(0 == func(0));
            EXPECT(0 == func(-1));
        }, 
};
    return lest::run(specification, argc, argv);
}
#endif