#include <iostream>

using namespace std;

class Figure {
public:
    virtual double GetArea() = 0;
    virtual ~Figure() {}
};

class Rectangle : public Figure {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double GetArea() override {
        return width * height;
    }
};

class Circle : public Figure {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double GetArea() override {
        return 3.141592653589793 * radius * radius;
    }
};

class Triangle : public Figure {
private:
    double base;
    double height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double GetArea() override {
        return 0.5 * base * height;
    }
};

int main() {
    int choice;
    cout << "1. Rectangle\n2. Circle\n3. Triangle\n> ";
    cin >> choice;

    Figure* fig = nullptr;

    if (choice == 1) {
        double w, h;
        cout << "Width: ";
        cin >> w;
        cout << "Height: ";
        cin >> h;
        fig = new Rectangle(w, h);
    }
    else if (choice == 2) {
        double r;
        cout << "Radius: ";
        cin >> r;
        fig = new Circle(r);
    }
    else if (choice == 3) {
        double b, h;
        cout << "Base: ";
        cin >> b;
        cout << "Height: ";
        cin >> h;
        fig = new Triangle(b, h);
    }

    if (fig != nullptr) {
        cout << "Area: " << fig->GetArea() << endl;
        delete fig;
    }
}