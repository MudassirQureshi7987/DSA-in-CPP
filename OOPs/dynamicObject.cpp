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
    
    health = h;
   }

   void setLevel(char ch)
   {
    level = ch;
   }
};

int main()
{
  //static allocation
  Hero a;
  cout<<"Health is "<<a.getHealth()<<endl;
  a.setLevel('N');
  cout<<"Level is "<<a.level<<endl;

  //dynamic allocation
  Hero *b = new Hero;
  b->setHealth(120);
  cout<<"Health is "<<(*b).getHealth()<<endl;
  cout<<"Health is "<<b->getHealth()<<endl;

}