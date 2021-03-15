//
// Created by dgt on 3/13/2021.
//

#include "LibPhys/Math/Vector2.h"
#include <iostream>
#include <cmath>

// TODO: add function comments.

namespace usc::types {
    double Vector2::AngleBetweenScalar2(Scalar2 &start_point, Scalar2 &end_point, AngleType angle_type) {
        double result = atan2((end_point.last - start_point.last), (end_point.first - start_point.first));
        switch (angle_type) {
            case kRadians:
                return result;
            case kDegrees:
                return conversion::RadiansToDegrees(result);
        }
        // fix for Warning C4715 in MSVC:
        return 0;
    }

    void Vector2::Info(bool clockwise_angle) const {
        std::cout << "VECTOR2 WITH INFO:" << "\n\t"
                  << "Components: {(" << this->origin.x << ", " << this->origin.y << "), ("
                  << this->end.x << ", " << this->end.y << ")}" << "\n\t"
                  << "Angle: " << (clockwise_angle ? this->angle_ : this->angle_ + circumference_degrees) << " deg.\n\t"
                  << "Angle: " << (clockwise_angle ? conversion::DegreesToRadians(this->angle_) :
                                   conversion::DegreesToRadians(this->angle_) + circumference_degrees) << " rad.\n\t"
                  << "Length: " << this->length_ << std::endl;
    }

    Vector2::Vector2(Cartesian2 &start_point, Cartesian2 &end_point) {
        this->origin = start_point;
        this->end = end_point;
        Polar polar = conversion::CartesianToPolar(this->origin, this->end);
        this->length_ = polar.radius;
        this->angle_ = polar.theta;
    }

    Vector2::Vector2(Cartesian2 &origin, double length, double theta, AngleType angle_type) {
        switch (angle_type) {
            case kDegrees:
                this->angle_ = theta;
                break;
            case kRadians:
                this->angle_ = conversion::RadiansToDegrees(theta);
                break;
        }
        this->length_ = length;
        this->origin = origin;
        this->end = conversion::PolarToCartesian(length, this->angle_);
    }

    void Vector2::Rotate(double angle, AngleType angle_type) {
        switch (angle_type) {
            case kDegrees:
                this->angle_ += angle;
                break;
            case kRadians:
                this->angle_ += conversion::RadiansToDegrees(angle);
                break;
        }
        this->end = conversion::PolarToCartesian(this->length_, this->angle_);
    }

    void Vector2::Scale(double factor) {
        this->length_ *= factor;
        this->end = conversion::PolarToCartesian(this->length_, this->angle_);
    }

    void Vector2::AdjustLength(double length) {
        this->length_ = length;
        this->end = conversion::PolarToCartesian(this->length_, this->angle_);
    }
}