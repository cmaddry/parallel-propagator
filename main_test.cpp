#include <iostream>
#include <fstream>
#include <math.h>

#include "physics/gravity.h"
#include "integrator/integrator.h"

using namespace std;


int main(){
    ofstream saveFile("output/output.txt");
    State state;
    // Initial conditions for r and v
    state.r[0] = 7e6; //in meters
    state.r[1] = 0;
    state.r[2] = 0.0;
    state.v[0] = 0.0;
    state.v[1] = 7546.05; // in m/s
    state.v[2] = 0.0;

    // Number of iterations and step size
    int total_its = 4000;
    int step_size = 1.0; // in seconds

    // Start stepping with the numerical integrator
    for(int i = 0; i < total_its; i++){
        cout << "Iteration #: " << i + 1 << endl;
        integrator_func(state, step_size);

        double distance = sqrt(state.r[0]*state.r[0] + state.r[1]*state.r[1] + state.r[2]*state.r[2]);

        cout << "Distance from the center of the Earth: " << distance << endl;
        cout << "\tFor x = " << state.r[0] << endl;
        cout << "\tFor y = " << state.r[1] << endl;

        if(saveFile.is_open()){
            saveFile << state.r[0] << "," << state.r[1] << "," << state.r[2] << "\n";
        }
        else{
            cout << "Can't open file" << endl;
        }

    }
  

    return 0;
}