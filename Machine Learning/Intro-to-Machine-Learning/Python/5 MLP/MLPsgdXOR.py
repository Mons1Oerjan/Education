from pylab import *
import numpy as np

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
num_trials = 2000
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
    # randomly pick training example
    pat = randint(26)
    x = X[:, pat]

    # calculate prediction
    h = 1 / (1 + exp(-wh @ x))
    y = 1 / (1 + exp(-wo @ h))

    # delta term for each layer (objective function error)
    do = y * (1 - y) * (Y[pat] - y)
    dh = (h * (1 - h)) * (wo.transpose() @ do)

    # update weights with momentum
    dow = 0.9 * dwo + outer(h, do).T
    wo = wo + 0.1 * dwo
    dwh = 0.9 * dwh + outer(dh, x)
    wh = wh + 0.1 * dwh

    # test all pattern
    h = 1 / (1 + exp(-wh @ X))
    y = 1 / (1 + exp(-wo @ h))
    error[trial] = error[trial] + sum(abs(y - Y))

xlabel('Number of trials (iterations)')
ylabel('Absolute Error')
title('MLP Learning Curve')
plot(error)
# savefig('tmp.eps', format='eps', dpi=1000)
