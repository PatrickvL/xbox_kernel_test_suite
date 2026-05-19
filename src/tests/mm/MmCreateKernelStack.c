#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(MmCreateKernelStack)
{
    TEST_BEGIN();

    // --- Basic stack creation (returns top = highest address) ---
    PVOID stack = MmCreateKernelStack(0, FALSE);
    GEN_CHECK(stack != NULL, TRUE, "stack created");
    if (stack) {
        // Stack top-4 should be valid (first usable DWORD below top)
        GEN_CHECK(MmIsAddressValid((PUCHAR)stack - 4), TRUE, "top-4 valid");
        // Stack should be in kernel space (above 0x80000000 on Xbox)
        GEN_CHECK((ULONG)stack >= 0x80000000, TRUE, "in kernel space");
        // Default kernel stack is 12KB (3 pages), so top-12KB+4 should be valid
        GEN_CHECK(MmIsAddressValid((PUCHAR)stack - (12 * 1024) + 4), TRUE, "bottom of 12KB valid");
        MmDeleteKernelStack(stack, NULL);
    }

    // --- Multiple stacks are distinct ---
    PVOID stack1 = MmCreateKernelStack(0, FALSE);
    PVOID stack2 = MmCreateKernelStack(0, FALSE);
    GEN_CHECK(stack1 != NULL, TRUE, "stack1 created");
    GEN_CHECK(stack2 != NULL, TRUE, "stack2 created");
    if (stack1 && stack2) {
        GEN_CHECK(stack1 != stack2, TRUE, "stacks are distinct");
    }
    if (stack1) MmDeleteKernelStack(stack1, NULL);
    if (stack2) MmDeleteKernelStack(stack2, NULL);

    // --- Stack with large size hint ---
    stack = MmCreateKernelStack(PAGE_SIZE * 8, FALSE);
    if (stack) {
        // Larger stack: validate deeper
        GEN_CHECK(MmIsAddressValid((PUCHAR)stack - 4), TRUE, "large stack top valid");
        GEN_CHECK(MmIsAddressValid((PUCHAR)stack - PAGE_SIZE * 7), TRUE, "large stack deep valid");
        MmDeleteKernelStack(stack, NULL);
    }

    // --- DebugStack = TRUE (allocates from debug memory) ---
    stack = MmCreateKernelStack(0, TRUE);
    if (stack) {
        GEN_CHECK(stack != NULL, TRUE, "debug stack created");
        GEN_CHECK(MmIsAddressValid((PUCHAR)stack - 4), TRUE, "debug stack valid");
        MmDeleteKernelStack(stack, NULL);
    }

    TEST_END();
}
