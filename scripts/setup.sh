#!/bin/bash
keymap_path="keyboards/preonic/keymaps/vaninc"
keymap_pattern=$keymap_path"/\*"
git_exclude=".git/info/exclude"
git_url="git@github.com:ReVanTis/preonic_qmk.git"

git clone $git_url $keymap_path

grep -q $keymap_pattern $git_exclude

if [ "$?" != "0" ] ; then
	echo $keymap_path"/*" >> $git_exclude
else
	echo "already added to git exclude locally"
fi
