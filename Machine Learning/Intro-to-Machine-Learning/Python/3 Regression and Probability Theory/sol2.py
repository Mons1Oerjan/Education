import numpy as np
import numpy.random as nprand
import matplotlib.pyplot as plt
import matplotlib.mlab as mlab

print('2.1)')
NUM_ROLLS = 20
DIE_LOWER_BOUND = 1  # inclusive
DIE_UPPER_BOUND = 7  # exclusive

# roll 1 time and store in vector
die_1 = nprand.randint(DIE_LOWER_BOUND, DIE_UPPER_BOUND)
die_2 = nprand.randint(DIE_LOWER_BOUND, DIE_UPPER_BOUND)
vector = [].append(die_1 + die_2)

# roll 19 more times and append results to vector
for i in range(NUM_ROLLS - 1):
    die_1 = nprand.randint(DIE_LOWER_BOUND, DIE_UPPER_BOUND)
    die_2 = nprand.randint(DIE_LOWER_BOUND, DIE_UPPER_BOUND)
    sum_die_rolls = die_1 + die_2
    vector.append(sum_die_rolls)

n, bins, patches = plt.hist(vector, normed=1, bins=list(range(1, 13)))
plt.xlabel('Sum of two die rolls')
plt.ylabel('Percentage')
plt.title('Sum of 2 die rolls with {} random samples'.format(NUM_ROLLS))
plt.show()

print('What are the estimates for the probabilities of each number?')
print('The probability estimates can be seen on the plotted histogram (Y axis).')

print('\n2.2)')
NUM_ROLLS = 1000

for i in range(NUM_ROLLS):
    die_1 = nprand.randint(DIE_LOWER_BOUND, DIE_UPPER_BOUND)
    die_2 = nprand.randint(DIE_LOWER_BOUND, DIE_UPPER_BOUND)
    sum_die_rolls = die_1 + die_2
    vector.append(sum_die_rolls)

n, bins, patches = plt.hist(vector, normed=1, bins=list(range(1, 13)))
plt.xlabel('Sum of two die rolls')
plt.ylabel('Percentage')
plt.title('Sum of 2 die rolls with {} random samples'.format(NUM_ROLLS))
plt.show()

print('What is your estimation now?')
print('The probability estimates can be seen on the plotted histogram (Y axis).')


print('\n2.3)')
NUM_ROLLS = 1000
vector = []

for i in range(NUM_ROLLS):
    fake_die = nprand.randint(DIE_LOWER_BOUND, DIE_UPPER_BOUND)
    real_die = nprand.randint(DIE_LOWER_BOUND, DIE_UPPER_BOUND)
    if fake_die == 2:
        vector.append(real_die)
    else:
        vector.append(fake_die + real_die)

count, bins, patches = plt.hist(vector, normed=1, bins=list(range(1, 13)))
plt.xlabel('Sum of two die rolls')
plt.ylabel('Percentage')
plt.title('Sum of fake_die and real_die with {} random samples'.format(NUM_ROLLS))
plt.show()

print('Calculate the probability of getting a 7 as the sum of the numbers appeared on the dice.')
print('P(X=7) = {}'.format(n[6]))
print('What is the probability of getting 3?')
print('P(X=3) = {}'.format(n[2]))



