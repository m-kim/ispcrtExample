#include <iostream>
#include <CL/sycl.hpp>
#include <ispcrt.hpp>
int main()
{
    ispcrt::Device ispcrtDevice(ISPCRT_DEVICE_TYPE_CPU);
    std::cout << "WTF" << std::endl;
    std::cout << ispcrtDevice.deviceCount(ISPCRT_DEVICE_TYPE_CPU) << std::endl;
    std::cout << ispcrtDevice.nativePlatformHandle() << std::endl;
    auto syclPlatform = sycl::ext::oneapi::level_zero::make_platform(
    reinterpret_cast<pi_native_handle>(ispcrtDevice.nativePlatformHandle()));
    std::cout << "WTF1" << std::endl;
    auto syclDevice = sycl::ext::oneapi::level_zero::make_device(syclPlatform,
    reinterpret_cast<pi_native_handle>(ispcrtDevice.nativeDeviceHandle()));
    std::cout << "WTF2" << std::endl;

    std::cout << "Using GPU device from ISPCRT: " << syclDevice.get_info<sycl::info::device::name>() << std::endl;

    return 0;
}