# Starting script

set +x

IMG_NAME=exercism

function build() {
	docker build . -t ${IMG_NAME}
}

exec=$(docker images -q "$IMG_NAME" 2> /dev/null)

if [[ -z "$exec" ]]; then
	build
fi

if [[ "$@" == 0 ]]; then
	echo "Need to specify the file to download"
	exit 1
fi

helpFunction() {
	echo " "
	echo "Usage: $0 -t \"Track\" -f \"File\" -s \"Submit-files\""
	echo -e "\t-t \"Track to download from, example: go\""
	echo -e "\t-f \"File to download from the track\""
	echo -e "\t-s \"File to submit to exercism\""
	echo -e "\t-a \"Attach shell to container\""
	echo -e "\t-h \"Display help message\""
	exit 1
}

SHELL=""

# Read in arguments
while getopts "t:f:s:bah" opt
do
   case "$opt" in
      t ) TRACK="$OPTARG" ;;
      f ) FILE="$OPTARG" ;;
	  s ) SUBMITFILES="$OPTARG" ;;
	  b ) build ;;
	  a ) SHELL=/bin/bash ;;
	  h ) helpFunction ;;
      ? ) helpFunction ;; # Print helpFunction in case parameter is non-existent
   esac
done

# Both flags need to be present
if [ -z "$TRACK" ] && [ -z "$FILE" ] && [ -z "$SUBMITFILES" ] 
then
	helpFunction
fi

local_user=$(id -u ${USER})
local_group=$(id -g ${USER})

		#-u ${local_user}:${local_group} \
# Run and download the specified exercism file
docker run --rm -v ${PWD}:/source/hostvolume \
		-e "TRACK=$TRACK" \
		-e "FILE=$FILE" \
		-e "SUBMITFILES=$SUBMITFILES" \
		-e "local_group=$local_group" \
		-e "local_user=$local_user" \
		-it ${IMG_NAME} 
