#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <cmath>
#ifndef DEBUG
int main(int argc, char **argv)
{
    int N,K;
    std::cin >> N >> K;
    std::vector<std::vector<int>> M(N, std::vector<int>(N));
    for(int i=0; i<N; i++){
        for (int j = 0; j < N; j++)
        {
            std::cin >> M[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for (int j = 0; j < N; j++)
        {
            std::cout << M[i][j];
        }
    }
    std::vector<int> v;
    for (int j = 1; j < N; j++){
        v.push_back(j);
    }

    int ans=0;
    do{
        int tmp = 0;
        tmp += M[0][v[0]];
        for (int z = 0; z < v.size()-1; z++)
        {
            tmp += M[v[z]][v[z+1]];
        }
        tmp += M[v[v.size()-1]][0];
        if(K==tmp)ans++;
    }while(std::next_permutation(v.begin(), v.end()));
    printf("%d\n", ans);
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