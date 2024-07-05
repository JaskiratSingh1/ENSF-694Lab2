/*
 *  lab2exe_C.cpp
 *  ENSF 694 Lab 2, exercise C
 *  Completed by: Jaskirat Singh
 *  Submission date: July 10
 */

#include <iostream>
using namespace std;
#include <assert.h>

int strictly_increasing(const int *a, int n);

int main()
{
  int a[] = { 100 };
  int b[] = { 100, 200, 300, 400 };
  int c[] = { 400, 100, 200, 300 };
  int d[] = { 100, 400, 200, 300 };
  int e[] = { 100, 200, 200, 300 };
  int f[] = { 100, 200, 500, 300, 400 };
  int g[] = { 100, 200, 300, 500, 400 };

  assert( strictly_increasing(a, sizeof(a) / sizeof(int)) );
  assert( strictly_increasing(b, sizeof(b) / sizeof(int)) );
  assert( !strictly_increasing(c, sizeof(c) / sizeof(int)) );
  assert( !strictly_increasing(d, sizeof(d) / sizeof(int)) );
  assert( !strictly_increasing(e, sizeof(e) / sizeof(int)) );
  assert( !strictly_increasing(f, sizeof(f) / sizeof(int)) );
  assert( !strictly_increasing(g, sizeof(g) / sizeof(int)) );

  cout << "All tests passed.\n";
  cout << "This suggests that strictly_increasing is correct,\n";
  cout << "but it does not PROVE that it is correct.\n";

  return 0;
}

int strictly_increasing(const int *a, int n) {
    //Base case end of array reached
    if(n == 1) { return 1; }
    //If element at index-1 is larger than element at index then return 0
    if(a[n-2] >= a[n-1]) { return 0; }
    
    return strictly_increasing(a, n - 1);
}

/* Original code
int strictly_increasing(const int *a, int n)
{
  // STUDENTS: Replace all of the code below with a RECURSIVE solution.
    int i;
    
    assert(n > 0);
    
    for (i = 1; i < n; i++)
        if (a[i - 1] >= a[i])
            return 0;
    
    return 1;
}
*/
