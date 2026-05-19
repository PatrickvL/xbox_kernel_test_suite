#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(MmDbgQueryAvailablePages)
{
    TEST_BEGIN();

    // DEVKIT-only. Should return number of available debug pages.
    ULONG pages = MmDbgQueryAvailablePages();
    // Should be >= 0 (could be 0 on retail)
    GEN_CHECK(pages >= 0, TRUE, "non-negative pages");

    TEST_END();
}
