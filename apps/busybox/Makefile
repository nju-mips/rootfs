export CROSS_COMPILE=$(ROOTFS_HOME)/../buildroot/output/host/bin/mipsel-buildroot-linux-uclibc-

REPO_PATH   := repo
BUSYBOX_ELF := $(abspath $(REPO_PATH)/busybox)

$(CROSS_COMPILE)gcc:
	cd ../buildroot && make noop_defconfig && make toolchain

$(REPO_PATH):
	mkdir -p $@
	git clone --depth 1 -b 1_29_stable git://git.busybox.net/busybox $@

$(BUSYBOX_ELF): $(CROSS_COMPILE)gcc $(REPO_PATH)
	cp config $(@D)/.config
	-$(MAKE) -C $(REPO_PATH) -j16

APPLETS != cd applets && ls
INSTALL_APPS := $(BUSYBOX_ELF):/bin/busybox
INSTALL_APPS += $(foreach app,$(APPLETS),applets/$(app):/bin/$(app))
include $(ROOTFS_HOME)/Makefile.app
