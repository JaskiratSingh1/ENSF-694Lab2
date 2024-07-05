/*
 *  lab2exe_D.cpp
 *  ENSF 694 Lab 2, exercise D
 *  Completed by: Jaskirat Singh
 *  Submission date: July 10
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;
#define N 2


void myPlot(int* x, double *y1, double *y2, int size){
    // This funcitn must be completed by the students
}


// Function to multiply two matrices of size N x N
void multiplyMatrix(int a[N][N], int b[N][N], int result[N][N]) {
    // This funcitn must be completed by the studnets
}

// Recursive function
void powerMatrix(int base[N][N], int exp, int result[N][N]) {
    // This funcitn must be completed by the students
}

// Function to calculate the nth Fibonacci number using recursive matrix exponentiation
int fibonacciRecursive(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    int base[N][N] = {{1, 1}, {1, 0}};
    int result[N][N];
    powerMatrix(base, n - 1, result);
    return result[0][0];
}

// Function to calculate the nth Fibonacci number iteratively
int fibonacciIterative(int n) {
    // This funcitn must be completed by the students and if necessary its return value to be corrected.
    return 0;
}

// Function to measure the time taken by a function to calculate the nth Fibonacci number
// This function is using a pointer to a funciton called fibonacciFunc
double measureTime(int (*fibonacciFunc)(int), int n) {
    // This funcitn must be completed by the students and if necessary its return value to be corrected.
    return 0;
}

int main(void) {
    const int maxN = 400000000; // Adjust maxN based on the range you want to test
    double recursive_result[50];
    double iterative_result[50];
    int N_value[50];

    cout << "Recursive Matrix Exponentiation Method\n";
    cout << setw(12) << "N" << setw(12) << "Time\n";
    for (int n = 20000000, i=0; n <= maxN; n+=20000000, i++) {
        double time = measureTime(fibonacciRecursive, n);
        recursive_result[i] = time;
        cout << setw(12) << n << setw(12) << recursive_result[i] << endl;
    }

    cout << "\nIterative Method\n";
    cout << setw(12) << "N" << setw(12) << "Time\n";
    for (int n = 20000000, i=0; n <= maxN; n+=20000000, i++) {
        double time = measureTime(fibonacciIterative, n);
        iterative_result[i] = time;
        cout << setw(12) << n << setw(12) << iterative_result[i] << endl;
        N_value[i] = n;
    }
    
    myPlot(N_value, iterative_result,  recursive_result, 30 );

    return 0;
}


