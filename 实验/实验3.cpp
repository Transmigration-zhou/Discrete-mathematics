#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10,INF=0x3f3f3f3f;
int n,m,fa[N],depth[N];
struct edge{
    int u,v,w;
}e[N];

bool cmp(edge x,edge y){
    return x.w<y.w;
}

void init(int n){
    for(int i=1;i<=n;i++) 
        fa[i]=i,depth[i]=1;
}
//查询树的根
int find(int x){
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}
//合并a和b所属的集合   
void unite(int a,int b){
    a=find(a),b=find(b);
    if(depth[a]==depth[b]){
        depth[a]=depth[a]+1;
        fa[b]=a;
    }
    else{
        if(depth[a]<depth[b]) fa[a]=b;
        else fa[b]=a;
    }
}
//判断a和b是否属于同一个集合
bool same(int a,int b){
    return find(a)==find(b);
}

int Kruskal(){
    int res=0,count=0;
    for(int i=0;i<m;i++){
        if(!same(e[i].u,e[i].v)){
            unite(e[i].u,e[i].v);
            res+=e[i].w;
            count++;
        }
        if(count==n-1) return res;
    }
    return -1;
}

int main(){
	puts("请输入结点数n和边数m");
    cin>>n>>m;
    puts("请依次输入m条无向边连接结点u,v和长度w"); 
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    sort(e,e+m,cmp);
    init(n);
    int k=Kruskal();
    if(k!=-1) cout<<k;
    else puts("impossible");
    return 0;
}
