#include <iostream>

int main() {
    
    /*
    INPUTS:
    Mass: m
    Height: h

    OUTPUTS:
    Position: y
    Velocity: v
    Acceleration: a
    Momentum: p
    Kinetic Energy: K
    Potential Energy: U
    */
    float m;
    float h;


    std::cout << "Mass of object (kg): ";
    std::cin >> m;

    std::cout << "Height to drop from (m): ";
    std::cin >> h;

    std::cout << "Mass: " << m << ", " << "Height: " << h <<std::endl;

}