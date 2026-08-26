#pragma once
#include <vector>
#include <tuple>

using namespace std;

class RigidBody {
public:
    int width;
    int height;

    // /* Constant quantities */
    float mass;                                /* mass M */
    vector<vector<float>> Ibody;         /* Ibody */
    vector<vector<float>> Ibodyinv;      /* I−1 body (inverse of Ibody) */
    
    /* State variables */
    vector<float> pos;                    /* x(t) */
    vector<vector<float>> R; /* R(t) */
    vector<float> P;                      /* P(t) */
    vector<float> L;                      /* L(t) */

    /* Derived quantities (auxiliary variables) */
    vector<vector<float>> Iinv; /* I−1(t) */
    vector<float> v; /* v(t) */
    float omega; /* ω(t) */

    // /* Computed quantities */
    vector<float> force; /* F(t) */
    vector<float> torque; /* τ(t) */


    RigidBody(double m, int w, int h, vector<float> x,
        vector<vector<float>> R, vector<float> P, vector<float> L,
        vector<vector<float>> Ibody, vector<vector<float>> Ibodyinv);

    // tuple<Vector2, Vector2, Vector2> get_rel_state();

    // void set_rel_state(Vector2 position, Vector2 velocity, Vector2 acceleration);
};

// class System {
// private:
//     Vector2 gravity = {0, 9.81};
//     float air_resistance = 0;
//     float time = 0;
//     vector<RigidBody> bodies;
// public:
//     System(vector<RigidBody> bodies);

//     tuple<Vector2, float, float, vector<RigidBody>> get_state();

//     void set_state(Vector2 g, float ar, float t);

//     void update_state();
// };

void state_to_vector(RigidBody *rb, double *arr);

void vector_to_state(RigidBody *rb, double *arr);

vector<vector<float>> multiply_matrices(vector<vector<float>> m1, vector<vector<float>> m2);

vector<vector<float>> transpose(vector<vector<float>> matrix);

void arr_to_bodies(double arr[], vector<RigidBody> bodies, int STATE_SIZE);

void bodies_to_arr(double arr[], vector<RigidBody> bodies, int STATE_SIZE = 10);