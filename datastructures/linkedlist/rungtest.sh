# Starting script for testing

IMG_NAME=testimg
# Build the testimg container
docker build . -t ${IMG_NAME}

# Run it now by mapping the volume of interest
docker run --rm  -v ${PWD}:/source -it ${IMG_NAME}

# Blow up the build directory
rm -rf build
