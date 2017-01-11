# Personal setting for prompt and G++
export PS1='\u@\w $ '
alias g++='g++ -std=c++11 -I/usr/local/include/ -L/usr/local/lib/'

# Setting PATH for Python 3.5
# The original version is saved in .bash_profile.pysave
PATH="/Library/Frameworks/Python.framework/Versions/3.5/bin:${PATH}"
export PATH

# Custonm Variables
result=""
userna="\/Users\/$(whoami)"
usernb=$(echo ${userna} | sed 's/\\//g')
hidden="${usernb}/.dirs"

# Custom Functions
# A function that gets the directory from the hidden file
function finddir() {
	result=$(cat ${hidden} | grep "^$1 " | sed 's/.* //' | sed "s/~/${userna}/")	
}

# This function saves time to move to a directory saved previously
function go() {
	finddir $1
	local resbool=$(echo $result | wc -w)

	if [ ${resbool} -gt 0 ]
	then
		echo "Moving to ${result}"
		cd $result
		result=""
	fi
}

# This function saves a directory into the hidden file
function save() {
	finddir $1
	local resbool=$(echo $result | wc -w)

	if [ ${resbool} -gt 0 ]
	then
		echo "The directory $1 already exists"
		result=""
	else
		echo "Saving $1 directory"
		echo $1 $(pwd) >> ${hidden}
	fi
}

# A function that deletes a directory saved previously
function delete() {
	finddir $1
	local resbool=$(echo $result | wc -w)

	if [ ${resbool} -gt 0 ]
	then
		echo "Deleting the directory"
		sed -i -e "/^$1 .*/d" ${hidden}
	else
		echo "The directory $1 is not in the list"
	fi
}

# A function that lists all the saved directories
function dirs() {
	cat ${usernb}/.dirs
}
