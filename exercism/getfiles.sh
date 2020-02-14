# Starting script

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
	exit 1
}

# Read in arguments
while getopts "t:f:s:b" opt
do
   case "$opt" in
      t ) TRACK="$OPTARG" ;;
      f ) FILE="$OPTARG" ;;
	  s ) SUBMITFILES="$OPTARG" ;;
	  b ) build ;;
      ? ) helpFunction ;; # Print helpFunction in case parameter is non-existent
   esac
done

# Both flags need to be present
if [ -z "$TRACK" ] && [ -z "$FILE" ] && [ -z "$SUBMITFILES" ] 
then
	helpFunction
fi

# Run and download the specified exercism file
docker run --rm -v ${PWD}:/source/hostvolume \
		-e "TRACK=$TRACK" \
		-e "FILE=$FILE" \
		-e "SUBMITFILES=$SUBMITFILES" \
		-it ${IMG_NAME}
