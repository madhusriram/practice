# Starting script for testing

IMG_NAME=testimg
# Build the testimg container
function build() {
	docker build . -t ${IMG_NAME}
}

if [[ "$(docker images -q testimg 2> /dev/null)" == "" ]] || [[ $1 == "-f" ]]; then
	build
fi

# Run it now by mapping the volume of interest
docker run --rm  -v ${PWD}:/source -it ${IMG_NAME}

# Blow up the build directory
rm -rf build
