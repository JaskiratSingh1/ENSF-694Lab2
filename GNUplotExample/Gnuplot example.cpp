#include <stdlib.h>
#include <stdio.h>
#define NUM_POINTS 6

void myPlot(double* x, double *y1, double *y2, int size){
    FILE * gnuplotPipe = popen ("/opt/homebrew/bin/gnuplot -persistent", "w");
    
    const char* name="Using";
   
    fprintf(gnuplotPipe, "set title '%s'\n", name);
    fprintf(gnuplotPipe, "set tics nomirror\n");
    fprintf(gnuplotPipe, "set y2tics\n");
    fprintf(gnuplotPipe, "set key top center horizontal\n");
    fprintf(gnuplotPipe, "plot '-' pt 7 ps 1 lc 'blue' title 'Y1', '-' pt 7 ps 1 lc 'red' title 'Y2'");
    for (int i=0; i < size; i++)
        fprintf(gnuplotPipe, "%f %f\n", x[i], y1[i]);
   
    fprintf(gnuplotPipe, "e\n");

    for (int i=0; i < size; i++)
        fprintf(gnuplotPipe, "%f %f\n", x[i], y2[i]);
}

int main(){
    double x[NUM_POINTS] = {0, 1.0, 2.0, 3.0, 4.0, 5.0};
    double y1[NUM_POINTS] = {0, 5.0 ,16.0, 7.0, 30.0, 50.0};
    double y2[NUM_POINTS] = {0, 100, 200, 300, 400, 500};
    myPlot(x, y1, y2, NUM_POINTS);
    return 0;
}

