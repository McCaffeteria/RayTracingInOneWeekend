#pragma once
#include "vec3.h"

#include "cmath"

class camera {
	vec3 origin = vec3();
	vec3 direction = vec3();
	int pixel_width = 1920;
	int pixel_height = 1080;
	double sensor_width = 36; //Assumes mm units
	double sensor_height; //Assumes mm units
	double focal_length = 50; //Assumes mm units

	double fov_width; //Assumes degree units
	double fov_height; //Assumes degree units

public:
	camera() {
		sensor_height = calc_sensor_height();
		fov_width = calc_fov_width();
		fov_height = calc_fov_height();
	}

	camera(vec3 orig, vec3 dir, int pw, int ph, double sw, double fl) { //Missing: sensor height (would conflict with pixels)
		origin = orig;
		direction = dir;
		pixel_width = pw;
		pixel_height = ph;
		sensor_width = sw;
		focal_length = fl;

		sensor_height = calc_sensor_height();
		fov_width = calc_fov_width();
		fov_height = calc_fov_height();
	}

	double calc_sensor_height() {
		double r = pixel_width / pixel_height;
		return sensor_width / r;
	}

	double calc_sensor_width() {
		double r = pixel_width / pixel_height;
		return sensor_height * r;
	}

	double calc_fov_width() {
		double h = pow(focal_length, 2) + pow(sensor_width / 2, 2);
		h = sqrt(h);
		return asin((sensor_width / 2) / h);
	}

	double calc_fov_height() {
		double h = pow(focal_length, 2) + pow(sensor_height / 2, 2);
		h = sqrt(h);
		return asin((sensor_height / 2) / h);
	}

	vec3 vec3_to_pixel() {}
};