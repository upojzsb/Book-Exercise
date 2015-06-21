#/bin/bash
#Test the usage of case

read $i

case "$1" in
	1)
		echo "Hi"
		;;
	2)
		echo "Bye"
		;;
	*)
		echo "Usage: $0 [1|2]"
		;;
esac
