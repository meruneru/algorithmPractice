#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <cmath>


#ifndef DEBUG
int main(int argc, char **argv)
{
    double sx,sy,gx,gy;
    std::cin >> sx >> sy>>gx>>gy;
    gy *= -1;
    double a =(sy-gy)/(sx-gx);
    double b=sy-(a*sx);
    
    printf("%lf\n", (-1*b)/a);

    return 0;
}
#endif

#ifdef DEBUG
#include "lest/lest.hpp"
int main(int argc, char *argv[])
{
    const lest::test specification[] = {
        CASE("#1"){
            EXPECT(3 == func(1,1,7,2));
            EXPECT(1.6666 == func(1,1,3,2));
        }, 
};
    return lest::run(specification, argc, argv);
}
#endif