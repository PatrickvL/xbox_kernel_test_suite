#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(MmDbgReleaseAddress)
{
    TEST_BEGIN();

    // DEVKIT-only. Test that it doesn't crash with valid debug memory.
    PVOID mem = MmDbgAllocateMemory(PAGE_SIZE, PAGE_READWRITE);
    if (mem) {
        MmDbgReleaseAddress(mem, NULL);
        GEN_CHECK(TRUE, TRUE, "release completed");
        // Note: after release, the memory may still need to be freed
        MmDbgFreeMemory(mem, PAGE_SIZE);
    }

    TEST_END();
}
