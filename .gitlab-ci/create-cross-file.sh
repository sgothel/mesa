#!/bin/bash

arch=$1
cross_file="/cross_file-$arch.txt"
/usr/share/meson/debcrossgen --arch $arch -o "$cross_file"
# Explicitly set ccache path for cross compilers
sed -i "s|/usr/bin/\([^-]*\)-linux-gnu\([^-]*\)-g|/usr/lib/ccache/\\1-linux-gnu\\2-g|g" "$cross_file"
if [ "$arch" = "i386" ]; then
    # Work around a bug in debcrossgen that should be fixed in the next release
    sed -i "s|cpu_family = 'i686'|cpu_family = 'x86'|g" "$cross_file"
fi
# Rely on qemu-user being configured in binfmt_misc on the host
sed -i -e '/\[properties\]/a\' -e "needs_exe_wrapper = False" "$cross_file"

# Set up cmake cross compile toolchain file for dEQP builds
toolchain_file="/toolchain-$arch.cmake"
if [[ "$arch" = "arm64" ]]; then
    GCC_ARCH="aarch64-linux-gnu"
    DE_CPU="DE_CPU_ARM_64"
    CMAKE_ARCH=arm
elif [[ "$arch" = "armhf" ]]; then
    GCC_ARCH="arm-linux-gnueabihf"
    DE_CPU="DE_CPU_ARM"
    CMAKE_ARCH=arm
fi

if [[ -n "$GCC_ARCH" ]]; then
    echo "set(CMAKE_SYSTEM_NAME Linux)" > "$toolchain_file"
    echo "set(CMAKE_SYSTEM_PROCESSOR arm)" >> "$toolchain_file"
    echo "set(CMAKE_C_COMPILER /usr/lib/ccache/$GCC_ARCH-gcc)" >> "$toolchain_file"
    echo "set(CMAKE_CXX_COMPILER /usr/lib/ccache/$GCC_ARCH-g++)" >> "$toolchain_file"
    echo "set(ENV{PKG_CONFIG} \"/usr/bin/$GCC_ARCH-pkg-config\")" >> "$toolchain_file"
    echo "set(DE_CPU $DE_CPU)" >> "$toolchain_file"
fi
