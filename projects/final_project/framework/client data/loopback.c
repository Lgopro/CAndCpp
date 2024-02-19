/*
 * loopback - example loopback device using BUSE
 * Copyright (C) 2013 Adam Cozzette
 *
 * This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#define _GNU_SOURCE
#define _LARGEFILE64_SOURCE

#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mount.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "buse.h"

static int fd;

/*Displays the correct usage of the program.*/

static void usage(void)
{
    fprintf(stderr, "Usage: loopback <phyical device> <virtual device>\n");
}

/*
    Implements the BUSE read operation. 
    Reads data from the physical block device at the specified offset 
    and stores it in the buffer.
*/

static int loopback_read(void *buf, u_int32_t len, u_int64_t offset, void *userdata)
{
    int bytes_read;
    (void)(userdata);
    printf("loopback_read length is: %f and the offset is: %f\n", len, offset);
    lseek64(fd, offset, SEEK_SET);
    while (len > 0) {
        bytes_read = read(fd, buf, len);
        assert(bytes_read > 0);
        len -= bytes_read;
        buf = (char *) buf + bytes_read;
    }

    return 0;
}

/*
    Implements the BUSE write operation. 
    Writes data from the buffer to the physical 
    block device at the specified offset.
*/

static int loopback_write(const void *buf, u_int32_t len, u_int64_t offset, void *userdata)
{
    int bytes_written;
    (void)(userdata);
    printf("loopback_write length is: %f and the offset is: %f\n", len, offset);
    lseek64(fd, offset, SEEK_SET);
    while (len > 0) 
    {
        bytes_written = write(fd, buf, len);
        assert(bytes_written > 0);
        len -= bytes_written;
        buf = (char *) buf + bytes_written;
    }

    return 0;
}


/*
Defines a structure (struct buse_operations) 
containing function pointers for BUSE operations, 
including read and write.
*/

static struct buse_operations bop = 
{
    .read = loopback_read,
    .write = loopback_write
};

/*    
    int main(int argc, char *argv[]): Entry point of the program.
    Checks if the correct number of command-line arguments (3) is provided. 
    If not, it displays the correct usage and exits.
    Opens the specified physical block device file (argv[1]) in read/write mode with large file support.
    Verifies that the opened file descriptor corresponds to a block device using fstat.
    Determines the size of the underlying block device using the ioctl system call with BLKGETSIZE64.
    Prints the size of the block device.
    Sets the bop.size member to the size of the block device.
    Calls buse_main with the specified virtual block device file (argv[2]) 
    and the BUSE operations structure (bop).
*/

int main(int argc, char *argv[])
{
    struct stat buf;
    int err;
    int64_t size;

    if (argc != 3) {
        usage();
        return -1;
    }

    fd = open(argv[1], O_RDWR|O_LARGEFILE);
    assert(fd != -1);

    /* Let's verify that this file is actually a block device. We could support
     * regular files, too, but we don't need to right now. */
    fstat(fd, &buf);
    assert(S_ISBLK(buf.st_mode));

    /* Figure out the size of the underlying block device. */
    err = ioctl(fd, BLKGETSIZE64, &size);
    assert(err != -1);
    (void)err;
    fprintf(stderr, "The size of this device is %ld bytes.\n", size);
    bop.size = size;

    buse_main(argv[2], &bop, NULL);

    return 0;
}
