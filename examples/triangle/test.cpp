#include <iostream>
using namespace std;

class Point {
	private:
		double x, y;
	public:
		Point(double a=0, double b=0) {
			x=a;
			y=b;
		}
		void setX(double a) { x=a; }
		void setY(double b) { y=b; }
		double getX() { return x; }
		double getY() { return y; }
		void print() { cout << "(" << x << ", " << y <<")"; }
};

class Polygon {
	public:
		virtual double area() = 0;
		virtual void printPts() = 0;
};

class Triangle: public Polygon {
	private:
		Point x, y, z;
	public:
		Triangle(Point a, Point b, Point c) {
			x.setX(a.getX());
			x.setY(a.getY());
			y.setX(b.getX());
			y.setY(b.getY());
			z.setX(c.getX());
			z.setY(c.getY());
		}
		double area() { return 1.0; }
		void printPts() {
			x.print();
			cout << ", ";
			y.print();
			cout << ", ";
			z.print();
			cout << endl;
		}
};

int main() {
	Point origin;
	Point pt1(4,4);
	Point pt2(2,3);
	Triangle tri(origin, pt1, pt2);	
	tri.printPts();
	/*origin.print();
	cout << endl;
	pt1.print();
	cout << endl;*/
	return 0;
}

