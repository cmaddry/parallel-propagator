#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>

#include "physics/gravity.h"
#include "integrator/integrator.h"

using namespace std;


int main(){
    ofstream saveFile("output/output.txt");
    ifstream esiFile("imported_tles/605_esi.txt");

    vector<string> result = {};
    string esi_data;

    while(getline(esiFile, esi_data, ',')){
        result.push_back(esi_data);
    }

    cout << "first one" << stod(result[0])*1000 << endl;






    State state;
    // // Initial conditions for r and v
    // state.r[0] = 7e6; //in meters
    // state.r[1] = 0;
    // state.r[2] = 0.0;
    // state.v[0] = 0.0;
    // state.v[1] = 7546.05; // in m/s
    // state.v[2] = 0.0;


    state.r[0] = stod(result[0])*1000; //in meters
    state.r[1] = stod(result[1])*1000;
    state.r[2] = stod(result[2])*1000;
    state.v[0] = stod(result[3])*1000;
    state.v[1] = stod(result[4])*1000; // in m/s
    state.v[2] = stod(result[5])*1000;

    // Number of iterations and step size
    int total_its = 40000;
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