# MLP with back-propagation learning of AND function
from pylab import *
import numpy as np

num_input_cols = 13
num_patterns = 26

# load data into X
X = np.loadtxt('pattern1', delimiter=' ')
X = X.reshape((26, 156))

# define labels (Y) as the alphabet A-Z
A = 65
Z = 90
Y = array(arange(A, Z+1, 1))

# convert Y (A-Z) to its binary representation:
for i in range(Y.size):
    Y[i] = bin(Y[i])[2:].zfill(8)

# define model specifications
num_input_neurons = 156  # input neurons = num_columns of input data + 1 bias neuron
num_hidden_neurons = 156  # hidden neurons = the mean value of num_input_neurons and num_output_neurons
num_output_neurons = 26  # output neurons = 1 because this neural network is a regressor (we wish to find ASCII values)

# parameter and array initialization
num_trials = 2000
hidden_neurons_arr = zeros(num_hidden_neurons)
output_neurons_arr = zeros(num_output_neurons)
weights_hidden_neurons_arr = randn(num_hidden_neurons, num_input_neurons)
weights_output_neurons_arr = randn(num_output_neurons, num_hidden_neurons)
delta_weights_hidden_neurons_arr = zeros(weights_hidden_neurons_arr.shape)
delta_weights_output_neurons_arr = zeros(weights_output_neurons_arr.shape)
delta_hidden_neurons_arr = zeros(num_hidden_neurons)
delta_output_neurons_arr = zeros(num_output_neurons)
error = zeros(num_trials)

for trial in range(num_trials):
    # pick example pattern randomly
    pat = randint(num_patterns)
    x = X[pat]

    # calculate hidden states of sigmoid nodes
    for ih in range(num_hidden_neurons):  # for each hidden node
        sumInput = 0

        for ii in range(num_input_neurons):  # loop over input features
            sumInput = sumInput + weights_hidden_neurons_arr[ih, ii] * x[ii]

        hidden_neurons_arr[ih] = 1 / (1 + exp(-sumInput))

    # calculate output (prediction) with sigmoid nodes
    for io in range(num_output_neurons):  # for each output node
        sumInput = 0

        for ih in range(num_hidden_neurons):  # loop over inputs from hidden
            sumInput = sumInput + weights_output_neurons_arr[io, ih] * hidden_neurons_arr[ih]

        output_neurons_arr[io] = 1 / (1 + exp(-sumInput))

    # delta term for each layer (objective function error)
    for io in range(num_output_neurons):  # for each output node
        delta_output_neurons_arr[io] = output_neurons_arr[io] * (1 - output_neurons_arr[io]) * (Y[pat] - output_neurons_arr[io])

    sumInput = 0

    for ih in range(num_hidden_neurons):  # for each hidden node
        sumInput = 0  # back-propagation starts

        for io in range(num_output_neurons):
            sumInput = sumInput + weights_output_neurons_arr[io, ih] * delta_output_neurons_arr[io]

        delta_hidden_neurons_arr[ih] = hidden_neurons_arr[ih] * (1 - hidden_neurons_arr[ih]) * sumInput

    # update weights with momentum
    for io in range(num_output_neurons):
        for ih in range(num_hidden_neurons):
            delta_weights_output_neurons_arr[io, ih] = 0.9 * delta_weights_output_neurons_arr[io, ih] + hidden_neurons_arr[ih] * delta_output_neurons_arr[io]
            weights_output_neurons_arr[io, ih] = weights_output_neurons_arr[io, ih] + 0.1 * delta_weights_output_neurons_arr[io, ih]

    for ih in range(num_hidden_neurons):
        for ii in range(num_input_neurons):
            delta_weights_hidden_neurons_arr[ih, ii] = 0.9 * delta_weights_hidden_neurons_arr[ih, ii] + x[ii] * delta_hidden_neurons_arr[ih]
            weights_hidden_neurons_arr[ih, ii] = weights_hidden_neurons_arr[ih, ii] + 0.1 * delta_weights_hidden_neurons_arr[ih, ii]

    # test all pattern
    for pat in range(num_patterns):
        x = X[pat]

        # calculate prediction
        for ih in range(num_hidden_neurons):  # for each hidden node
            sumInput = 0

            for ii in range(num_input_neurons):  # loop over input features
                sumInput = sumInput + weights_hidden_neurons_arr[ih, ii] * x[ii]

            hidden_neurons_arr[ih] = 1 / (1 + exp(-sumInput))

        for io in range(num_output_neurons):  # for each output node
            sumInput = 0

            for ih in range(num_hidden_neurons):  # loop over inputs from hidden
                sumInput = sumInput + weights_output_neurons_arr[io, ih] * hidden_neurons_arr[ih]

            output_neurons_arr[io] = 1 / (1 + exp(-sumInput))
            # y[io]=round(y[io])

        error[trial] = error[trial] + abs(output_neurons_arr - Y[pat])

xlabel('Number of trials (iterations)')
ylabel('Absolute Error')
title('MLP Learning Curve')
plot(error)
