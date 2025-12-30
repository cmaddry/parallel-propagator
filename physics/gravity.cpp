#include <iostream>
#include <omp.h>
#include <math.h>
#include "gravity.h"

using namespace std;

// Function to calculate the euclidean norm of R (distance of satellite from center of earth)
double eucl_norm(double* vec){
    // Initializes the variable
    double distance =  0.0;

    // Calculates Sqrt(x^2 + y^2 + z^2)
    distance = sqrt(vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]);

    // Returns the calculated value
    return distance;
}

void two_body(double* initial_vec, double* out_vec){

    // Constants
    double u = 3.986004418e14; //m^3/s^2
    double scalar_value = 0.0;

    // Calculates the r^3
    double r_cubed = pow(eucl_norm(initial_vec), 3.0);
    cout << "Here is r^3: " << r_cubed << endl;

    // If r^3 > 0.00001, then calculate -u/r^3
    if(r_cubed < 0.000001){
        cout << "Error: divide by zero" << endl;
        exit(1);
    }
    else{
        scalar_value = -u/r_cubed;
        cout << "Here is the scalar value: " << scalar_value << endl;
    }
    
    // multiplies each value in the array by the scalar value
    #pragma omp parallel for
    for(int i = 0; i < 3; i++){
        out_vec[i] = scalar_value * initial_vec[i];
    }
}