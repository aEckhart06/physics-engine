#pragma once
#include <vector>
#include <tuple>

using namespace std;

class RigidBody {
public:
    float width;
    float height;

    /* Constant quantities */
    float mass;                                /* mass M */
    float I;         /* The pre-computed moment of inertia of the body */
    
    /* State variables */
    vector<float> pos;                    /* Position vector (about COM) */
    vector<vector<float>> R;              /* Rotation matrix {{cosT, -sinT}, {sinT, cosT}} */
    vector<float> P;                      /* p=mv Linear momentum vector (about COM) */
    float L;                      /* L=Iw Angular momentum vector (about COM) */

    /* Derived quantities (auxiliary variables) */
    vector<float> v;        /* Linear velocity */
    float omega;            /* Angular velocity */

    /* Computed quantities */
    vector<float> force; /* F(t) the net force about the COM */
    vector<float> torque; /* τ(t) the net torque about the COM */


    RigidBody(int w, int h, float mass, float I, vector<float> x,
        vector<vector<float>> R);

    // tuple<Vector2, Vector2, Vector2> get_rel_state();
    void draw();
    void compute_net_force(float dt);
    void update_state(float dt);
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

void bodies_to_arr(double arr[], vector<RigidBody> bodies, int STATE_SIZE);