//
// Created by dgt on 3/20/2021.
//

#ifndef ODA_MEASUREMENTS_H
#define ODA_MEASUREMENTS_H

#include "LibPhys/Math/GeometryTypes.h"

namespace usc::measurements {
    // Given two Scalar2 points, calculate the angle between them
    // and return it in the angle type specified.
    static double
    Vector2::AngleBetweenScalar2(types::Scalar2 &start_point, types::Scalar2 &end_point,
                                 types::Angle angle_output) {
        double delta_x = (end_point.first - start_point.first);
        double delta_y = (end_point.last - start_point.last);

        // atan2 returns arc in radians
        double result = atan2(delta_y, delta_x);

        // if user wants angle as degrees
        if (angle_output == kDegrees)
            result = conversion::RadiansToDegrees(result);

        return result;
    }
}

#endif //ODA_MEASUREMENTS_H
