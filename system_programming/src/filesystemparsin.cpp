

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/fs.h>
#include <cstring>
#include <ext2fs/ext2_fs.h>


#define EXT2_SUPER_MAGIC	0xEF53
#define BLOCK_OFFSET(block) (BASE_OFFSET+(block-1)*block_size)
#define EXT2_NAME_LEN 255


#define BASE_OFFSET 1024                   /* locates beginning of the super block (first group) */
#define FD_DEVICE "/dev/ram0"               /* the floppy disk device */

static unsigned int block_size = 0;        /* block size (to be calculated) */
void PrintGroup();
int PrintSuperBlock();
static void read_dir(int, const struct ext2_inode*, const struct ext2_group_desc*);
static void read_inode(int, int, const struct ext2_group_desc*, struct ext2_inode*);
int ReadDir();

int main()
{
	struct ext2_super_block super;
	struct ext2_group_desc group;
	struct ext2_inode inode;
	int fd;
	int i;

	
 
	if ((fd = open(FD_DEVICE, O_RDONLY)) < 0) {
		perror(FD_DEVICE);
		exit(1);  
	}

	

	lseek(fd, BASE_OFFSET, SEEK_SET); 
	read(fd, &super, sizeof(super));

	if (super.s_magic != EXT2_SUPER_MAGIC) {
		fprintf(stderr, "Not a Ext2 filesystem\n");
		exit(1);
	}
		
	block_size = 1024 << super.s_log_block_size;

	

	lseek(fd, BASE_OFFSET + block_size, SEEK_SET);
	read(fd, &group, sizeof(group));

	/* read root inode */
	/*  PrintSuperBlock();  */
	/* PrintGroup(); */
	/* read_dir(fd, &inode, &group); */
	/* read_dir(fd, &inode, &group);
	read_inode(fd, 2, &group, &inode);  */
	/* ReadDir(); */

	read_dir(fd, &inode, &group);
	return 0;
}

void PrintGroup()
{
	struct ext2_group_desc group;
	int fd;

	/* open floppy device */

	if ((fd = open(FD_DEVICE, O_RDONLY)) < 0) {
		perror(FD_DEVICE);
		exit(1);  /* error while opening the floppy device */
	}


	/* read group descriptor */

	lseek(fd, BASE_OFFSET + block_size, SEEK_SET);
	read(fd, &group, sizeof(group));
	close(fd);

	printf("Reading first group-descriptor from device " FD_DEVICE ":\n"
	       "Blocks bitmap block: %u\n"
	       "Inodes bitmap block: %u\n"
	       "Inodes table block : %u\n"
	       "Free blocks count  : %u\n"
	       "Free inodes count  : %u\n"
	       "Directories count  : %u\n"
	       ,
	       group.bg_block_bitmap,
	       group.bg_inode_bitmap,
	       group.bg_inode_table,
	       group.bg_free_blocks_count,
	       group.bg_free_inodes_count,
	       group.bg_used_dirs_count);    /* directories count */
	
}






int PrintSuperBlock()
{
	struct ext2_super_block super;
	int fd;

	/* open floppy device */

	if ((fd = open(FD_DEVICE, O_RDONLY)) < 0) {
		perror(FD_DEVICE);
		exit(1);  /* error while opening the floppy device */
	}

	/* read super-block */

	lseek(fd, BASE_OFFSET, SEEK_SET); 
	read(fd, &super, sizeof(super));
	close(fd);

	if (super.s_magic != EXT2_SUPER_MAGIC) {
		fprintf(stderr, "Not a Ext2 filesystem\n");
		exit(1);
	}
		
	block_size = 1024 << super.s_log_block_size;

	printf("Reading super-block from device " FD_DEVICE ":\n"
	       "Inodes count            : %u\n"
	       "Blocks count            : %u\n"
	       "Reserved blocks count   : %u\n"
	       "Free blocks count       : %u\n"
	       "Free inodes count       : %u\n"
	       "First data block        : %u\n"
	       "Block size              : %u\n"
	       "Blocks per group        : %u\n"
	       "Inodes per group        : %u\n"
	       "Creator OS              : %u\n"
	       "First non-reserved inode: %u\n"
	       "Size of inode structure : %hu\n"
	       ,
	       super.s_inodes_count,  
	       super.s_blocks_count,
	       super.s_r_blocks_count,     /* reserved blocks count */
	       super.s_free_blocks_count,
	       super.s_free_inodes_count,
	       super.s_first_data_block,
	       block_size,
	       super.s_blocks_per_group,
	       super.s_inodes_per_group,
	       super.s_creator_os,
	       super.s_first_ino,          /* first non-reserved inode */
	       super.s_inode_size);
	
	exit(0);
} /* main() */





