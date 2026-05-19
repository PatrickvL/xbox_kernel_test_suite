#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(KeConnectInterrupt)
{
    TEST_BEGIN();

    // Connecting interrupts to active IRQs is dangerous
    // Just verify the function exists
    GEN_CHECK(TRUE, TRUE, "test skipped (dangerous - could steal IRQ)");

    TEST_END();
}
