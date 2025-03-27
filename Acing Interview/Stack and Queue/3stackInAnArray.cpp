//C++ program for creating k stacks in a single array

#include<bits/stdc++.h>
using namespace std;
class kStacks
{
	int *arr; 
	int *top; of size k to store indexes of top items of stacks
	int *next; 
	int n, k;
	int free; 
	public:

	//constructor for creating k stacks in a single array

	kStacks(int k,int n);

	bool isFull() 
	{ return (free == -1); }

	// To push an element in stack number 'sn' where sn is from 0 to k-1

	void push(int item,int sn);

	// To pop an element from stack number 'sn'

	int pop(int sn);

	// To check if stack number 'sn' is empty

	bool isEmpty(int sn) 
	{ return (top[sn] == -1); }

};


//constructor for creating k stacks in a single array of dimension n
kStacks::kStacks(int k1, int n1)
{
	// Initialize n and k
	
	k = k1, n = n1;
	arr = new int[n];
	top = new int[k];
	next = new int[n];

	// Initialize all stacks to empty
	
	for (int i = 0; i < k; i++)
	top[i] = -1;

	// Initialize all spaces to free
	
	free = 0;
	for (int i=0; i<n-1; i++)
	next[i] = i+1;
	next[n-1] = -1; // -1 is used to tell end of free list
}


// Pushing an item in stack number 'sn' where sn is from 0 to k-1
void kStacks::push(int item, int sn)
{
	if (isFull())
	{
		cout << "\nStack Overflow\n";
		return;
	}
	int i = free;
	free = next[i];
	next[i] = top[sn];
	top[sn] = i;
	
	// Put the item in array
	
	arr[i] = item;
}

// To pop an element from stack number 'sn' where sn is from 0 to k-1

int kStacks::pop(int sn)
{
	// Underflow check for mergin k stacks in a single array
	if (isEmpty(sn))
	{
	cout << "\nStack Underflow\n";
	return INT_MAX;
	}

	// Find index of top element in stack number 'sn'

	int i = top[sn];
	top[sn] = next[i]; 
	next[i] = free;
	free = i;

	// Returning the previous top element

	return arr[i];
}

//Main function for creating k stacks in a single array

int main()
{
	// Let us create three stacks in an array of size 10
	
	int k = 3, n = 10;
	kStacks ks(k, n);

	// Putting some items in stack 2

	ks.push(17, 2);
	ks.push(14, 2);

	// Putting some items in stack 1

	ks.push(0, 1);
	ks.push(100, 1);
	ks.push(48, 1);

	// Putting some items in stack 0

	ks.push(13, 0);
	ks.push(7, 0);
	ks.push(5, 0);

	cout << "Popped item from stack 0 is " << ks.pop(0) << endl;
	cout << "Popped item from stack 1 is " << ks.pop(1) << endl;
	cout << "Popped item from stack 2 is " << ks.pop(2) << endl;

	return 0;
}