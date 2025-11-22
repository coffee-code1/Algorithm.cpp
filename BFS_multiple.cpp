#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N=1010;
int n,m;
char g[N][N];
struct Node{int x,y;};
int dis[N][N];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void bfs(){
  memset(dis,-1,sizeof dis);
  queue<Node> q;
  for(int i=0; i<n; i++)//多源的起始点输入
    for(int j=0; j<m; j++)
      if(g[i][j] == '1')
        dis[i][j]=0, q.push({i,j});//输入后初始化为0；一是防止走回头路，二是要计算距离这个点的距离
  while(q.size()){
    auto t=q.front(); q.pop();
    for(int i=0; i < 4; i++){
      int a=t.x+dx[i], b=t.y+dy[i];
      if(a<0||a>=n||b<0||b>=m)continue;
      if(dis[a][b]!=-1) continue;
      dis[a][b]=dis[t.x][t.y]+1;//一次加一代表距离
      q.push({a,b});
    }
  }
}
int main(){
  cin >> n >> m;
  for(int i=0; i < n; i ++) 
    scanf("%s",g[i]);
  bfs();
  for(int i=0; i < n; i ++){
    for(int j=0; j < m; j ++) 
      printf("%d ",dis[i][j]);
    puts("");
  }
  return 0;
}