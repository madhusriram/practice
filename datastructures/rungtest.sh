# Starting script for testing

IMG_NAME=testimg

dockershell=

# Build the container
function build() {
	docker build . -t ${IMG_NAME}
}

for i in "$@"; do
	case "$i" in
		-f)
			build
			shift
			;;
		-d)
			dockershell="/bin/bash"
			shift
			;;
	esac
done

if [[ "$(docker images -q testimg 2> /dev/null)" == "" ]]; then
	build
fi

LOCAL_USER_ID=`id -u`
LOCAL_GROUP_ID=`id -g`

# Run it now by mapping the volume of interest
docker run --rm  -v ${PWD}:/source -it \
		--cap-add=SYS_PTRACE --security-opt seccomp=unconfined \
		${IMG_NAME} \
		${dockershell}

rm -rf build
