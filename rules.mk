# Copyright 2019 ReVanTis Zhao <revantis0@gmail.com>
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

NKRO_ENABLE = no
UNICODE_ENABLE = yes
RGBLIGHT_ENABLE = yes
MOUSEKEY_ENABLE = yes
#TAP_DANCE_ENABLE = no
SRC += muse.c

#RAW_ENABLE = no
#VIRTSER_ENABLE = no
CONSOLE_ENABLE = yes
COMMAND_ENABLE = yes

#XAP_ENABLE = yes

KEYMAP_OUTPUT = ~/qmk_firmware/keymap_output