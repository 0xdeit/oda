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

    // Returns a Scalar2 with the cartesian components first and last of a vector that begins in the origin(0,0).
    static types::Scalar2 CartesianToPolar(double x, double y, types::AngleType angle_type = types::kDegrees) {
        types::Scalar2 result{0, 0};

        result.first = sqrt((pow(x, 2) + pow(y, 2)));

        switch (angle_type) {
            case types::kDegrees:
                // TODO: review the proper use of radians and degrees of atan2
                result.last = RadiansToDegrees(atan2(y, x));
                break;
            case types::kRadians:
                result.last = atan2(y, x);
                break;
        }

        return result;
    }

    // Returns a Scalar2 with the cartesian components first and last of a vector that begins in a given origin.
    static types::Scalar2 CartesianToPolar(types::Scalar2 &origin, types::Scalar2 &end, types::AngleType angle_type = types::kDegrees) {
        types::Scalar2 result{0, 0};

        double x = end.first - origin.first;
        double y = end.last - origin.last;

        result.first = sqrt((pow(x, 2) + pow(y, 2)));

        switch (angle_type) {
            case types::kDegrees:
                // TODO: review the proper use of radians and degrees of atan2
                result.last = RadiansToDegrees(atan2(y, x));
                break;
            case types::kRadians:
                result.last = atan2(y, x);
                break;
        }

        return result;
    }

    // TODO: Create analog function with a given origin.
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
