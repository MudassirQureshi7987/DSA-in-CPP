#include<iostream>
using namespace std;

void walking(int src,int dest)
{
    cout<<src<<" "<<dest<<endl;
    //base case
    if(src==dest)
    {
        cout<<"Pahuch gaya re bhai!!!";
        return ;
    }

    return walking(++src,dest);
}

int main()
{
  int src ;
  int dest;
  cin>>src>>dest;

  walking(src,dest);

}