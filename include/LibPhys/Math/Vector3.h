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
        void RecalculateEndPoint_();
    public:
        Cartesian3 origin{};
        Cartesian3 end{};

        Vector3(Cartesian3 &start_point, Cartesian3 &end_point);

        Vector3(Cartesian3 &origin, double length, double theta, double phi,
                Angle angle_input = kDegrees);

        void Info() const;

        void Rotate(double theta, double phi, Angle angle_input = kDegrees);

        void Scale(double factor);

        void AdjustLength(double length);
    };
}
#endif //ODA_VECTOR3_H
