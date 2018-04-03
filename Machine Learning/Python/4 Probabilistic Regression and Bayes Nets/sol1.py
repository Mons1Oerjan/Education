import numpy as np
import matplotlib.pyplot as plt
from collections import namedtuple

iris_data = np.loadtxt('fisheriris.data', delimiter=',')
classes = iris_data[:, 4]
iris_data = np.delete(iris_data, 4, axis=1)
rand_lower_bound = 0
rand_upper_bound = 50
epsilon = 0.0001
num_classes = [2, 3, 4]


# EM Algorithm with Gaussian distribution
def em(x, k, max_iterations=1000):
    # extract input shape:
    num_data_points, dimension = x.shape

    # randomly init means as k of the points from the data set:
    mu = x[np.random.choice(num_data_points, k, False), :]

    # init the covariance matrices for each gaussian:
    sigma = [np.eye(dimension)] * k

    # init probabilities (phi) for each gaussian:
    phi = [1. / k] * k

    # init responsibility matrix to all zeros (for each data point and for each k gaussian)
    responsibility_matrix = np.zeros((num_data_points, k))

    log_likelihoods = []

    def prob(mean, cov):
        return np.linalg.det(cov) ** -0.5 ** (2 * np.pi) ** (-dimension / 2.) * np.exp(
            -0.5 * np.einsum('ij, ij -> i', x - mean, np.dot(np.linalg.inv(cov), (x - mean).T).T))

    # repeat until convergence:
    while len(log_likelihoods) < max_iterations:
        # E step - calculate membership for each k gaussian:
        for i in range(k):
            responsibility_matrix[:, i] = phi[i] * prob(mu[i], sigma[i])

        # compute log_likelihood:
        log_likelihood = np.sum(np.log(np.sum(responsibility_matrix, axis=1)))
        log_likelihoods.append(log_likelihood)

        # normalize responsibility matrix to make it row-stochastic:
        responsibility_matrix = (responsibility_matrix.T / np.sum(responsibility_matrix, axis=1)).T

        # calculate number of data points belonging to each gaussian:
        num_ks = np.sum(responsibility_matrix, axis=0)

        # M step - calculate the new mean and covariance for each k with the new responsibility matrix:
        for i in range(k):
            # means:
            mu[i] = 1. / num_ks[i] * np.sum(responsibility_matrix[:, i] * x.T, axis=1).T
            x_mu = np.matrix(x - mu[i])

            # covariances:
            sigma[i] = np.array(1 / num_ks[i] * np.dot(np.multiply(x_mu.T, responsibility_matrix[:, i]), x_mu))

            # probabilities (phi):
            phi[i] = 1. / num_data_points * num_ks[i]

        # check for convergence:
        if len(log_likelihoods) < 2:
            continue
        if np.abs(log_likelihood - log_likelihoods[-2]) < epsilon:
            break

    # construct an object containing all results:
    results = namedtuple('params', ['mu', 'sigma', 'phi', 'log_likelihoods', 'num_iterations'])
    results.mu = mu
    results.sigma = sigma
    results.phi = phi
    results.log_likelihoods = log_likelihoods
    results.num_iterations = len(log_likelihoods)

    # return all results
    return results


# Function to predict EM (gaussian) results
def predict(results, x):
    def prob(mean, cov):
        return np.linalg.det(cov) ** -0.5 ** (2 * np.pi) ** (-len(x) / 2.) * np.exp(
            -0.5 * np.dot(x - mean, np.dot(np.linalg.inv(cov), x - mean)))

    probabilities = np.array([phi * prob(mean, cov) for mean, cov, phi in zip(results.mu, results.sigma, results.phi)])

    return probabilities / np.sum(probabilities)


# Try classes 2, 3, and 4:
# k = 2:
results_2 = em(iris_data, num_classes[0])
print('Results for k = 2:')
print('mu: {0}'.format(results_2.mu))
print('sigma: {0}'.format(results_2.sigma))
print('phi: {0}'.format(results_2.phi))
print('log likelihoods: {0}'.format(results_2.log_likelihoods))
print('Num iterations: {0}'.format(results_2.num_iterations))
print('Num clusters: {0}'.format(len(results_2.mu)))


# Plot the Sepal data points based on the obtained clusters:
num_clusters = len(results_2.mu)
plt.xlabel('Sepal length in cm')
plt.ylabel('Sepal width in cm')
plt.title('k = 2')
plt.scatter(iris_data.T[0], iris_data.T[1])
plt.show()

plt.xlabel('Num Iterations')
plt.ylabel('Log Likelihood')
plt.plot(results_2.log_likelihoods)
plt.show()

# k = 3:
results_3 = em(iris_data, num_classes[1])
print('Results for k = 2:')
print('mu: {0}'.format(results_3.mu))
print('sigma: {0}'.format(results_3.sigma))
print('phi: {0}'.format(results_3.phi))
print('log likelihoods: {0}'.format(results_3.log_likelihoods))
print('Num iterations: {0}'.format(results_3.num_iterations))

# Plot the Sepal data points based on the obtained clusters:
num_clusters = len(results_2.mu)
plt.xlabel('Sepal length in cm')
plt.ylabel('Sepal width in cm')
plt.title('k = 3')
plt.scatter(iris_data.T[0], iris_data.T[1])
plt.show()

plt.xlabel('Num Iterations')
plt.ylabel('Log Likelihood')
plt.plot(results_2.log_likelihoods)
plt.show()

# k = 4:
results_4 = em(iris_data, num_classes[2])
print('Results for k = 2:')
print('mu: {0}'.format(results_4.mu))
print('sigma: {0}'.format(results_4.sigma))
print('phi: {0}'.format(results_4.phi))
print('log likelihoods: {0}'.format(results_4.log_likelihoods))
print('Num iterations: {0}'.format(results_4.num_iterations))

# Plot the Sepal data points based on the obtained clusters:
num_clusters = len(results_2.mu)
plt.xlabel('Sepal length in cm')
plt.ylabel('Sepal width in cm')
plt.title('k = 4')
plt.scatter(iris_data.T[0], iris_data.T[1])
plt.show()

plt.xlabel('Num Iterations')
plt.ylabel('Log Likelihood')
plt.plot(results_2.log_likelihoods)
plt.show()
