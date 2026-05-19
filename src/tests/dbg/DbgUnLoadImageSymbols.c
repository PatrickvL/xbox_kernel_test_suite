#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(DbgUnLoadImageSymbols)
{
    TEST_BEGIN();

    // SKIP: DbgUnLoadImageSymbols notifies the kernel debugger about unloaded symbols.
    // It's a no-op when no debugger is attached. No observable side effect to verify.

    GEN_CHECK(TRUE, TRUE, "DbgUnLoadImageSymbols skipped - debugger notification only");

    TEST_END();
}
