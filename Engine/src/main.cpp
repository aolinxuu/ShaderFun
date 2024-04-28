#include <vulkan/vulkan.hpp>
#include <iostream>

int main() {
    // Set up the application info
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Vulkan";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;  // Ensure you're using a defined Vulkan API version.

    // Set up the instance create info
    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    // Create the Vulkan instance
    VkInstance instance;
    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to create Vulkan instance." << std::endl;
        return -1;  // Use an error code like -1 to indicate failure.
    }

    std::cout << "Vulkan instance created successfully." << std::endl;

    // Clean up the Vulkan instance before exiting
    vkDestroyInstance(instance, nullptr);

    return 0;
}
