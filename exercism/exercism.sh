#!/bin/bash
# This script runs inside the container and configures exercism CLI

# Fail immediately
set -e
set -x
ver=$(exercism version)

if [ -z "$ver" ]; then
	echo "Exercism not installed"
	exit 1
fi

basedir=/source/hostvolume

# Change workspace based on the track
# If track is go configure download folder to be go/
if [[ "$TRACK" == "go" ]]; then
	downloadfolder=${basedir}/go/
elif [[ "$TRACK" == "cpp" ]]; then
	downloadfolder=${basedir}/cpp/
elif [[ "$TRACK" == "c" ]]; then
	downloadfolder=${basedir}/c/
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
	# Docker runs as root and the files downloaded to disk would be
	# of "root" user as well. Change the permission as the host passed-in
	# user type
	chown -R ${local_user}:${local_group} ${downloadfolder}/${TRACK}/${FILE}	
else
	if [ -z "$TRACK" ]; then
		echo "Docker needs the track to submit files"
		exit 1
	fi
	
	# File submission request can be for multiple files, csv seperated so, split 'em
	#SUBMITFILES=$(echo $SUBMITFILES | tr ',' ' ')
	IFS=', ' read -r -a array <<< "$SUBMITFILES"
	# Append basedir location to files
	len=$(echo "${#array[@]}")
	for i in "${!array[@]}"; do
		tmp="$basedir/${array[$i]}"
		if [ ! -z "$final" ]; then
			final+=" $tmp"
		else
			final="$tmp"
		fi
			
		# Take care of the trailing space
		if [ "$(($i + 1))" -le "$(($len - 1))" ]; then
			final="$final "
		fi
	done

	exercism submit $final
fi
