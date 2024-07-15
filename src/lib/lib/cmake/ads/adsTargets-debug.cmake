#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ads::ads" for configuration "Debug"
set_property(TARGET ads::ads APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ads::ads PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/ads.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/ads.dll"
  )

list(APPEND _cmake_import_check_targets ads::ads )
list(APPEND _cmake_import_check_files_for_ads::ads "${_IMPORT_PREFIX}/lib/ads.lib" "${_IMPORT_PREFIX}/bin/ads.dll" )

# Import target "ads::AdsTool" for configuration "Debug"
set_property(TARGET ads::AdsTool APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ads::AdsTool PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/AdsTool.exe"
  )

list(APPEND _cmake_import_check_targets ads::AdsTool )
list(APPEND _cmake_import_check_files_for_ads::AdsTool "${_IMPORT_PREFIX}/bin/AdsTool.exe" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
