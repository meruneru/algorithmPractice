// Problem: B - Frog 2
// Contest: AtCoder - Educational DP Contest / DP まとめコンテスト
// URL: https://atcoder.jp/contests/dp/tasks/dp_b
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
ll N, K;
ll h[100010];
ll dp[100010];
int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }
  dp[0] = 0;
  for (int i = 1; i < N; i++) {
    dp[i] = INF;
  }

  for (int i = 1; i < N; i++) {
    for (int j = 1; j <= K; j++) {
      if (i - j >= 0) chmin(dp[i], dp[i - j] + abs(h[i - j] - h[i]));
    }
  }

  cout << dp[N - 1] << endl;

  return 0;
}