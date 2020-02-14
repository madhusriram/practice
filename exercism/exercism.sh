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
	downloadfolder=/source/hostvolume/cpp/
elif [[ "$TRACK" == "c" ]]; then
	downloadfolder=/source/hostvolume/c/
fi

# Configure exercism
exercism configure --token=b89e5400-3ff7-4622-a606-0665f67e13fc
# Update the downloaded folder
exercism configure -w "$downloadfolder"

# Download or submit!
# For submitting please provide the track to
# change to the submitted file directory
if [ -z "$SUBMITFILES" ]
then
	exercism download --exercise="$FILE" --track="$TRACK"
else
	if [ -z "$TRACK" ]; then
		echo "Docker needs the track to submit files"
		exit 1
	fi
	exercism submit "$SUBMITFILES"
fi
