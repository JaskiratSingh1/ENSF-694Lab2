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
    FILE * gnuplotPipe = popen ("/opt/homebrew/bin/gnuplot -persistent", "w");
    
    //Name for the plot
    const char* name="Fibonacci Iterative v.s. Recursive Approaches";
   
    //Setting title, axis names, grid and legend style
    fprintf(gnuplotPipe, "set title '%s'\n", name);
    fprintf(gnuplotPipe, "set xlabel 'N'\n");
    fprintf(gnuplotPipe, "set ylabel 'Time (seconds)'\n");
    fprintf(gnuplotPipe, "set grid\n");
    fprintf(gnuplotPipe, "set key inside left\n");
    fprintf(gnuplotPipe, "set style line 1 lt 1 lw 2 pt 7 ps 1.5 lc rgb 'blue'\n");
    fprintf(gnuplotPipe, "set style line 2 lt 1 lw 2 pt 7 ps 1.5 lc rgb 'red'\n");
    
    //Plotting the data
    fprintf(gnuplotPipe, "plot '-' pt 7 ps 1 lc 'blue' title 'Iterative', '-' pt 7 ps 1 lc 'red' title 'Recursive'");
    
    for (int i=0; i < size; i++)
        fprintf(gnuplotPipe, "%d %f\n", x[i], y1[i]);
   
    fprintf(gnuplotPipe, "e\n");

    for (int i=0; i < size; i++)
        fprintf(gnuplotPipe, "%d %f\n", x[i], y2[i]);
    
    fprintf(gnuplotPipe, "e\n");
    
    pclose(gnuplotPipe);
}


// Function to multiply two matrices of size N x N
void multiplyMatrix(int a[N][N], int b[N][N], int result[N][N]) {
    // Three loops for dot products
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            result[i][j] = 0;
            for(int k = 0; k < N; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Recursive function
void powerMatrix(int base[N][N], int exp, int result[N][N]) {
    // Base case exp = 1
    if(exp == 1){
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result[i][j] = base[i][j];
            }
        }
        return;
    }
    
    int bufferMatrix[N][N]; // Temporary matrix for intermediate calculations
    
    // If exponent is even
    if(exp % 2 == 0){
        powerMatrix(base, exp / 2, bufferMatrix);
        multiplyMatrix(bufferMatrix, bufferMatrix, result);
    }
    // If exponent is odd
    else{
        powerMatrix(base, exp / 2, bufferMatrix);
        multiplyMatrix(bufferMatrix, bufferMatrix, result);
        multiplyMatrix(result, base, result);
    }
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
    // This function must be completed by the students and if necessary its return value to be corrected.
    //Base case for n = 0
    if (n <= 0) {
        return 0;
    }
    //Base case for n = 1
    if (n == 1) {
        return 1;
    }

    int last = 0, current = 1;
    for (int i = 2; i <= n; i++){
        int next = last + current;
        last = current;
        current = next;
    }

    return current;
}

// Function to measure the time taken by a function to calculate the nth Fibonacci number
// This function is using a pointer to a funciton called fibonacciFunc
double measureTime(int (*fibonacciFunc)(int), int n) {
    // This funcitn must be completed by the students and if necessary its return value to be corrected.
    clock_t start, end;
    
    start = clock();
    fibonacciFunc(n);
    end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
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
