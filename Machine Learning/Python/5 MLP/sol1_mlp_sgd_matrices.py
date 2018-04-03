# MLP with back-propagation
from pylab import *
import numpy as np

# test vector:
ascii_values = array(arange(65, 91, 1))
Y = zeros((26, 8))

# convert ascii_values to 8-bit binary numbers and store them in Y:
for i in range(ascii_values.size):
    binary = bin(ascii_values[i])[2:].zfill(8)
    index = 0

    # store each bit in a new index (8 indices for 8 bits):
    for b in binary:
        Y[i][index] = b
        index += 1

# training vector / data:
X = np.loadtxt('pattern1', delimiter=' ')
X = X.reshape((26, 156))
X = X.T

# model specifications
Ni = 156  # num columns of input matrix
Nh = 82   # mean(Ni, No)
No = 8    # num columns of output vector

# parameter and array initialization
Ntrials = 200000
h = zeros(Nh)
y = zeros(No)
wh = randn(Nh, Ni)
wo = randn(No, Nh)
dwh = zeros(wh.shape)
dwo = zeros(wo.shape)
dh = zeros(Nh)
do = zeros(No)
error = zeros(Ntrials)

print('It takes a little while to iterate over 200000. Calculating... please wait.')

for trial in range(Ntrials):
    # randomly pick training example
    pat = randint(8)
    x = X[:, pat]

    # calculate prediction
    h = 1 / (1 + exp(-wh @ x))
    y = 1 / (1 + exp(-wo @ h))

    # delta term for each layer (objective function error)
    do = y[pat] * (1 - y) * (Y[pat] - y)
    dh = (h * (1 - h)) * (wo.T @ do)

    # update weights with momentum
    dow = 0.9 * dwo + outer(h, do).T
    wo = wo + 0.1 * dwo
    dwh = 0.9 * dwh + outer(dh, x)
    wh = wh + 0.1 * dwh

    # test all pattern
    h = 1 / (1 + exp(-wh @ X))
    y = 1 / (1 + exp(-wo @ h))
    y = y.T
    error[trial] = error[trial] + sum(abs(y - Y))

title("MLP Learning Curve")
xlabel("Number of Iterations")
ylabel("Error")
plot(error)

print('See code comments for my selection of Ni, Nh, and No.')

print('Results:')
print(y)
