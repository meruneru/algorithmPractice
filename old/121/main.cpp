#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

std::string func(std::string str)
{
    int N = std::stoi(str);
    if (N == std::pow(std::floor(std::sqrt(N)), 2))return "Yes";
    return "No";
}

#ifndef DEBUG
int main(int argc, char **argv)
{
    std::string a,b;
    std::cin >> a >> b;
    std::cout << func(a+b) << '\n';

    return 0;
}
#endif

#ifdef DEBUG
#include "lest/lest.hpp"
int main(int argc, char *argv[])
{
    const lest::test specification[] = {
        CASE("#1"){
            EXPECT("Yes" == func("121"));
        }, 
        CASE("#2"){
            EXPECT("No" == func("100100"));
        }, 
        CASE("#3"){
            EXPECT("No" == func("1210"));
        }, 
};
    return lest::run(specification, argc, argv);
}
#endif