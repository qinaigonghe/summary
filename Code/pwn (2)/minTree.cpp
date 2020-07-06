#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define INF 1<<30-1
#define Max 200001
typedef struct Edge{
    int x,y,z;
    bool operator < (const Edge& obj)const{
            return z<obj.z;
    }


}Edge;
Edge edge[Max];
int fa[5010];

int init(){
    for(int i=0;i<5001;i++){
        fa[i]=i;
    }
}
int findfa(int i){
    if(fa[i]==i) return i;
    int r=i;
    while(fa[r]!=r){
        r=fa[r];
    }
    int x=i;
    while(fa[x]!=x){
        i=x;
        x=fa[x];
        fa[i]=r;
    }
    return r;
}
int uni(int a,int b){
    int x=findfa(a);
    int y=findfa(b);
    fa[x]=y;
}
int cnt=0,ans=0;
int main(){
    init();
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>edge[i].x>>edge[i].y>>edge[i].z;
    }
    sort(edge,edge+m);
    for(int i=0;i<m;i++){
        Edge &e=edge[i];
        int pa=findfa(e.x);
        int pb=findfa(e.y);
        if(pa==pb)continue;
        fa[pa]=pb;
        ans+=e.z;
        cnt++;
    }
    if(cnt==n-1) cout<<ans;
    else cout<<"orz";
    return 0;

}
/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,m,i,j,u,v,total;
struct edge{
    int start,to;long long val;
}bian[2000005];
int f[100000];
long long ans;

int find(int x)//���鼯����
{
    if (f[x]==x) return x; else
    {
        f[x]=find(f[x]);
        return f[x];
    }
}

bool cmp(edge a,edge b)//�ṹ�����ʱ�õ���
{
    return a.val<b.val;
}

inline void kruskal()//��С������
{

    for(int i=1;i<=m;i++)
    {
        u=find(bian[i].start);
        v=find(bian[i].to);
        if(u==v) continue;//�ж��ڲ���ͬһ�����鼯���棬�ھ���һ��ѭ��
            ans+=bian[i].val;//���ڣ��ͼ���
            f[u]=v;//�����������鼯
            total++;
            if(total==n-1) break;//���γ�����С���������˳���֮������Ҳû���ˣ�
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) f[i]=i;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&bian[i].start,&bian[i].to,&bian[i].val);
    }
    sort(bian+1,bian+m+1,cmp);//���ű߳�
    kruskal();
    printf("%d",ans);
    return 0;
}
*/
