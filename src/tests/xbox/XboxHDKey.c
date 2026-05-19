#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(XboxHDKey)
{
    TEST_BEGIN();

    // XboxHDKey is a 16-byte exported array (hard drive key)
    BOOLEAN is_valid = MmIsAddressValid((PVOID)XboxHDKey);
    GEN_CHECK(is_valid, TRUE, "HDKey address valid");

    TEST_END();
}
