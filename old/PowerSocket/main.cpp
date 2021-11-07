#include <iostream>

int count_taps(int hols, int need_hols)
{
    int ans = 0;
    int count = 1;

    while (count < need_hols){
        count--;
        count += hols;
        ans++;
    }

    return ans;
}

#ifndef DEBUG
int main(int argc, char **argv)
{
    int A, B;
    std::cin >> A >> B;
    std::cout << count_taps(A, B) << std::endl;
    return 0;
}
#endif

#ifdef DEBUG
#include "lest/lest.hpp"
const lest::test specification[] =
    {
        CASE("succeed"){
            EXPECT(3 == count_taps(4, 10));
            EXPECT(2 == count_taps(8, 9));
            EXPECT(1 == count_taps(8, 8));
            EXPECT(0 == count_taps(2, 1));
            EXPECT(3 == count_taps(9, 25));
            EXPECT(4 == count_taps(9, 26));
        },
    };
int main(int argc, char *argv[])
{
    return lest::run(specification, argc, argv);
}
#endif