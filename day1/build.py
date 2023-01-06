#!/usr/bin/env python3

import os

def build_project():
    # Get the path to the current directory
    project_dir = os.getcwd()

    # Create a build directory
    build_dir = os.path.join(project_dir, "build")
    os.makedirs(build_dir, exist_ok=True)

    # Generate the makefiles
    os.system(f"cmake {project_dir} -B{build_dir}")

    # Build the project
    os.system(f"cmake --build {build_dir}")

# Example usage
build_project()
        