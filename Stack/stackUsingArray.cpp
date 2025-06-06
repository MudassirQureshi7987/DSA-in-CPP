#include<iostream>
using namespace std;

class Stack
{
  //properties
  public:
          int *arr;
          int top;
          int size;

          //functions / behaviour
          Stack(int size)
          {
            this->size =  size;
            arr = new int[size];
            top = -1;
          }

          void push(int element)
          {
            if(size - top > 1)
            { 
                top++;
                arr[top] = element;
            }
            else{
                cout<<"Stack Overflow"<<endl;
            }
          }

          void pop()
          {
            if( top >= 0)
            {
                top--;
            }
            else
            {
                cout<<"Stack Underflow"<<endl;
            }
          }

          int peek()
          {
            if(top >= 0)
            {
                return arr[top];
            }
            else
            {
                cout<<"Stack is Empty"<<endl;
                return -1;
            }
          }

          bool isEmpty()
          {
              if(top == -1)
              {
                return true;
              }
              else{
                return false;
              }
          }
};

int main()
{
   Stack st(5);

   st.push(23);
   st.push(43);
   st.push(32);
   st.push(13);
   st.push(23);
   st.push(43);
   st.push(32);
   st.push(13);

   cout<< st.peek()<<endl;

   st.pop();

   cout<< st.peek()<<endl;

   st.pop();
   st.pop();
   st.pop();

   cout<< st.peek()<<endl;

   if(st.isEmpty())
   {
     cout<<"Stack is Empty"<<endl;
   }
   else{
     cout<<"Stack is not Empty"<<endl;
   }
}