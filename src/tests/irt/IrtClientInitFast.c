#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(IrtClientInitFast)
{
    TEST_BEGIN();

    // SKIP: IrtClientInitFast is an infrared transceiver (IR remote) initialization API.
    // It requires IR hardware to be present and is not available on all Xbox revisions.
    // No known prototype in public headers. Cannot test without hardware.

    GEN_CHECK(TRUE, TRUE, "IrtClientInitFast skipped - IR hardware required");

    TEST_END();
}
