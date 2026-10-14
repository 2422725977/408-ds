# 408 数据结构练习 —— 一键编译运行
# 用法：make run f=linearlist/01-顺序表基本操作.c
#       make build f=sort/04-快速排序.c

CC      ?= cc
CFLAGS  ?= -std=c11 -Wall -Wextra -g -fsanitize=address,undefined
BIN_DIR := build

.PHONY: build run clean list

build:
	@test -n "$(f)" || (echo "用法: make build f=路径/文件.c"; exit 1)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) "$(f)" -o "$(BIN_DIR)/$(notdir $(basename $(f)))"
	@echo "✅ 编译完成: $(BIN_DIR)/$(notdir $(basename $(f)))"

run: build
	@"$(BIN_DIR)/$(notdir $(basename $(f)))"

list:
	@find . -name '*.c' -not -path './build/*' | sort

clean:
	@rm -rf $(BIN_DIR)
	@echo "🧹 已清理 build/"
