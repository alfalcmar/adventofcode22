#!/usr/bin/env python3
import os
import argparse

def create_hello_world_cpp(project_name):
    # Create a new directory for the project
    project_dir = project_name
    os.makedirs(project_dir)

    # Create the src directory
    src_dir = os.path.join(project_dir, "src")
    os.makedirs(src_dir)

    # Create the CMakeLists.txt file
    with open(os.path.join(project_dir, "CMakeLists.txt"), "w") as f:
        f.write("""cmake_minimum_required(VERSION 3.10)
project({project_name})

set(CMAKE_CXX_STANDARD 20)

# Add an executable target
add_executable(hello_world src/main.cpp)
        """.format(project_name=project_name))
    # Create build file
    with open(os.path.join(project_dir,"build.py"),"w") as f:
        f.write("""#!/usr/bin/env python3

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
        """)
    # give permission access
    build_path = project_dir + "/build.py"
    os.chmod(build_path, 0o777)

    # Create the main.cpp file
    with open(os.path.join(src_dir, "main.cpp"), "w") as f:
        f.write("""#include <iostream>
#include<ranges>
#include<string>
#include<utility>
#include<fstream>
#include<vector>
int main() {
    std::vector<std::string> lines; 
    std::string line;
    std::ifstream file("../input.txt");
    if (file.is_open()) {
        while (std::getline(file, line)) {
            lines.push_back(std::move(line));
        }
        file.close();
    } else {
        std::cout<< "file could not be opened"<<std::endl;
    }

    return 0;
}
        """)
    # Create a txt file
    filename = project_dir + "/input.txt"
    open(filename, "w").close()

    # Print a message
    print(f"Successfully created project {project_name}!")

# Parse command-line arguments
parser = argparse.ArgumentParser()
parser.add_argument("project_name", help="name of the project to create")
args = parser.parse_args()

# Create the project
create_hello_world_cpp(args.project_name)

