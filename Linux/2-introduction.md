# INTRODUCTION 2

## System calls

System calls are the interface between the user space and the kernel space.  
They are used by the user space to request services from the kernel.  
The kernel provides a set of functions that can be called by the user space to perform tasks such as:

- process management
- file management
- memory management
- device management
- network management

System calls are implemented as functions in the kernel that can be called by user space programs.  
When a user space program makes a system call, the kernel switches from user mode to kernel mode to execute the system call.
these functions are a wrapper around the actual system call instruction that switches the CPU from user mode to kernel mode.

   ```bash
   man 2 syscalls
   ```

## Filder structure

every thing in linux is a file

1. /bin: contains essential command binaries
2. /etc: contains system-wide configuration files
3. /sbin: contains essential system binaries
4. /usr: contains user binaries and libraries
5. /var: contains variable data files(log, cache, temp etc)
6. /dev: contains device files
7. /home: contains user home directories
8. /lib: contains system libraries
9. /proc, /sys, /dev: doesn't exist on disk created in RAM by init process at boot time

## resolv.conf

`/etc/resolv.conf` is a configuration file for the DNS resolver.

the resolver refers to a library that consists of a collection of functions that does domain name translation.

DNS queries are the requests that are made to a Domain Name System (DNS) server for resolving a domain name into its corresponding IP address.

  ```bash
   cat /etc/resolv.conf
   ```

## fstab

`/etc/fstab` is a configuration file that contains information about all the partitions and storage devices in your system which should be mounted automatically at boot time.

   ```bash
   $ cat /etc/fstab
# /etc/fstab: static file system information.
#
# Use 'blkid' to print the universally unique identifier for a
# device; this may be used with UUID= as a more robust way to name devices
# that works even if disks are added and removed. See fstab(5).
#
# <file system> <mount point>   <type>  <options>       <dump>  <pass>
# / was on /dev/sda2 during installation
UUID=d538b03c-c5ad-45f5-902a-80e78a2842c3 /               btrfs   defaults,subvol=@,noatime,discard=async,ssd 0 1
# /boot/efi was on /dev/sda1 during installation
UUID=A241-53BA  /boot/efi       vfat    umask=0077      0       1
# /home was on /dev/sda2 during installation
UUID=d538b03c-c5ad-45f5-902a-80e78a2842c3 /home           btrfs   defaults,subvol=@home,noatime,discard=async,ssd  0       2
# swap was on /dev/sda3 during installation
UUID=22b987d3-2a98-4007-a0b6-5385bbc6d7dc none            swap    sw              0       0

UUID=0C660EA90C660EA9  /home/hala/windows-a         ntfs3   defaults,noatime,nofail,noauto,exec,user,x-systemd.device-timeout=5,comment=x-gvfs-show 0 0
UUID=44A0358DA0358708  /home/hala/windows-b         ntfs3   defaults,noatime,nofail,noauto,exec,user,x-systemd.device-timeout=5,comment=x-gvfs-show 0 0
   ```

### file content

  1.UUID: the universally unique identifier for the device.  
  you can use `blkid` command to get the UUID of a device.
  2.last two digits:
   **first digit**
   `1` dump utility backup of a partition.  
   `0` no backup. This is an outdated backup method and should NOT be used.
   **second digit**
   This controls the order in which fsck checks the filesystems at boot time. The root filesystem should have the highest priority `1`, and other filesystems should have `2`. If it is `0`, fsck will not check the filesystem.

## crontab

`crontab` is a command-line utility that allows you to schedule tasks to run at specific times.

  ```bash
   # open the crontab file for editing
   $ crontab -e
   # list the current crontab entries
   $ crontab -l
   # entry format example
   # Example of job definition:
   # .---------------- minute (0 - 59)
   # |  .------------- hour (0 - 23)
   # |  |  .---------- day of month (1 - 31)
   # |  |  |  .------- month (1 - 12) OR jan,feb,mar,apr ...
   # |  |  |  |  .---- day of week (0 - 6) (Sunday=0 or 7) OR sun,mon,tue,wed,thu,fri,sat
   # |  |  |  |  |
   # *  *  *  *  * user-name command to be executed
   m   h  dom mon dow  command
   0   *   *   *   *   DISPLAY=:0 XDG_RUNTIME_DIR=/run/user/$(id -u) notify-send "Hydration Reminder" "Don't forget to drink water!"

  ```

## uptime

`uptime` command displays the current time, how long the system has been running, how many users are currently logged on, and the system load averages for the past 1, 5, and 15 minutes.

  ```bash
  $ uptime
   09:48:48 up  9:18,  1 user,  load average: 0.33, 0.76, 1.23
  ```

`/proc/uptime` contains two numbers (in seconds):

1. The uptime of the system (time since last boot).
2. The amount of time the machine has spent idle.

  ```bash
   $ cat /proc/uptime
   33437.32 27168.44
  ```

## cmdline

`/proc/cmdline` contains the command line parameters passed to the kernel at boot time.

  ```bash
   $ cat /proc/cmdline
   BOOT_IMAGE=/@/boot/vmlinuz-5.15.0-91-generic root=UUID=d538b03c-c5ad-45f5-902a-80e78a2842c3 ro rootflags=subvol=@ quiet splash
  ```

## sources.list

`/etc/apt/sources.list` is a configuration file that contains a list of package repositories from which the `apt` package manager can download and install packages.

   ```bash
   cat /etc/apt/sources.list
   ```
