// #include <iostream>
// #include <chrono>
// #include <thread>

// int main() {
    
//     /*
//     INPUTS:
//     Mass: m
//     Height: h

//     OUTPUTS:
//     Duration: t
//     Position: y
//     Velocity: v
//     Acceleration: a
//     Momentum: p
//     Kinetic Energy: K
//     Potential Energy: U
//     */
//     float m;
//     float t_max;
//     float h;

//     std::cout << "Mass of object (kg): ";
//     std::cin >> m;

//     std::cout << "Height to drop from (m): ";
//     std::cin >> h;

//     std::cout << "Max duration (s): ";
//     std::cin >> t_max;

    


//     // INITIALIZE
//     float g = -9.81;       // acceleration due to gravity
//     float v = 0.0;        // initial velocity
//     float y = h;          // initial height
//     //float h_f = 0.0;      // final height
//     float t = 0.0;
//     float dt = 0.0;
//     float p = 0.0;
//     float K = 0.0;
//     float U = 0.0;
//     auto program_start = std::chrono::high_resolution_clock::now();
//     while (y > 0.0 && t < t_max) {
//         auto start = std::chrono::high_resolution_clock::now();
    
//         y = y + v*dt;                   // Position
//         v = v + g*dt;                   // Velocity
//         p = m*v;                        // Momentum
//         K = (m*std::pow(v, 2)) / 2 ;    // Kinetic Energy
//         U = m*g*y;                      // Potential Energy
        
//         std::cout
//         << "\rDuration: " << t << " [s] " 
//         << "Position: " << y << " [m] "
//         << "Velocity: " << v << " [m/s] " 
//         << "Acceleration: " << g << " [m/s^2] " 
//         << "Momentum: " << p << " [(kg)(m/s)] "
//         << "KE: " << K << " [J] "
//         << "PE: " << U << " [J] "
//         << std::flush;


//         auto end = std::chrono::high_resolution_clock::now();
//         dt = (float) std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() / 1000;
//         t += dt;
//         // std::this_thread::sleep_for(std::chrono::milliseconds(1));
//     }
//     auto program_end = std::chrono::high_resolution_clock::now();
//     auto diff = (float) std::chrono::duration_cast<std::chrono::microseconds>(program_end-program_start).count() / 1000000;
//     std::cout << std::endl;
//     std::cout << "Total program time elapsed: " << diff << " [s]"<< std::endl;

// }