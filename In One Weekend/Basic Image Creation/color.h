#pragma once
#include "vec3.h"

#include <iostream>

class color: public vec3 {
public:
	color() : vec3() {}
	color(double e0, double e1, double e2) : vec3(e0, e1, e2) {}

	void write_color(std::ostream& out, color pixel_color) {
        // Write the translated [0,255] value of each color component.
        out << static_cast<int>(255.999 * pixel_color.x()) << ' '
            << static_cast<int>(255.999 * pixel_color.y()) << ' '
            << static_cast<int>(255.999 * pixel_color.z()) << '\n';
    }
};