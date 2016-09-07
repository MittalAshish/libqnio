/*
 * Network IO library for VxHS QEMU block driver (Veritas Technologies)
 *
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the COPYING file in the top-level directory.
 *
 * Contributions after 2014-08-15 are licensed under the terms of the
 * GNU GPL, version 2 or (at your option) any later version.
 */

#ifndef QNIO_API_H
#define QNIO_API_H

#include <inttypes.h>

typedef enum {
    VDISK_AIO_READ,
    VDISK_AIO_WRITE,
    VDISK_STAT,
    VDISK_TRUNC,
    VDISK_AIO_FLUSH,
    VDISK_AIO_RECLAIM,
    VDISK_GET_GEOMETRY,
    VDISK_CHECK_IO_FAILOVER_READY,
    VDISK_AIO_LAST_CMD
} VDISKAIOCmd;

/*
 * API for consumers of libqnioshim.so
 */
void *qnio_iio_init(void *cb);
int32_t qnio_open_iio_conn(void *qnio_ctx, const char *uri, uint32_t flags);
int32_t qnio_iio_devopen(void *qnio_ctx, int32_t cfd, const char *devpath,
                         uint32_t flags);
int32_t qnio_iio_devclose(void *qnio_ctx, int32_t cfd, uint32_t rfd);
int32_t qnio_iio_writev(void *qnio_ctx, uint32_t rfd, struct iovec *iov,
                        int iovcnt, uint64_t offset, void *ctx, uint32_t flags);
int32_t qnio_iio_readv(void *qnio_ctx, uint32_t rfd, struct iovec *iov,
                       int iovcnt, uint64_t offset, void *ctx, uint32_t flags);
int32_t qnio_iio_ioctl(void *apictx, uint32_t rfd, uint32_t opcode, void *in,
                       void *ctx, uint32_t flags);
int32_t qnio_iio_close(void *qnio_ctx, uint32_t cfd);
int32_t qnio_iio_read(void *qnio_ctx, uint32_t rfd, unsigned char *buf,
                      uint64_t size, uint64_t offset, void *ctx,
                      uint32_t flags);
uint32_t qnio_iio_extract_msg_error(void * ptr);
uint32_t qnio_iio_extract_msg_opcode(void * ptr);
size_t qnio_iio_extract_msg_size(void * ptr);
void *qnio_ck_initialize_lock(void);
void qnio_ck_spin_lock(void *ptr);
void qnio_ck_spin_unlock(void *ptr);
void qnio_ck_destroy_lock(void *ptr);
void qnio_iio_release_msg(void *ptr);

#endif
