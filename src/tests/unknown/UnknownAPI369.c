#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(UnknownAPI369)
{
    TEST_BEGIN();

    // SKIP: This kernel export has no known documentation or signature.

    GEN_CHECK(TRUE, TRUE, "UnknownAPI369 skipped - undocumented");

    TEST_END();
}
