cmake_minimum_required (VERSION 3.10)

if(MSVC)
    set_target_properties(EnjoyObamium PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
endif()

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Enjoy Obamium Simulator")

set(VCPKG_MANIFEST_MODE ON)

find_package(glfw3 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(tinyexr CONFIG REQUIRED)
find_package(assimp CONFIG REQUIRED)

add_executable (EnjoyObamium "main.cpp" "headers/camera.cpp" "headers/shader.cpp" "headers/input.cpp" "headers/Mesh.cpp" "headers/Model.cpp")

target_link_libraries(EnjoyObamium PRIVATE fmt::fmt)
target_link_libraries(EnjoyObamium PRIVATE glfw)     
target_link_libraries(EnjoyObamium PRIVATE glad::glad)
target_link_libraries(EnjoyObamium PRIVATE glm::glm)
target_link_libraries(EnjoyObamium PRIVATE unofficial::tinyexr::tinyexr)
target_link_libraries(EnjoyObamium PRIVATE assimp::assimp)

add_custom_command(TARGET EnjoyObamium POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/shaders
    $<TARGET_FILE_DIR:EnjoyObamium>/shaders
)

add_custom_command(TARGET EnjoyObamium POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    $<TARGET_FILE_DIR:EnjoyObamium>/assets
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EnjoyObamium PROPERTY CXX_STANDARD 20)
endif()