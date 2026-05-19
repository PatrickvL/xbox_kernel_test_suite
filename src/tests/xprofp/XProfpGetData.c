#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(XProfpGetData)
{
    TEST_BEGIN();

    // SKIP: XProfpGetData retrieves profiling data and is only available
    // in debug/checked kernel builds. The API is not exported in retail kernels.

    GEN_CHECK(TRUE, TRUE, "XProfpGetData skipped - debug kernel only");

    TEST_END();
}
