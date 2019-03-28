#!/bin/sh

pushd $MESON_INSTALL_DESTDIR_PREFIX/$1
mkfontdir -x .bdf
popd
