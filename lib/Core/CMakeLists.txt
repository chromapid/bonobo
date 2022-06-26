set(LIBSRC "dummy.cpp")
add_library("BonoCore" SHARED "${LIBSRC}")
set_target_properties("BonoCore" PROPERTIES FOLDER "Bono")
target_include_directories("BonoCore" PUBLIC "${BONO_INCLUDES}")