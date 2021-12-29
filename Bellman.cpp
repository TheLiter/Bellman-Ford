#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int shortest[510], parent[510], INF = 1e6;
int adj[510][510];

vector<int> p;

void f(int point) {
  if(parent[point] == 0) return;
  p.push_back(point);
  f(parent[point]);
}

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

  fill(shortest+1, shortest+n+1, INF);

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

  f(n);
  p.push_back(1);
  for(int i=p.size()-1; i>=0; i--)
    printf("%d ", p[i]);

  return 0;
}
