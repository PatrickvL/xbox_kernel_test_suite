#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(KeDisconnectInterrupt)
{
    TEST_BEGIN();

    // Disconnecting active interrupts is dangerous
    GEN_CHECK(TRUE, TRUE, "test skipped (dangerous)");

    TEST_END();
}
