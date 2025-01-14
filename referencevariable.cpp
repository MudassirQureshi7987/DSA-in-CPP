#include<iostream>
using namespace std;

void update(int& s)
{
    s = s + 1;
}

int main()
{
    int ans = 5;
    cout<<"Before "<<ans<<endl;
    update(ans);
    cout<<"After "<<ans<<endl;

}