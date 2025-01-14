#include<iostream>
#include<vector>
using namespace std;
/*
bool isPossible(vector<int> &boards,int k,int mid)
{
   int kCount = 1;
   int boardsCount = 0;
   int n = boards.size();

   for(int i = 0;i<=n;i++)
   {
     if(boardsCount + boards[i] <= mid)
     {
        cout<<"if"<<endl;
         boardsCount += boards[i];
     }
     else{
         kCount++;
         if(kCount>k || boards[i]>mid)
         {
            cout<<"else"<<endl;
             return false;
         }
         boardsCount = boards[i];
     }
  }
cout<<"true"<<endl;
return true;
}*/


int isPossibleSolution(vector<int> &boards, int k, int n, int mid){
    cout<<"enter in is"<<endl;
    int countNum = 1;

    int sum = 0;

    for(int i=0; i<n; i++){

        if(sum+boards[i]<=mid){

            sum+=boards[i];

        }else{

            countNum++;

            if(countNum>k || boards[i]>mid){
                cout<<"false "<<i<<endl;
                return false;

            }

            sum=boards[i]; 

        }

    }
    cout<<"true return"<<endl;
    return true;

}
 

/*
void solve(vector<int> &boards,int k,int s,int e,int sum,int &ans)
{
    //base case
    if(s>e)
    {
        return ;
    }

    int mid = s + (e - s)/2;

    if(isPossible(boards,k,mid))
    {
       cout<<"if"<<endl;
        ans = mid;
        solve(boards,k,s,mid-1,sum,ans);
    }
    else{
       
        solve(boards,k,mid+1,e,sum,ans);
    }

}

*/


int checkPossibleSolution(vector<int> &boards, int k, int n, int ans, int s, int e){

    // base case
    cout<<"before if"<<endl;
    if(s>e){

        return ans; 

    }
    cout<<"after if"<<endl;
    int mid = s+(e-s)/2;

 

    if(isPossibleSolution(boards, k, n, mid)){
      
        ans = mid;

        return checkPossibleSolution(boards, k, n, ans, s, mid-1);

    }else{

        return checkPossibleSolution(boards, k, n, ans, mid+1, e);

    }

}













int findLargestMinDistance(vector<int> &boards, int k)
{
  int n = boards.size();

  int sum = 0;
  for(int i = 0;i<n;i++)
  {
      sum += boards[i];
  }
  int e = sum;
  int ans = -1;
  cout<<"getting in check"<<endl;
  checkPossibleSolution(boards,k,n-1,ans,0,e);

  return ans;
}

int main()
{
    vector<int> boards = {2, 1, 5, 6, 2, 3};
    int k = 2;
    int time = findLargestMinDistance(boards,k);
    
    for(int i =0;i<boards.size();i++)
    {
        cout<<boards[i]<<" ";
    }
    

}