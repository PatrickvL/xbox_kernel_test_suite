#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(MmDbgAllocateMemory)
{
    TEST_BEGIN();

    // MmDbgAllocateMemory is a DEVKIT-only function
    // On retail, it may return NULL or not be available
    // Test conservatively - just ensure it doesn't crash
    PVOID mem = MmDbgAllocateMemory(PAGE_SIZE, PAGE_READWRITE);
    if (mem) {
        // If it succeeded, verify it's usable
        BOOLEAN is_valid = MmIsAddressValid(mem);
        GEN_CHECK(is_valid, TRUE, "dbg memory valid");
        *(volatile ULONG*)mem = 0xDBDBDBDB;
        GEN_CHECK(*(volatile ULONG*)mem, 0xDBDBDBDB, "dbg memory writable");
        MmDbgFreeMemory(mem, PAGE_SIZE);
    }

    TEST_END();
}
