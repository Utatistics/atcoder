# compiler settings
CXX = g++
CXXFLAGS = -std=gnu++17 -O2 -Wall -Wextra

# directory settings
BUILD_DIR = build
TEST_DIR = test
STRESS_DIR = stress
ID := $(patsubst ABC_%,%,$(notdir $(CURDIR)))

# stress test settings
STRESS_TESTS ?= 10000

# ANSI color codes
GREEN  := \033[0;32m
RED    := \033[0;31m
NC     := \033[0m   # No Color

# rules
.PHONY: clean

hello:
        @echo "Welcome to ABC $(ID)!"

# normal build
$(BUILD_DIR)/%: %.cpp
        @mkdir -p $(BUILD_DIR)
        $(CXX) $(CXXFLAGS) $< -o $@

# debug build for gdb
$(BUILD_DIR)/%_dbg: %.cpp
        @mkdir -p $(BUILD_DIR)
        $(CXX) -std=gnu++17 -O0 -g -DDEBUG $< -o $@

# run tests
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

# run program with test input
run%: $(BUILD_DIR)/%
        @./$(BUILD_DIR)/$* < $(TEST_DIR)/$*.in

# run interactive program
runi%: $(BUILD_DIR)/%
        @./$(BUILD_DIR)/$*

# gdb debug
gdb%: $(BUILD_DIR)/%_dbg
        @gdb -tui ./$(BUILD_DIR)/$*_dbg

# stress testing
stress%: $(BUILD_DIR)/%
        @mkdir -p $(BUILD_DIR)/stress
        @$(CXX) $(CXXFLAGS) $(STRESS_DIR)/$*.cpp -o $(BUILD_DIR)/stress/$*_brute
        @$(CXX) $(CXXFLAGS) $(STRESS_DIR)/$$(echo $* | tr '[:upper:]' '[:lower:]').cpp -o $(BUILD_DIR)/stress/$*_gen
        @echo "Stress testing $*..."
        @for i in $$(seq 1 $(STRESS_TESTS)); do \
                ./$(BUILD_DIR)/stress/$*_gen > $(TEST_DIR)/$*.stress.in; \
                ./$(BUILD_DIR)/$* < $(TEST_DIR)/$*.stress.in > $(TEST_DIR)/$*.stress.out; \
                ./$(BUILD_DIR)/stress/$*_brute < $(TEST_DIR)/$*.stress.in > $(TEST_DIR)/$*.stress.brute; \
                if ! diff -q $(TEST_DIR)/$*.stress.out $(TEST_DIR)/$*.stress.brute > /dev/null; then \
                        echo -e "$(RED)Mismatch found on test $$i! ❌$(NC)"; \
                        echo ""; \
                        echo "Input:"; \
                        cat $(TEST_DIR)/$*.stress.in; \
                        echo ""; \
                        echo "Your output:"; \
                        cat $(TEST_DIR)/$*.stress.out; \
                        echo ""; \
                        echo "Random output:"; \
                        cat $(TEST_DIR)/$*.stress.brute; \
                        cp $(TEST_DIR)/$*.stress.in $(TEST_DIR)/$*.in; \
                        rm -f $(TEST_DIR)/$*.stress.in \
                              $(TEST_DIR)/$*.stress.out \
                              $(TEST_DIR)/$*.stress.brute \
                              $(BUILD_DIR)/stress/$*_brute \
                              $(BUILD_DIR)/stress/$*_gen; \
                        rmdir $(BUILD_DIR)/stress 2>/dev/null || true; \
                        exit 1; \
                fi; \
                if [ $$((i % 100)) -eq 0 ]; then \
                        echo "$$i tests passed"; \
                fi; \
        done; \
        echo -e "$(GREEN)All $(STRESS_TESTS) tests passed! ✅$(NC)"; \
        rm -f $(TEST_DIR)/$*.stress.in \
              $(TEST_DIR)/$*.stress.out \
              $(TEST_DIR)/$*.stress.brute \
              $(BUILD_DIR)/stress/$*_brute \
              $(BUILD_DIR)/stress/$*_gen; \
        rmdir $(BUILD_DIR)/stress 2>/dev/null || true

clean:
        rm -rf $(BUILD_DIR) $(TEST_DIR)/*.tmp $(TEST_DIR)/*.diff
