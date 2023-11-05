COLOR_RED := $(shell echo "\033[1;31m")
COLOR_END := $(shell echo "\033[0m")

ifeq ($(wildcard $(WORK_DIR)/.config),)
$(warning $(COLOR_RED)Warning: .config does not exists!$(COLOR_END))
$(warning $(COLOR_RED)To build the project, first run 'make menuconfig'.$(COLOR_END))
endif

Q            := @
KCONFIG_PATH := $(WORK_DIR)/tools/kconfig
Kconfig      := $(WORK_DIR)/Kconfig
rm-distclean += config/ .config .config.old
silent := -s

export KCONFIG_AUTOCONFIG = $(WORK_DIR)/config/auto.conf
export KCONFIG_AUTOHEADER = $(CC_SRC_HOME)/include/autoconf.h

CONF   := $(KCONFIG_PATH)/build/conf
MCONF  := $(KCONFIG_PATH)/build/mconf

$(CONF):
	$(Q)$(MAKE) $(silent) -C $(KCONFIG_PATH) NAME=conf

$(MCONF):
	$(Q)$(MAKE) $(silent) -C $(KCONFIG_PATH) NAME=mconf

menuconfig: $(MCONF) $(CONF)
	$(Q)$(MCONF) $(Kconfig)
	$(Q)$(CONF) $(silent) --syncconfig $(Kconfig)

savedefconfig: $(CONF)
	$(Q)$< $(silent) --$@=configs/defconfig $(Kconfig)

%defconfig: $(CONF)
	$(Q)$< $(silent) --defconfig=configs/$@ $(Kconfig)
	$(Q)$< $(silent) --syncconfig $(Kconfig)

.PHONY: menuconfig savedefconfig defconfig

# Help text used by make help
help:
	@echo  '  menuconfig	  - Update current config utilising a menu based program'
	@echo  '  savedefconfig   - Save current config as configs/defconfig (minimal config)'

distclean: clean
	-@rm -rf $(rm-distclean)

CC_CONFIG = $(CC_SRC_HOME)/include/autoconf.h
SV_CONFIG = $(V_SRC_HOME)/include/config_generated.svh

# define configs
$(SV_CONFIG): $(CC_CONFIG)
	@sed -e '1i `ifndef SYNTHESIS' -e 's/#/`/g' -e '$$a `endif' $(CC_CONFIG) > $(SV_CONFIG)
	
.PHONY: help distclean