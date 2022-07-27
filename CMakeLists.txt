cmake_minimum_required(VERSION 3.1)
project(simpleISPCRTExample LANGUAGES CXX)

find_package(ispcrt REQUIRED)
find_package(rkcommon REQUIRED)
find_package(embree 4.0 REQUIRED)
add_executable(simpleISPCRTExample apps/example.cpp)
target_link_libraries(simpleISPCRTExample 
PUBLIC 
sycl 
OpenCL
omp
ze_loader
irng
imf
intlc
svml
rkcommon::rkcommon_sycl
$<BUILD_INTERFACE:ispcrt::ispcrt>
$<BUILD_INTERFACE:embree>)