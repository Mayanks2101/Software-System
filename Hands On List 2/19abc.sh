#
# ============================================================================
# Name        : 19abc.sh
# Author      : Mayankkumar Satapara
# Roll Number : MT2025069
# Description : Create a FIFO file by
#               a. mknod command
#               b. mkfifo command
#               c. use strace command to find out, which command (mknod or mkfifo) is better.
#               d. mknod system call
#               e. mkfifo library function
# Date        : 07 Sep, 2025
# ============================================================================



#!/bin/bash

mknod 19_fifo_mknod_cmd p

mkfifo 19_fifo_mkfifo_cmd

touch 19_strace_mknod.txt
touch 19_strace_mkfifo.txt

strace -o 19_strace_mknod.txt mknod 19_fifo_mknod_strace p
strace -o 19_strace_mkfifo.txt mkfifo 19_fifo_mkfifo_strace

ls -l 19_f*

# Output :
# $ chmod +x 19abc.sh
# $ ./19abc.sh
# prw-rw-r-- 1 mayank mayank 0 Oct  1 14:46 19_fifo_mkfifo_cmd
# prw-rw-r-- 1 mayank mayank 0 Oct  1 14:46 19_fifo_mkfifo_strace
# prw-rw-r-- 1 mayank mayank 0 Oct  1 14:46 19_fifo_mknod_cmd
# prw-rw-r-- 1 mayank mayank 0 Oct  1 14:46 19_fifo_mknod_strace
#
#
# ===> Which is better, mknod vs mkfifo?
# Both do the same thing (both call mknod system call under the hood).
# mkfifo is preferred because:
# It’s more readable and specific for FIFO creation.
#
# mknod can create all types of special files (block, char devices, etc.), which can be risky if you make a mistake.(This is the reason we are using "p" in mknod to specify FIFO special file type)
#
# So → Using mkfifo for FIFO files is better.
#
