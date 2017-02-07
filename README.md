# realpath

This is a thin wrapper around the realpath(3) library function present on certain BSD operating systems (e.g. macOS).

It will accept any options available with GNU realpath, but only a few will have any effect, as the behaviour of the realpath library function cannot be easily changed and also varies between OS vendors and versions.
