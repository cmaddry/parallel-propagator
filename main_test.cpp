#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>

#include "integrator/integrator.h"

using namespace std;


int main(){
    ofstream saveFile("output/output.txt");

    // Reads the imported TLE file and stores the values in the starting vector
    ifstream esiFile("imported_tles/605_esi.txt");
    vector<string> initial_vec = {};
    string esi_data;

    while(getline(esiFile, esi_data, ',')){
        initial_vec.push_back(esi_data);
    }

    cout << "first one" << stod(initial_vec[0])*1000 << endl;






    State state;
    // Initial conditions for r and v
    // state.r[0] = 7e6; //in meters
    // state.r[1] = 0;
    // state.r[2] = 0.0;
    // state.v[0] = 0.0;
    // state.v[1] = 7546.05; // in m/s
    // state.v[2] = 0.0;

    // // Initial conditions for r and v
    // state.r[0] = 7e6; //in meters
    // state.r[1] = 0;
    // state.r[2] = 0.0;
    // state.v[0] = 0.0;
    // state.v[1] = 6500.0; // in m/s
    // state.v[2] = 3300.0;

    state.r[0] = stod(initial_vec[0])*1000; //in meters
    state.r[1] = stod(initial_vec[1])*1000;
    state.r[2] = stod(initial_vec[2])*1000;
    state.v[0] = stod(initial_vec[3])*1000;
    state.v[1] = stod(initial_vec[4])*1000; // in m/s
    state.v[2] = stod(initial_vec[5])*1000;

    // Number of iterations and step size
    int total_its = 345600;
    int step_size = 1; // in seconds

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