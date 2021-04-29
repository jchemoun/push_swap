#!/bin/bash
if [ -z "$1" ]
then
    n=10
else
    n=$1
fi
re='^[0-9]+$'
if ! [[ $n =~ $re ]] ; then
    echo "error: Not an int" >&2; exit 1
fi
tab=$(shuf -i 0-50000 -n $n)
for i in ${tab[@]}
do
    echo -n " $i"
done
