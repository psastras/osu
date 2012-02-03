FILE(REMOVE_RECURSE
  "CMakeFiles/libmad"
  "CMakeFiles/libmad-complete"
  "libmad-prefix/src/libmad-stamp/libmad-install"
  "libmad-prefix/src/libmad-stamp/libmad-mkdir"
  "libmad-prefix/src/libmad-stamp/libmad-download"
  "libmad-prefix/src/libmad-stamp/libmad-update"
  "libmad-prefix/src/libmad-stamp/libmad-patch"
  "libmad-prefix/src/libmad-stamp/libmad-configure"
  "libmad-prefix/src/libmad-stamp/libmad-build"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/libmad.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
