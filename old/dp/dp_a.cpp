// Problem: A - Frog 1
// Contest: AtCoder - Educational DP Contest / DP まとめコンテスト
// URL: https://atcoder.jp/contests/dp/tasks/dp_a
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
ll h[100010];
ll dp[100010];
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }
  dp[0] = 0;
  for (int i = 1; i < N; i++) {
    dp[i] = INF;
  }

  for (int i = 1; i < N; i++) {
    chmin(dp[i], dp[i - 1] + abs(h[i - 1] - h[i]));
    if (i > 1) chmin(dp[i], dp[i - 2] + abs(h[i - 2] - h[i]));
  }

  cout << dp[N - 1] << endl;

  return 0;
}