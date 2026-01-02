#ifndef INTEGRATOR_H
#define INTEGRATOR_H

struct State
{
    double r[3];
    double v[3];
};

void integrator_func(State& state, double step_size);


#endif 