from sklearn import metrics, preprocessing
from sklearn.neural_network import MLPClassifier
from pylab import *
import numpy as np

# load data from external files
wine_train = np.loadtxt('wine.train', delimiter=',')
wine_test = np.loadtxt('wine.test', delimiter=',')

# extract validation data
array = list(range(30, 40))
array = np.append(array, list(range(70, 80)))
array = np.append(array, list(range(110, 120)))
wine_validation = wine_train[array, :]
wine_train = np.delete(wine_train, array, axis=0)
num_instances = wine_train.shape[0]

# define MLP model
input_neurons = 13  # we have 12 attributes in the data set (we exclude the class IDs)
output_neurons = 3  # number of cultivars = 3
alpha = 2  # input sample is small
hidden_neurons = int(num_instances / (alpha * (input_neurons + output_neurons))) + 1

MLP = MLPClassifier(
    hidden_layer_sizes=(input_neurons, hidden_neurons, output_neurons),
    solver='sgd',
    max_iter=1000,
    alpha=0.1,
)

# training
y_true_train = wine_train[:, [0]]
y_true_validation = wine_validation[:, [0]]
y_true_test = wine_test[:, [0]]
num_epochs = 20
x_scaled = preprocessing.scale(wine_train)  # pre-process data using zero mean and unit variance
for i in range(num_epochs):
    MLP.fit(x_scaled, y_true_train)

# validation
y_pred = MLP.predict(wine_validation)

# calculate validation scores
print('Validation scores:')
print('Accuracy-score: {}'.format(metrics.accuracy_score(y_true_validation, y_pred)))
print('Confusion matrix:\n{}\n'.format(metrics.confusion_matrix(y_true_validation, y_pred)))

print('I chose the MLP model because this is a multi classification problem where we \n'
      'wish to classify each row into 3 possible wine classes. I chose to go with a \n'
      '(13, 5, 3) hidden-layered neural network because we have 13 attributes (input neurons) and \n'
      '3 cultivars / class IDs (output neurons). I divided the wine_train data set into a \n'
      '75%/25% training / validation set, trained the neural network using stochastic gradient descent \n'
      'and used the validation set to predict the output during the first round. Further, I ran \n'
      'the neural network against the wine_test dataset and wrote the results to a file prediction.csv.\n')

# test against unknown data
y_pred_test = MLP.predict(wine_test)

np.savetxt('prediction.csv', y_pred_test)
