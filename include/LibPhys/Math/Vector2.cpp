//
// Created by dgt on 3/13/2021.
//

#include "LibPhys/Math/Vector2.h"
#include <iostream>
#include <cmath>

namespace usc::types {
    double
    Vector2::AngleBetweenScalar2(Scalar2 &start_point, Scalar2 &end_point, Angle angle_output) {
        double delta_x = (end_point.first - start_point.first);
        double delta_y = (end_point.last - start_point.last);

        // atan2 returns arc in radians
        double result = atan2(delta_y, delta_x);

        // if user wants angle as degrees
        if (angle_output == kDegrees)
            result = conversion::RadiansToDegrees(result);

        return result;
    }

    void Vector2::Info() const {
        std::cout << "[VECTOR2] INFO:" << "\n\t"
                  << "Components: {(" << origin.x << ", " << origin.y
                  << "), (" << end.x << ", " << end.y << ")}" << "\n\t"
                  << "Angle: " << angle_ << " deg.\n\t"
                  << "Angle: " << conversion::DegreesToRadians(angle_)  << " rad.\n\t"
                  << "Length: " << length_ << std::endl;
    }

    Vector2::Vector2(Cartesian2 &start_point, Cartesian2 &end_point) {
        origin = start_point;
        end = end_point;
        Polar polar = conversion::Cartesian2ToPolar(origin, end);
        length_ = polar.radius;
        angle_ = polar.theta;
    }

    Vector2::Vector2(Cartesian2 &origin, double length, double theta, Angle angle_input) {
        // Always store angles as degrees.
        if (angle_input == kRadians){
            theta = conversion::RadiansToDegrees(theta);
        }

        this->angle_ = theta;
        this->length_ = length;
        this->origin = origin;
        RecalculateEndPoint_();
    }

    void Vector2::Rotate(double angle, Angle angle_input) {
        // Always store angles as degrees.
        if (angle_input == kRadians){
            angle = conversion::RadiansToDegrees(angle);
        }

        this->angle_ += angle;
        RecalculateEndPoint_();
    }

    void Vector2::Scale(double factor) {
        this->length_ *= factor;
        RecalculateEndPoint_();
    }

    void Vector2::AdjustLength(double length) {
        this->length_ = length;
        RecalculateEndPoint_();
    }

    void Vector2::RecalculateEndPoint_() {
        end = conversion::PolarToCartesian2(origin, length_, angle_);
    }
}