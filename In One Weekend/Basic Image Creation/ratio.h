#pragma once
class ratio {
	double r = 1;

public:
	ratio() : r(1) {}
	ratio(double x, double y) : r(x/y) {}

	double get_horiz_res(int v) {
		return r * v;
	}

	double get_vert_res(int h) {
		return r / h;
	}
};