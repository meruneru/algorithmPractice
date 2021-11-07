// Problem: D - Knapsack 1
// Contest: AtCoder - Educational DP Contest / DP まとめコンテスト
// URL: https://atcoder.jp/contests/dp/tasks/dp_d
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
ll N, W;
ll w[110], v[110];
ll dp[110][100010];

int main() {
  cin >> N >> W;
  for (int i = 0; i < N; i++) {
    cin >> w[i] >> v[i];
  }

  for (ll i = 0; i < N; i++) {
    for (ll sum_w = 0; sum_w <= W; sum_w++) {
      if(sum_w-w[i]>=0)chmax(dp[i+1][sum_w], dp[i][sum_w-w[i]] + v[i]);
      chmax(dp[i+1][sum_w], dp[i][sum_w]);
    }
  }
  ll ret = 0;
  for (int j = 0; j <= W; j++) {
    chmax(ret, dp[N][j]);
  }
  cout << ret << endl;

  return 0;
}