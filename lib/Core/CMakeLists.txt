set(LIBSRC )
add_library("BonoCore" SHARED "${LIBSRC}")
set_target_properties("BonoCore" PROPERTIES FOLDER "Yarr3D")
target_include_directories("BonoCore" PRIVATE ${Vulkan_INCLUDE_DIRS} ${BONO_GLFW_INCLUDES} ${YARR_GLM_INCLUDES})