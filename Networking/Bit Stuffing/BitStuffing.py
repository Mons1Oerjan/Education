filename = 'random_gibberish.txt'


# 3.a)
# Function for generating a bit stream with bit stuffing
def generate_bit_stream_with_bit_stuffing(file_name):
    file = open(file_name, 'r')
    lines = file.readlines()
    binaryLines = []
    bit_stream = ''

    # Convert to binary:
    for line in lines:
        binaryLines.append(' '.join(format(ord(x), 'b') for x in line))

    # Generate bit stream:
    for bin_line in binaryLines:
        bit_stream += bin_line

    # Apply bit stuffing:
    bit_stream = bit_stream.replace('11111 ', '11111 0')
    bit_stream = bit_stream.replace('11111', '111110')
    bit_stream = bit_stream.replace('1111 1', '1111 10')
    bit_stream = bit_stream.replace('111 11', '111 110')
    bit_stream = bit_stream.replace('11 111', '11 1110')
    bit_stream = bit_stream.replace('1 1111', '1 11110')

    return bit_stream


# 3.b)
# Function that takes a bit stream with stuffed bits, removes the
# stuffed bits, converts the bits into ASCII codes and generates a text file
def convert_bit_stream_to_ascii_text_file(bit_stream):
    output_file = open('bit_stuffing_output.txt', 'w')

    # remove stuffed bits:
    bit_stream = bit_stream.replace('1 11110', '1 1111')
    bit_stream = bit_stream.replace('11 1110', '11 111')
    bit_stream = bit_stream.replace('111 110', '111 11')
    bit_stream = bit_stream.replace('1111 10', '1111 1')
    bit_stream = bit_stream.replace('111110', '11111')
    bit_stream = bit_stream.replace('11111 0', '11111 ')

    # convert to ASCII:
    bit_array = bit_stream.split(' ')
    ascii_text = ''.join([chr(int(x, 2)) for x in bit_array])

    return output_file.write(ascii_text)

print('Convert from ASCII to bit stream:')
stream = generate_bit_stream_with_bit_stuffing(filename)
print(stream)
print('Convert from bit stream to ASCII:')
num_chars_written = convert_bit_stream_to_ascii_text_file(stream)
print('See bit_stuffing_output.txt')
