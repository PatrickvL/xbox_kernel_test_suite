#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(XboxHardwareInfo)
{
    TEST_BEGIN();

    // XboxHardwareInfo is an exported XBOX_HARDWARE_INFO structure
    // Flags field contains hardware revision info
    GEN_CHECK(XboxHardwareInfo.Flags != 0, TRUE, "Flags non-zero");
    // GpuRevision should be a valid NV2A revision
    GEN_CHECK(XboxHardwareInfo.GpuRevision != 0, TRUE, "GpuRevision non-zero");

    TEST_END();
}
