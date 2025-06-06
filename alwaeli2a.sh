#!/bin/bash

# Ensure we start fresh for Figure 1 structure
rm -rf faculti

# Create the main 'faculti' directory and enter it
mkdir faculti
cd faculti

# Create 'subject' directory and its files
mkdir subject
cd subject
echo "operating systems" > operating_systems
echo "software engineering" > software_engineering
echo "data communication" > data_communication
cd .. # Go back to 'faculti'

# Create 'books' directory and its files
mkdir books
cd books
echo "Linux operating systems" > Linux_operating_systems
# THIS IS CRUCIAL: Filename has underscores
echo "Best of software engineering" > Best_of_software_engineering
cd .. # Go back to 'faculti'

# Create 'ECS' directory and its files
mkdir ECS
cd ECS
echo "dean" > dean
echo "deputy dean" > deputy_dean
cd .. # Go back to 'faculti'

# Create 'FRE' directory and its file
mkdir FRE
cd FRE
# THIS IS CRUCIAL: Filename has underscore
echo "Project Manager" > Project_Manager
cd .. # Go back to 'faculti' (script finishes, so you'll be back in $HOME)

echo "Directory structure for Figure 1 created successfully under faculti/."
