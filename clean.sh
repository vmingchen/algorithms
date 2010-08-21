#!/bin/bash - 
#===============================================================================
#
#          FILE:  clean.sh
# 
#         USAGE:  ./clean.sh 
# 
#   DESCRIPTION:  clean object, backup and executable files
# 
#       OPTIONS:  ---
#  REQUIREMENTS:  ---
#          BUGS:  ---
#         NOTES:  ---
#        AUTHOR: Ming Chen (chenming), chenming@sohu-rd.com
#       COMPANY: imeresearch@sogou
#       CREATED: 08/21/2010 11:36:00 AM CST
#      REVISION: 1.0
#===============================================================================

set -o nounset                              # Treat unset variables as an error

echo 'moving files to /tmp ...'
find . -regextype 'posix-awk' -iregex '.*(exe|obj|~|o)' -print -exec mv '{}' /tmp \;
find . -mindepth 2 -type f -exec file '{}' \; | grep executable | cut -d ':' -f 1 | xargs -i mv '{}' /tmp
echo 'done'
