// Problem: E - Knapsack 2
// Contest: AtCoder - Educational DP Contest / DP まとめコンテスト
// URL: https://atcoder.jp/contests/dp/tasks/dp_e
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
  for(int i=0; i<110; i++)for(int j=0; j<100010; j++)dp[i][j]=INF;
  dp[0][0]=0;
  
  for (ll i = 0; i < N; i++) {
    for (ll sum_v = 0; sum_v <= 100010; sum_v++) {
      if(sum_v-v[i]>=0)chmin(dp[i+1][sum_v], dp[i][sum_v-v[i]] + w[i]);
      chmin(dp[i+1][sum_v], dp[i][sum_v]);
    }
  }
  ll ret = 0;
  for (ll sum_v = 0; sum_v < 100010; sum_v++) {
    if(dp[N][sum_v]<=W) chmax(ret,sum_v);
  }
  cout << ret << endl;

  return 0;
}