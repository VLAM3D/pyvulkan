%carray_of_float(float)
%carray_of_long(int32_t)
%carray_of_long(uint32_t)
%carray_of_struct(VkMemoryType)
%carray_of_struct(VkMemoryHeap)
%ref_counted_handle(VkPhysicalDevice)
%ref_counted_handle(VkSwapchainKHR)
%ref_counted_handle(VkDisplayKHR)
%ref_counted_handle(VkDevice)
%ref_counted_handle(VkBufferView)
%ref_counted_handle(VkFence)
%ref_counted_handle(VkDescriptorSetLayout)
%ref_counted_handle(VkSemaphore)
%ref_counted_handle(VkDeviceMemory)
%ref_counted_handle(VkShaderModule)
%ref_counted_handle(VkCommandPool)
%ref_counted_handle(VkPipeline)
%ref_counted_handle(VkImage)
%ref_counted_handle(VkBuffer)
%ref_counted_handle(VkFramebuffer)
%ref_counted_handle(VkInstance)
%ref_counted_handle(VkPipelineCache)
%ref_counted_handle(VkImageView)
%ref_counted_handle(VkRenderPass)
%ref_counted_handle(VkDescriptorPool)
%ref_counted_handle(VkPipelineLayout)
%ref_counted_handle(VkDebugReportCallbackEXT)
%ref_counted_handle(VkSurfaceKHR)
%ref_counted_handle(VkEvent)
%ref_counted_handle(VkQueue)
%ref_counted_handle(VkDisplayModeKHR)
%ref_counted_handle(VkQueryPool)
%ref_counted_handle(VkSampler)
%shared_ptr(MirConnection)
%shared_ptr(xcb_connection_t)
%shared_ptr(Display)
%shared_ptr(wl_display)
%raii_struct(VkCommandBufferBeginInfo)
%raii_struct(VkApplicationInfo)
%raii_struct(VkDisplayPropertiesKHR)
%raii_struct(VkSubmitInfo)
%raii_struct(VkSubpassDescription)
%raii_struct(VkWriteDescriptorSet)
%raii_struct(VkFramebufferCreateInfo)
%raii_struct(VkPipelineLayoutCreateInfo)
%raii_struct(VkSwapchainCreateInfoKHR)
%raii_struct(VkPipelineViewportStateCreateInfo)
%raii_struct(VkDescriptorPoolCreateInfo)
%raii_struct(VkInstanceCreateInfo)
%raii_struct(VkDeviceCreateInfo)
%raii_struct(VkBufferCreateInfo)
%raii_struct(VkSpecializationInfo)
%raii_struct(VkBindSparseInfo)
%raii_struct(VkRenderPassCreateInfo)
%raii_struct(VkGraphicsPipelineCreateInfo)
%raii_struct(VkDescriptorSetLayoutBinding)
%raii_struct(VkPipelineShaderStageCreateInfo)
%raii_struct(VkSparseBufferMemoryBindInfo)
%raii_struct(VkDeviceQueueCreateInfo)
%raii_struct(VkDescriptorSetLayoutCreateInfo)
%raii_struct(VkSparseImageMemoryBindInfo)
%raii_struct(VkDescriptorSetAllocateInfo)
%raii_struct(VkSparseImageOpaqueMemoryBindInfo)
%raii_struct(VkPipelineDynamicStateCreateInfo)
%raii_struct(VkImageCreateInfo)
%raii_struct(VkRenderPassBeginInfo)
%raii_struct(VkPipelineVertexInputStateCreateInfo)
%raii_struct(VkPresentInfoKHR)
%raii_struct(VkPipelineColorBlendStateCreateInfo)

%apply (unsigned int* IN_ARRAY1, int DIM1) {(unsigned int* pImageIndices_in_array1, int pImageIndices_dim1)};
%apply (float* IN_ARRAY1, int DIM1) {(float* pQueuePriorities_in_array1, int pQueuePriorities_dim1)};
%apply (unsigned int* IN_ARRAY1, int DIM1) {(unsigned int* pPreserveAttachments_in_array1, int pPreserveAttachments_dim1)};
%apply (unsigned int* IN_ARRAY1, int DIM1) {(unsigned int* pQueueFamilyIndices_in_array1, int pQueueFamilyIndices_dim1)};
%apply (unsigned int* IN_ARRAY1, int DIM1) {(unsigned int* pDynamicOffsets_in_array1, int pDynamicOffsets_dim1)};
