#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(DbgPrompt)
{
    TEST_BEGIN();

    // SKIP: DbgPrompt sends a prompt string to the debugger and waits for input.
    // This blocks indefinitely without a kernel debugger attached.
    // Cannot be tested safely in an automated environment.

    GEN_CHECK(TRUE, TRUE, "DbgPrompt skipped - would block waiting for debugger input");

    TEST_END();
}
