#! /bin/bash

VALGRIND_URL="https://sourceware.org/pub/valgrind/valgrind-3.15.0.tar.bz2"
VALGRIND_DOWNLOAD="valgrind.tar.bz2"

# Install all necessary tools except vscode and xcode

# Install Homebrew
if [[ -z $(command -v brew) ]]; then
    echo "Homebrew not found, installing it..."
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
elif [[ -n $(command -v brew) ]]; then
    echo "Homebrew installed!"
fi

# Install Valgrind
if [[ -z $(command -v valgrind) ]]; then
    echo "Valgrind not installed, trying to download from web"

    # Currently the official valgrind does not support Mac 10.15.4 Catalina

    # wget -O $VALGRIND_DOWNLOAD $VALGRIND_URL
    # bzip2 -d $VALGRIND_DOWNLOAD
    # mkdir ${VALGRIND_DOWNLOAD%%.*}
    # tar -xf ${VALGRIND_DOWNLOAD%.*} -C ${VALGRIND_DOWNLOAD%%.*} --strip-components=1
    # cd ${VALGRIND_DOWNLOAD%%.*}
    # ./configure
    # make
    # make install

    # Use the unofficial version instead

elif [[ -n $(command -v valgrind) ]]; then
    echo "Valgrind installed!"
fi 