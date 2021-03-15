//
// Created by dgt on 3/13/2021.
//

#ifndef ODA_MATH_HELPER_H
#define ODA_MATH_HELPER_H

#include "LibPhys/Math/GeometryTypes.h"
#include "LibPhys/Math/Constants.h"
#include <cmath>

namespace usc::types {
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
    static types::Polar CartesianToPolar(double x, double y, types::AngleType angle_output_type = types::kDegrees) {
        types::Polar result{0, 0};

        result.radius = sqrt((pow(x, 2) + pow(y, 2)));

        // atan2 returns in radians.
        result.theta = atan2(y, x);

        // give user the angle type they want
        if (angle_output_type == types::kDegrees){
            result.theta = RadiansToDegrees(result.theta);
        }

        return result;
    }

    // Convert cartesian coordinates with given origin and end in (x, y) form to polar coordinates (r, theta).
    static types::Polar
    CartesianToPolar(types::Cartesian2 &origin, types::Cartesian2 &end, types::AngleType angle_output_type = types::kDegrees) {
        types::Polar result{0, 0};

        double delta_x = end.x - origin.x;
        double delta_y = end.y - origin.y;

        result.radius = sqrt((pow(delta_x, 2) + pow(delta_y, 2)));

        // atan2 returns the arc in radians.
        result.theta = atan2(delta_y, delta_x);

        // give user the angle type they want
        if (angle_output_type == types::kDegrees){
            result.theta = RadiansToDegrees(result.theta);
        }

        return result;
    }

    // Convert polar coordinates (r, theta) to cartesian coordinates (x, y)
    static types::Cartesian2
    PolarToCartesian(double length, double angle, types::AngleType angle_input_type = types::kDegrees) {
        types::Cartesian2 result{0, 0};

        // Both cos() and sin() take the angle param in radians.
        if (angle_input_type == types::kDegrees) {
            angle = DegreesToRadians(angle);
        }

        result.x = length * cos(angle);
        result.y = length * sin(angle);

        return result;
    }

    // Convert spherical coordinates (radial distance, polar angle, azimuth angle) to cartesian (x, y, z)
    // Names for the spherical components come from the ISO 80000-2:2019 convention (src: Wikipedia)
    static types::Cartesian3
    SphericalToCartesian(double radius, double theta, double phi, types::AngleType angle_input_type = types::kDegrees) {
        types::Cartesian3 result{0, 0, 0};

        // Both cos() and sin() take the angle param in radians.
        if (angle_input_type == types::kDegrees) {
            theta = DegreesToRadians(theta);
            phi = DegreesToRadians(phi);
        }


        result.x = (radius * sin(theta) * cos(phi));
        result.y = (radius * sin(theta) * sin(phi));
        result.z = (radius * cos(theta));

        return result;
    }

    // Convert cartesian (x, y, z) to spherical coordinates (radial distance, polar angle, azimuth angle)
    static types::Spherical
    CartesianToSpherical(double x, double y, double z) {
        types::Spherical result{0, 0, 0};

        result.radius = sqrt((pow(x, 2) + pow(y, 2) + pow(z, 2)));
        result.theta = atan2(sqrt(pow(x, 2) + pow(y, 2)), z);
        result.phi = atan2(y, x);

        return result;
    }
}

#endif //ODA_MATH_HELPER_H
