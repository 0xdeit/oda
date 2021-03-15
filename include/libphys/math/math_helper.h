//
// Created by dgt on 3/13/2021.
//

#ifndef ODA_MATH_HELPER_H
#define ODA_MATH_HELPER_H

#include "libphys/math/Scalar2.h"
#include "libphys/math/Scalar3.h"
#include <cmath>

namespace usc::types {
    const double pi = 3.14159265358979323846;
    const double circumference_degrees = 360;

    enum AngleType {
        kRadians,
        kDegrees
    };
}

namespace usc::conversion {
    static double RadiansToDegrees(double radians) {
        return radians * (180 / types::pi);
    }

    static double DegreesToRadians(double degrees) {
        return degrees * (types::pi / 180);
    }

    // Convert cartesian coordinates with the origin at (0, 0) and  end in (x, y) form to polar coordinates (r, theta).
    static types::Scalar2 CartesianToPolar(double x, double y, types::AngleType angle_output_type = types::kDegrees) {
        types::Scalar2 result{0, 0};

        result.first = sqrt((pow(x, 2) + pow(y, 2)));

        // atan2 returns in radians.
        result.last = atan2(y, x);

        // give user the angle type they want
        if (angle_output_type == types::kDegrees){
            result.last = RadiansToDegrees(result.last);
        }

        return result;
    }

    // Convert cartesian coordinates with given origin and end in (x, y) form to polar coordinates (r, theta).
    static types::Scalar2
    CartesianToPolar(types::Scalar2 &origin, types::Scalar2 &end, types::AngleType angle_output_type = types::kDegrees) {
        types::Scalar2 result{0, 0};

        double delta_x = end.first - origin.first;
        double delta_y = end.last - origin.last;

        result.first = sqrt((pow(delta_x, 2) + pow(delta_y, 2)));

        // atan2 returns the arc in radians.
        result.last = atan2(delta_y, delta_x);

        // give user the angle type they want
        if (angle_output_type == types::kDegrees){
            result.last = RadiansToDegrees(result.last);
        }

        return result;
    }

    // Convert polar coordinates (r, theta) to cartesian coordinates (x, y)
    static types::Scalar2
    PolarToCartesian(double length, double angle, types::AngleType angle_input_type = types::kDegrees) {
        types::Scalar2 result{0, 0};

        // Both cos() and sin() take the angle param in radians.
        if (angle_input_type == types::kDegrees) {
            angle = DegreesToRadians(angle);
        }

        // component x
        result.first = length * cos(angle);
        // component y
        result.last = length * sin(angle);

        return result;
    }

    // Convert spherical coordinates (radial distance, polar angle, azimuth angle) to cartesian (x, y, z)
    // Names for the spherical components come from the ISO 80000-2:2019 convention (src: Wikipedia)
    static types::Scalar3
    SphericalToCartesian(double radius, double theta, double phi, types::AngleType angle_input_type = types::kDegrees) {
        types::Scalar3 result{0, 0, 0};

        // Both cos() and sin() take the angle param in radians.
        if (angle_input_type == types::kDegrees) {
            theta = DegreesToRadians(theta);
            phi = DegreesToRadians(phi);
        }

        // component x
        result.first = (radius * sin(theta) * cos(phi));
        // component y
        result.middle = (radius * sin(theta) * sin(phi));
        // component z
        result.last = (radius * cos(theta));

        return result;
    }

    // Convert cartesian (x, y, z) to spherical coordinates (radial distance, polar angle, azimuth angle)
    static types::Scalar3
    CartesianToSpherical(double x, double y, double z) {
        types::Scalar3 result{0, 0, 0};

        // radius
        result.first = sqrt((pow(x, 2) + pow(y, 2) + pow(z, 2)));
        // polar angle / theta
        result.middle = atan2(sqrt(pow(x, 2) + pow(y, 2)), z);
        // azimuth angle / phi
        result.last = atan2(y, x);

        return result;
    }
}

#endif //ODA_MATH_HELPER_H
