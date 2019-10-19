#include"13water.h"
int hs[300];
char Hs[300],HS[300];
void init(){
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
}
int main(int argc, char *argv[])
{
	init();
	cards c;
	for (int i=0,j=0;i<13;++i,j+=2){
		int a=hs[argv[1][j]];
		int b=isalpha(argv[1][1+j])?hs[argv[1][1+j]]:atoi(argv[1]+j+1);
		if (b==10)
			j++;
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
		if (i<2)
			cout<<" ";
		else
			cout<<"\n";
	}
	for (int i=3;i<8;++i){
		cout<<Hs[c[i].se];
		if (c[i].fi>10)
			cout<<HS[c[i].fi];
		else
			cout<<c[i].fi;
		if (i<7)
			cout<<" ";
		else
			cout<<"\n";
	}
	for (int i=8;i<13;++i){
		cout<<Hs[c[i].se];
		if (c[i].fi>10)
			cout<<HS[c[i].fi];
		else
			cout<<c[i].fi;
		if (i<12)
			cout<<" ";
		else
			cout<<"\n";
	}
	return 0;
}
/*
*10*7*2#10^&6^&9^&10$A*J$4^&2#A*5
*/
