#include <vector>
#include <tuple>
#include "raylib.h"
#include "../headers/objects.h"
#include <iostream>
#include <vector>

using namespace std;

// System Object
// System::System(vector<RigidBody> bodies) : bodies(bodies) {}

// tuple<Vector2, float, float, vector<RigidBody>> System::get_state(){
//     // Return the current pos, vel, acc of each body and the system variables
//     return {gravity, air_resistance, time, bodies};
// }

// void System::set_state(Vector2 g, float ar, float t){
//     gravity = g;
//     air_resistance = ar;
//     time = t;
// }

// void System::update_state() {

// }

// Body Object
// All bodies are rectangles for now
RigidBody::RigidBody(double m, int w, int h, vector<float> x,
        vector<vector<float>> R, vector<float> P, vector<float> L,
        vector<vector<float>> Ibody, vector<vector<float>> Ibodyinv){
    pos = x;
    width = w;
    height = h;
    mass = m;
    this->R = R;
    this->P = P;
    this->L = L;
    this->Ibody = Ibody;
    this->Ibody = Ibody;
}

// tuple<Vector2, Vector2, Vector2> RigidBody::get_rel_state(){
//     // return {pos,vel,acc};
// }

// void RigidBody::set_rel_state(Vector2 position, Vector2 velocity, Vector2 acceleration) {
//     // pos = position;
//     // vel = velocity;
//     // acc = acceleration;
// }
void state_to_vector(RigidBody *rb, double *arr) {
    // Copy position
    *arr++ = rb->pos[0]; // x
    *arr++ = rb->pos[1]; // y

    // Copy rotation matrix
    for (int i = 0; i<2; i++) {
        for (int j = 0; j < 2; j++) {
            *arr++ = rb->R[i][j];
        }
    }

    // Copy Momentum
    *arr++ = rb->P[0];
    *arr++ = rb->P[1];

    // Copy Angular Momentum
    *arr++ = rb->L[0];
    *arr++ = rb->L[1];
}

void vector_to_state(RigidBody *rb, double *arr) {
    rb->pos[0] = *arr++;
    rb->pos[1] = *arr++;

    for (int i = 0; i<2; i++) {
        for (int j = 0; j < 2; j++) {
            rb->R[i][j] = *arr++;
        }
    }

    rb->P[0] = *arr++;
    rb->P[1] = *arr++;

    rb->L[0] = *arr++;
    rb->L[1] = *arr++;

    // Compute auxillary variables too
    rb->v[0] = rb->P[0] / rb->mass;
    rb->v[1] = rb->P[1] / rb->mass;

    vector<vector<float>> Ibodyinv_RT = multiply_matrices(rb->Ibodyinv, transpose_square(rb->R));
    rb->Iinv = multiply_matrices(rb->R, Ibodyinv_RT);
    
    rb->omega = multiply_matrices(rb->Iinv, {{rb->L[0]}, {rb->L[1]}})[0];

}

vector<vector<float>> multiply_matrices(vector<vector<float>> m1, vector<vector<float>> m2) {

    // Verify matrices can be multiplied
    if (m1.size() == 0 || m2.size() == 0 || m1[0].size() != m2.size()) {return {};}

    // h of m1 * w of m2 
    vector<vector<float>> res(m1.size(), vector<float>(m2[0].size(), 0));

    for (int i = 0; i < m1.size(); i++) {
        for (int j = 0; j<m2[0].size(); j++) {
            for (int k = 0; k<m1[0].size(); k++) {
                res[i][j] += m1[i][k]*m2[k][j];
            }
        }
    }
    return res;
}

vector<vector<float>> transpose_square(vector<vector<float>> matrix) {
    // Check if square matrix
    if (matrix.size() == 0 || matrix.size() != matrix[0].size()) {return {};}

    vector<vector<float>> res(matrix.size(), vector<float>(matrix.size(), 0));

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = i; j < matrix[0].size(); j++) {
            if (i == j) {
                res[i][j] = matrix[i][j];
            } else {
                res[i][j] = matrix[j][i];
                res[j][i] = matrix[i][j];
            }
        }
    }

    return res;
}

void arr_to_bodies(double arr[], vector<RigidBody> bodies, int STATE_SIZE = 10) {
    for(int i = 0; i<bodies.size(); i++) {
        vector_to_state(&bodies[i], &arr[i*STATE_SIZE]);
    }
}

void bodies_to_arr(double arr[], vector<RigidBody> bodies, int STATE_SIZE = 10) {
    for (int i = 0; i<bodies.size(); i++) {
        state_to_vector(&bodies[i], &arr[i*STATE_SIZE]);
    }
}

void ddt_state_to_vector(RigidBody *rb, double *ydot) {
    *ydot++ = rb->v[0];
    *ydot++ = rb->v[1];

    vector<vector<float>> Rdot = multiply_matrices(star(rb->omega), rb->R);
}


vector<vector<float>> star(vector<float> a) {
    if (a.size() != 2) {return {};}
    
}