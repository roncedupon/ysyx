-include $(NEMU_HOME)/../Makefile
include $(NEMU_HOME)/scripts/build.mk

include $(NEMU_HOME)/tools/difftest.mk

compile_git:
	$(call git_commit, "compile NEMU")
$(BINARY): compile_git

# Some convenient rules

override ARGS ?= --log=$(BUILD_DIR)/nemu-log.txt
override ARGS += $(ARGS_DIFF)

# Command to execute NEMU
IMG ?=
#“？=”表示如果该变量没有被赋值，则赋予等号后的值
NEMU_EXEC := $(BINARY) $(ARGS) $(IMG)
NENU_EXEC_BATCH := $(BINARY)
run-env: $(BINARY) $(DIFF_REF_SO)
	echo $(BINARY) 
	
run: run-env
	$(call git_commit, "run NEMU")
	$(NEMU_EXEC)
run_batch: 
	$(NEMU_EXEC) -b

gdb: run-env
	$(call git_commit, "gdb NEMU")
	gdb -s $(BINARY) --args $(NEMU_EXEC)
#-s:生成汇编文件

clean-tools = $(dir $(shell find ./tools -maxdepth 2 -mindepth 2 -name "Makefile"))
$(clean-tools):
	-@$(MAKE) -s -C $@ clean
clean-tools: $(clean-tools)
clean-all: clean distclean clean-tools

.PHONY: run gdb run-env clean-tools clean-all $(clean-tools)
