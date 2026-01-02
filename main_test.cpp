#include <iostream>
#include "physics/gravity.h"
#include "integrator/integrator.h"
#include <math.h>

using namespace std;

int main(){

    State state;
    // Initial conditions for r and v
    state.r[0] = 7000e3; //in meters
    state.r[1] = 0;
    state.r[2] = 0.0;
    state.v[0] = 0.0;
    state.v[1] = 7546.05; // in m/s
    state.v[2] = 0.0;

    // Number of iterations and step size
    int total_its = 6000;
    int step_size = 10; // in seconds

    // Start stepping with the numerical integrator
    for(int i = 0; i < total_its; i++){
        cout << "Iteration #: " << i + 1 << endl;
        integrator_func(state, step_size);

        double distance = sqrt(state.r[0]*state.r[0] + state.r[1]*state.r[1] + state.r[2]*state.r[2]);

        cout << "Distance from the center of the Earth: " << distance << endl;
        cout << "For x = " << state.r[0] << endl;

    }
  

    return 0;
}