# compiler settings
CXX = g++
CXXFLAGS = -std=gnu++17 -O2 -Wall -Wextra

# directoy settings
BUILD_DIR = build
TEST_DIR = test
ID := $(patsubst ABC_%,%,$(notdir $(CURDIR)))

# rules
.PHONY: clean

hello:
	@echo "Welcome to ABC $(ID)!"

$(BUILD_DIR)/%: %.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

test%: $(BUILD_DIR)/%
	@echo "Running test $*..."
	@./$(BUILD_DIR)/$* < $(TEST_DIR)/$*.in > $(TEST_DIR)/$*.tmp
	@diff -u $(TEST_DIR)/$*.out $(TEST_DIR)/$*.tmp || true

run%: $(BUILD_DIR)/%
	@./$(BUILD_DIR)/$* < $(TEST_DIR)/$*.in

clean:
	rm -rf $(BUILD_DIR) $(TEST_DIR)/*.tmp

