#include <iostream>
#include <omp.h>
#include <math.h>
#include "../physics/gravity.h"
#include "../physics/perturbations.h"

using namespace std;

struct State
{
    double r[3];
    double v[3];
};

void integrator_func(State& state, double step_size){

    //Declaration of structs
    State k1, k2, k3, k4;

    // Step size which will actually need to be calculated at some point
    double dt = step_size;

    // Calculates v_dot and stores this in the variable v_dot
    double v_dot[3] = {};
    // two_body(state.r, v_dot);
    total_acceleration(state.r, v_dot);

    // This loop assigns the values for k1
    for(int i = 0; i < 3; i++){
        k1.r[i] = state.v[i];
        k1.v[i] = v_dot[i];
    }

    // Next iteration (k2)
    // Calculates v_dot and stores this in the variable v_dot
    double temp_r[3] = {};
    double temp_v[3] = {};

    for(int i = 0; i < 3; i++){
        temp_r[i] = state.r[i] + (dt*0.5)*k1.r[i];
        temp_v[i] = state.v[i] + (dt*0.5)*k1.v[i];
        k2.r[i] = temp_v[i];
    }

    // two_body(temp_r, k2.v);
    total_acceleration(temp_r, k2.v);

    // Next iteration (k3)
    // Calculates v_dot and stores this in the variable v_dot

    for(int i = 0; i < 3; i++){
        temp_r[i] = state.r[i] + (dt*0.5)*k2.r[i];
        temp_v[i] = state.v[i] + (dt*0.5)*k2.v[i];
        k3.r[i] = temp_v[i];
    }
    // two_body(temp_r, k3.v);
    total_acceleration(temp_r, k3.v);

    // Next iteration (k4)
    // Calculates v_dot and stores this in the variable v_dot

    for(int i = 0; i < 3; i++){
        temp_r[i] = state.r[i] + (dt)*k3.r[i];
        temp_v[i] = state.v[i] + (dt)*k3.v[i];
        k4.r[i] = temp_v[i];
    }
    // two_body(temp_r, k4.v);
    total_acceleration(temp_r, k4.v);

    for(int i = 0; i < 3; i++){
        state.r[i] = state.r[i] + (dt/6)*(k1.r[i] + 2*k2.r[i] + 2*k3.r[i] + k4.r[i]);
        state.v[i] = state.v[i] + (dt/6)*(k1.v[i] + 2*k2.v[i] + 2*k3.v[i] + k4.v[i]);
    }
}