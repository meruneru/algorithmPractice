// C headers
#include <cassert>
#include <cctype>
// #include <cerrno>
#include <cfloat>
// #include <ciso646>
#include <climits>
// #include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
// #include <ccomplex>
#include <cfenv>
#include <cinttypes>
// #include <cstdalign>
// #include <cstdbool>
#include <cstdint>
// #include <ctgmath>
// #include <cuchar>
// #include <cwchar>
// #include <cwctype>
#endif
// C++ headers
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
// #include <atomic>
#include <chrono>
// #include <codecvt>
// #include <condition_variable>
#include <forward_list>
// #include <future>
#include <initializer_list>
// #include <mutex>
#include <random>
#include <ratio>
#include <regex>
// #include <scoped_allocator>
#include <system_error>
// #include <thread>
#include <tuple>
// #include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#if __cplusplus >= 201402L
#include <shared_mutex>
#endif
#include <atcoder/all>
using namespace std;
using namespace atcoder;

// type
using ull = unsigned long long;
using ll = long long;
using ld = long double;

#define all(obj) (obj).begin(), (obj).end()
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

/* REP macro */
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define repd(i,n) for(ll i=n-1;i>=0;i--)
#define rrepd(i,n) for(ll i=n;i>=1;i--)

/* debug */
// 標準エラー出力を含む提出はrejectされる場合もあるので注意
#define debug(x) cerr << "\033[33m(line:" << __LINE__ << ") " << #x << ": " << x << "\033[m" << endl;

/* func */
inline int ctoi(char c) {return c - '0';}

// vector_finder: (arg)elementを vectorの先から(arg)search_lengthまで先頭から検索し、boolを返す
// (arg)search_length: 走査するベクトル長の上限(先頭から何要素目までを検索対象とするか、1始まりで)
template <typename T> inline bool vector_finder(std::vector<T> vec, T element, unsigned int search_length) {
    auto itr = std::find(vec.begin(), vec.end(), element);
    size_t index = std::distance( vec.begin(), itr );
    if (index == vec.size() || index >= search_length) {return false;} else {return true;}
}

// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}

int main() {
    int n; cin>>n;
    int maxCount = 0;
    int ans = 1;
    for(int i=1; i<=n; i++){
        int x=i;
        int cnt=0;
        while(x%2==0){
            cnt++;
            x/=2;
        }
        if(maxCount<cnt){
            maxCount = cnt;
            ans = i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
