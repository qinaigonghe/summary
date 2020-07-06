#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define M 110
#define INF 0x7fffffff

struct node{
    int x,y;
};

int n,m;

node p[4];
char mpt[M][M];

int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

int vis[M][M][4];
int i;
void bfs(int index){
    queue<node> q;
    node now,next;
    now.x=p[index].x;
    now.y=p[index].y;
    q.push(now);
    vis[now.x][now.y][index]=0;
    while(!q.empty()){
        now=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            next=now;
            next.x+=dir[i][0];
            next.y+=dir[i][1];
            if(next.x<1 ||next.x>n ||next.y<1 ||next.y>m) continue;
            int tmp=vis[now.x][now.y][index];
            if(mpt[next.x][next.y]=='#') tmp++;
            if(tmp<vis[next.x][next.y][index])
                {
                    vis[next.x][next.y][index]=tmp;
                    q.push(next);
                }
        }
    }
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int k=1;k<4;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    vis[i][j][k]=INF;
                }
            }
        }
        for(int i=1;i<=n;i++){
            scanf("%s",mpt[i]+1);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mpt[i][j]=='w') p[1].x=i,p[1].y=j;
                else if(mpt[i][j]=='W') p[2].x=i,p[2].y=j;
                else if(mpt[i][j]=='f') p[3].x=i,p[3].y=j;
            }
        }
        bfs(1);
        bfs(2);
        bfs(3);
        int ans=INF;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int tmp=0;
                for(int k=1;k<=3;k++)
                {
                    tmp+=vis[i][j][k];
                }
                if(mpt[i][j]=='#') tmp-=2;
                if(tmp<ans) ans=tmp;
            }
        }
        cout<<ans<<endl;
    }
}
