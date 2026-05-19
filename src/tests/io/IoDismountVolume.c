#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(IoDismountVolume)
{
    TEST_BEGIN();

    // SKIP: IoDismountVolume unmounts a filesystem volume from a device object.
    // Calling this on any mounted volume would unmount it, potentially
    // making the system unstable or preventing further file I/O.
    // Cannot be tested safely without a dedicated test volume.

    GEN_CHECK(TRUE, TRUE, "IoDismountVolume skipped - would unmount real volume");

    TEST_END();
}
