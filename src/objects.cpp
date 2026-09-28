#include <vector>
#include <tuple>
#include "raylib.h"
#include "../include/objects.h"
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
RigidBody::RigidBody(int w, int h, float mass, float I, vector<float> x, vector<vector<float>> R){
    width = w;
    height = h;
    this->mass = mass;
    this->I = I;
    pos = x;
    this->R = R;
    P = {0,0};
    L = 0;
    v = {0,0};
    omega = 0;
    force = {0,0};
    torque = {0,0};
    
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
    *arr++ = rb->L;
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

    rb->L = *arr++;

    // Compute auxillary variables too
    rb->v[0] = rb->P[0] / rb->mass;
    rb->v[1] = rb->P[1] / rb->mass;

    

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

void arr_to_bodies(double arr[], vector<RigidBody> bodies, int STATE_SIZE = 9) {
    for(int i = 0; i<bodies.size(); i++) {
        vector_to_state(&bodies[i], &arr[i*STATE_SIZE]);
    }
}

void bodies_to_arr(double arr[], vector<RigidBody> bodies, int STATE_SIZE = 9) {
    for (int i = 0; i<bodies.size(); i++) {
        state_to_vector(&bodies[i], &arr[i*STATE_SIZE]);
    }
}

void dydt(double t, double y[], vector<RigidBody> bodies, double ydot[], int STATE_SIZE = 9){
    // We move the state data from the array into the states of the bodies
    arr_to_bodies(y, bodies);
    for (int i = 0; i<bodies.size(); i++) {
        // Compute the force and torque HERE
    }
}



void RigidBody::draw() {
    // rotation matrix affects r and rot
    Rectangle r = {pos[0]-width/2, pos[1]-height/2, width, height};
    float rot = 0.0f;
    DrawRectanglePro(r, {0,0}, rot, RED);
}

// Computes the total forces exerted onto a body by the system
// expand to also compute torque
void RigidBody::compute_net_force(float dt) {
    float m = 50;
    vector<float> F_gravity = {0.0f*mass*m, 9.81f*mass*m};

    force = {0,0};
    vector<vector<float>> forces = {F_gravity};

    // calculate forces during collisions
    // add to forces vector
    
    for (vector<float> f : forces) {
        force[0] += f[0];
        force[1] += f[1];
    }
}

void RigidBody::update_state(float dt) {
    vector<float> acc = {force[0]/mass, force[1]/mass};
    // linear velocity
    vector<float> dv = {acc[0]*dt, acc[1]*dt};
    v = {v[0]+dv[0], v[1]+dv[1]};
    // linear momentum
    vector<float> dp = {mass*dv[0], mass*dv[1]};
    P = {P[0]+dp[0], P[1]+dp[1]};
    // world position
    vector<float> dpos = {v[0]*dt, v[1]*dt};
    pos = {pos[0]+dpos[0], pos[1]+dpos[1]};
}