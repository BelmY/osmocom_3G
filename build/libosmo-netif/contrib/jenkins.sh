#!/usr/bin/env bash

set -ex

base="$PWD"
deps="$base/deps"
inst="$deps/install"
export deps inst

mkdir "$deps" || true
rm -rf "$inst"

osmo-build-dep.sh libosmocore

"$deps"/libosmocore/contrib/verify_value_string_arrays_are_terminated.py $(find . -name "*.[hc]")

export PKG_CONFIG_PATH="$inst/lib/pkgconfig:$PKG_CONFIG_PATH"
export LD_LIBRARY_PATH="$inst/lib"

osmo-build-dep.sh libosmo-abis

set +x
echo
echo
echo
echo " =============================== libosmo-netif ==============================="
echo
set -x

autoreconf --install --force
./configure
$MAKE $PARALLEL_MAKE
$MAKE distcheck \
  || cat-testlogs.sh
