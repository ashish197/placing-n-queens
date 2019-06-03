#include<bits/stdc++.h>
using namespace std;

char board[11][11];
bool issafe(int n,int row,int column){
    
    //same column  
   for(int i=row-1;i>=0;i--)
   {
   	if(board[i][column]=='Q'){
   		 return false;
   	}
   }
   //upper left diagonal
   for(int i=row-1,j=column-1;i>=0 && j>=0;i--,j--){
   	if(board[i][j]=='Q'){
   	 return false;	
   	}
   }

   // upper right diagonal

   for(int i=row-1,j=column+1;i>=0 && j<n;i--,j++){
   	if(board[i][j]=='Q'){
   		return false;
   	}
   }

   return true;
    
}


void nqueenhelper(vector<vector<string> >&s,int n,int row)
{
	
	if(row==n){
		// placed right
		vector<string>v;
		for(int i=0;i<n;i++)
		{
			
			string st="";
			for(int j=0;j<n;j++)
			{
				st+=board[i][j];
			}
			v.push_back(st);
		}
        s.push_back(v);
        v.clear();
	}

	//place to all possible positions
	for(int j=0;j<n;j++)
	{
		if(issafe(n,row,j))
		{
			board[row][j]='Q';
			nqueenhelper(s,n,row+1);
			board[row][j]='.';
		}
	}
	return;
}
void placeNqueens(int n){

 for(int i=0;i<11;i++){
 	for(int j=0;j<11;j++){
 		board[i][j]='.';
 	}
 }

      vector<vector<string> > s;
      nqueenhelper(s,n,0);
       for(int i=0;i<s.size();i++)
		{
			for(int j=0;j<s[i].size();j++)
			{
				for(int k=0;k<s[i][j].size();k++)
				    cout<<s[i][j][k];
				cout<<endl;
			}
			cout<<"\n\n";

		}

}

void insert(vector<int> &a)
{
	a.push_back(4);
	a.push_back(4);
	a.push_back(4);a.push_back(4);


}
int main(){

  placeNqueens(3);
/*	vector<int> v;
	insert(v);
	for(int i=0;i<v.size();i++)
		cout<<v[i];
	cout<<"\n";*/


}