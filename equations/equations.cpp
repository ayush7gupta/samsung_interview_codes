#include<iostream>

using namespace std;

long long a,b,c,k;


int logo(int n)
{
	int j=1;
	int i=0;
	while(j<=n)
	{
		j=j*2;
		i++;
		
	}
	return --i;
	
	
}

int func(int n)
{
	int ans=0;
	ans+=n*a;
	ans+=b*n*logo(n);
	ans+=c*n*n*n;
	//cout<<"inside func"<<endl;
	return ans;
	
}

int uttar()
{
	int low ,high;
	low =1;
	high=2;
	if(func(low)==k)
	return low;
	if(func(high)==k)
	return high;
	while(func(high)<k)
	{
		low=high;
		high=high*2;
	}
	int flag=0;
	//cout<<"inside uttar"<<endl;
	while(low<=high)
	{
		int mid=(low+high)/2;
		int x=func(mid);
		if(x==k)
			return mid;
		else if(x>k)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	return 0;
}


int main()
{
cin>>a>>b>>c>>k;

cout<<uttar();
//cout<<logo(k);

	return 0;	
}
