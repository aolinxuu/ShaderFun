ASSEMBLY:= src
BUILD_DIR:= bin

COMPILER_FLAGS := -std=c++2a
INCLUDE_FLAGS:= -I$(VULKAN_SDK)/include
LINKER_FLAGS:= -L$(VULKAN_SDK)/lib -lMoltenVK -o test

SRC_FILES:= $(shell find $(ASSEMBLY) -type f \( -name "*.cpp" \))

.PHONY: build
build:
	@clang++ $(COMPILER_FLAGS) $(SRC_FILES) -o $(BUILD_DIR)/app $(INCLUDE_FLAGS) $(LINKER_FLAGS)


