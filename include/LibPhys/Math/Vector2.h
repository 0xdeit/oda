//
// Created by dgt on 3/13/2021.
//

#ifndef ODA_VECTOR2_H
#define ODA_VECTOR2_H

#include "LibPhys/Math/GeometryTypes.h"
#include "LibPhys/Math/Conversions.h"

namespace usc::types {
    class Vector2 {
    private:
        double angle_;
        double length_;
        void RecalculateEndPoint_();
    public:
        Cartesian2 origin{};
        Cartesian2 end{};

        // Create a new Vector2 object with a start and end point,
        // calculating the length and angle automatically.
        Vector2(Cartesian2 &start_point, Cartesian2 &end_point);

        // Create a new Vector2 object with an origin point,
        // length and angle, calculating the end point automatically.
        Vector2(Cartesian2 &origin, double length, double theta, Angle angle_input = kDegrees);

        // Prints start, end, length and angle of vector to stdout.
        void Info() const;

        // Rotate vector, calculating new end point.
        void Rotate(double angle, Angle angle_input = kDegrees);

        // Scale vector, calculating new end point.
        void Scale(double factor);

        // Set new length of vector, calculating new end point.
        void AdjustLength(double length);
    };
}
#endif //ODA_VECTOR2_H
