#pragma once
#include "vec3.h"

class ray {
public:
	ray() {}
	ray(const vec3& orig, const vec3& dir)
		: origin(orig), direction(dir) {}

	vec3 origin;
	vec3 direction;
};

