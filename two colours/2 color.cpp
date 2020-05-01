#include <iostream>
#include <string.h>
using namespace std;
struct node
{
	int data;
	node* next=NULL;
};

bool dfs(node **arr, int *visited, int *colour, int current, int n, int c )
{
	
	visited[current]=1;
	colour[current]=c;
	node *ptr=arr[current];
	
	if(ptr==NULL)
	return true;
	
	//ptr=ptr->next;
	while(ptr!=NULL)
	{
		if(colour[ptr->data]==c)
		return false;
		ptr=ptr->next;
	}
	ptr=arr[current];
	//ptr=ptr->next;
	while(ptr!=NULL)
	{
		if(visited[ptr->data]==0)
		{
			if(!dfs(arr, visited, colour, ptr->data, n, 1-c))
			{
				return false;
			}
		}
		ptr=ptr->next;
	}
	return true;
	
}

void print_sol(int *colour , int n)
{
	for(int i=0;i<n;i++)
	cout<<colour[i]<<" ";
}
int main() {
	int n,m;
	cin>>n>>m;
	node *arr[n];
	int visited[n];
	int colour[n];
	
	memset(colour, -1, sizeof colour);
	memset(visited,0,sizeof visited);
	memset(arr, NULL,sizeof arr);
	/*for(int i=0;i<n;i++)
	{
		arr[i]=NULL;
	}*/
	int u,v;
	node *ptr;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		
		ptr=new node;
		ptr->data=v;
		ptr->next=arr[u];
		arr[u]=ptr;
		
		ptr=new node;
		ptr->data=u;
		ptr->next=arr[v];
		arr[v]=ptr;
		
	}
	for(int i=0;i<n;i++)
	{
		ptr=arr[i];
		cout<<i<<" : visited"<<visited[i]<<":  ";
		while(ptr!=NULL)
		{
			cout<<ptr->data<<" ";
			ptr=ptr->next;
		}
		cout<<endl;
	}
	bool l=true;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			l=l && dfs(arr, visited, colour, i, n, 0);
		}
			
	}
	if(l)
	print_sol(colour,n);
	else
	cout<<"no solution";
	
	// your code goes here
	return 0;
}
