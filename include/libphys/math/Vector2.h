//
// Created by dgt on 3/13/2021.
//

#ifndef ODA_VECTOR2_H
#define ODA_VECTOR2_H

#include "libphys/math/Scalar2.h"
#include "math_helper.h"

namespace usc::types {
    class Vector2 {
    private:
        double angle_;
        double length_;
    public:
        Scalar2 origin{};
        Scalar2 end{};

        // Create a new Vector2 object with a start and end point, calculating the length and angle automatically.
        Vector2(Scalar2 &start_point, Scalar2 &end_point);

        // Create a new Vector2 object with an origin point, length and angle, calculating the end point automatically.
        Vector2(Scalar2 &origin, double length, double theta, AngleType angle_type = kDegrees);

        // Prints start, end, length and angle of vector to stdout.
        void Info(bool clockwise_angle = false) const;

        // Rotate vector, calculating new end point.
        void Rotate(double angle, AngleType angle_type = kDegrees);

        // Scale vector, calculating new end point.
        void Scale(double factor);

        // Set new length of vector, calculating new end point.
        void AdjustLength(double length);

        // Given two Scalar2 points, calculate the angle between them and return it in the angle type specified.
        static double AngleBetweenScalar2(Scalar2 &start_point, Scalar2 &end_point, AngleType angle_type = kDegrees);
    };
}
#endif //ODA_VECTOR2_H
