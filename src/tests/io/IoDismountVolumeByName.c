#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(IoDismountVolumeByName)
{
    TEST_BEGIN();

    // SKIP: IoDismountVolumeByName unmounts a volume by its device name string.
    // Same safety concerns as IoDismountVolume - would unmount real filesystems.

    GEN_CHECK(TRUE, TRUE, "IoDismountVolumeByName skipped - would unmount real volume");

    TEST_END();
}
