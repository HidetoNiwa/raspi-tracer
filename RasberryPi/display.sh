#!/bin/bash
sudo service dbus restart
DISPLAY_0:0 XDG_SESSION_TYPE=x11 gnome-session
