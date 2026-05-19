#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(KeBugCheckEx)
{
    TEST_BEGIN();

    // KeBugCheckEx would crash the system - DO NOT CALL
    GEN_CHECK(TRUE, TRUE, "test skipped (would BSOD)");

    TEST_END();
}
