//
// Created by dgt on 3/14/2021.
//

#include "Vector2_test.h"
#include "libphys/math/Vector2.h"
#include "utils/print_utils.h"

namespace usc::test {
    static void Vector2Methods() {
        usc::types::Scalar2 sca1{-1.5, 3.2};
        usc::types::Scalar2 sca2{4, -6.7};
        usc::types::Vector2 vector{sca1, sca2};

        utils::TestPrintLn("[START] Running Vector2 tests for methods...");
        utils::TestPrintLn("Starting information...");
        vector.Info();

        utils::PrintLn("Rotating vec +5 degrees...");
        vector.Rotate(5);
        vector.Info();

        utils::PrintLn("Rotating vec -0.15 radians...");
        vector.Rotate(-0.15, usc::types::kRadians);
        vector.Info();

        utils::PrintLn("Scale vec by a factor of 2...");
        vector.Scale(2);
        vector.Info();

        utils::PrintLn("Resetting vec to 5 length");
        vector.AdjustLength(5);
        vector.Info();

        utils::TestPrintLn("[END] Vector2 tests finished running...");
    }
}