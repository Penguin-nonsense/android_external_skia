/*
 * Copyright 2022 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef skgpu_graphite_VulkanGraphiteUtils_DEFINED
#define skgpu_graphite_VulkanGraphiteUtils_DEFINED

#include <memory>

namespace skgpu { struct VulkanBackendContext; }

namespace skgpu::graphite {

class Context;
struct ContextOptions;

namespace ContextFactory {
std::unique_ptr<Context> MakeVulkan(const VulkanBackendContext&, const ContextOptions&);
} // namespace ContextFactory

} // namespace skgpu::graphite

#endif // skgpu_graphite_VulkanGraphiteUtils_DEFINED
