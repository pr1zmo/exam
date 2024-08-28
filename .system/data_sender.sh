#!/bin/bash
userpost="user=$LOGNAMELOG42EXAM"
os="os=$(uname)"
date=$(date '+%F_%H:%M:%S')
time="time=$date"

usingpost="using=$1"

# Commented out the curl command to prevent sending data
# curl -X POST -F "$userpost" -F "$usingpost" -F "$os" -F "$time" "https://user.grademe.fr/exam.php" > /dev/null 2>&1