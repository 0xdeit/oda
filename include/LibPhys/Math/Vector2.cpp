//
// Created by dgt on 3/13/2021.
//

#include "LibPhys/Math/Vector2.h"
#include <iostream>
#include <cmath>

namespace usc::types {
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