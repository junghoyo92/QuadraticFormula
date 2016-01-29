#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 
 * Name : <Hoyoung Jung>
 * Program to compute the zeros of a
 * quadratic equation
 */
 void InputQuadraticEquation(double *a, double *b, double *c);
 void QuadraticEquation(double a, double b, double c, 
                       double *pZ1r, double *pZ1i, double *pZ2r, double *pZ2i);

int main()
{
    /* Values for the quadratic formula */
    double a, b, c;
    double z1r, z1i;    /* First zero */
    double z2r, z2i;    /* Second zero */
    double discriminant;
    
    InputQuadraticEquation(&a, &b, &c);
    QuadraticEquation(a, b, c,
    					&z1r, &z1i, &z2r, &z2i);
    
}

/* 
 * Input a quadratic equation as a, b, and c
 */
void InputQuadraticEquation(double *a, double *b, double *c)
{
    printf("Input a: ");
    scanf("%lf", a);
    printf("Input b: ");
    scanf("%lf", b);
    printf("Input c: ");
    scanf("%lf", c);
}

void QuadraticEquation(double a, double b, double c, 
                       double *pz1r, double *pz1i, double *pz2r, double *pz2i)
{
    /*
     * This code computes the quadratic equation
     * for both real and complex zeros 
     */
     
    /* Compute the discriminant */
    double discriminant;
    discriminant = b * b - 4 * a * c;
    if(discriminant >= 0)
    {
        /* If the discriminant is greater than or
           equal to zero, the zeros are real */
        *pz1r = (-b + sqrt(discriminant)) / (2 * a);
        *pz2r = (-b - sqrt(discriminant)) / (2 * a);
        *pz1i = 0;
        *pz2i = 0;
    }
    else
    {
        /* If the discriminant is less than zero
           the zeros are complex  */
        *pz1r = -b / (2 * a);
        *pz2r = *pz1r;
        *pz1i = sqrt(-discriminant) / (2 * a);
        *pz2i = -sqrt(-discriminant) / (2 * a);
    }
	
	/* Display the results */
    printf("Zero 1: %f + %fj\n", *pz1r, *pz1i);
    printf("Zero 2: %f + %fj\n", *pz2r, *pz2i);

}
