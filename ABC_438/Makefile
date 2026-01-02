# compiler settings
CXX = g++
CXXFLAGS = -std=gnu++17 -O2 -Wall -Wextra
DBGFLAGS = -O0 -g -DDEBUG

# directory settings
BUILD_DIR = build
TEST_DIR = test
ID := $(patsubst ABC_%,%,$(notdir $(CURDIR)))

# ANSI color codes
GREEN  := \033[0;32m
RED    := \033[0;31m
NC     := \033[0m   # No Color

# rules
.PHONY: clean hello

hello:
	@echo "Welcome to ABC $(ID)!"

# normal build (optimized)
$(BUILD_DIR)/%: %.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

# debug build (no optimization, with symbols)
$(BUILD_DIR)/%_dbg: %.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(DBGFLAGS) $< -o $@

test%: $(BUILD_DIR)/%
	@echo "Running test $*..."
	@./$(BUILD_DIR)/$* < $(TEST_DIR)/$*.in > $(TEST_DIR)/$*.tmp
	@diff -u $(TEST_DIR)/$*.out $(TEST_DIR)/$*.tmp > $(TEST_DIR)/$*.diff || true
	@if [ ! -s $(TEST_DIR)/$*.diff ]; then \
		echo -e "$(GREEN)Test $* passed! ✅$(NC)"; \
		rm -f $(TEST_DIR)/$*.diff; \
	else \
		echo -e "$(RED)Test $* failed! ❌$(NC)"; \
		if command -v colordiff >/dev/null 2>&1; then \
			colordiff $(TEST_DIR)/$*.diff; \
		else \
			cat $(TEST_DIR)/$*.diff; \
		fi; \
	fi

run%: $(BUILD_DIR)/%
	@./$(BUILD_DIR)/$* < $(TEST_DIR)/$*.in

# run inside gdb with test input
gdb%: $(BUILD_DIR)/%_dbg
	@gdb ./$(BUILD_DIR)/$*_dbg

clean:
	rm -rf $(BUILD_DIR) $(TEST_DIR)/*.tmp $(TEST_DIR)/*.diff

