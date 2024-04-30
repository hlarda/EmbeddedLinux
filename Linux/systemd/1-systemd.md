# [SYSTEM-D](https://www.youtube.com/playlist?list=PL6IQ3nFZzWfpKKWfZMRxiuEBwqQBwjzS1)

## why systemD?

- **faster boot-up** since demons start in parallel.
- **easier** for developers as it's no longer nessary to figure out the order in which demons should be started.
- **no longer need for numbered "s" and "k" links**.
  - In traditional SysV init systems, the /etc/rc.d/init.d directory contains startup scripts for various services. These scripts are named with a prefix "S" or "K", followed by a number.
  
    - "S" stands for "start", and these scripts are used to start a service.
    - "K" stands for "kill", and these scripts are used to stop a service.
  
  - The number following the "S" or "K" determines the order in which the scripts are executed during startup or shutdown. Lower numbers are executed before higher numbers.
  - In systemd, these "S" and "K" scripts are no longer necessary because systemd uses a different method for starting and stopping services. Instead of scripts, systemd uses service units, which are configuration files that specify how a service should start or stop.
  **This approach has several advantages:**
  - It's more efficient:
        systemd starts services in parallel, which can significantly reduce boot time.
  - It's simpler:
        service units are easier to write and understand than shell scripts.
  - It's more powerful:
        systemd provides more advanced features, like on-demand service starting, timer-based activation, and dependency handling.
  - It's more consistent:
        all services are managed in the same way, regardless of the details of the service itself.
- insread of controlling the daemons with complex init scripts, systemd uses a **simple configuration file to control the daemons**.
  - you can configure your deamon to restart if it crashes and when it can start and stop as needed.
  - you can also configure the daemon to start only when a specific device is connected or when a specific network is available.
- **Better security**
  - `auditd` is a daemon that monitors system events and logs them to the audit log. It can be used to track changes to the system, detect unauthorized access, and investigate security incidents.
  - the `auditd` daemon cannot be disabled by a user with root privileges, which makes it more secure.
  - every process runs in its own cgroup, which limits the resources that it can use and makes it more difficult for a process to interfere with other processes which provides better process separation and security.
- **More consistant administration**
  - systemd provides a consistent interface for managing services, regardless of the underlying technology or destro.
  - This makes it easier for administrators to learn and use the system, because they only need to know one set of commands.
