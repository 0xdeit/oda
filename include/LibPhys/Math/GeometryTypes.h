//
// Created by dgt on 3/15/2021.
//

#ifndef ODA_GEOMETRYTYPES_H
#define ODA_GEOMETRYTYPES_H

namespace usc::types {
    struct Scalar2 {
        double first, last;
    };

    struct Scalar3 {
        double first, middle, last;
    };

    struct Cartesian2 {
        double x, y;
    };

    struct Cartesian3 {
        double x, y, z;
    };

    struct Polar {
        double radius, theta;
    };

    struct Spherical {
        double radius, theta, phi;
    };

    enum Angle {
        kRadians,
        kDegrees
    };
}

#endif //ODA_GEOMETRYTYPES_H
