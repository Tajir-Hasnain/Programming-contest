/*
Manuel Pineda
Accepted
*/
using namespace std;
#include<iostream>
#include<cstdio>
#include<string>
#include<cctype>
#include<cmath>
#define Mdouble 1.79769e+308

const double EPS = 1e-7;
char buf[20];

int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

double a,b,c,d,m,t,p;

double fun(double v){
    return v*v*v*a + v*v*b + c*v;
}


int main (){
	int i;
	double si,un,f,e,mid,ans;
	while(cin>>a>>b>>c>>d>>m>>t){
		p=(t/m)-d;
		si=0.0;
		un= Mdouble;
		while(cmp(si,un)==-1){
			f=fun(si);
			e=fun(un);
			mid=fun((si+un)/2.0);
			if(cmp(mid,p)==-1)
			si=(si+un)/2.0;
			else if(cmp(mid,p)==1)
				un=(si+un)/2.0;
			else{
				ans=(si+un)/2.0;
				break;
			}			
		}
		//ans=(floor(ans*100.0 + 0.5))/100.0;
		ans=(floor(ans*100.0))/100.0;
		printf("%.2lf\n",ans);
	}
	return 0;    
}
