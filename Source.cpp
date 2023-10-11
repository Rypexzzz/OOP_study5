#include <iostream>
#include <string>

struct BoundingBoxDimensions {
	double lenght = 0;
	double width = 0;
}; 

class Shape {
public:
	virtual double square() const = 0;
	virtual BoundingBoxDimensions dimensions() const = 0;
	virtual std::string type() const = 0;
	void printParams(Shape* shape) {
		std::cout << "Type: " << shape->type() << std::endl;
		std::cout << "Square: " << shape->square() << std::endl;
		std::cout << "Dimensions: " << shape->dimensions().lenght << " " << shape->dimensions().width << std::endl;
	}
};

class Circle : public Shape {
private:
	double radius;
public:
	Circle(double _rad) {
		radius = _rad;
	}
	virtual double square() const override {
		return 3.14 * radius * radius;
	}
	virtual BoundingBoxDimensions dimensions() const override {
		BoundingBoxDimensions d = {radius * 2, radius * 2};
		return d;
	}
	virtual std::string type() const override {
		return "Circle";
	}
};

class Triangle : public Shape {
private:
	double a;
	double b; 
	double c;
public:
	Triangle(double _a, double _b, double _c) {
		a = _a;
		b = _b;
		c = _c;
	}
	virtual double square() const override {
		double p = (a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
	virtual BoundingBoxDimensions dimensions() const override {
		double p = (a + b + c) / 2;
		double r = a * b * c / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));
		BoundingBoxDimensions d = { r * 2, r * 2 };
		return d;
	}
	virtual std::string type() const override {
		return "Triangle";
	}
};

class Rectangle : public Shape {
private:
	double a;
	double b;
public:
	Rectangle(double _a, double _b) {
		a = _a;
		b = _b;
	}
	virtual double square() const override {
		return a*b;
	}
	virtual BoundingBoxDimensions dimensions() const override {
		BoundingBoxDimensions d = {a, b};
		return d;
	}
	virtual std::string type() const override {
		return "Rectangle";
	}
};

int main() {
	Triangle t(3, 4, 5);
	Circle c(3);
	Rectangle r(4, 5);
	t.printParams(&t);
	c.printParams(&c);
	r.printParams(&r);
}