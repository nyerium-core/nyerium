
Debian
====================
This directory contains files used to package nyeriumd/nyerium-qt
for Debian-based Linux systems. If you compile nyeriumd/nyerium-qt yourself, there are some useful files here.

## nyerium: URI support ##


nyerium-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install nyerium-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your nyeriumqt binary to `/usr/bin`
and the `../../share/pixmaps/nyerium128.png` to `/usr/share/pixmaps`

nyerium-qt.protocol (KDE)

