#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next=NULL;
};

int flag=0;
int count=0;
int head=-1;

void dfs( node **graph, int * visited, int current,int * arr, int *stack)
{
	visited[current]=1;
	stack[current]=1;
	if(flag==1 || flag==2)
	{
		stack[current]=0;
		return;
	}
	
	if(graph[current]==NULL)
	{
		stack[current]=0;
		return;
	}
	node *ptr=graph[current];
	
	while(ptr!=NULL)
	{
		if(stack[ptr->data]==1)
		{
			flag=1;
			head=ptr->data;
			break;
			
		}
		if(visited[ptr->data]==0)
		{
			dfs(graph, visited, ptr->data, arr,stack);	
		}
		
		ptr=ptr->next;
	}
	if(flag==1 && current==head)
	{
		flag=2;
		arr[count]=head;
		count++;
		
	}
	if(flag==1)
	{
		arr[count]=current;
		count++;
		
	}
	stack[current]=0;
	
}

int partition(int *arr, int low, int high)
{
	int pivot=arr[high];
	int s=low-1;
	int l=low;
	int a;
	for(;l<high;l++)
	{
		if(arr[l]<pivot)
		{
			s++;
			a=arr[s];
			arr[s]=arr[l];
			arr[l]=a;
		}
	}
	a=arr[high];
	arr[high]=arr[s+1];
	arr[s+1]=a;
	return s+1;
	
}

void sorte(int *arr, int low, int high)
{
	if(low<high)
	{
		int x=partition(arr, low, high);
		
		sorte(arr,low,x-1);
		sorte(arr,x+1,high);
	}
}

int main() {
	int n,m;
	cin>>n>>m;
	node *graph[n];
	for(int i=0;i<n;i++)
	{
		graph[i]=NULL;
	}
	
	node *ptr;
	int u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		
		ptr=new node;
		ptr->data=v;
		ptr->next=graph[u];
		graph[u]=ptr;
		
		/*ptr=new node;
		ptr->data=u;
		ptr->next=arr[v];
		arr[v]=ptr;*/
		
		
	}
	for(int i=0;i<n;i++)
	{
		ptr=graph[i];
		cout<<i<<":";
		while(ptr!=NULL)
		{
			cout<<ptr->data<<" ";
			ptr=ptr->next;
		}
		cout<<endl;
	}
	int visited[n];
	int stack[n];
	int ans[n];
	for(int i=0;i<n;i++)
	{
		ans[i]=-1;
		visited[i]=0;
		stack[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			dfs(graph, visited, i, ans,stack);	
		}
		
	}
	
	sorte(ans,0,count-1);
	 cout<<count<<endl;
	 for(int i=0;i<count;i++)
	 {
	 	cout<<ans[i]<<" ";
	 }
	// your code goes here
	return 0;
}
