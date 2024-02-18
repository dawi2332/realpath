#! /bin/sh

if [ ! -f configure.sh ] || [ ! -f Makefile.in ] || [ ! -f aclocal.m4 ] || [ ! -f config.h.in ]; then
    autoreconf
fi
