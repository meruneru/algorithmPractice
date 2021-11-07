#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

std::string func(std::vector<std::vector<int>> &A, std::vector<int> &B)
{
    std::vector<std::vector<int>> ans(3, std::vector<int>(3));
    int N = B.size();

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (A[i][j] == B[k])
                {
                    ans[i][j] = 1;
                    break;
                }
            }
        }
    }
    //Col
    if(ans[0][0]+ans[0][1]+ans[0][2]==3) return "Yes";
    if(ans[1][0]+ans[1][1]+ans[1][2]==3) return "Yes";
    if(ans[2][0]+ans[2][1]+ans[2][2]==3) return "Yes";
    //Row
    if(ans[0][0]+ans[1][0]+ans[2][0]==3) return "Yes";
    if(ans[0][1]+ans[1][1]+ans[2][1]==3) return "Yes";
    if(ans[0][2]+ans[1][2]+ans[2][2]==3) return "Yes";
    //Cross
    if(ans[0][0]+ans[1][1]+ans[2][2]==3) return "Yes";
    if(ans[0][2]+ans[1][1]+ans[2][0]==3) return "Yes";
    return "No";
}

#ifndef DEBUG
int main(int argc, char **argv)
{
    std::vector<std::vector<int>> A(3, std::vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cin >> A[i][j];
        }
    }

    int N;
    std::cin >> N;

    std::vector<int> B(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> B[i];
    }

    std::cout << func(A, B) << '\n';

    return 0;
}
#endif

#ifdef DEBUG
#include "lest/lest.hpp"
int main(int argc, char *argv[])
{
    const lest::test specification[] = {
        CASE("#1"){
            std::vector<std::vector<int>> A = {{84, 97, 66},{79, 89, 11}, {61, 59, 7}};
            std::vector<int> B = {89,7,87,79,24,84,30};
            EXPECT("Yes" == func(A, B));
        }, 
        CASE("#2"){
            std::vector<std::vector<int>> A = {{41,7,46},{26,89,2},{78,92,8}};
            std::vector<int> B = {6,45,16,57,17};
            EXPECT("No" == func(A, B));
        }, 
};
    return lest::run(specification, argc, argv);
}
#endif