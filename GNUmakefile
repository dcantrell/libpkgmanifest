# This GNU make Makefile is intended as a helper.  meson is used for
# the actual build and configuration, but this GNUmakefile provides
# some useful targets for development and release purposes.  Type
# "gmake help" for more details.  It is called GNUmakefile to indicate
# it requires GNU make.

# Allow calling environment overrides to commands used in this
# GNUmakefile.  Defaults are below.

REALPATH ?= realpath

# Core directories
MESON_BUILD_DIR = build
topdir := $(shell $(REALPATH) $(dir $(lastword $(MAKEFILE_LIST))))

# Project information (may be an easier way to get this from meson)
PROJECT_NAME = $(shell grep ^project $(topdir)/meson.build | cut -d "'" -f 2)
PROJECT_VERSION = $(shell grep version $(topdir)/meson.build | grep -E ',$$' | cut -d "'" -f 2)

# Take additional command line argument as a positional parameter for
# the GNUmakefile target
TARGET_ARG = `arg="$(filter-out $@,$(MAKECMDGOALS))" && echo $${arg:-${1}}`

all:
	@echo "Type 'gmake help' for targets."

authors:
	echo "Authors" > AUTHORS.md
	echo "=======" >> AUTHORS.md
	echo >> AUTHORS.md
	git log --pretty="%aN <%aE>" | sort -u | sed -e 's|^|- |g' | sed G >> AUTHORS.md

help:
	@echo "libpkgmanifest helper GNUmakefile"
	@echo "The source tree uses meson(1) for building and testing, but this GNUmakefile"
	@echo "is intended as a simple helper for the common steps."
	@echo
	@echo "    authors           Generate a new AUTHORS.md file"

# Quiet errors about target arguments not being targets
%:
	@true
