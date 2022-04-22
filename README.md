# ANT file system 
## Introduction
That filesystem was based on FUSE (Filesystem in Userspace) idea, because <\br>
kernel space fs needs deep knowledge of kernel working
## What is in our file system?
In our file system we have:
  1. Simple Files
  2. Directories
  3. Links (optional)
## Structure and description of Group Descriptor Tables (GDT)
### Description GDT
The Block Group Descriptor Table contains a descriptor for each block group within the file system.
### Structure GDT
GDT consist of:
  1. Block address of block usage bitmap
  2. Block address of inode usage bitmap 
  3. Starting block address of inode table
  4. Number of unallocated inodes in group
## In which blocks is it located SuperBlock and GDT?
### Superblock
SuperBlock located in 1, 32, 512 1024 and last blocks
### GDT
Group Descriptor Tables located like SuperBlock

