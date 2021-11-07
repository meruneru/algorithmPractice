#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

// int ans = func(M, C, B, A);
int func(int N, int M, int C, std::vector<int>& B, std::vector<std::vector<int>>& A)
{
    int ans = 0;
    for(int i=0; i<N; i++){
        int sum = 0;
        for(int j=0; j<M; j++){
            sum += A.at(i).at(j)*B.at(j);
        }
        //std::cout<< sum+C<<std::endl;
        if(sum + C > 0){
            ans++;
        }
    }
    return ans;
}

#ifndef DEBUG
int main(int argc, char **argv)
{
    int N,M,C;
    std::cin >> N >> M >>C;
    std::vector<int> B(M);
    std::vector<std::vector<int>> A(N, std::vector<int>(M));

    for (int i = 0; i < M; i++)
    {
        std::cin >> B[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> A[i][j];
        }
    }

    int ans = func(N, M, C, B, A);
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
            int N = 2;
            int M = 3;
            int C = -10;
            std::vector<int> B = {1,2,3};
            std::vector<std::vector<int>> input = {{3,2,1},{1,2,2}};
            EXPECT(1 == func(N, M, C, B, input));
        }, 
        CASE("#2"){
            int N = 5;
            int M = 2;
            int C = -4;
            std::vector<int> B = {-2, 5};
            std::vector<std::vector<int>> input = {{100,41},{100,40},{-3,0},{-6,-2},{18,-13}};
            EXPECT(2 == func(N, M, C, B, input));
        }, 
};
    return lest::run(specification, argc, argv);
}
#endif