#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(panic)
{
    TEST_BEGIN();

    // HalInitiateShutdown/panic is too dangerous to call
    // It would reboot/halt the system
    // Just verify the test framework works
    GEN_CHECK(TRUE, TRUE, "panic test skipped (would halt system)");

    TEST_END();
}
