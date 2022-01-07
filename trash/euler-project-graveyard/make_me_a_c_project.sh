#!/bin/bash

PRJ_NAME=$1
BIN_NAME=$2

mkdir "$PRJ_NAME" &&\
    cd $_ &&\
    git init &&\
    echo "$BIN_NAME" > .gitignore &&\
    git add . &&\
    git commit -m "gitignore"
