#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

// A 国内で集めたい人数, B 海外から許容できる人数, c 候補者
// 関数実行後は、候補者が通過した場合は true/falseで返す
// 通過者の国籍に応じて、AかBを減らしていく
bool func(int& A, int& B, char c)
{
    if(A+B>0 && c=='a'){
        A--;
        return true;
    }
    if(A+B>0 && B>0 && c=='b'){
        B--;
        return true;
    }
    return false;
}

#ifndef DEBUG
int main(int argc, char **argv)
{
    int N,A,B;
    std::string str;
    std::cin >> N >> A>>B;
    std::cin >> str;
    for(char i :str){
        if(func(A, B, i)){
            std::cout << "Yes" << '\n';
        }else{
            std::cout << "No" << '\n';
        }
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
            int A = 2;
            int B = 3;
            EXPECT(true == func(A, B, 'a'));
            EXPECT(true == func(A, B, 'b'));
            EXPECT(false ==func(A, B, 'c'));
            EXPECT(false == func(A, B, 'c'));
            EXPECT(true == func(A, B, 'a'));
            EXPECT(true ==func(A, B, 'b'));
            EXPECT(true == func(A, B, 'a'));
            EXPECT(false == func(A, B, 'a'));
            EXPECT(false ==func(A, B, 'b'));
            EXPECT(false ==func(A, B, 'b'));
        }, 
        CASE("#2"){
            int A = 5;
            int B = 2;
            EXPECT(false == func(A, B, 'c'));
            EXPECT(true == func(A, B, 'a'));
            EXPECT(true ==func(A, B, 'b'));
            EXPECT(true == func(A, B, 'b'));
            EXPECT(true == func(A, B, 'a'));
            EXPECT(false == func(A, B, 'b'));
            EXPECT(true == func(A, B, 'a'));
            EXPECT(true == func(A, B, 'a'));
            EXPECT(false == func(A, B, 'c'));
            EXPECT(true == func(A, B, 'a'));
            EXPECT(false == func(A, B, 'b'));
            EXPECT(false == func(A, B, 'a'));
        }, 
};
    return lest::run(specification, argc, argv);
}
#endif