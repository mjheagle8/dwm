#!/bin/bash

MENUFILE="$HOME/builds/dwm/mygtkmenu/menu"

# get mpd status
MPDSTATUSLINES=$(mpc status)
MPDPLAYING=$(echo $MPDSTATUSLINES | grep -c playing)
MPDPAUSED=$(echo $MPDSTATUSLINES | grep -c paused)
if [[ $MPDPLAYING -eq 1 ]]; then
    MPDSTATUS="playing"
elif [[ $MPDPAUSED -eq 1 ]]; then
    MPDSTATUS="paused"
else
    MPDSTATUS="stopped"
fi
MPDNOWPLAYING=$(echo $MPDSTATUSLINES | grep -o "[^\[]*" | head -n 1)

echo "
iconsize  = 16

item = $(whoami)@$(hostname)
cmd = " "
icon = NULL

SEPARATOR

item = _chromium
cmd = xdotool key super+g
icon = /usr/share/icons/hicolor/16x16/apps/chromium.png

item = _dwb
cmd = xdotool key super+w
icon = /usr/share/pixmaps/dwb.png

SEPARATOR

item = _term
cmd = urxvtc
icon = /usr/share/icons/gnome/16x16/apps/terminal.png

Submenu = t_ermapps
    icon = /usr/share/icons/gnome/16x16/apps/terminal.png

    item = ncmpcpp
    cmd = xdotool key super+n
    icon = NULL

    item = mutt
    cmd = xdotool key super+e
    icon = /usr/share/icons/oxygen/16x16/actions/mail-mark-unread.png

    item = weechat
    cmd = xdotool key super+i
    icon = /home/mhiggin5/.icons/Nostromo2/16x16/apps/internet-group-chat.png

    SEPARATOR

    item = htop
    cmd = xdotool key super+q
    icon = /usr/share/icons/oxygen/16x16/apps/utilities-system-monitor.png

    item = ranger
    cmd = xdotool key super+d
    icon = /usr/share/icons/oxygen/16x16/apps/system-file-manager.png

    SEPARATOR

    item = tasknc
    cmd = xdotool key super+a
    icon = /usr/share/icons/oxygen/16x16/status/task-complete.png

    SEPARATOR

    item = ssh arch-phoenix
    cmd = xdotool key super+s
    icon = NULL

SEPARATOR

Submenu = _media
    icon = NULL

    item = msearch
    cmd = xdotool key super+r
    icon = NULL

    item = utub
    cmd = xdotool key super+u
    icon = NULL

    item = watchvideo
    cmd = xdotool key super+y
    icon = NULL

Submenu = m_pd: $MPDSTATUS
    icon = NULL

    item = $MPDNOWPLAYING
    cmd = " "
    icon = NULL

    SEPARATOR

    item = toggle
    cmd = mpc toggle
    icon = NULL

    item = prev
    cmd = mpc prev
    icon = NULL

    item = next
    cmd = mpc next
    icon = NULL

    item = stop
    cmd = mpc stop
    icon = NULL

" > $MENUFILE

mygtkmenu $MENUFILE
