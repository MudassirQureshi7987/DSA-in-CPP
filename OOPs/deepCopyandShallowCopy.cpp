#include<iostream>
#include<string.h>
using namespace std;

class Hero {
    
    //properties
    private:
    int health;

    public:
    char *name;
    char level;
    static int timeToComplete;

    Hero() {
        cout << "Simple constructor called" << endl;
        name = new char[100];
    }

    //Paramerterised Constructor
    Hero(int health) {
        this -> health = health;
    }

    Hero(int health, char level) {
        this -> level = level;
        this -> health = health;
    }

    //copy constructor
    Hero(Hero& temp) {

        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;

        cout << "Copy constructor called" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    void print(){
        cout << endl;
        cout << "[ Name: " << this->name<< " ,";
        cout << "health: " << this->health << " ,";
        cout <<"level: " << this->level << " ]";
        cout << endl << endl;
    }

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }

    void setName(char name[]) {
        strcpy(this->name, name);
    }

    static int random() {
        return timeToComplete ;
    }

    //Destructor
    ~Hero() {   
        cout << "Destructor bhai called" << endl;
    }

};

int main()
{
   //Shallow copy is the simple one in which a new memory is not located but the same address is shared

   //In deep copy,a new array is made and then a whole new copy is created

   //In shallow copy,changes are applied to both the objects as they share the same memory address
   //In deep copy,only the one which we made changes is changed

  Hero hero1;

   hero1.setHealth(12);    
   hero1.setLevel('D');
   char name[7] = "Babbar";
   hero1.setName(name);

   hero1.print();
   
   //default copy constructor called
   Hero hero2(hero1);

   hero2.print();

   hero1.name[0]='G';
   hero1.print();



}