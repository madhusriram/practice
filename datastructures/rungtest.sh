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

exec=$(docker images -q $IMG_NAME 2> /dev/null)
if [[ -z "$exec" ]]; then
	build
fi

# Run it now by mapping the volume of interest
docker run --rm  -v ${PWD}:/source -it \
		--cap-add=SYS_PTRACE --security-opt seccomp=unconfined \
		${IMG_NAME} \
		${dockershell}

rm -rf build
