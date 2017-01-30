/* realpath.c -- prints resolved absolute pathname.
   Copyright © 2017 David Winter

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include <config.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <getopt.h>
#include <err.h>
#include <sysexits.h>

enum {
	RELATIVE_TO_OPTION,
	RELATIVE_BASE_OPTION,
	HELP_OPTION,
	VERSION_OPTION
};

static const struct option longopts[] = {
	{"canonicalize-existing", no_argument, NULL, 'e'},
	{"canonicalize-missing", no_argument, NULL, 'm'},
	{"help", no_argument, NULL, HELP_OPTION},
	{"logical", no_argument, NULL, 'L'},
	{"no-symlinks", no_argument, NULL, 's'},
	{"physical", no_argument, NULL, 'P'},
	{"quiet", no_argument, NULL, 'q'},
	{"relative-base", required_argument, NULL, RELATIVE_BASE_OPTION},
	{"relative-to", required_argument, NULL, RELATIVE_TO_OPTION},
	{"strip", no_argument, NULL, 's'},
	{"version", no_argument, NULL, VERSION_OPTION},
	{"zero", no_argument, NULL, 'z'},
	{NULL, 0, NULL, 0}
};

static int longindex;
static const char *program_name = NULL;
static char verbose = true;
static char eol = '\n';

void usage() {
	printf("Usage: %s [OPTION]... FILE...\n"
			"Prints the canonicalized absolute pathname of FILE.\n\n"
			"  -e, --canonicalize-existing	the path must exist (default)\n"
			"  -P, --physical		resolve symlinks (default)\n"
			"  -q, --quiet			suppress error messages\n"
			"  -z, --zero			terminate lines with \\0 instead of \\n\n"
			"  -h, --help			display this help and exit\n", program_name);
	exit(EXIT_SUCCESS);
}

void usage_err(const char *msg) {
	if (msg != NULL) {
		warnx("%s", msg);
	}
	fprintf(stderr, "Try \"%s --help\" for more information.\n", program_name);
	exit(EXIT_FAILURE);
}

void version() {
	printf("%s %s\n"
			"Copyright © 2017 David Winter\n"
			"License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>\n"
			"This is free software: you are free to change and redistribute it.\n"
			"There is NO WARRANTY, to the extent permitted by law.\n", PACKAGE, VERSION);
	exit(EXIT_SUCCESS);
}

void set_program_name(const char *argv0) {
	const char *s = strrchr(argv0, '/');
	program_name = (s != NULL ? s + 1 : argv0);
}

bool resolve_path(const char *filename) {
	bool ok = false;
	char *resolved_path = malloc(sizeof(char) * (PATH_MAX+1));

	if (resolved_path == NULL) {
		err(EX_OSERR, NULL);
	}

	if (realpath(filename, resolved_path) != NULL) {
		printf("%s%c", resolved_path, eol);
		ok = true;
	} else if (verbose) {
		warn("%s", resolved_path);
	}

	free(resolved_path);
	return ok;
}

void warn_ignored(char c) {
	const struct option *opt = &longopts[longindex];
	if (opt->val == c) {
		warnx("the option \"--%s\" is not supported but ignored.", opt->name);
	} else {
		warnx("the option \"-%c\" is not supported but ignored.", c);
	}
}

int main(int argc, char **argv) {
	bool ok = true;
	int ch;

	set_program_name(argv[0]);

	while ((ch = getopt_long(argc, argv, "emhLPqsz", longopts, &longindex)) != -1) {
		switch (ch) {
			case 'm':
			case 'L':
			case 's':
			case RELATIVE_TO_OPTION:
			case RELATIVE_BASE_OPTION:
				warn_ignored(ch);
			case 'e':
			case 'P':
				break;
			case HELP_OPTION:
				usage();
				break;
			case 'q':
				verbose = false;
				break;
			case VERSION_OPTION:
				version();
				break;
			case 'z':
				eol = '\0';
				break;
			default:
				usage_err(NULL);
		}
	}

	if (optind >= argc) {
		usage_err("not enough arguments");
	}

	for (; optind < argc; ++optind) {
		ok &= resolve_path(argv[optind]);
	}

	return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
