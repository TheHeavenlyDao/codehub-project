#!/bin/bash
##################################################################################################################
# # Author(s):	Squidy (https://github.com/gsemac)
# Description:	This script installs Allegro 5 on your computer. Will prompt for sudo password when installing
#				dependencies. Allegro's header files are copied to /usr/local/include/ and its library files are 
#				copied to /usr/local/lib.
##################################################################################################################

install_core="apt install git cmake libx11-dev libglu1-mesa-dev libxcursor-dev libxi-dev"
install_optional="apt install libfreetype6-dev libpng-dev libvorbis-dev libogg-dev libjpeg-turbo8-dev libpulse-dev libgtk2.0-dev libflac-dev libopenal-dev"
repository_url="https://github.com/liballeg/allegro5.git"

# Install core dependencies.
echo "Installing core dependencies (requires sudo)."
sudo $install_core

# Install add-on dependencies.
echo "Installing optional dependencies (requires sudo)."
sudo $install_optional 

# Clone the Allegro 5 github repository to the current directory.
echo "Cloning/updating Allegro 5 repository..."
if cd allegro5; then 
	git pull
else 
	git clone $repository_url
	cd allegro5 || exit 1
fi

# Create and cd into the build directory.
mkdir -p build
cd build

# Compile and install Allegro.
echo "Building Allegro 5..."
cmake ..
echo "Installing library files (requires sudo)."
sudo make -j2 install

# Delete the repository since we don't need it anymore.
echo "Cleaning up repository..."
sudo rm -rf ../../allegro5

echo "Process complete!"
