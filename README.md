# template
Template repository with common workflows for future clone

## Portal image selection

The vDevice Image Tests and Coverage workflow accepts a portal `build_number`.
It lists artifacts from the `VDEVICE-Middleware-Github` job and downloads the
timestamped `build-images/vdevice-test-image-vdevice_x86-64-mw-<timestamp>.bin`
and matching `.rootfs.ext4`. No image filenames or timestamps need to be supplied.
The workflow fails if either file is missing, multiple candidates exist, or their
timestamps differ. Other artifacts, including `bzImage` and untimestamped images,
are ignored.

Portal authentication uses `RDK_PORTAL_USERNAME` (secret or repository variable)
and the `RDK_PORTAL_TOKEN` secret. The downloaded images are used by the existing
QEMU tests and coverage steps.
