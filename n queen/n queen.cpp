#include <iostream>
using namespace std;
int n;
bool is_safe(int[n][n] chess, int x, int y)
{
    for(int i=0;i<y;i++)
    {
        // check the row
        if(chess[x][i]==1)
        return false;

        // check upper diagonal
        int i,j;
        j=y;
        for(i=x;i>=0 && j>=0 && i<n && j<n;)
        {
            if(chess[i][j]==1)
            return false;
            i--;
            j--;
        }
        i=x;
        j=y;
        for(;i>=0 && j>=0 && i<n && j<n;)
        {
            if(chess[i][j]==1)
            return false;
            i++;
            j--;
        }

    }
}
bool util(int[n][n] chess, int col)
{
    if(col>=n)
    return true;
    for(int i=0;i<n;i++)
    {
        if(is_safe(chess,i,col))
        {
            chess[i][col]=1;
            if(util(chess,col+1))
            return true;
            else
            chess[i][col]=0;
        }
    }
    return false;
}
void print_sol(int chess[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<chess[i]<<"  ";
        cout<<endl;
    }
}
void nq(int n)
{
    int chess[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        chess[i][j]=0;
    }
    if(util(chess,0)==true)
        print_sol(chess);
    else
    cout<<"No solution exist";
}

int main() {
    //int n;
    n=4;
    nq();
    // your code goes here
	return 0;
}