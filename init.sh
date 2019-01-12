#! /bin/bash

CONTEST_NAME=$1
echo "initialize: $CONTEST_NAME"

if [ ! -e $CONTEST_NAME ]; then
    echo "mkdir: $CONTEST_NAME"
    mkdir $CONTEST_NAME
fi

if [ -z $2 ]; then
    exit 0
fi

if [ $2 = 'all' ] ; then
    for PROBREM in A B C D
    do
        if [ ! -e $PROBREM.cpp ]; then
            echo "CREATE: $PROBREM.cpp"
            cp ../cpp-lib/template.cpp $CONTEST_NAME/$PROBREM.cpp
        fi
    done
else
    PROBREM=$2
    if [ ! -e $PROBREM.cpp ]; then
        echo "CREATE: $PROBREM.cpp"
        cp ../cpp-lib/template.cpp $CONTEST_NAME/$PROBREM.cpp
    else
        echo "ERROR: $PROBREM.cpp is already existed."
    fi
fi



