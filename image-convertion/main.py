import os
import subprocess
from image import bmp_to_c_array


def image_to_bmp(image_folder_pathfile, bmp_folder_pathfile):
    image_counter = 1

    for filename in os.listdir(image_folder_pathfile):
        if filename.endswith(('.jpg', '.jpeg')):
            input_file = image_folder_pathfile + '/' + filename
            output_file = bmp_folder_pathfile + str(image_counter) + ".bmp"

            ffmpeg_command = [
                'ffmpeg',
                '-i', input_file,         # Input file
                '-vf', 'scale=240:240',   # Video filter to scale the image
                '-pix_fmt', 'rgb565',     # Pixel format
                output_file               # Output file
            ]
            image_counter += 1

            try:
                # Run the ffmpeg command
                subprocess.run(ffmpeg_command, check=True)
                print(f"Successfully processed {input_file} to {output_file}")
            except subprocess.CalledProcessError as e:
                print(f"An error occurred: {e}")


def bmp_to_binary(bmp_folder_pathfile, image_header_pathname):
    image_counter = 0

    for filename in os.listdir(bmp_folder_pathfile):
        image_data_name = "image_data" + str(image_counter)
        input_file = bmp_folder_pathfile + filename
        output_file = image_header_pathname + str(image_counter) + ".h"

        bmp_to_c_array(input_file, output_file, image_data_name)
        image_counter += 1


image_folder_pathfile = "./images"
bmp_folder_pathfile = "./bmp-files/"
image_header_pathname = "./images-header-files/"

image_to_bmp(image_folder_pathfile, bmp_folder_pathfile)
bmp_to_binary(bmp_folder_pathfile, image_header_pathname)
