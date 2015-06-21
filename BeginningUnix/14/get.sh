#/bin/bash

while getopts "xy:z:" name
do
	echo "$name" $OPTIND $OPTARG
done
