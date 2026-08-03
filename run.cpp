#include <iostream>
#include <chrono>
#include <thread>

int main() {
    
    /*
    INPUTS:
    Mass: m
    Height: h

    OUTPUTS:
    Duration: t
    Position: y
    Velocity: v
    Acceleration: a
    Momentum: p
    Kinetic Energy: K
    Potential Energy: U
    */
    float m;
    float t_max;

    std::cout << "Mass of object (kg): ";
    std::cin >> m;

    std::cout << "Max duration (s): ";
    std::cin >> t_max;

    // std::cout << "Height to drop from (m): ";
    // std::cin >> h;


    // INITIALIZE
    float g = 9.81;       // acceleration due to gravity
    float v = 0.0;        // initial velocity
    // float h_f = 0.0;   // final height
    float t = 0.0;
    float dt = 0.0;
    float p = 0.0;
    float K = 0.0;
    float U = 0.0;
    auto program_start = std::chrono::high_resolution_clock::now();
    while (t < t_max) {
        auto start = std::chrono::high_resolution_clock::now();
    
        v = v + g*dt;                   // Velocity
        p = m*v;                        // Momentum
        K = (m*std::pow(v, 2)) / 2 ;    // Kinetic Energy
        U = 0;                          // Potential Energy

        
        std::cout 
        << "\rDuration: " << t << " [s] " 
        << "Velocity: " << v << " [m/s] " 
        << "Acceleration: " << g << " [m/s^2] " 
        << "Momentum: " << p << " [(kg)(m/s)] "
        << "KE: " << K << " [J] "
        << "PE: " << U << " [J] "
        << std::flush;


        auto end = std::chrono::high_resolution_clock::now();
        dt = (float) std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() / 1000;
        t += dt;
    }
    auto program_end = std::chrono::high_resolution_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(program_end-program_start).count();
    std::cout << "Total program time elapsed: " << diff << std::endl;

}