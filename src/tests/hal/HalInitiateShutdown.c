#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(HalInitiateShutdown)
{
    TEST_BEGIN();

    // HalInitiateShutdown would shut down the system - DO NOT CALL
    GEN_CHECK(TRUE, TRUE, "test skipped (would shut down system)");

    TEST_END();
}
