BUILD_DIR = "./build"
SRC_DIR = "./src"
INSTALL_DIR = "./install"
INCLUDE_DIR = "./include"
BINARY_NAME = "zpr"

# create object files in BUILD_DIR directory
VariantDir(BUILD_DIR, SRC_DIR, duplicate=0)
env = Environment()

# collect files for compilation
files = Glob(BUILD_DIR + '/*.cpp')
if len(files) == 0:
    print("No files given!")
    exit(1)

env.Program(BINARY_NAME, files, CPPPATH=INCLUDE_DIR)