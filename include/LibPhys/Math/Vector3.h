//
// Created by dgt on 3/13/2021.
//

#ifndef ODA_VECTOR3_H
#define ODA_VECTOR3_H

#include "LibPhys/Math/GeometryTypes.h"

namespace usc::types {
    class Vector3 {
    private:
        double phi_angle_;
        double theta_angle_;
        double length_;
    public:
        Scalar3 origin{};
        Scalar3 end{};

        Vector3(Scalar3 &start, Scalar3 &end);

        // TODO: Constructor with angles

        void Info() const;
    };
}
#endif //ODA_VECTOR3_H
