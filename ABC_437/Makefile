CXX = g++
CXXFLAGS = -std=gnu++17 -O2 -Wall -Wextra
BUILD_DIR = build
TEST_DIR = test

.PHONY: clean

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

%: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $(BUILD_DIR)/$@

test%: %
	@echo "Running test $*..."
	@./$(BUILD_DIR)/$* < $(TEST_DIR)/$*.in > $(TEST_DIR)/$*.tmp
	@diff -u $(TEST_DIR)/$*.out $(TEST_DIR)/$*.tmp || true

run%: %
	@./$(BUILD_DIR)/$* < $(TEST_DIR)/$*.in

clean:
	rm -rf $(BUILD_DIR) $(TEST_DIR)/*.tmp

