# realpath(1) -- prints resolved absolute pathname.

This is a thin wrapper around the realpath(3) library function present on certain BSD operating systems (e.g. macOS).

It will accept any options available with GNU realpath, but only a few will have any effect, as the behaviour of the realpath library function cannot be easily changed and also varies between OS vendors and versions.

## SYNOPSIS

`realpath` [<OPTION>]... <FILE>...

## OPTIONS
 * `-q`, `--quiet`:
   suppress error messages
 * `-z`, `--zero`:
   terminate lines with \\\0 instead of \n
 * `--help`:
   display help and exit
 * `--version`:
   display version information and exit

## DIAGNOSTICS
The `realpath` program will return 0 on success and 1 if an error occurs.
It will not terminate as long as not all <FILE> arguments have been processed, even if a filename could not be resolved.

## SEE-ALSO
realpath(3)

## COPYRIGHT
    Copyright © 2017 David Winter
    License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
    This is free software: you are free to change and redistribute it.
    There is NO WARRANTY, to the extent permitted by law.
