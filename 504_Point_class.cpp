#include <iostream>

class Point {
public:
    // Constructors
    Point() : x(0), y(0) {}
    Point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}

    // Member functions to access coordinates
    int getX() const { return x; }
    int getY() const { return y; }

    // Member function to set coordinates
    void setCoordinates(int newX, int newY) {
        x = newX;
        y = newY;
    }

    // Member function to display point
    void display() const {
        std::cout << "(" << x << ", " << y << ")";
    }

private:
    int x, y;
};

int main() {
    // Create a Point object
    Point myPoint(3, 4);

    // Display coordinates
    std::cout << "Coordinates of myPoint: ";
    myPoint.display();
    std::cout << std::endl;

    // Change coordinates
    myPoint.setCoordinates(7, 2);

    // Display updated coordinates
    std::cout << "Updated coordinates: ";
    myPoint.display();
    std::cout << std::endl;

    return 0;
}
