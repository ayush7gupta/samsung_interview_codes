#include <iostream>
using namespace std;

int ans=(1<<30)-1;

int abs(int  x)
{
	if(x>=0)
	return x;
	return x*-1;
}
void calculat(int n, int index1, int index2, int index3, int p1, int p2, int p3)
{
	int uttar=0;
	int i=0;
	for(;i<p1;i++)
	{
		uttar+=abs(i-index1)+1;
	}
	for(;i<p1+p2;i++)
	{
		uttar+=abs(i-index2)+1;
	}
	for(;i<p1+p2+p3; i++)
	{
		uttar+=abs(i-index3)+1;
	}
	if(uttar<ans)
	ans=uttar;
}

void func(int n, int m, int index1, int index2, int index3, int p1, int p2, int p3)
{
	if(n<m)
	return;
	if(n==m)
	{
		calculat(n,index1, index2, index3, p1, p2, p3);
	}
	if(index1-1>=0)
	{
		func(n-1,m,index1-1,index2-1,index3-1, p1, p2, p3);
	}
	if(index1< index2-1)
	{
		func(n-1,m,index1, index2-1, index3-1, p1, p2, p3);
	}
	if(index2< index3-1)
	{
		func(n-1,m, index1, index2, index3-1, p1, p2, p3);
	}
	
	func(n-1,m, index1, index2, index3, p1, p2, p3);
	
}
int main() {
	// your code goes here
	int n;
	int m;
	cin>>n>>m;
	int g1,g2,g3;
	int p1,p2,p3;
	
	cin>>g1>>p1>>g2>>p2>>g3>>p3;
	cout<<ans<<endl;
	func(n, m, g1, g2, g3, p1, p2, p3);
	cout<<ans;
	return 0;
}
