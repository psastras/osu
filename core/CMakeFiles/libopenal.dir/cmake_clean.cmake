FILE(REMOVE_RECURSE
  "CMakeFiles/libopenal"
  "CMakeFiles/libopenal-complete"
  "libopenal-prefix/src/libopenal-stamp/libopenal-install"
  "libopenal-prefix/src/libopenal-stamp/libopenal-mkdir"
  "libopenal-prefix/src/libopenal-stamp/libopenal-download"
  "libopenal-prefix/src/libopenal-stamp/libopenal-update"
  "libopenal-prefix/src/libopenal-stamp/libopenal-patch"
  "libopenal-prefix/src/libopenal-stamp/libopenal-configure"
  "libopenal-prefix/src/libopenal-stamp/libopenal-build"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/libopenal.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
