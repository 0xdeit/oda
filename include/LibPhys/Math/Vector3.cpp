//
// Created by dgt on 3/13/2021.
//

#include "LibPhys/Math/Vector3.h"
#include "LibPhys/Math/Conversions.h"
#include <iostream>

namespace usc::types {

    Vector3::Vector3(Cartesian3 &start_point, Cartesian3 &end_point) {
        origin = start_point;
        end = end_point;
        Spherical sph = conversion::Cartesian3ToSpherical(origin, end);
        length_ = sph.radius;
        theta_angle_ = sph.theta;
        phi_angle_ = sph.phi;
    }

    Vector3::Vector3(Cartesian3 &origin, double length, double theta, double phi,
                     Angle angle_input) {
        this->origin = origin;
        length_ = length;

        if (angle_input == kRadians) {
            theta = conversion::RadiansToDegrees(theta);
            phi = conversion::RadiansToDegrees(phi);
        }

        theta_angle_ = theta;
        phi_angle_ = phi;

        end = conversion::SphericalToCartesian3(origin, length, theta, phi);
    }

    void Vector3::Info() const {
        std::cout << "[VECTOR3] INFO:" << "\n\t"
                  << "Components: {(" << origin.x << ", " << origin.y << ", " << origin.z
                  << "), (" << end.x << ", " << end.y << ", " << end.z << ")}" << "\n\t"
                  << "Polar Angle: " << theta_angle_ << " deg.\n\t"
                  << "Polar Angle: " << conversion::DegreesToRadians(theta_angle_) << " rad.\n\t"
                  << "Azimuth Angle: " << phi_angle_ << " deg.\n\t"
                  << "Azimuth Angle: " << conversion::DegreesToRadians(phi_angle_) << " rad.\n\t"
                  << "Length: " << length_ << std::endl;
    }

    void Vector3::Rotate(double theta, double phi, Angle angle_input) {
        if (angle_input == kRadians){
            theta = conversion::RadiansToDegrees(theta);
            phi = conversion::RadiansToDegrees(phi);
        }

        theta_angle_ = theta;
        phi_angle_ = phi;
        RecalculateEndPoint_();
    }

    void Vector3::Scale(double factor) {
        length_ *= factor;
        RecalculateEndPoint_();
    }

    void Vector3::AdjustLength(double length) {
        length_ = length;
        RecalculateEndPoint_();
    }

    void Vector3::RecalculateEndPoint_() {
        end = conversion::SphericalToCartesian3(origin, length_, theta_angle_, phi_angle_);
    }
}