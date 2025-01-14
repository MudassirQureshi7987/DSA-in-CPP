#include<iostream>
using namespace std;

class Hero
{
   private:
   int health=70;

   public:
   char level='j';
   string attack= "AttackonTitans";
   
   //getter
   int getHealth()
   {
    return health;
   }
   
   //setter
   void setHealth(int h)
   {
    if(health==7)
    health = h;
   }
};

int main()
{
  Hero Muddu;
  //using setter
  Muddu.setHealth(101);
  //using getter
  cout<<"Health is "<<Muddu.getHealth()<<endl;
  cout<<"Level is "<<Muddu.level<<endl;
  cout<<"Attack is "<<Muddu.attack<<endl;
}