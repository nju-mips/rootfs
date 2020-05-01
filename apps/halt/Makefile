SRCS = halt.c
CFLAGS := -EL -nostdlib -static
LDFLAGS := -EL -nostdlib -static -Wl,-entry=main

include $(ROOTFS_HOME)/Makefile.compile

INSTALL_APPS := build/halt:/bin/halt
include $(ROOTFS_HOME)/Makefile.app
