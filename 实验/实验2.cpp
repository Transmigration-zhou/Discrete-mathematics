#include <bits/stdc++.h> 
using namespace std;
const int N=105;
int n;
int a[N][N],b[N][N];
void Warshall(){
    for(int j=1;j<=n;j++){ //第1列到最后列
   		for(int i=1;i<=n;i++){ //第j列从第1行到最后行
    		if(b[i][j]){
    			for(int k=1;k<=n;k++) {
                    b[i][k]|=b[j][k];
                }
			}	
		}
	}
}

int main(){
	puts("请输入矩阵大小n");
	cin>>n; 
    puts("请输入n*n的矩阵");
    bool flag=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]>1&&a[i][j]<0) flag=0;
		}
	}
    if(!flag){
        printf("输入格式有误\n");
    }
	else{
		puts("自反闭包：");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				b[i][j]=a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			b[i][i]=1;
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<b[i][j]<<" ";
			}
			puts("");
		}
		puts("-------------------");
		
		puts("对称闭包：");
		memset(b,0,sizeof b);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]) b[i][j]=b[j][i]=1;
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<b[i][j]<<" ";
			}
			puts("");
		}
		puts("-------------------");
		
		puts("传递闭包：");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				b[i][j]=a[i][j];
			}
		}
		Warshall();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<b[i][j]<<" ";
			}
			puts("");
		}
	}
    return 0;
}

