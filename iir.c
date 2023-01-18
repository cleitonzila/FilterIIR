#include <math.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include "inout16.c"
#define HEADER_SIZE 24

struct Filter {
    double b0;
    double r[4];
    double s[4];
    double p[4];
    double q[4];
};

double process_sample(struct Filter* filter, double x, double* z1, double* z2, double* z3, double* z4) {
    double y;
    z1[4] = z1[3];
    z1[3] = z1[2];
    z1[2] = z1[1];
    z1[1] = z1[0];
    z2[4] = z2[3];
    z2[3] = z2[2];
    z2[2] = z2[1];
    z2[1] = z2[0];
    z3[4] = z3[3];
    z3[3] = z3[2];
    z3[2] = z3[1];
    z3[1] = z3[0];
    z4[4] = z4[3];
    z4[3] = z4[2];
    z4[2] = z4[1];
    z4[1] = z4[0];

    z1[0] = filter->b0 * x + filter->p[0] * z1[1] + filter->q[0] * z1[2];
    y = z1[0] + filter->r[0] * z1[1] + filter->s[0] * z1[2];
    y += filter->p[1] * z2[1] + filter->q[1] * z2[2];
    z2[0] = y;
    y += filter->r[1] * z2[1] + filter->s[1] * z2[2];
    y += filter->p[2] * z3[1] + filter->q[2] * z3[2];
    z3[0] = y;
    y += filter->r[2] * z3[1] + filter->s[2] * z3[2];
    y += filter->p[3] * z4[1] + filter->q[3] * z4[2];
    z4[0] = y;
    y += filter->r[3] * z4[1] + filter->s[3] * z4[2];

    return y;

}
int main() {
    int i;
    double x, y;
    struct Filter filter = {b0, {r1, r2, r3, r4}, {s1, s2, s3, s4}, {p1, p2, p3, p4}, {q1, q2, q3, q4}};
    double z1[5] = {0, 0, 0, 0, 0};
    double z2[5] = {0, 0, 0, 0, 0};
    double z3[5] = {0, 0, 0, 0, 0};
    double z4[5] = {0, 0, 0, 0, 0};
    double sum[3] = {0, 0, 0};

    for(i=0; i<HEADER_SIZE; i++){
        putchar(getchar());
    }

    while (get16d(stdin, &x) != EOF){
        y = process_sample(&filter, x, z1, z2, z3, z4);
        put16d(stdout, y); 
    }
    return 0;
}
