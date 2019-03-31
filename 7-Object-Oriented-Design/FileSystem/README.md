## Data structures used to build file systems

All file systems are different, so there are a huge number of data structures that actually
get used in file systems.

Many file systems use some sort of bit vector ( usually referred to as a bitmap ) to track
where certain free blocks are, since they have excellent performance for querying whether
a specific block of disk is in use and (for disks that aren't overwhelmingly full) support
reasonably fast lookups of free blocks.

Many older file systems ( ext and ext2) stored directory structures using simple linked lists.
Apparently this was actually fast enough for most applications, though some types of applications
that used lots of large directories suffered noticeable performance hits.

The XFS file system was famous for using B+-trees for just about everything, including directory
structures and its journaling system.

Microsoft's FAT32 system used a huge array (the file allocation table) that store what files
were stored where and which disk sectors follow one another logically in a file. The main drawback
is that the table had to be set up in advance, so there ended up being upper limits on the sizes of
files that could be stored on the disk. However, the array-based system was pretty easy to implement.