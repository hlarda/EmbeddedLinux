# what is systemd?

[click for source video](https://www.youtube.com/watch?v=Kzpm-rGAXos) ddnt watch it till the end.

init system used in Linux distributions to bootstrap the user space and manage all processes subsequently, instead of the traditional SystemV init system.

the init system is the very first process that gets started by the kernel and is given the process id of 1. It is responsible for starting all other processes on the system.

have a look at

  ```bash
    htop
  ```

## working with systemd units

- units in systemd are the resourses that it's able to manage including services, sockets, devices, mounts, and more.
- each unit is defined by a unit file, which is a simple text file that specifies how the unit should be started and stopped.
- unit files are stored in the `/etc/systemd/system` directory and have a .service extension.

  ```bash
  hala@lat:/etc/systemd/system
    $ ls
    bluetooth.target.wants                      final.target.wants           sockets.target.wants
    dbus-fi.w1.wpa_supplicant1.service          getty.target.wants           sudo.service
    dbus-org.bluez.service                      graphical.target.wants       sysinit.target.wants
    dbus-org.freedesktop.Avahi.service          multi-user.target.wants      syslog.service
    dbus-org.freedesktop.ModemManager1.service  network-online.target.wants  timers.target.wants
    dbus-org.freedesktop.nm-dispatcher.service  nix-daemon.service           zed.service
    dbus-org.freedesktop.resolve1.service       nix-daemon.socket            zfs-import.target.wants
    dbus-org.freedesktop.thermald.service       oem-config.service.wants     zfs-mount.service.wants
    dbus-org.freedesktop.timesync1.service      paths.target.wants           zfs.target.wants
    display-manager.service                     printer.target.wants         zfs-volumes.target.wants
    display-manager.service.wants               rescue.target.wants
    emergency.target.wants 
  ```

- for now, we will focus on service units, which are used to manage system services.

## managing services with systemd

first, lets install apache2

It provides a secure, efficient, and extensible server that provides HTTP services in sync with the current HTTP standards. It's commonly used to host websites and web applications on the internet.

  ```bash
    sudo apt install apache2
  ```
  
1. go to ur browser and type `https://localhost` to check if the apache2 server is running.
2. check the status of the apache2 service using the `systemctl` command.

  ```bash
    systemctl status apache2
  ```

  ```bash
    ● apache2.service - The Apache HTTP Server
     Loaded: loaded (/lib/systemd/system/apache2.service; enabled; vendor preset: enabled)
     Active: active (running) since Tue 2024-04-30 04:06:56 EEST; 14min ago
       Docs: https://httpd.apache.org/docs/2.4/
   Main PID: 36327 (apache2)
      Tasks: 55 (limit: 9255)
     Memory: 5.4M
        CPU: 68ms
     CGroup: /system.slice/apache2.service
             ├─36327 /usr/sbin/apache2 -k start
             ├─36328 /usr/sbin/apache2 -k start
             └─36329 /usr/sbin/apache2 -k start

Apr 30 04:06:56 lat systemd[1]: Starting The Apache HTTP Server...
Apr 30 04:06:56 lat apachectl[36326]: AH00558: apache2: Could not reliably determine the server's fully qualif>
Apr 30 04:06:56 lat systemd[1]: Started The Apache HTTP Server.
  ```

u can see that the apache2 service is active and running.

3. to stop the apache2 service, use the `systemctl stop` command.

  ```bash
    $ systemctl stop apache2

    $ systemctl status apache2
○ apache2.service - The Apache HTTP Server
     Loaded: loaded (/lib/systemd/system/apache2.service; enabled; vendor preset: enabled)
     Active: inactive (dead) since Tue 2024-04-30 04:27:52 EEST; 4s ago
       Docs: https://httpd.apache.org/docs/2.4/
    Process: 38692 ExecStop=/usr/sbin/apachectl graceful-stop (code=exited, status=0/SUCCESS)
   Main PID: 36327 (code=exited, status=0/SUCCESS)
        CPU: 109ms

Apr 30 04:06:56 lat systemd[1]: Starting The Apache HTTP Server...
Apr 30 04:06:56 lat apachectl[36326]: AH00558: apache2: Could not reliably determine the server's fully qualif>
Apr 30 04:06:56 lat systemd[1]: Started The Apache HTTP Server.
Apr 30 04:27:52 lat systemd[1]: Stopping The Apache HTTP Server...
Apr 30 04:27:52 lat apachectl[38694]: AH00558: apache2: Could not reliably determine the server's fully qualif>
Apr 30 04:27:52 lat systemd[1]: apache2.service: Deactivated successfully.
Apr 30 04:27:52 lat systemd[1]: Stopped The Apache HTTP Server.
  ```

## systemd unit direcrories

(index specifing the priority)

1. `/etc/systemd/system/` - for system-wide unit files.
2. `/run/systemd/system/` - for runtime unit files.
3. `/usr/lib/systemd/system/` - for unit files provided by installed packages.

## navigate through apache2.service unit file

  ```bash
  hala@lat:/lib/systemd/system
$ cat apache2.service
[Unit]
Description=The Apache HTTP Server
After=network.target remote-fs.target nss-lookup.target
Documentation=https://httpd.apache.org/docs/2.4/

[Service]
Type=forking
Environment=APACHE_STARTED_BY_SYSTEMD=true
ExecStart=/usr/sbin/apachectl start
ExecStop=/usr/sbin/apachectl graceful-stop
ExecReload=/usr/sbin/apachectl graceful
KillMode=mixed
PrivateTmp=true
Restart=on-abort

[Install]
WantedBy=multi-user.target

  ```

## journalctl

- a command-line utility for querying and displaying logs from the journal.
- the journal is a system log that stores messages from the kernel, the init system, and system services.
- the journal is stored in binary format in the `/var/log/journal` directory.
- the journalctl command can be used to view and filter log messages from the journal.
  
  ```bash
    journalctl
  ```

journalctl provides various options to filter and display these logs, such as by service, by time, by priority level, and more. It's a powerful tool for system debugging and troubleshooting.

  ```bash
  Show all messages with priority level 3 (errors) from this [b]oot:
    $ journalctl -b --priority={{3}}

  Delete journal logs which are older than 2 days:
    $ journalctl --vacuum-time={{2d}}

  [f]ollow new messages (like tail -f for traditional syslog):
    $ journalctl -f

  Show all messages by a specific [u]nit:
    $ journalctl -u {{unit}}

  Show all messages by a specific process:
    $ journalctl _PID={{pid}}

  Show all messages by a specific executable:
    $ journalctl {{path/to/executable}}
  ```
