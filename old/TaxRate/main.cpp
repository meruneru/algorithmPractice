#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <cmath>
int func(int N)
{
    int x = std::ceil(N / 1.08);

    if(std::floor(x*1.08) != N){
        return -1;
    }
    return x;
}

#ifndef DEBUG
int main(int argc, char **argv)
{
    int N;
    std::cin >> N;
    int ans = func(N);
    if (ans == -1)
    {
        std::cout << ":(" << '\n';
    }
    else
    {
        std::cout << ans << '\n';
    }

    return 0;
}
#endif

#ifdef DEBUG
#include "lest/lest.hpp"
int main(int argc, char *argv[])
{
    const lest::test specification[] = {
        CASE("#1"){
            EXPECT(400 == func(432));
            EXPECT(-1 == func(1079));
            EXPECT(927 == func(1001));
        }, 
};
    return lest::run(specification, argc, argv);
}
#endif