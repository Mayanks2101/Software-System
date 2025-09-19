# ============================================================================
# Name : 1a.sh
# Author : Mayankkumar Satapara
# Roll Number : MT2025069
# Description : 1. Create the following types of a files using (i) shell command
#              		a. soft link
# Date: 15 Aug, 2025.
# ============================================================================

# code :

#!/bin/bash
ln -s /folder/slink slinked_cmd


# Output : 
# ./1a.sh
# ls -l | grep 'slinked_cmd'
# lrwxrwxrwx 1 mayank mayank    13 Sep  6 16:47 slinked_cmd -> /folder/slink


