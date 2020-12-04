# QMK Keymap for ReVanTis' Preonic Rev3

How to setup:

- Setup qmk build environment.
- cd to qmk_firmware root.
- git clone git@github.com:ReVanTis/preonic_qmk.git keyboards/preonic/keymaps/vaninc
- run qmk flash --kb preonic/rev3 --km vaninc to compile and flash
- To exclude this keymap from qmk_firmware locally add keyboards/preonic/keymaps/vaninc* to qmk_firmware/.git/info/exclude


Or automatically:

- cd to qmk_firmware root.
- execute "curl -s https://raw.githubusercontent.com/ReVanTis/xd75_qmk/master/scripts/setup.sh | bash"

