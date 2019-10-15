#include"13water.h"
int hs[300];
char Hs[300],HS[300];
int main()
{
	//ifstream fin("test.txt");
	char col[2],val[5];
	cards c;
	hs['$']=1;
	hs['&']=2;
	hs['*']=3;
	hs['#']=4;
	hs['A']=14;
	hs['J']=11;
	hs['Q']=12;
	hs['K']=13;
	Hs[1]='$';
	Hs[2]='&';
	Hs[3]='*';
	Hs[4]='#';
	HS[14]='A';
	HS[11]='J';
	HS[12]='Q';
	HS[13]='K';
	for (int i=0;i<13;++i){
		cin >> val;
		int a=hs[val[0]];
		int b=isalpha(val[1])?hs[val[1]]:atoi(val+1);
		c.push_back(mp(b,a));
	}
	autoPlayer ap(c);
	c=ap.calculate();
	for (int i=0;i<3;++i){
		cout<<Hs[c[i].se];
		if (c[i].fi>10)
			cout<<HS[c[i].fi];
		else
			cout<<c[i].fi;
		cout<<" ";
	}
	cout<<endl;
	for (int i=3;i<8;++i){
		cout<<Hs[c[i].se];
		if (c[i].fi>10)
			cout<<HS[c[i].fi];
		else
			cout<<c[i].fi;
		cout<<" ";
	}
	cout<<endl;
	for (int i=8;i<13;++i){
		cout<<Hs[c[i].se];
		if (c[i].fi>10)
			cout<<HS[c[i].fi];
		else
			cout<<c[i].fi;
		cout<<" ";
	}
	cout << endl;
	return 0;
}

