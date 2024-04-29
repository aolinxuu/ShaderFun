#pragma once
#include <vulkan/vulkan.hpp>
#include "vulkan_queue.hpp"

QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
VkPhysicalDevice getPhysicalDevice(VkInstance instance);
