#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <cmath>

typedef long long int ll;

char M[2000][2000];
ll dp[2000][2000];
ll X[2000][2000];
ll Y[2000][2000];
ll Z[2000][2000];
const ll m=1000000007;
ll H, W;

int func()
{
    dp[0][0]=1;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(i==0 && j==0)continue;
            if(M[i][j]=='#')continue;
            if(j>0)X[i][j] = (X[i][j-1]+dp[i][j-1])%m;
            if(i>0)Y[i][j] = (Y[i-1][j]+dp[i-1][j])%m;
            if(i>0 && j>0)Z[i][j] = (Z[i-1][j-1]+dp[i-1][j-1])%m;
            dp[i][j] = ((ll)X[i][j] + Y[i][j] + Z[i][j])%m;
        }
    }
    return dp[H-1][W-1];
}

#ifndef DEBUG
int main(int argc, char **argv)
{
    std::cin >> H >> W;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            std::cin>>M[i][j];
        }
    }
    std::cout<<func()<<std::endl;
    return 0;
}
#endif

#ifdef DEBUG
#include "lest/lest.hpp"
void init(){
    for (int i = 0; i < 2000; i++)
    {
        for (int j = 0; j < 2000; j++)
        {
            M[i][j] = 0;
            dp[i][j] = 0;
            X[i][j] = 0;
            Y[i][j] = 0;
            Z[i][j] = 0;
        }
    }
}
int main(int argc, char *argv[])
{
    const lest::test specification[] = {
        CASE("#1"){
            init();
            H=3;
            W=3;
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    M[i][j]='.';
                }
            }
            M[1][1] = '#';
            EXPECT(10 == func());
        }, 
        CASE("#2"){
            init();
            H=8;
            W=10;
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    M[i][j]='.';
                }
            }
            EXPECT(13701937 == func());
        }, 
        CASE("#3"){
            init();
            H=4;
            W=4;
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    M[i][j]='.';
                }
            }
            M[0][3] = '#';
            M[2][2] = '#';
            EXPECT(84 == func());
        }, 
};
    return lest::run(specification, argc, argv);
}
#endif