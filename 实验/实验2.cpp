#include <bits/stdc++.h> 
using namespace std;
const int N=105;
int n;
int a[N][N],b[N][N];
void Warshall(){
    for(int j=1;j<=n;j++){ //��1�е������
   		for(int i=1;i<=n;i++){ //��j�дӵ�1�е������
    		if(b[i][j]){
    			for(int k=1;k<=n;k++) {
                    b[i][k]|=b[j][k];
                }
			}	
		}
	}
}

int main(){
	puts("����������Сn");
	cin>>n; 
    puts("������n*n�ľ���");
    bool flag=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]>1&&a[i][j]<0) flag=0;
		}
	}
    if(!flag){
        printf("�����ʽ����\n");
    }
	else{
		puts("�Է��հ���");
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
		
		puts("�ԳƱհ���");
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
		
		puts("���ݱհ���");
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

