ifeq ($(ROOTFS_HOME),)
$(error ROOTFS_HOME is not defined)
endif

ifeq ($(INSTALL_APPS),)
$(error INSTALL_APPS is not defined)
endif

define install_from
$(firstword $(subst :, ,$1))
endef

define install_dependency
$(shell if [ ! -L $(call install_from,$1) ]; then \
  echo $(call install_from,$1); else echo; fi)
endef

define install_target
$(ROOTFS_HOME)/build/root/$(lastword $(subst :, ,$1))
endef

define make_install
$(call install_target,$1): $(call install_dependency,$1)
	mkdir -p $$(@D)
	cp -d $(call install_from,$1) $$@
endef

$(foreach app,$(INSTALL_APPS),$(eval $(call make_install,$(app))))

.PHONY: install clean

install: $(foreach app,$(INSTALL_APPS),$(call install_target,$(app)))

clean:
