#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#define sz(x) int(x.size())
#define fi first
#define se second
#define dd(x) cout<<#x<<" = "<<x<<" "
#define de(x) cout<<#x<<" = "<<x<<"\n"
using namespace std;
typedef vector<pair<int,int>> cards; //firsr:2-14, se:1-4
class autoPlayer{
private:
	cards card;
	vector<int> set3,set5;
	pair<int,int> f[10000],g[10000];
public:
	autoPlayer(cards _card){
		card=_card;
		for (int i=1;i<(1<<13)-1;++i){
			f[i].first=f[i].se=g[i].first=g[i].fi=0;
			if (__builtin_popcount(i)==5){
				set5.push_back(i);
				f[i]=evaluate5(i);
			}
			if (__builtin_popcount(i)==3){
				set3.push_back(i);
				g[i]=evaluate3(i);
			}
		}
	}
	pair<int,int> evaluate3(int status){
		
	}
	pair<int,int> evaluate5(int status){
		
	}
	int THS(cards c){
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
	int SZ(cards c){
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
	int DZ(cards c){
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
	
