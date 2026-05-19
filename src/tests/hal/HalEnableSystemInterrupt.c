#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(HalEnableSystemInterrupt)
{
    TEST_BEGIN();

    // Enabling system interrupts for arbitrary vectors is dangerous
    GEN_CHECK(TRUE, TRUE, "HalEnableSystemInterrupt test skipped (dangerous)");

    TEST_END();
}
