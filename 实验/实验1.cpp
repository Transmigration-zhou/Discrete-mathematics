#include <bits/stdc++.h>
using namespace std;

int tag[30]; 
vector<bool> g;

void menu(){
	cout << "***************************************\n";
	cout << "**                                   **\n";
	cout << "**         欢迎进入逻辑运算软件      **\n";
	cout << "**        (可运算真值表,支持括号)    **\n";
	cout << "**                                   **\n";
	cout << "**             用!表示取反           **\n";
	cout << "**             用&表示合取           **\n";
	cout << "**             用|表示析取           **\n";
	cout << "**             用^表示蕴含           **\n";
	cout << "**             用~表示等值           **\n";
	cout << "**  优先级:取反>合取>析取>蕴含>等价  **\n";
	cout << "**                                   **\n";
	cout << "***************************************\n\n";
}

//中缀转后缀
string change(string s){
	string ss="";
	stack<char> st;
	char t;
	for(auto x:s){
		if(x=='!'){
			 st.push(x);
		}
		else if(x=='&'){
			if(st.empty()){
				st.push(x);
			}
			else{
				do{
					t=st.top();
					st.pop();
					if(t=='('||t=='|'||t=='^'||t=='~'){
						st.push(t);
					}
					else{
						ss+=t;
					}
				}while(!st.empty()&&t!='('&&t!='|'&&t!='^'&&t!='~');
				st.push(x);
			}
		}
		else if(x=='|'){
			if(st.empty()){
				st.push(x);
			}
			else{
				do{
					t=st.top();
					st.pop();
					if(t=='('||t=='^'||t=='~'){
						st.push(t);
					}
					else{
						ss+=t;
					}
				}while(!st.empty()&&t!='('&&t!='^'&&t!='~');
				st.push(x);
			}
		}
		else if(x=='^'){
			if(st.empty()){
				st.push(x);
			}
			else{
				do{
					t=st.top();
					st.pop();
					if(t=='('||t=='~'){
						st.push(t);
					}
					else{
						ss+=t;
					}
				}while(!st.empty()&&t!='('&&t!='~');
				st.push(x);
			}
		}
		else if(x=='~'){
			if(st.empty()){
				st.push(x);
			}
			else{
				do{
					t=st.top();
					st.pop();
					if(t=='('){
						st.push(t);
					}
					else{
						ss+=t;
					}
				}while(!st.empty()&&t!='(');
				st.push(x);
			}
		}
		else if(x=='('){
			st.push(x);
		}
		else if(x==')'){
			t=st.top();
			st.pop();
			while(t!='('){
				ss+=t;
				t=st.top();
				st.pop();
			}
		}
		else if(x>='a'&&x<='z'){
			ss+=x;
		}
		else{
			cout<<"非法\n";
			exit(0);
		}
	}
	while(!st.empty()){
		t=st.top();
		st.pop();
		ss+=t;
	}
	char temp=ss[ss.length()-1];
	if(temp>='a'&&temp<='z') return ss;
	else {
		cout<<"非法\n";
		exit(0);
	}
}

bool calc(string s){
	bool ans;
	stack<bool> st;
	for(auto c:s){
		if(c=='!'){
			if(st.empty()){
				cout<<"非法\n";
				exit(0);
			}
			bool t=st.top();
			st.pop();
			st.push(!t);
		}
		else if(c=='&'){
			if(st.empty()){
				cout<<"非法\n";
				exit(0);
			}
			bool t1=st.top();
			st.pop();
			if(st.empty()){
				cout<<"非法\n";
				exit(0);
			}
			bool t2=st.top();
			st.pop();
			st.push(t1&t2);
		}
		else if(c=='|'){
			if(st.empty()){
				cout<<"非法\n";
				exit(0);
			}
			bool t1=st.top();
			st.pop();
			if(st.empty()){
				cout<<"非法\n";
				exit(0);
			}
			bool t2=st.top();
			st.pop();
			st.push(t1|t2);
		}
		else if(c=='^'){
			if(st.empty()){
				cout<<"非法\n";
				exit(0);
			}
			bool t1=st.top();
			st.pop();
			if(st.empty()){
				cout<<"非法\n";
				exit(0);
			}
			bool t2=st.top();
			st.pop();
			st.push((!t1)|t2);
		}
		else if(c=='~'){
			if(st.empty()){
				cout<<"非法\n";
				exit(0);
			}
			bool t1=st.top();
			st.pop();
			if(st.empty()){
				cout<<"非法\n";
				exit(0);
			}
			bool t2=st.top();
			st.pop();
			st.push(t1==t2);
		}
		else{
			st.push(g[tag[c-'a']]);
		}
	}
	return st.top();
}

int main(){
	menu();
	string s,ss;
	cin>>s;
	ss=change(s);
//	cout<<ss<<"\n"; 
	vector<char> v;
	int cnt=0;
	for(auto c:s){
		if(isalpha(c)){
			if(!tag[c-'a']){
				tag[c-'a']=cnt++;
				v.push_back(c);
			}
		}
	}
	
	for(auto x:v) cout<<x<<"\t";
	cout<<s<<"\n";
	
	for(int i=0;i<(1<<cnt);i++){
		int t=i;
		g.clear();
		for(int j=0;j<cnt;j++){
			g.push_back(t%2);
			t/=2;
		}
		for(int x:g) cout<<x<<"\t";
		cout<<calc(ss)<<"\n";
	}
	return 0;
}


