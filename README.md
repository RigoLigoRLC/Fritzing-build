
# fritzing-build

A Windows build of Fritzing, with all modified dependencies.

# Modifications

Fritzing was modified so it will not use QWindows11Style (it doesn't work very well, for example PNG export DPI selector uses a QSpinBox and it will get ridiculously small when using QWindows11Style). QMake pri file was modified so it will find Boost 1.82. Some places also has "$$_PRO_FILE_PWD_/../" edits.

QuaZip CMakeLists was edited so it can work with Qt6's ZlibPrivate. BZip and GZip are disabled as Fritzing doesn't seem to use it. GZip is disabled because Qt6 doesn't expose that Zlib API.

Boost 1.82 is a verbatim copy.

Clipper1 6.4.2 is a verbatim copy.

libgit2 is a verbatim copy.

ngspice-42 is a verbatim copy from my computer's vcpkg downloads.

svgpp-1.3.1 is a verbatim copy.

`Clipper1-6.4.2` and `quazip-6.8.0-1.4` are two empty directories that was kept to tell you you should set CMAKE_INSTALL_PREFIX to these places so they will get installed correctly. libgit2 should be built in `libgit2/build64` (use build32 if you really want to run it on a 32 bit system) directory.

