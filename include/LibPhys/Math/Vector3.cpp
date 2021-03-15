//
// Created by dgt on 3/13/2021.
//

#include "LibPhys/Math/Vector3.h"
#include "math_helper.h"
#include <iostream>

namespace usc::types {

    Vector3::Vector3(Scalar3 &start, Scalar3 &end) {
        this->origin = start;
        this->end = end;
        // TODO: assign them accordingly
        this->phi_angle_ = 0;
        this->theta_angle_ = 0;
        this->length_ = 0;
    }

    void Vector3::Info() const {
        std::cout << "INIT VECTOR WITH INFO:" << "\n\t"
                  << "Components: {(" << this->origin.first << ", " << this->origin.middle << ", " << this->origin.last
                  << "), ("
                  << this->end.first << ", " << this->end.middle << ", " << this->end.last << ")}" << "\n\t"
                  << "Phi Angle: " << this->phi_angle_ << " deg.\n\t"
                  << "Phi Angle: " << conversion::DegreesToRadians(this->phi_angle_) << " rad.\n\t"
                  << "Theta Angle: " << this->theta_angle_ << " deg.\n\t"
                  << "Theta Angle: " << conversion::DegreesToRadians(this->theta_angle_) << " rad.\n\t"
                  << "Length: " << this->length_ << std::endl;
    }

}