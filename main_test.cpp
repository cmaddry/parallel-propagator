#include <iostream>
#include "physics/gravity.h"

using namespace std;

int main(){

    double x = 1.0;
    double y = 2.0;
    double z = 3.0;
    double v_x = 1.0;
    double v_y = 1.0;
    double v_z = 1.0;

    double vec[] = {x, y, z, v_x, v_y, v_z};
    double output_vec[6] = {};
    int len = 6;

    two_body(vec, output_vec, len);

    cout << "Here is the output vector: " << endl;
    cout << "\t a_x: " << output_vec[0] << endl;
    cout << "\t a_y: " << output_vec[1] << endl;
    cout << "\t a_z: " << output_vec[2] << endl;

    return 0;
}