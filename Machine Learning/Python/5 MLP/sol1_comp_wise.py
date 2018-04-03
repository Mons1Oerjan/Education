# MLP with back-propagation
from pylab import *
import numpy as np

num_patterns = 26

# load data into X
X = np.loadtxt('pattern1', delimiter=' ')
X = X.reshape((26, 156))

# define labels (Y) as the alphabet A-Z
A = 65
Z = 90
ascii_values = array(arange(A, Z+1, 1))
Y = zeros((26, 8))

# convert Y (A-Z) to its binary representation:
for i in range(ascii_values.size):
    binary = bin(ascii_values[i])[2:].zfill(8)
    index = 0
    for b in binary:
        Y[i][index] = b
        index += 1

# model specifications
Ni = 26
Nh = 26
No = 26

# parameter and array initialization
num_trials = 1000
h = zeros(Nh)
y = zeros(No)
wh = randn(Nh, Ni)
wo = randn(No, Nh)
dwh = zeros(wh.shape)
dwo = zeros(wo.shape)
dh = zeros(Nh)
do = zeros(No)
error = zeros(num_trials)

for trial in range(num_trials):
    print(trial)
    # pick example pattern randomly
    pat = randint(156)
    x = X[:, pat]

    # calculate hidden states of sigmoid nodes
    for ih in range(Nh):  # for each hidden node
        sumInput = 0
        for ii in range(Ni):  # loop over input features
            sumInput = sumInput + wh[ih, ii] * x[ii]
        h[ih] = 1 / (1 + exp(-sumInput))
    # calculate output (prediction) with sigmoid nodes
    for io in range(No):  # for each output node
        sumInput = 0
        for ih in range(Nh):  # loop over inputs from hidden
            sumInput = sumInput + wo[io, ih] * h[ih]
        y[io] = 1 / (1 + exp(-sumInput))

    # delta term for each layer (objective function error)
    for io in range(No):  # for each output node
        do[io] = y[io] * (1 - y[io]) * (Y[pat] - y[io])
    sumInput = 0
    for ih in range(Nh):  # for each hidden node
        sumInput = 0  # back-propagation starts
        for io in range(No):
            sumInput = sumInput + wo[io, ih] * do[io]
        dh[ih] = h[ih] * (1 - h[ih]) * sumInput

    # update weights with momentum
    for io in range(No):
        for ih in range(Nh):
            dwo[io, ih] = 0.9 * dwo[io, ih] + h[ih] * do[io]
            wo[io, ih] = wo[io, ih] + 0.1 * dwo[io, ih]
    for ih in range(Nh):
        for ii in range(Ni):
            dwh[ih, ii] = 0.9 * dwh[ih, ii] + x[ii] * dh[ih]
            wh[ih, ii] = wh[ih, ii] + 0.1 * dwh[ih, ii]

    # test all pattern
    for pat in range(156):
        x = X[:, pat]
        # calculate prediction
        for ih in range(Nh):  # for each hidden node
            sumInput = 0
            for ii in range(Ni):  # loop over input features
                sumInput = sumInput + wh[ih, ii] * x[ii]
            h[ih] = 1 / (1 + exp(-sumInput))
        for io in range(No):  # for each output node
            sumInput = 0
            for ih in range(Nh):  # loop over inputs from hidden
                sumInput = sumInput + wo[io, ih] * h[ih]
            y[io] = 1 / (1 + exp(-sumInput))
            # y[io]=round(y[io])

        error[trial] = error[trial] + abs(y - Y[pat])

print('Plotting...')
xlabel('Number of trials (iterations)')
ylabel('Absolute Error')
title('MLP Learning Curve')
plot(error)
