#!/bin/bash

# Ensure the script is run from the parent directory of 'faculti'
if [ ! -d "faculti" ]; then
    echo "Error: 'faculti' directory not found. Please run this script from your HOME directory and ensure faculti exists."
    exit 1
fi

echo "Changing access control permissions..."

# Change permissions for 'subjects' directory to 770
chmod 770 faculti/subject

# Change permissions for 'Best_of_software_engineering' file to 650
# ENSURE THIS IS EXACTLY 'Best_of_software_engineering' (with underscores)
chmod 650 faculti/books/Best_of_software_engineering

# Change permissions for 'FCS' directory to 607
chmod 607 faculti/ECS

# Change permissions for 'Project_Manager' file to 055
# ENSURE THIS IS EXACTLY 'Project_Manager' (with underscore)
chmod 055 faculti/FRE/Project_Manager

echo "Access control permissions updated successfully."
