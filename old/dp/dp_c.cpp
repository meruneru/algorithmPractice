// Problem: C - Vacation
// Contest: AtCoder - Educational DP Contest / DP まとめコンテスト
// URL: https://atcoder.jp/contests/dp/tasks/dp_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>

using namespace std;
typedef long long ll;

ll INF = 1LL << 60;

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
ll N;
ll a[100010][3];
ll dp[100010][3];
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (j == k)continue;
         chmax(dp[i + 1][k], dp[i][j] + a[i][k]);
      }
    }
  }	
  ll ret = 0;
  for (int j = 0; j < 3; j++) {
    chmax(ret, dp[N][j]);
  }
  cout << ret << endl;

  return 0;
}