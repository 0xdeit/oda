//
// Created by dgt on 3/13/2021.
//

#ifndef ODA_CONVERSIONS_H
#define ODA_CONVERSIONS_H

#include "LibPhys/Math/GeometryTypes.h"
#include "LibPhys/Math/Constants.h"
#include <cmath>

namespace usc::conversion {
    static double RadiansToDegrees(double radians) {
        return radians * (180 / types::pi);
    }

    static double DegreesToRadians(double degrees) {
        return degrees * (types::pi / 180);
    }

    // Convert cartesian coordinates with the origin at (0, 0) and  end in (x, y) form
    // to polar coordinates (r, theta).
    static types::Polar
    Cartesian2ToPolar(double x, double y, types::Angle angle_output = types::kDegrees) {
        double radius = sqrt((pow(x, 2) + pow(y, 2)));

        // atan2 returns in radians.
        double theta = atan2(y, x);

        // give user the angle type they want
        if (angle_output == types::kDegrees) {
            theta = RadiansToDegrees(theta);
        }

        return types::Polar{radius, theta};
    }

    // Convert cartesian coordinates with given origin and end in (x, y) form
    // to polar coordinates (r, theta).
    static types::Polar
    Cartesian2ToPolar(types::Cartesian2 &origin, types::Cartesian2 &end,
                      types::Angle angle_output = types::kDegrees) {
        double delta_x = end.x - origin.x;
        double delta_y = end.y - origin.y;

        double radius = sqrt((pow(delta_x, 2) + pow(delta_y, 2)));

        // atan2 returns the arc in radians.
        double theta = atan2(delta_y, delta_x);

        // give user the angle type they want
        if (angle_output == types::kDegrees) {
            theta = RadiansToDegrees(theta);
        }

        return types::Polar{radius, theta};
    }

    // Convert polar coordinates (r, theta) to cartesian coordinates (x, y)
    static types::Cartesian2
    PolarToCartesian2(double length, double angle, types::Angle angle_input = types::kDegrees) {
        // Both cos() and sin() take the angle param in radians.
        if (angle_input == types::kDegrees) {
            angle = DegreesToRadians(angle);
        }

        double x = length * cos(angle);
        double y = length * sin(angle);

        return types::Cartesian2{x, y};
    }

    // Convert polar coordinates (r, theta) to cartesian coordinates (x, y)
    static types::Cartesian2
    PolarToCartesian2(types::Cartesian2 &origin, double length, double angle,
                      types::Angle angle_input = types::kDegrees) {
        // Both cos() and sin() take the angle param in radians.
        if (angle_input == types::kDegrees) {
            angle = DegreesToRadians(angle);
        }

        // the original method assumes our origin to be (0, 0)
        // so, to get our expected end point from a given origin, we have to take its
        // components into account
        double delta_x = (length * cos(angle)) + origin.x;
        double delta_y = (length * cos(angle)) + origin.y;

        return types::Cartesian2{delta_x, delta_y};
    }

    // Convert spherical coordinates (radial distance, polar angle, azimuth angle)
    // with the origin at (0, 0, 0) to cartesian (x, y, z)
    // Names for the spherical components come from the ISO 80000-2:2019 convention (src: Wikipedia)
    static types::Cartesian3
    SphericalToCartesian3(double radius, double theta, double phi,
                          types::Angle angle_input = types::kDegrees) {
        // Both cos() and sin() take the angle param in radians.
        if (angle_input == types::kDegrees) {
            theta = DegreesToRadians(theta);
            phi = DegreesToRadians(phi);
        }

        double x = (radius * sin(theta) * cos(phi));
        double y = (radius * sin(theta) * sin(phi));
        double z = (radius * cos(theta));

        return types::Cartesian3{x, y, z};
    }

    // Convert spherical coordinates (radial distance, polar angle, azimuth angle)
    // with a given origin (x0, y0, z0) to cartesian (x, y, z)
    // Names for the spherical components come from the ISO 80000-2:2019 convention (src: Wikipedia)
    static types::Cartesian3
    SphericalToCartesian3(types::Cartesian3 &origin, double radius, double theta, double phi,
                          types::Angle angle_input = types::kDegrees) {
        // Both cos() and sin() take the angle param in radians.
        if (angle_input == types::kDegrees) {
            theta = DegreesToRadians(theta);
            phi = DegreesToRadians(phi);
        }

        double x = (radius * sin(theta) * cos(phi)) + origin.x;
        double y = (radius * sin(theta) * sin(phi)) + origin.y;
        double z = (radius * cos(theta)) + origin.z;

        return types::Cartesian3{x, y, z};
    }

    // Convert cartesian (x, y, z) to spherical coordinates (radial distance, polar angle, azimuth angle)
    static types::Spherical
    Cartesian3ToSpherical(double x, double y, double z) {
        double radius = sqrt((pow(x, 2) + pow(y, 2) + pow(z, 2)));
        double theta = atan2(sqrt(pow(x, 2) + pow(y, 2)), z);
        double phi = atan2(y, x);

        return types::Spherical{radius, theta, phi};
    }

    // Convert cartesian coordinates (x, y, z), given a start and end point,
    // to spherical coordinates (radial distance, polar angle, azimuth angle)
    static types::Spherical
    Cartesian3ToSpherical(types::Cartesian3 &start, types::Cartesian3 &end) {
        double delta_x = end.x - start.x;
        double delta_y = end.y - start.y;
        double delta_z = end.z - start.z;

        double radius = sqrt((pow(delta_x, 2) + pow(delta_y, 2) + pow(delta_z, 2)));
        // atan2 returns arc in radians
        double theta = atan2(sqrt(pow(delta_x, 2) + pow(delta_y, 2)), delta_z);
        // atan2 returns arc in radians
        double phi = atan2(delta_y, delta_x);

        // our default for angles is degrees
        theta = RadiansToDegrees(theta);
        phi = RadiansToDegrees(phi);

        return types::Spherical{radius, theta, phi};
    }
}

#endif //ODA_CONVERSIONS_H
