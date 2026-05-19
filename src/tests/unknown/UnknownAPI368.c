#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(UnknownAPI368)
{
    TEST_BEGIN();

    // SKIP: This kernel export has no known documentation or signature.

    GEN_CHECK(TRUE, TRUE, "UnknownAPI368 skipped - undocumented");

    TEST_END();
}
