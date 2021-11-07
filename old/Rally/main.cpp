#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
int func(const std::vector<int> &x)
{
    int ans = INT_MAX;
    auto range = std::minmax_element(x.begin(), x.end());
    // std::cout << *range.first << " "<< *range.second <<std::endl;

    int p = *range.first;
    while (p <= *range.second)
    {
        int tmp = 0;
        for (const auto &i : x)
        {
            tmp += (p - i) * (p - i);
        }
        ans = std::min(ans, tmp);
        p++;
    }
    return ans;
}

#ifndef DEBUG
int main(int argc, char **argv)
{
    int N;
    std::vector<int> x;
    std::cin >> N;
    while (N--)
    {
        int tmp;
        std::cin >> tmp;
        x.push_back(tmp);
    }
    std::cout << func(x) << std::endl;
    return 0;
}
#endif

#ifdef DEBUG
#include "lest/lest.hpp"
int main(int argc, char *argv[])
{
const lest::test specification[] = {
    CASE("#1"){
        std::vector input{1, 4};
        EXPECT(5 == func(input));
        }, 
    CASE("#2"){
        std::vector input{14, 14, 2, 13, 56, 2, 37};
        EXPECT(2354 == func(input));
        },
};
    return lest::run(specification, argc, argv);
}
#endif