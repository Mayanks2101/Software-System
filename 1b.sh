# ============================================================================
# Name : 1b.sh
# Author : Mayankkumar Satapara
# Roll Number : MT2025069
# Description : 1. Create the following types of a files using (i) shell command
#                       b. hard link
# Date: 15 Aug, 2025.
# ============================================================================

# code :

#!/bin/bash

ln folder/hlink hlinked_cmd

# Output :
# ./1b.sh
# ls -l | grep 'hlinked_cmd'
# -rw-rw-r-- 3 mayank mayank    20 Aug 15 18:50 hlinked_cmd
# 
# ls -l ./folder
# -rw-rw-r-- 3 mayank mayank 20 Aug 15 18:50 hlink


