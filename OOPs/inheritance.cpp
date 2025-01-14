//c:\Users\asd\AppData\Local\Temp\note_797_cebd57bd5e43_2.png

/*
    Base class member access specifier  | Public  | Protected  | Private  |


    Public                              | Public  | Protected  | Private  |

    Protected                           | Protected| Protected | Private  |

    Private                             | NA       |  NA       |  NA      |
*/

#include<iostream>
using namespace std;

class Human
{
  public:
    int height;

    
};

class Male:public Human{
  public:
  string name;

  int getHeight()
    {
        return height;
    }

};

int main()
{
 Male me;
 cout<<me.height<<endl;
}