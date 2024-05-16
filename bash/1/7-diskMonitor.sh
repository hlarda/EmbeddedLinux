#! /bin/bash

set -e

max=90
storage=$(df -h | grep "/dev/sda5" | awk '{print $5}' | sed 's/%//g')
echo "Storage: $storage"
if [ "$storage" -ge "$max" ]; then
    notify-send "Storage is full"
    gnome-terminal -- bash -c "watch df -h"
else
    notify-send "Storage is not full"
fi
