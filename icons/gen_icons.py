import os
import subprocess
from shutil import copyfile

inkscape_default_dpi = 96

svg_default_folder = './'
root1 = './'

file_paths = []

for root, subdirs, files in os.walk(svg_default_folder):
    for name in files:
        if ".svg" in name:
            print(os.path.join(root, name))
            file_paths.append(os.path.join(root, name))

for file_path in file_paths:
    png_file_path = file_path.replace("svg", "png")
    call_params = ["inkscape",
                   "--vacuum-defs",
                   "--export-dpi=%s" % inkscape_default_dpi,
                   "--export-filename=%s" % png_file_path,
                   file_path]
    subprocess.check_call(call_params, stdout=subprocess.DEVNULL, stderr=subprocess.STDOUT)
    print('Generated {0}'.format(file_path))
