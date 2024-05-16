#include "vulkan_setup.hpp"
#include <vulkan/vulkan.hpp>
#include <iostream>

bool isDeviceSuitable(VkPhysicalDevice device) {
    QueueFamilyIndices indices = findQueueFamilies(device);
    return indices.isComplete();
}

VkPhysicalDevice getPhysicalDevice(VkInstance instance) {
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    uint32_t deviceCount = 0;

    vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
    if (deviceCount == 0) {
        std::cout << "Failed to find GPUs with Vulkan support!" << std::endl;
        return 0;
    }

    std::vector<VkPhysicalDevice> devices(deviceCount);
    vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

    for (const auto& device : devices) {
        if (isDeviceSuitable(device)) {
            VkPhysicalDeviceProperties deviceProperties;
            vkGetPhysicalDeviceProperties(device, &deviceProperties);
            std::cout << "Successfully using GPU: " << deviceProperties.deviceName << std::endl;
            physicalDevice = device;
            break;
        }
    }
    return physicalDevice;
}