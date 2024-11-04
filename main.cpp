#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>

class Electric_Field {
private:
    double *E; 

public:
    // Default constructor
    Electric_Field() {
        E = new double[3]{0.0, 0.0, 0.0}; 
    }

    // Parameterized constructor
    Electric_Field(double ex, double ey, double ez) {
        E = new double[3]{ex, ey, ez};
    }

    // Destructor
    ~Electric_Field() {
        delete[] E; 
    }

    // Getters
    double getX() const { return E[0]; }
    double getY() const { return E[1]; }
    double getZ() const { return E[2]; }

    // Setters
    void setX(double ex) { E[0] = ex; }
    void setY(double ey) { E[1] = ey; }
    void setZ(double ez) { E[2] = ez; }

    // Calculate magnitude of the electric field vector
    double calculateMagnitude() const {
        return sqrt(E[0] * E[0] + E[1] * E[1] + E[2] * E[2]);
    }

    // Calculate inner product of the electric field vector
    double calculateInnerProduct() const {
        return E[0] * E[0] + E[1] * E[1] + E[2] * E[2];
    }
};

class Magnetic_Field {
private:
    double *B; 
public:
    // Default constructor
    Magnetic_Field() {
        B = new double[3]{0.0, 0.0, 0.0}; 
    }

    // Parameterized constructor
    Magnetic_Field(double bx, double by, double bz) {
        B = new double[3]{bx, by, bz};
    }

    // Destructor
    ~Magnetic_Field() {
        delete[] B; 
    }

    // Getters
    double getX() const { return B[0]; }
    double getY() const { return B[1]; }
    double getZ() const { return B[2]; }

    // Setters
    void setX(double bx) { B[0] = bx; }
    void setY(double by) { B[1] = by; }
    void setZ(double bz) { B[2] = bz; }

    // Calculate magnitude of the magnetic field vector
    double calculateMagnitude() const {
        return sqrt(B[0] * B[0] + B[1] * B[1] + B[2] * B[2]);
    }

    // Calculate unit vector of the magnetic field
    void calculateUnitVector() const {
        double magnitude = calculateMagnitude();
        if (magnitude == 0) {
            std::cout << "Unit vector undefined for zero magnitude field." << std::endl;
        } else {
            std::cout << "Unit Vector: (" 
                      << B[0] / magnitude << ", " 
                      << B[1] / magnitude << ", " 
                      << B[2] / magnitude << ")" << std::endl;
        }
    }
};

int main() {
    // Create electric and magnetic field objects
    Electric_Field E_default;
    Electric_Field E_components(1e5, 10.9, 1.7e2);
    Magnetic_Field B_default;
    Magnetic_Field B_components(0.5, 0.8, 1.2);

    // Setters to modify components
    E_default.setX(3.2);
    E_default.setY(4.5);
    E_default.setZ(6.7);
    B_default.setX(0.3);
    B_default.setY(0.4);
    B_default.setZ(0.5);

    // Calculate and output magnitudes
    std::cout << "Electric Field Magnitude (default): " << E_default.calculateMagnitude() << std::endl;
    std::cout << "Electric Field Magnitude (components): " << E_components.calculateMagnitude() << std::endl;

    std::cout << "Magnetic Field Magnitude (default): " << B_default.calculateMagnitude() << std::endl;
    std::cout << "Magnetic Field Magnitude (components): " << B_components.calculateMagnitude() << std::endl;

    // Output electric field inner product
    std::cout << "Electric Field Inner Product: " << E_components.calculateInnerProduct() << std::endl;

    // Output magnetic field unit vector
    std::cout << "Magnetic Field Unit Vector: ";
    B_components.calculateUnitVector();

    return 0;
}
