#include<bits/stdc++.h>
using namespace std;

int main() {
    // Deleting a dynamically allocated array
    int* arr = new int[5]; // Dynamically allocate an array of 5 integers
    delete[] arr; // Use delete[] to free the memory allocated for the array

    // Deleting a single dynamically allocated object
    int* num = new int(10); // Dynamically allocate a single integer
    delete num; // Use delete to free the memory allocated for the single integer

    return 0;
}