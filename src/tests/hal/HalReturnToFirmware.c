#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(HalReturnToFirmware)
{
    TEST_BEGIN();

    // HalReturnToFirmware would reboot/shutdown - DO NOT CALL
    GEN_CHECK(TRUE, TRUE, "test skipped (would reboot system)");

    TEST_END();
}
