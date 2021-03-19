//
// Created by dgt on 3/12/2021.
//

#include "LibPhys/Math/Vector3.h"
#include "LibPhys/Math/Conversions.h"

// dev purposes only
namespace ut = usc::types;
namespace uc = usc::conversion;

int main() {
    auto origin = ut::Cartesian3{0, 0, 0};
    auto pt_a = ut::Cartesian3{1, 2, 1};
    auto pt_b = ut::Cartesian3{5, 4, 2};

    auto vec3_a = ut::Vector3(origin, pt_a);
    auto vec3_b = ut::Vector3(origin, pt_b);
    auto vec3_ab = ut::Vector3(pt_a, pt_b);

    vec3_a.Info();
    vec3_b.Info();
    vec3_ab.Info();

    return 0;
}