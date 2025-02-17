#include <iostream>
#include <cmath>

using namespace std;

int distance_between_points(int x0,int y0, int x1, int y1)	
{
	int dist_x = x0 - x1;
	int dist_y = y0 - y1;

	return sqrt(dist_x * dist_x + dist_y * dist_y );
}

int distance_between_point_line(int x0, int y0, int m, int n) // y = mx + n
{
	int quo = abs(m*x0 - y0 + n);
	int den = sqrt(m*m+1);
	
	return quo/den;
}

int distance_between_point_line(int x0, int y0, int a, int b, int c) // ax + by + c = 0
{
	int quo = abs(a*x0 + b*y0 + c);
	int den = sqrt(a*a + b*b);
	
	return quo/den;
}

bool is_parallels(int m0, int n0, int m1, int n1)
{
	return (m0 == m1 && n0 != n1); // se n0 = n1 elas sao iguais
}

bool is_parallels(int a0, int b0, int c0, int a1, int b1, int c1)
{
	return (a0 == a1 && b0 == b1 && c0 != c1); // se c0 = c1 elas sao iguais
}

struct Line // y = mx + n
{
	int m, n;
	Line () : m(0), n(0) {}
	Line(int m, int n) : m(m), n(n) {}

	bool contains(int x0, int y0)
	{
		return (y0 == (m*x0 + n));
	}
	Line* normal_line(int x0, int y0) // reta normal que passa pela ponto (x0,y0)
	{
		return new Line(-1/m, x0/m +y0);
	}
};


struct Line // ax + bx + c = 0
{
	int a, b, c;
	Line () : a(0), b(0), c(0) {}
	Line(int a, int b, int c) : a(a), b(b), c(c) {}

	bool contains(int x0, int y0)
	{
		return (a*x0 + b*y0 + c) == 0;
	}
	Line* normal_line(int x0, int y0) // reta normal que passa pela ponto (x0,y0)
	{
		return new Line(b,-a,a*y0-b*x0);
	}
};

struct Circle
{
	int radius;
	int x, y;

	Circle() : radius(0), x(0), y(0) {}
	Circle(int radius) : radius(radius), x(0), y(0) {}
	Circle(int radius, int x, int y) : radius(radius), x(x), y(y) {}

	bool is_inside(int x0, int y0)
	{
		return distance_between_points(x0,y0,x,y) <= radius;
	}
	int circular_sector_area(int theta)
	{
		return theta*M_PI*radius*radius/360;
	}
};



