int ReadDir()
{
	struct ext2_super_block super;
	struct ext2_group_desc group;
	struct ext2_inode inode;
	int fd;

	/* open floppy device */

	if ((fd = open(FD_DEVICE, O_RDONLY)) < 0) {
		perror(FD_DEVICE);
		exit(1);  /* error while opening the floppy device */
	}

	/* read super-block */

	lseek(fd, BASE_OFFSET, SEEK_SET); 
	read(fd, &super, sizeof(super));

	if (super.s_magic != EXT2_SUPER_MAGIC) {
		fprintf(stderr, "Not a Ext2 filesystem\n");
		exit(1);
	}
		
	block_size = 1024 << super.s_log_block_size;

	/* read group descriptor */

	lseek(fd, BASE_OFFSET + block_size, SEEK_SET);
	read(fd, &group, sizeof(group));

	/* show entries in the root directory */

	read_inode(fd, 2, &group, &inode);   /* read inode 2 (root directory) */
	read_dir(fd, &inode, &group);

	close(fd);
	exit(0);
} /* main() */

 
void read_inode(int fd, int inode_no, const struct ext2_group_desc *group, struct ext2_inode *inode)
{
	int i = 0;
	lseek(fd, BLOCK_OFFSET(group->bg_inode_table)+(inode_no-1)*sizeof(struct ext2_inode), 
	      SEEK_SET);
	read(fd, inode, sizeof(struct ext2_inode));

	printf("Reading root inode\n"
	       "File mode: %hu\n"
	       "Owner UID: %hu\n"
	       "Size     : %u bytes\n"
	       "Blocks   : %u\n"
	       ,
	       inode->i_mode,
	       inode->i_uid,
	       inode->i_size,
	       inode->i_blocks);

	for(i=0; i<EXT2_N_BLOCKS; i++)
	{
		if (i < EXT2_NDIR_BLOCKS)         /* direct blocks */
		{
			printf("Block %2u : %u\n", i, inode->i_block[i]);
		}
		else if (i == EXT2_IND_BLOCK)     /* single indirect block */
		{
			printf("Single   : %u\n", inode->i_block[i]);
		}
		else if (i == EXT2_DIND_BLOCK)    /* double indirect block */
		{
			printf("Double   : %u\n", inode->i_block[i]);
		}
		else if (i == EXT2_TIND_BLOCK)    /* triple indirect block */
		{
			printf("Triple   : %u\n", inode->i_block[i]);
		}
	}

} /* read_inode() */


static void read_dir(int fd, const struct ext2_inode *inode, const struct ext2_group_desc *group)
{
    void *block;

    if (S_ISDIR(inode->i_mode)) 
    {
        struct ext2_dir_entry_2 *entry;
        unsigned int size = 0;

        if ((block = malloc(block_size)) == NULL) { /* allocate memory for the data block */
            fprintf(stderr, "Memory error\n");
            close(fd);
            exit(1);
        }

        lseek(fd, BLOCK_OFFSET(inode->i_block[0]), SEEK_SET);
        read(fd, block, block_size); /* read block from disk */

        while (size < inode->i_size) 
        {
            entry = (struct ext2_dir_entry_2 *) block; /* set entry to the beginning of the block */

            while ((size < inode->i_size) && entry->inode) 
            {
                char file_name[EXT2_NAME_LEN + 1];
                memcpy(file_name, entry->name, entry->name_len);
                file_name[entry->name_len] = 0; /* append null character to the file name */
                printf("%10u %s\n", entry->inode, file_name);

                /* Move to the next entry properly, accounting for variable entry lengths */
                size += entry->rec_len;
                entry = (struct ext2_dir_entry_2 *)((char *)entry + entry->rec_len);
            }

            /* Move to the next block */
            if (size < inode->i_size) {
                lseek(fd, BLOCK_OFFSET(entry->inode), SEEK_SET);
                read(fd, block, block_size);
            }
        }

        free(block);
    }
}