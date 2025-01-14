#include<iostream>
using namespace std;

class Hero
{
   private:
   int health=70;

   public:
   char level='j';
   string attack= "AttackonTitans";     //Default constructor 
                                        //ramesh.Hero( )
                                        // its called automatically if we do not call ourselves
   
    //constructor
    Hero()
    {
        cout<<"Constructor called"<<endl;
    }
    
    //parameterised constructor
    Hero(int health,char level)
    {
        this->health = health;
        this->level = level;
    }




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

   void print()
   {
    cout<<"print is "<<level<<endl;
    cout<<"Print health is "<<health<<endl;
   }

   //copy constructor khudka
   Hero(Hero& temp)
   {
    cout<<"Copy constructor called"<<endl;
    this->health=health;
    this->level=level;
   }
};

int main()
{
    Hero ramesh;

    Hero *a = new Hero;
    a->print();

    Hero h(65,'N');
    //  cout<<"Health para is "<<h.getHealth()<<endl;
  //  cout<<"Level para is "<<h.level<<endl;
    h.print();

    Hero *h1=new Hero(23,'M');
    //cout<<"Health para is "<<h1->getHealth()<<endl;
   // cout<<"Level para is "<<h1->level<<endl;
   h1->print();
   

   //copy constructor
   Hero S(h);
   S.print();

   Hero R(*h1);
   R.print();

    
}

//constructor has no return type and no input parameter

//this keyword stores the current address of the object
