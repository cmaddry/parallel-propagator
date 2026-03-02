#include <iostream>
#include <math.h>
#include "gravity.h"

#include "../helpers/helpers.h"

using namespace std;

void two_body(double* initial_vec, double* out_vec){

    // Constants
    double u = 3.986004418e14; //m^3/s^2
    double scalar_value = 0.0;

    // Calculates the r^3
    double r_cubed = pow(eucl_norm(initial_vec), 3.0);

    // If r^3 > 0.00001, then calculate -u/r^3
    if(r_cubed < 0.000001){
        cout << "Error: divide by zero" << endl;
        exit(1);
    }
    else{
        scalar_value = -u/r_cubed;
    }
    
    // multiplies each value in the array by the scalar value
    for(int i = 0; i < 3; i++){
        out_vec[i] = scalar_value * initial_vec[i];
    }
}