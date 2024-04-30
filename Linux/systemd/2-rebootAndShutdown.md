# Systemd Shutdown And Reboot

With systemd, many old commands for managing services and system shutdown/reboot are replaced with the `systemctl` command. For example:

- `service <service-name> start/stop/restart` is now `systemctl start/stop/restart <service-name>`.
- `chkconfig <service-name> on/off` for enabling or disabling a service at boot is now `systemctl enable/disable <service-name>`.
- `shutdown -h now` for halting the system is now `systemctl halt`.
- `shutdown -r now` for rebooting the system is now `systemctl reboot`.
- `shutdown -h +time` for scheduling a shutdown is now `systemctl poweroff`.

The `systemctl` command provides a unified interface for managing system services and controlling the state of the systemd system and service manager.

through `systemctl` commands, you **can't schedule the shutdown or reboot**.

  ```bash
    sudo systemctl poweroff
    sudo systemctl reboot
  ```

but you can still use the `shutdown` command to schedule the shutdown or reboot.

  ```bash
    [r]eboot in 5 minutes:
    $ shutdown -r +{{5}} &

    Shutdown at 1:00 pm (Uses 24[h] clock):
    $ shutdown -h 13:00

    [c]ancel a pending shutdown/reboot operation:
    $ shutdown -c

  ```
  
- to make some process to run in the background, you can use `&` at the end of the command.
