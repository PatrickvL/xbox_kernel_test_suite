#include <xboxkrnl/xboxkrnl.h>

#include "util/output.h"
#include "assertions/defines.h"

TEST_FUNC(KeRemoveEntryDeviceQueue)
{
    TEST_BEGIN();

    KDEVICE_QUEUE queue;
    KDEVICE_QUEUE_ENTRY entry1, entry2;

    KeInitializeDeviceQueue(&queue);
    KeInsertDeviceQueue(&queue, &entry1); // starts device
    KeInsertDeviceQueue(&queue, &entry2); // queued

    // Remove specific entry
    // NOTE: nxdk declares second param as PKDEVICE_QUEUE (header bug), cast needed
    BOOLEAN was_queued = KeRemoveEntryDeviceQueue(&queue, (PKDEVICE_QUEUE)&entry2);
    GEN_CHECK(was_queued, TRUE, "entry was in queue");

    // Try to remove again (not in queue anymore)
    was_queued = KeRemoveEntryDeviceQueue(&queue, (PKDEVICE_QUEUE)&entry2);
    GEN_CHECK(was_queued, FALSE, "entry not in queue");

    // Clean up
    KeRemoveDeviceQueue(&queue);

    TEST_END();
}
