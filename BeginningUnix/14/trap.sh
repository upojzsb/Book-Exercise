#/bin/bash

CC()
{
	echo bye
	kill $$
}

trap CC 2
while [ 1 ]
do
	sleep 1
done
