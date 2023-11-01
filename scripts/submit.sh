#!/bin/bash

get_default_url() {
    git remote -v | while read line; do
        if [[ $line =~ "origin" ]] && [[ $line =~ "push" ]]; then
            echo $1
            echo $line | grep -o '\ .*\ '
            return
        fi
    done
}

add_remote_url() {
    git remote add origin $1
}

push_repo() {
    URL="$(get_default_url $1)"

    if [[ ! -n "$URL" ]]; then
        add_remote_url  https://gitee.com/oscpu/core_test
        URL="https://gitee.com/oscpu/core_test"
    fi

    printf "Enter a new URL to replace the default push URL(\e[1;34m%s\e[0m) or leave a blank to skip.\n" $URL
    read -p "Enter your new push URL: " -e INPUT
    if [[ -n "$INPUT" ]] && [[ ! $INPUT == $URL ]]; then
        git remote set-url --push origin $INPUT
    else
        INPUT=$URL
    fi
    
    git add src
    git commit -m "dc & vcs" --no-verify --allow-empty 1>/dev/null 2>&1

    git push origin
    if [ $? -ne 0 ]; then
        printf "\e[1;31mFailed to push!!!\e[0m\n"
        exit 1
    fi

    printf "You repo has been pushed to \e[1;32m%s\e[0m.\n" $INPUT
}


A53_PATH=$(dirname $(readlink -f "$0"))

copy_src_file $PREFIX".v" 

push_repo
