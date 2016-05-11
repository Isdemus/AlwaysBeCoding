#!/bin/bash

# The program readlines each file name in the given beginning directory,
# then it changes the names with a given previous EXT to be with a new (next) EXT
# After the names modified, it uses find command under the given directory to
# find and copy the items with a new name to be in a destination directory

# If the given input (parameters) are not proper
if [ $# != 5 ]; then
	echo Please Try Again [Usage: ./fileTransfer [prev Ext] [next Ext] [begin directory] [find directory] [dest directory]
else
	for fileName in ${3}/*
		do
			fileNameWithoutDir=${fileName##*/}
			fileNameWithNewExt=${fileNameWithoutDir/${1}/${2}}

			# the command 'cp' does not have -t option on Mac OS X
			# so in the case, the option must be changed 
			find ${4} -type f -name ${fileNameWithNewExt} | xargs cp -t ${5}
		done
fi
