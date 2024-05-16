#! /bin/bash

# this script will open a file manager in the selected directory

set -e

menu="${HOME}/windows-b/EmbeddedLinux\n${HOME}/windows-b/codeGIT"

choice=$(echo -e "$menu" | dmenu -i -p "Select a directory:")

#choice=$(echo -e "$menu" | rofi -dmenu -i -p "Select a directory:")

#choice=$(echo -e "$menu" | fzf)

nemo "$choice" &

