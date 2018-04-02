print('Cyclic Redundancy Check')


# function that divides the bitstring with the divisor G(x) and determines if the message is error-free
def crc(bitstring, divisor, crc_remainder='000'):
    # append validation string to the bitstring:
    bitstring += crc_remainder

    # convert bitstring and divisor to lists:
    bitstring = list(bitstring)
    divisor = list(divisor)

    # loop over each bit in the bitstring:
    for i in range(len(bitstring) - len(crc_remainder)):
        if bitstring[i] == '1':
            # perform mod 2 multiplication on each index of the divisor:
            for j in range(len(divisor)):
                bitstring[i+j] = str((int(bitstring[i+j]) + int(divisor[j])) % 2)

    return ''.join(bitstring[-len(crc_remainder):])

print('Test 1:')
bits = '11010011101100'
div = '1011'  # simulates x^3 + x + 1

print('Bitstring: ' + bits)
print('Divisor: ' + div)

remainder = crc(bits, div)

print('CRC remainder: ' + remainder)

# verify the validity of the received message:
backtrack_remainder = crc(bits, div, remainder)
detected_error = backtrack_remainder == '000'
if detected_error:
    print('Error detected. Backtrack remainder should be 000')
    print('Backtrack remainder is: ' + backtrack_remainder)
else:
    print('No error detected.')


print('\n\nTest 2:')
bits = '00101111011101'
div = '0101'  # simulates x^2 + 1

print('Bitstring: ' + bits)
print('Divisor: ' + div)

remainder = crc(bits, div)

print('CRC remainder: ' + remainder)

# verify the validity of the received message:
backtrack_remainder = crc(bits, div, remainder)
detected_error = backtrack_remainder == '000'
if detected_error:
    print('Error detected. Backtrack remainder should be 000')
    print('Backtrack remainder is: ' + backtrack_remainder)
else:
    print('No error detected.')
