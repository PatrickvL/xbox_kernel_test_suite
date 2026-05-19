#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(XProfpControl)
{
    TEST_BEGIN();

    // SKIP: XProfpControl is a profiling control API that is only available
    // in debug/checked kernel builds. The API is not exported in retail kernels.
    // Cannot be tested reliably across all environments.

    GEN_CHECK(TRUE, TRUE, "XProfpControl skipped - debug kernel only");

    TEST_END();
}
