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
    float t;
    float m;
    float h;
    float y;
    float y_v;
    float y_a;
    float y_p;
    float K;
    float U;

    // float t;
    float dt = 0.001;
    std::chrono::seconds s(3);

    std::cout << "Mass of object (kg): ";
    std::cin >> m;

    std::cout << "Height to drop from (m): ";
    std::cin >> h;

    auto program_start = std::chrono::high_resolution_clock::now();


    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    // Timesteped operation
    do {
        std::cout << "\rDuration: " << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << std::flush;
        end = std::chrono::high_resolution_clock::now();
    } while (std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() < 3000000); // 3 seconds
    
    
    
    auto program_end = std::chrono::high_resolution_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(program_end-program_start).count();
    std::cout << "Program time elapsed: " << diff << std::endl;

}