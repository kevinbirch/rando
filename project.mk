# -*- mode: Makefile-gmake -*-

owner = io.node6
package = rando
version = 1.0.0-SNAPSHOT
artifact = program
build = debug

CFLAGS = -std=c11 -fstrict-aliasing -Wall -Wextra -Werror -Wformat -Wformat-security -Wformat-y2k -Winit-self -Wmissing-include-dirs -Wswitch-default -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast -Wconversion -Wstrict-prototypes -Wold-style-definition -Wmissing-prototypes -Wmissing-declarations -Wredundant-decls -Wnested-externs -Wunreachable-code -Wno-switch-default -Wno-unknown-pragmas -Wno-gnu -fms-extensions -Wno-microsoft
debug_CFLAGS = -DUSE_LOGGING -O0 -g
release_CFLAGS = -O3 -flto
