#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<bitset>
#include<string>
#include<cstring>
#define sz(x) int(x.size())
#define mp make_pair
#define fi first
#define se second
#define dd(x) cout<<#x<<" = "<<x<<" "
#define de(x) cout<<#x<<" = "<<x<<"\n"
using namespace std;
typedef vector<pair<int,int>> cards; //firsr:2-14, se:1-4
inline int count(int x) {
	int cnt = 0;
	while (x) {
		cnt += x & 1;
		x >>= 1;
	}
	return cnt;
}
class autoPlayer{
private:
	cards card;
	vector<int> set3,set5;
	pair<int,int> f[10000],g[10000];
	int value[3][10];				//º€÷µ∆¿π¿æÿ’Û 
public:
	autoPlayer(cards _card){
		card=_card;
		for (int i=1;i<(1<<13)-1;++i){
			if (count(i)==5){
				set5.push_back(i);
				f[i]=evaluate5(i);
			}
			if (count(i)==3){
				set3.push_back(i);
				g[i]=evaluate3(i);
			}
		}
		memset(value,0,sizeof(value));
		value[0][1]=2;
		value[0][2]=3;
		for (int i=1;i<=7;++i)
			value[1][i]=i+1; 
		value[1][8]=50;
		value[1][9]=100;
		for (int i=1;i<=7;++i)
			value[2][i]=i;
		value[2][8]=15;
		value[2][9]=20;
	}
	void getSolution(int choose[20],int a,int b,int c){
		for (int i=0;i<13;++i){
			if (a>>i&1)
				choose[i]=0;
			else if (b>>i&1)
				choose[i]=1;
			else
				choose[i]=2;
		}
	}
	cards calculate(){
		int choose[20]={0};
		int mxval=0;
		for (auto i:set5)
			for (auto j:set3){
				if (i&j)
					continue;
				int k=(i|j)^((1<<13)-1);
				if (!(f[i]>=f[k]&&f[k]>=g[j]))
					continue;
				int sum=value[2][f[i].fi]+value[1][f[k].fi]+value[0][g[j].fi];
				if (sum>mxval){
					mxval=sum;
					getSolution(choose,j,k,i);
				}
			}
		cards res;
		for (int i=0;i<3;++i)
			for (int j=0;j<sz(card);++j)
				if (choose[j]==i)
					res.push_back(card[j]);
		return res;
	}
	pair<int,int> evaluate3(int status){
		cards c;
		int mx=0;
		for (int i=0;i<13;++i)
			if (status>>i&1){
				c.push_back(card[i]);
				mx=max(mx,card[i].fi);
			}
		int val;
		if (val=Triple(c))
			return mp(4,val);
		if (val=DZ(c))
			return mp(1,val);
		return mp(0,mx);
	}
	pair<int,int> evaluate5(int status){
		cards c;
		int mx=0;
		for (int i=0;i<13;++i)
			if (status>>i&1){
				c.push_back(card[i]);
				mx=max(mx,card[i].fi);
			}
		int val;
		if (val=THS(c))
			return mp(9,val);
		if (val=Boom(c))
			return mp(8,val);
		if (val=Hulu(c))
			return mp(7,val);
		if (val=TH(c))
			return mp(6,val);
		if (val=SZ(c))
			return mp(5,val);
		if (val=Triple(c))
			return mp(4,val);
		if (val=LD(c))
			return mp(3,val);
		if (val=DD(c))
			return mp(2,val);
		if (val=DZ(c))
			return mp(1,val); 
		return mp(0,mx);		
	}
	int THS(cards& c){
		sort(c.begin(),c.end());
		for (int i=1;i<sz(c);++i)
			if (c[i].fi-c[i-1].fi!=1||c[i].se!=c[i-1].se)
				return 0;
		return c.back().fi;
	}
	int Boom(cards& c){
		int cnt[20]={0};
		for (auto i:c)
			cnt[i.fi]++;
		for (int i=2;i<=14;++i)
			if (cnt[i]==4)
				return i;
		return 0;
	}
	int Hulu(cards& c){
		int cnt[20]={0};
		for (auto i:c)
			cnt[i.fi]++;
		int f1=0,f2=0;
		for (int i=2;i<=14;++i){
			if (cnt[i]==3)
				f1=i;
			else if (cnt[i]==2)
				f2=1;
		}
		if (f1&&f2)
			return f1;
		return 0;
	}
	int TH(cards& c){
		int mx=c[0].fi;
		for (int i=1;i<sz(c);++i){
			if (c[i].se!=c[i-1].se)
				return 0;
			mx=max(mx,c[i].fi);
		}
		return mx;
	}
	int SZ(cards& c){
		sort(c.begin(),c.end());
		for (int i=1;i<sz(c);++i)
			if (c[i].fi-c[i-1].fi!=1)
				return 0;
		return c.back().fi;
	}
	int Triple(cards& c){
		int cnt[20]={0};
		for (auto i:c)
			cnt[i.fi]++;
		for (int i=2;i<=14;++i)
			if (cnt[i]==3)
				return i;
		return 0;
	}
	int LD(cards& c){
		int cnt[20]={0};
		for(auto i:c)
			cnt[i.fi]++;
		vector<int> t;
		for (int i=2;i<=14;++i)
			if (cnt[i]==2)
				t.push_back(i);
		if (sz(t)==2&&abs(t[1]-t[0])==1)
			return max(t[0],t[1]);
		return 0;
	}
	int DD(cards& c){
		int cnt[20]={0};
		for(auto i:c)
			cnt[i.fi]++;
		vector<int> t;
		for (int i=2;i<=14;++i)
			if (cnt[i]==2)
				t.push_back(i);
		if (sz(t)==2)
			return max(t[0],t[1]);
		return 0;
	}
	int DZ(cards& c){
		int cnt[20]={0};
		for(auto i:c)
			cnt[i.fi]++;
		int t=0;
		for (int i=2;i<=14;++i)
			if (cnt[i]==2)
				t=i;
		return t;
	}
	bool MostDragon(cards& card){
		for (int i=1;i<sz(card);++i)
			if (card[i].se!=card[i-1].se)
				return 0;
			return 1;
	}
	bool Dragon(cards card){
		sort(card.begin(),card.end());
		for (int i=1;i<sz(card);++i)
			if (card[i].fi-card[i-1].fi!=1)
				return 0;
		return 1;
	}
	bool TwelveRoyal(cards& card){
		int cnt=0;
		for (auto i:card)
			cnt+=i.fi>=10;
		return cnt==12;
	}
	bool AllBig(cards& card){
		for (auto i:card)
			if (i.fi<8)
				return 0;
		return 1;
	}
	bool AllSmall(cards& card){
		for (auto i:card)
			if (i.fi>8)
				return 0;
		return 1;
	}
	bool TripleBoom(cards& card){
		int cnt[20]={0};
		for (auto i:card)
			cnt[i.fi]++;
		for (int i=2;i<=14;++i)
			cnt[0]+=cnt[i]==4;
		return cnt[0]==3;
	}
	bool OneColor(cards& card){
		int cnt[2]={0};
		for (auto i:card)
			cnt[i.fi<=2]++;
		return !cnt[0]||!cnt[1];
	}
};
	
