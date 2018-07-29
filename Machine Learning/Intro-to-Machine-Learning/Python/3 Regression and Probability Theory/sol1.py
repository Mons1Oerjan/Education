import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

print('1.1)')

# load the houses dataset:
df = pd.read_csv('houses.csv', delimiter=',')
df.describe()

print('What is pandas dataframe?')
print('Pandas dataframe is a 2D size-mutable, potentially heterogeneous tabular data structure with '
      'labeled rows and columns. Arithmetic operations align on both row and column labels.')

# split the dataset into target value Y, feature matrix X, and sqft_living X_1:
Y = df.loc[:, :'price (grands)']
X = df.loc[:, 'bedrooms':]
X_1 = df.loc[:, 'sqft_living15':'sqft_living15']

print('\n1.2)')


# Function that normalizes a dataset's columns with range 0-1
def normalize_dataset(df_dataset):
    df_norm = df_dataset.apply(lambda x: ((x - x.min()) / (x.max() - x.min())))
    df_norm = df_norm.clip(lower=0.00, upper=1.00)

    return df_norm


# Function that calculates the root mean squared error (RMSE)
def rmse(predictions, targets):
    return np.sqrt(((predictions - targets) ** 2).mean())


# Function that calculates the mean squared error (MSE)
def mse(y, y_hat, axis):
    return ((y - y_hat) ** 2).mean(axis=axis)


# Least Squares loss function
def compute_cost(X, Y, theta):
    inner = np.power(((X * theta.T) - Y), 2)
    return np.sum(inner) / (2 * len(X))


# function to calculate gradient descent
def gradient_descent(X, Y, theta, lr, repetitions):
    temp = np.matrix(np.zeros(theta.shape))
    parameters = int(theta.ravel().shape[1])
    cost = np.zeros(repetitions)

    for i in range(repetitions):
        # find the error:
        error = (X * theta.T) - Y

        # compute the gradient of the error:
        for j in range(parameters):
            term = np.multiply(error, X[:, j])
            temp[0, j] = theta[0, j] - ((lr / len(X)) * np.sum(term))

        theta = temp
        cost[i] = compute_cost(X, Y, theta)

    return theta, cost


def linear_regression(X, Y, lr, repetitions):
    # initialize theta as an array of zeros based on input size:
    theta = np.matrix(np.array(np.zeros(X.shape[1])))

    # perform gradient descent:
    model, loss = gradient_descent(X, Y, theta, lr, repetitions)

    return model, loss


# normalize X
X = normalize_dataset(X)
X_1 = normalize_dataset(X_1)

# append a column containing 1's to the front of the datasets
X.insert(0, 'Ones', 1)
X_1.insert(0, 'Ones', 1)

# convert from data frames to numpy matrices:
X = np.matrix(X.values)
X_1 = np.matrix(X_1.values)
Y = np.matrix(Y.values)

# define variables for linear regression with SGD:
num_iterations = 10000
learning_rates = [10, 1, 0.1, 0.01, 0.001]

# linear regression:
model, loss = linear_regression(X_1, Y, learning_rates[3], num_iterations)

# compute cost:
error = compute_cost(X_1, Y, model)

# linear regression:
model2, loss2 = linear_regression(X, Y, learning_rates[3], num_iterations)

# compute cost:
error2 = compute_cost(X, Y, model2)

# plot cost at each training iteration:
fig, ax = plt.subplots(figsize=(12, 8))
plt.yscale('log')
ax.plot(np.arange(num_iterations), loss, 'r', label='X_1')
ax.plot(np.arange(num_iterations), loss2, 'b', label='X')
ax.legend(loc=2)
ax.set_xlabel('Iterations')
ax.set_ylabel('Cost')
ax.set_title('Cost vs. Training Iterations')

print('Performing linear regression on X_1 for all learning rates [10, 1, 0.1, 0.01, 0.001]:')
regressions_X_1 = []
for lr in range(len(learning_rates)):
    # linear regression:
    model, loss = linear_regression(X_1, Y, learning_rates[lr], num_iterations)
    # compute cost:
    error = compute_cost(X_1, Y, model)
    regression = {
        'model': model,
        'loss': loss,
        'error': error
    }
    regressions_X_1.append(regression)
    print('X_1 RMSE with lr={}: {}'.format(learning_rates[lr], regression['error']))


print('Performing linear regression on X for all learning rates [10, 1, 0.1, 0.01, 0.001]:')
regressions_X = []
for lr in range(len(learning_rates)):
    # linear regression:
    model2, loss2 = linear_regression(X, Y, learning_rates[lr], num_iterations)
    # compute cost:
    error2 = compute_cost(X, Y, model2)
    regression = {
        'model': model2,
        'loss': loss2,
        'error': error2
    }
    regressions_X.append(regression)
    print('X RMSE with lr={}: {}'.format(learning_rates[lr], regression['error']))

print('\n1.3)')
print('Visualizing X_1...')
x = np.array(X_1[:, 1].A1)
f = regressions_X_1[2]['model'].item(0) * x + regressions_X_1[2]['model'].item(1)
fig, ax = plt.subplots()
ax.plot(x, f, color='r', label='Prediction')
ax.scatter(x, np.array(Y), color='b', label='Training Data')
ax.legend(loc=2)
ax.set_xlabel('Area')
ax.set_ylabel('Price (grands)')
ax.set_title('Price vs Area')
fig.show()

print('\nVisualizing X...')
x = np.array(X[:, list(range(1, 16))])
f = regressions_X[2]['model'].item(0) * x + regressions_X[2]['model'].item(1)
fig, ax = plt.subplots()
ax.plot(x, f, color='r', label='Prediction')
for i in range(x.shape[1]):
    ax.scatter(x[:, i], np.array(Y), label=list(df.columns.values)[i])
ax.legend(loc=2)
ax.set_xlabel('Area')
ax.set_ylabel('Price (grands)')
ax.set_title('Price vs Area')
fig.show()


print('\nDoes the scatter plot create a linear line? why?')
print('The scatter plot creates a linear line because we used linear regression for training.\n')

print('\n1.4)')


# Linear regression function with Ridge (performing L2 regularization)
def linear_regression_Ridge():

    return


# linear regression function with LASSO (least absolute shrinkage and selection operator, performing L1 regularization)
def linear_regression_LASSO():

    return



