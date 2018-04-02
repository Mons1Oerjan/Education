# Read text file:
file = open('test.txt', 'r')

lines = file.readlines()
binaryLines = []

# Convert to binary:
for line in lines:
    binaryLines.append(' '.join(format(ord(x), 'b') for x in line.strip()))


# Generate NRZ and Manchester waveforms for both
def manchester(wordToEncode):
    waveform = ''
    prevbit = '-1'
    transitions = 0

    for bit in wordToEncode:
        if bit == '0':
            if prevbit == '0':
                waveform += '|-|_'
                transitions += 2
            else:
                waveform += '-|_'
                transitions += 1
        if bit == '1':
            if prevbit == '1':
                waveform += '|_|-'
                transitions += 2
            else:
                waveform += '_|-'
                transitions += 1
        prevbit = bit

    return waveform, transitions


def NRZ(wordToEncode):
    waveform = ''
    prevbit = '-1'
    transitions = 0

    for bit in wordToEncode:
        if bit == '0':
            if prevbit == '0' or prevbit == '-1':
                waveform += '-'
            else:
                waveform += '|-'
                transitions += 1
        if bit == '1':
            if prevbit == '1' or prevbit == '-1':
                waveform += '_'
            else:
                waveform += '|_'
                transitions += 1
        prevbit = bit

    return waveform, transitions

print('NRZ ENCODING:')
num_nrz_transitions = 0
for binaryLine in binaryLines:
    binaryWords = binaryLine.split(' ')
    for word in binaryWords:
        waveformNrz, transitionsNrz = NRZ(word)
        print(word + ': ' + waveformNrz)
        num_nrz_transitions += transitionsNrz

print('\n\nMANCHESTER ENCODING:')
num_manchester_transitions = 0
for binaryLine in binaryLines:
    binaryWords = binaryLine.split(' ')

    for word in binaryWords:
        waveformManchester, transitionsManchester = manchester(word)
        print(word + ': ' + waveformManchester)
        num_manchester_transitions += transitionsManchester

# Calculate the number of transitions
print('\n\n\nTest File:')
print('NRZ Num Transitions: {0}'.format(num_nrz_transitions))
print('Manchester Num Transitions: {0}'.format(num_manchester_transitions))


print('\n\n\nSmall Test File:')
small_file = open('small_test.txt', 'r')
line = small_file.readline()
binaryLine = ' '.join(format(ord(x), 'b') for x in line.strip())
binaryWords = binaryLine.split(' ')

print('NRZ ENCODING:')
num_nrz_transitions = 0
for word in binaryWords:
    waveformNrz, transitionsNrz = NRZ(word)
    print(word + ': ' + waveformNrz)
    num_nrz_transitions += transitionsNrz

print('\n\nMANCHESTER ENCODING:')
num_manchester_transitions = 0
binaryWords = binaryLine.split(' ')
for word in binaryWords:
    waveformManchester, transitionsManchester = manchester(word)
    print(word + ': ' + waveformManchester)
    num_manchester_transitions += transitionsManchester

print('\n\n')
print('NRZ Num Transitions: {0}'.format(num_nrz_transitions))
print('Manchester Num Transitions: {0}'.format(num_manchester_transitions))
