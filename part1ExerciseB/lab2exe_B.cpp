/*
 *  lab2exe_B.cpp
 *  ENSF 694 Lab 2, exercise B
 *  Completed by: Jaskirat Singh
 *  Submission date: July 10
 */

#include <iostream>
#include <assert.h>
using namespace std;

int sum_of_array(const int *a, int n);
// REQUIRES
//   n > 0, and elements a[0] ... a[n-1] exist.
// PROMISES:
//  Return value is a[0] + a[1] + ... + a[n-1].

int main()
{
    int a[] = { 100 };
    int b[] = { 100, 200, 300, 400 };
    int c[] = { -100, -200, -200, -300 };
    int d[] = { 10, 20, 30, 40, 50, 60, 70 };

    
    int sum = sum_of_array(a, 1);
    cout << "sum of integers in array a is: " << sum << endl;
  
    sum = sum_of_array(b, 4);
    cout << "sum of integers in array b is: " << sum << endl;
 
    sum = sum_of_array(c, 4);
    cout << "sum of integers in array c is: " << sum << endl;
    
    sum = sum_of_array(d, 7);
    cout << "sum of integers in array d is: " << sum << endl;
    
    return 0;
}

int sum_of_array(const int *a, int n)
{
    //Base case
    if(n == 1) { return *a; }
    //Return a plus the next value of a
    return *a + sum_of_array(a + 1, n - 1);
}
