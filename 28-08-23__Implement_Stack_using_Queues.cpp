#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	   int n,m;
	   cin>>n>>m;
	   if(n%2==0&&m%2==0)cout<<"0\n";
	   else if(n%2==1&&m%2==1)cout<<n+m-1<<endl;
	   else if(n%2==0)cout<<n<<endl;
	   else cout<<m<<endl;
	}
	return 0;
}