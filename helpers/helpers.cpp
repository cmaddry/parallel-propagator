#include <iostream>
#include <math.h>

#include "helpers.h"

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