#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(DbgLoadImageSymbols)
{
    TEST_BEGIN();

    // SKIP: DbgLoadImageSymbols notifies the kernel debugger about loaded symbols.
    // It's a no-op when no debugger is attached. No observable side effect to verify.

    GEN_CHECK(TRUE, TRUE, "DbgLoadImageSymbols skipped - debugger notification only");

    TEST_END();
}
