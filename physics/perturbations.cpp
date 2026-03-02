#include <iostream>
#include <math.h>

#include "perturbations.h"
#include "../helpers/helpers.h"
#include "gravity.h"

using namespace std;


void j2_perturbation(double* r0_vec, double* out_vec)
{
    const double mu = 3.986004418e14;
    const double Re = 6378137.0;
    const double J2 = 1.08262668e-3;

    double x = r0_vec[0];
    double y = r0_vec[1];
    double z = r0_vec[2];

    double r2 = x*x + y*y + z*z;
    double r = sqrt(r2);
    double r5 = r2*r2*r;

    double z2_over_r2 = (z*z)/r2;

    double k = 1.5 * J2 * mu * Re * Re / r5;

    out_vec[0] = k * x * (5*z2_over_r2 - 1);
    out_vec[1] = k * y * (5*z2_over_r2 - 1);
    out_vec[2] = k * z * (5*z2_over_r2 - 3);
}


void total_acceleration(double* r0_vec, double* out_vec){ 

    double tmp_vec[3] = {};

    two_body(r0_vec, out_vec);
    j2_perturbation(r0_vec, tmp_vec);

    double magJ2 = sqrt(tmp_vec[0]*tmp_vec[0] + tmp_vec[1]*tmp_vec[1] + tmp_vec[2]*tmp_vec[2]);
    double mag2b = sqrt(out_vec[0]*out_vec[0] + out_vec[1]*out_vec[1] + out_vec[2]*out_vec[2]);

    cout << "2-body: " << mag2b << "  J2: " << magJ2 << endl;


    for(int i = 0; i < 3; i++){
        out_vec[i] = out_vec[i] + tmp_vec[i];
    }

}