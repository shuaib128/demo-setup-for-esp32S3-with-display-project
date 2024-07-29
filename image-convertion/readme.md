1. ffmpeg -i image.jpeg -vf scale=240:240 -pix_fmt rgb565 output_image.bmp
    Use this command to make it to a bmp file.

2. Run the image.py script to convert it to a image.h file.
3. Use that image.h file in src/main.c and display the image.