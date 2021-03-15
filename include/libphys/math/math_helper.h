//
// Created by dgt on 3/13/2021.
//

#ifndef ODA_MATH_HELPER_H
#define ODA_MATH_HELPER_H

#include "libphys/math/Scalar2.h"
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
    static types::Scalar2 CartesianToPolar(double x, double y, types::AngleType angle_type = types::kDegrees) {
        types::Scalar2 result{0, 0};

        result.first = sqrt((pow(x, 2) + pow(y, 2)));

        switch (angle_type) {
            case types::kDegrees:
                // atan2 returns the arc in radians.
                result.last = RadiansToDegrees(atan2(y, x));
                break;
            case types::kRadians:
                result.last = atan2(y, x);
                break;
        }

        return result;
    }

    // Convert cartesian coordinates with given origin and end in (x, y) form to polar coordinates (r, theta).
    static types::Scalar2 CartesianToPolar(types::Scalar2 &origin, types::Scalar2 &end, types::AngleType angle_type = types::kDegrees) {
        types::Scalar2 result{0, 0};

        double x = end.first - origin.first;
        double y = end.last - origin.last;

        result.first = sqrt((pow(x, 2) + pow(y, 2)));

        switch (angle_type) {
            case types::kDegrees:
                // atan2 returns the arc in radians.
                result.last = RadiansToDegrees(atan2(y, x));
                break;
            case types::kRadians:
                result.last = atan2(y, x);
                break;
        }

        return result;
    }

    // TODO: Create analog PolarToCartesian function with a given origin if really needed?

    // Convert polar coordinates (r, theta) to cartesian coordinates (x, y)
    static types::Scalar2
    PolarToCartesian(double length, double angle, types::AngleType angle_type = types::kDegrees) {
        types::Scalar2 result{0, 0};
        // TODO: maybe remove this variable and just use angle param?
        double final_angle = 0;

        switch (angle_type) {
            case types::kDegrees:
                final_angle = DegreesToRadians(angle);
                break;
            case types::kRadians:
                final_angle = angle;
                break;
        }

        result.first = length * cos(final_angle);
        result.last = length * sin(final_angle);

        return result;
    }
}

#endif //ODA_MATH_HELPER_H
