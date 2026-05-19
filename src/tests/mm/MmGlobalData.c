#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(MmGlobalData)
{
    TEST_BEGIN();

    // MmGlobalData is an exported MMGLOBALDATA struct
    // Verify its address is in valid kernel memory
    BOOLEAN is_valid = MmIsAddressValid(&MmGlobalData);
    GEN_CHECK(is_valid, TRUE, "MmGlobalData address valid");

    TEST_END();
}
