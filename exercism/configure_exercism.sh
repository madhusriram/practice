#!/bin/bash
# This script runs inside the container and configures exercism CLI

ver=$(exercism version)

if [ -z "$ver" ]; then
	echo "Exercism not installed"
	exit 1
fi

# Change workspace based on the track
# If track is go configure download folder to be go/
if [[ "$TRACK" == "go" ]]; then
	downloadfolder=/source/hostvolume/go/
elif [[ "$TRACK" == "cpp" ]]; then
	downloadfilder=/source/hostvolume/cpp/
elif [[ "$TRACK" == "c" ]]; then
	downloadfolder=/source/hostvolume/c/
fi

# Configure exercism
exercism configure --token=b89e5400-3ff7-4622-a606-0665f67e13fc
# Update the downloaded folder
exercism configure -w "$downloadfolder"

# Download
if [ -z "$SUBMITFILES" ]
then
	exercism download --exercise=$FILE --track=$TRACK
else
	exercism submit $SUBMITFILES
fi
