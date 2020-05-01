DEBIAN_HOME := $(ROOTFS_HOME)/../../debian/rootfs

INSTALL_APPS += hello.c:/home/hello.c

INSTALL_APPS += link/init:/init
INSTALL_APPS += link/sh:/bin/sh
INSTALL_APPS += bashrc:.bashrc
INSTALL_APPS += bashrc:/root/.bashrc
INSTALL_APPS += $(DEBIAN_HOME)/bin/bash:/bin/bash
INSTALL_APPS += $(DEBIAN_HOME)/bin/ls:/bin/ls
INSTALL_APPS += $(DEBIAN_HOME)/bin/pwd:/bin/pwd
INSTALL_APPS += $(DEBIAN_HOME)/bin/chmod:/bin/chmod
INSTALL_APPS += $(DEBIAN_HOME)/bin/chown:/bin/chown
INSTALL_APPS += $(DEBIAN_HOME)/bin/cp:/bin/cp
INSTALL_APPS += $(DEBIAN_HOME)/bin/ln:/bin/ln
INSTALL_APPS += $(DEBIAN_HOME)/bin/mount:/bin/mount
INSTALL_APPS += $(DEBIAN_HOME)/bin/cat:/bin/cat
INSTALL_APPS += $(DEBIAN_HOME)/usr/bin/vim.basic:/usr/bin/vim
INSTALL_APPS += $(DEBIAN_HOME)/usr/bin/mipsel-linux-gnu-as:/usr/bin/as
INSTALL_APPS += $(DEBIAN_HOME)/usr/bin/mipsel-linux-gnu-ld.bfd:/usr/bin/ld
INSTALL_APPS += $(DEBIAN_HOME)/usr/bin/mipsel-linux-gnu-objdump:/usr/bin/objdump
INSTALL_APPS += $(DEBIAN_HOME)/usr/bin/mipsel-linux-gnu-readelf:/usr/bin/readelf
INSTALL_APPS += $(DEBIAN_HOME)/usr/bin/mipsel-linux-gnu-gcc-6:/usr/bin/gcc
INSTALL_APPS += $(DEBIAN_HOME)/usr/lib/gcc/mipsel-linux-gnu/6/cc1:/usr/lib/gcc/mipsel-linux-gnu/6/cc1

LIB_HOME := $(DEBIAN_HOME)/lib/mipsel-linux-gnu
INSTALL_APPS += $(LIB_HOME)/ld-2.24.so:/lib/ld.so.1
INSTALL_APPS += $(LIB_HOME)/libtinfo.so.5.9:/lib/libtinfo.so.5
INSTALL_APPS += $(LIB_HOME)/libc-2.24.so:/lib/libc.so.6
INSTALL_APPS += $(LIB_HOME)/libdl-2.24.so:/lib/libdl.so.2
INSTALL_APPS += $(LIB_HOME)/libselinux.so.1:/lib/libselinux.so.1
INSTALL_APPS += $(LIB_HOME)/libpcre.so.3.13.3:/lib/libpcre.so.3
INSTALL_APPS += $(LIB_HOME)/libpthread-2.24.so:/lib/libpthread.so.0
INSTALL_APPS += $(LIB_HOME)/libm-2.24.so:/lib/libm.so.6
INSTALL_APPS += $(LIB_HOME)/libacl.so.1.1.0:/lib/libacl.so.1
INSTALL_APPS += $(LIB_HOME)/libattr.so.1.1.0:/lib/libattr.so.1
INSTALL_APPS += $(LIB_HOME)/libz.so.1.2.8:/lib/libz.so.1

