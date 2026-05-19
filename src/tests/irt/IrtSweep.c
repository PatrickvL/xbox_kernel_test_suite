#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(IrtSweep)
{
    TEST_BEGIN();

    // SKIP: IrtSweep is an infrared transceiver sweep/scan API.
    // Requires IR hardware. No known prototype in public headers.

    GEN_CHECK(TRUE, TRUE, "IrtSweep skipped - IR hardware required");

    TEST_END();
}
