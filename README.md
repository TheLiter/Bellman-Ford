# Bellman-Ford algorithm

#### 벨만 포드 알고리즘

벨만 포드는 얼핏보면 반복문을 3번 돌려서 최단경로를 얻는 알고리즘처럼 보이지만,

자세히 보다보면 O(|V||E|)라는 시간복잡도를 나타내는 신기한 알고리즘입니다.

O(|V|^3)이라는 시간복잡도와 다르게 시간복잡도가 많이 줄어든 것을 볼 수 있는데...

굳이 따지자면 |V|*|E| = 1e9( = 10억) 안에 연산량이 들어가기만 한다면 연산이 가능합니다.

우선 구현된 코드는 다음과 같습니다.

```c
#include <cstdio>
#include <algorithm>

int shortest[510], parent[510], INF = 1e6;
int adj[510][510];

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  while(m--) {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    adj[a][b] = adj[b][a] = w;
  }

  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      adj[i][j] = adj[i][j] ? adj[i][j] : INF;

  std::fill(shortest+1, shortest+n+1, INF);

  shortest[1] = 0;
  bool update = 1;

  while(update) {
    update = 0;

    for(int j=1; j<=n; j++) {
      for(int k=1; k<=n; k++) {
        if(shortest[k] > shortest[j] + adj[j][k]) {
          shortest[k] = shortest[j] + adj[j][k];
          parent[k] = j;
          update = 1;
        }
      }
    }
  }

  printf(shortest[n] != INF ? "%d\n" : "Impossible\n", shortest[n]);
  if(shortest[n] == INF) { return 0; }

  return 0;
}
```
