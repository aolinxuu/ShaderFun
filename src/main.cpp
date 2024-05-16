#include <vulkan/vulkan.hpp>
#include <iostream>
#include "render/vulkan_setup.hpp"

int main() {
    // Set up the application info
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Vulkan";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0; 

    // Create info
    VkInstanceCreateInfo instanceCreateInfo = {};
    instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceCreateInfo.pApplicationInfo = &appInfo;

    // Create the Vulkan instance
    VkInstance instance;
    VkResult result = vkCreateInstance(&instanceCreateInfo, nullptr, &instance);

    if (result != 0) {
        std::cout << "Failed to create Vulkan instance." << std::endl;
        return -1; 
    }
    std::cout << "Vulkan instance created successfully." << std::endl;

    VkPhysicalDevice physicalDevice = getPhysicalDevice(instance);
    VkDevice logicalDevice;

    QueueFamilyIndices indices = findQueueFamilies(physicalDevice);
    VkDeviceQueueCreateInfo queueCreateInfo{};
    queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    queueCreateInfo.queueFamilyIndex = indices.graphicsFamily.value();
    queueCreateInfo.queueCount = 1;
    float queuePriority = 1.0f;
    queueCreateInfo.pQueuePriorities = &queuePriority;


    VkPhysicalDeviceFeatures deviceFeatures{};

    VkDeviceCreateInfo deviceCreateInfo{};
    deviceCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    deviceCreateInfo.pQueueCreateInfos = &queueCreateInfo;
    deviceCreateInfo.queueCreateInfoCount = 1;
    deviceCreateInfo.pEnabledFeatures = &deviceFeatures;
    deviceCreateInfo.enabledExtensionCount = 0;

    // Clean up the Vulkan instance before exiting
    vkDestroyInstance(instance, nullptr);
    return 0;
}