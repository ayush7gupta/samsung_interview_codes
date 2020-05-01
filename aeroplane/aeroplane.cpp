#include <iostream>
using namespace std;
int ans=-1;

int get_val(int row, int col, int bomb, int **arr)
{
	if(bomb==-1)
	{
		if(arr[row][col]==2)
		{
			return -1;
		}
		else
		return arr[row][col];
	}
	
	else
	{
		if(arr[row][col]==2)
		{
			if(row>bomb && row<=bomb+5)
			{
				return 0;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			return arr[row][col];
		}
	}
	return arr[row][col];

}

int  valid( int n)
{
	if(n>=0 && n<=4)
	return 1;
	return 0;
}
void func(int row, int col, int current, int bomb, int **arr, int n)
{
		/*if(row==3 && col==0)
	{
		cout<<current<<" "<<get_val(row, col, bomb, arr)<<" "<<ans<<endl;
	}*/
	current+= get_val(row, col, bomb, arr);
	if(current<0)
	{
		return ;
	}
	/*if(row>n)
	{
		return;
	}*/
	
	//cout<<"row "<<row<<"  "<<"col  "<<col<<"  current"<<current<<"  bomb"<<bomb<<"  ans"
//<<ans<<endl;
	if(row>=n)
		{
		//int x= get_val(row, col, bomb, arr);
		if(current>ans )
		{
			ans=current;
			//cout<<col<<"  "<<ans<<endl;
		}
		return;
	}
	
	if(bomb==-1)
	{
		if(col+1<5)
		{
			func(row+1,col+1,current, row, arr, n);
		}
		
		
		func(row+1, col, current, row, arr, n);
		if(col-1>=0)
		{
			func(row+1, col-1, current, row, arr, n);
		}
		
		
	}
	if(col+1<5)
	{
		func(row+1, col+1, current, bomb, arr, n);	
	}
	
	func(row+1, col, current, bomb, arr, n);
	
	if(col-1>=0)
	{
		func(row+1, col-1, current, bomb, arr, n);
	}
	
	
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	int **arr=new int *[n+1];
	for(int i=0;i<n+1;i++)
	{
		arr[i]=new int[5];
	}
	
	arr[0][0]=arr[0][1]=arr[0][2]=arr[0][3]=arr[0][4]=0;
	//arr[0][2]=1;
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<5;j++)
		{
			cin>>arr[i][j];
			//cout<<arr[i][j];
		}
		//cout<<endl;
	}
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	//void func(int row, int col, int current, int bomb, int **arr, int n)
	/*func(1, 1, 0, -1, arr, n);
	func(1, 2, 0, -1, arr, n);
	func(1, 3, 0, -1, arr, n);
	func(1, 1, 0,  0, arr, n);
	func(1, 2, 0,  0, arr, n);
	func(1, 3, 0,  0, arr, n);
	*/
	func(0, 2, 0, -1, arr, n);
	cout<<ans;
	//cout<<get_val(4, 1, -1, arr);
	return 0;
}
