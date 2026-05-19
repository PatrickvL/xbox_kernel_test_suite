#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(MmDbgWriteCheck)
{
    TEST_BEGIN();

    // MmDbgWriteCheck verifies a virtual address range is writable.
    // Returns the address if writable, NULL otherwise.
    PVOID mem = MmAllocateSystemMemory(PAGE_SIZE, PAGE_READWRITE);
    GEN_CHECK(mem != NULL, TRUE, "allocation");
    if (mem) {
        PVOID result = MmDbgWriteCheck(mem, NULL);
        GEN_CHECK(result, mem, "writable memory passes check");
        MmFreeSystemMemory(mem, PAGE_SIZE);
    }

    TEST_END();
}
