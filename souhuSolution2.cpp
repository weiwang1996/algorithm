#include <cstdio>
#include <iostream>
#include<algorithm>
//#include<windows.h>
using namespace std;
int p[6];
void solve(){
	int ans=0;
	ans+=p[5];
	ans+=p[4];
	if(p[0]<=p[4]*11) p[0] = 0;
	else p[0]-=(p[4]*11);
	ans+=p[3];
	if(p[1]<=p[3]*5) {
		int t=p[3]*20-p[1]*4;
		p[1]=0;
		if(p[0]<t) p[0] = 0;
		else p[0]-=t;
	}
	else p[1]-=p[3]*5;
	ans+=(p[2]+3)/4;
	p[2]%=4;
	if(p[2]==1){
		if(p[1]<=5){
			int t=27-p[1]*4;
			p[1]=0;
			p[0]=max(0,p[0]-t);
		}else{
			p[1]-=5;
			p[0]=max(0,p[0]-7);
		}
	}else if(p[2]==2){
		if(p[1]<=3){
			int t=18-p[1]*4;
			p[1]=0;
			p[0]=max(0,p[0]-t);
		}else {
			p[1]-=3;
			p[0]=max(0, p[0] - 6);
		}
	}else if(p[2]==3){
		if(p[1]){
			p[1]--;
			p[0]=max(0,p[0]-5);
		}else p[0]=max(0,p[0]-9);
	}
	ans+=(p[1]+8)/9;
	p[1]%=9;
	if(p[1])
		p[0]=max(0,p[0]-(36-p[1]*4));
	ans+=(p[0]+35)/36;
	printf("%d\n",ans);
}
int main(){
	while(true){
		bool flag=true;
		for(int i=0;i<6;i++){
			scanf("%d",p+i);
			if(p[i]!=0) flag=false;
		}
		if(flag) break;
		solve();
	}
	return 0;
}
