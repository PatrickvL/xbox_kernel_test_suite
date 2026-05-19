#include <xboxkrnl/xboxkrnl.h>

#include "global.h" // for NV2A_MMIO_BASE var
#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(AvSendTVEncoderOption)
{
    TEST_BEGIN();

    // Query AV pack type (option 6 = AV_QUERY_AV_CAPABILITIES)
    ULONG result = 0;
    AvSendTVEncoderOption((void *)NV2A_MMIO_BASE, 6, 0, &result);

    // Result should be a valid AV_PACK_* value (0-6 range)
    GEN_CHECK(result <= 6, TRUE, "AV pack type in valid range");

    // Query again to verify consistency
    ULONG result2 = 0;
    AvSendTVEncoderOption((void *)NV2A_MMIO_BASE, 6, 0, &result2);
    GEN_CHECK(result2, result, "consistent result on repeated query");

    TEST_END();
}
