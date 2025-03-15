# sofle_layout

Layout for my Sofle Choc Pro keyboard

## Building

1. Install QMK cli:

        brew install qmk/qmk/qmk
        qmk setup

1. Clone <https://github.com/qmk/qmk_firmware>
1. Create link to this repo

        ln -s ~/work/vc/sofle_layout keyboards/keebart/sofle_choc_pro/keymaps/edevil

1. Compile

        make keebart/sofle_choc_pro:edevil

1. Flash

        make keebart/sofle_choc_pro:edevil:flash
