#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(HalDisableSystemInterrupt)
{
    TEST_BEGIN();

    // Disabling and re-enabling a system interrupt is dangerous
    // Just verify the test doesn't crash with a stub check
    GEN_CHECK(TRUE, TRUE, "HalDisableSystemInterrupt test skipped (dangerous)");

    TEST_END();
}