USR_LIB_HOME := $(DEBIAN_HOME)/usr/lib/mipsel-linux-gnu
INSTALL_APPS += $(USR_LIB_HOME)/libgpm.so.2:/usr/lib/mipsel-linux-gnu/libgpm.so.2
INSTALL_APPS += $(USR_LIB_HOME)/libisl.so.15.3.0:/usr/lib/mipsel-linux-gnu/libisl.so.15
INSTALL_APPS += $(USR_LIB_HOME)/libmpc.so.3.0.0:/usr/lib/mipsel-linux-gnu/libmpc.so.3
INSTALL_APPS += $(USR_LIB_HOME)/libmpfr.so.4.1.5:/usr/lib/mipsel-linux-gnu/libmpfr.so.4
INSTALL_APPS += $(USR_LIB_HOME)/libgmp.so.10.3.2:/usr/lib/mipsel-linux-gnu/libgmp.so.10

INSTALL_APPS += $(USR_LIB_HOME)/libopcodes-2.28-system.so:/usr/lib/mipsel-linux-gnu/libopcodes-2.28-system.so
INSTALL_APPS += $(USR_LIB_HOME)/libbfd-2.28-system.so:/usr/lib/mipsel-linux-gnu/libbfd-2.28-system.so

GCC6_LIB_HOME := $(DEBIAN_HOME)/usr/lib/gcc/mipsel-linux-gnu/6
INSTALL_APPS += $(GCC6_LIB_HOME)/liblto_plugin.so.0.0.0:/usr/lib/gcc/mipsel-linux-gnu/6/liblto_plugin.so

# gcc link libs
INSTALL_APPS += $(DEBIAN_HOME)/usr/lib/mipsel-linux-gnu/Scrt1.o:/usr/lib/mipsel-linux-gnu/Scrt1.o
INSTALL_APPS += $(DEBIAN_HOME)/usr/lib/mipsel-linux-gnu/crti.o:/usr/lib/mipsel-linux-gnu/crti.o
INSTALL_APPS += $(DEBIAN_HOME)/usr/lib/mipsel-linux-gnu/crtn.o:/usr/lib/mipsel-linux-gnu/crtn.o
INSTALL_APPS += $(DEBIAN_HOME)/usr/lib/gcc/mipsel-linux-gnu/6/crtbeginS.o:/usr/lib/gcc/mipsel-linux-gnu/6/crtbeginS.o
INSTALL_APPS += $(DEBIAN_HOME)/usr/lib/gcc/mipsel-linux-gnu/6/crtendS.o:/usr/lib/gcc/mipsel-linux-gnu/6/crtendS.o
INSTALL_APPS += $(DEBIAN_HOME)/usr/lib/mipsel-linux-gnu/libc.a:/usr/lib/mipsel-linux-gnu/libc.a
INSTALL_APPS += $(DEBIAN_HOME)/usr/lib/mipsel-linux-gnu/libc_nonshared.a:/usr/lib/mipsel-linux-gnu/libc_nonshared.a
INSTALL_APPS += $(DEBIAN_HOME)/usr/lib/mipsel-linux-gnu/libc.so:/usr/lib/mipsel-linux-gnu/libc.so
INSTALL_APPS += $(DEBIAN_HOME)/lib/mipsel-linux-gnu/libc-2.24.so:/lib/mipsel-linux-gnu/libc.so.6
INSTALL_APPS += $(DEBIAN_HOME)/lib/mipsel-linux-gnu/ld-2.24.so:/lib/mipsel-linux-gnu/ld.so.1
INSTALL_APPS += $(DEBIAN_HOME)/usr/lib/gcc/mipsel-linux-gnu/6/libgcc.a:/usr/lib/gcc/mipsel-linux-gnu/6/libgcc.a
INSTALL_APPS += $(DEBIAN_HOME)/usr/lib/gcc/mipsel-linux-gnu/6/libgcc_s.so:/usr/lib/gcc/mipsel-linux-gnu/6/libgcc_s.so
INSTALL_APPS += $(DEBIAN_HOME)/lib/mipsel-linux-gnu/libgcc_s.so.1:/lib/mipsel-linux-gnu/libgcc_s.so.1
INSTALL_APPS += link/libgcc_s.so.1:/usr/lib/gcc/mipsel-linux-gnu/6/libgcc_s.so.1

include $(ROOTFS_HOME)/Makefile.app
