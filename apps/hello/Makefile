NAME = hello
SRCS = hello.c
CFLAGS := -EL -static -fno-stack-protector
LDFLAGS := -EL -nostdlib
INSTALL_APPS := build/hello:/bin/hello

include $(ROOTFS_HOME)/Makefile.compile
include $(ROOTFS_HOME)/Makefile.app
