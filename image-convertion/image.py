import struct

def bmp_to_c_array(bmp_file, output_file):
    with open(bmp_file, 'rb') as f:
        bmp_data = f.read()

    # BMP header is 54 bytes; the pixel data starts at byte 54
    header_size = 54
    width, height = struct.unpack('<II', bmp_data[18:26])
    bpp = struct.unpack('<H', bmp_data[28:30])[0]

    if bpp != 16:
        raise ValueError("Only 16-bit BMP images are supported")

    # Extract pixel data
    pixel_data = bmp_data[header_size:]
    pixel_count = width * height

    # Prepare the output file
    with open(output_file, 'w') as f:
        f.write(f'const uint16_t image_data[{pixel_count}] = {{\n')

        for i in range(pixel_count):
            pixel = pixel_data[i*2:i*2+2]
            value = struct.unpack('<H', pixel)[0]
            # Swap the bytes to match the display's endianness
            value = (value >> 8) | ((value & 0xFF) << 8)
            f.write(f'0x{value:04X}, ')

            if (i + 1) % 12 == 0:
                f.write('\n')

        f.write('\n};\n')

bmp_to_c_array('output_image.bmp', 'image.h')
