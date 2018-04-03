from sklearn import datasets, svm, metrics, model_selection, utils
from pylab import *

print('1.1)')
iris = datasets.load_iris()
n = iris.data[:, [0]].size
y1 = zeros(int(n / 2))
y2 = zeros(int(n / 2)) + 1
y = hstack((y1, y2))
sepal_data = iris.data[:, [0, 1]]
petal_data = iris.data[:, [2, 3]]

# define models
svc_iris = svm.SVC(kernel='linear', C=1)
svc_sepal = svm.SVC(kernel='linear', C=1)
svc_petal = svm.SVC(kernel='linear', C=1)

# training
svc_iris.fit(iris.data, y)
svc_sepal.fit(sepal_data, y)
svc_petal.fit(petal_data, y)

# testing
predicted_iris = svc_iris.predict(iris.data)
predicted_sepal = svc_sepal.predict(sepal_data)
predicted_petal = svc_petal.predict(petal_data)

print('\nRole of the fit(x, y) method:')
print('Fit the SVM model according to the given training data.')
print('\nRole of the predict(x) method:')
print('Perform classification on samples in x.')


print('\n\n1.2)')
print('Accuracy-score iris: {}'.format(metrics.accuracy_score(y, predicted_iris)))
print('Precision-score iris: {}'.format(metrics.precision_score(y, predicted_iris)))
print('Recall-score iris: {}'.format(metrics.recall_score(y, predicted_iris)))
print('F1-score iris: {}'.format(metrics.f1_score(y, predicted_iris)))
print('Confusion matrix iris:\n{}'.format(metrics.confusion_matrix(y, predicted_iris)))
print('\n')
print('Accuracy-score sepal: {}'.format(metrics.accuracy_score(y, predicted_sepal)))
print('Precision-score sepal: {}'.format(metrics.precision_score(y, predicted_sepal)))
print('Recall-score sepal: {}'.format(metrics.recall_score(y, predicted_sepal)))
print('F1-score sepal: {}'.format(metrics.f1_score(y, predicted_sepal)))
print('Confusion matrix sepal:\n{}'.format(metrics.confusion_matrix(y, predicted_sepal)))
print('\n')
print('Accuracy-score petal: {}'.format(metrics.accuracy_score(y, predicted_petal)))
print('Precision-score petal: {}'.format(metrics.precision_score(y, predicted_petal)))
print('Recall-score petal: {}'.format(metrics.recall_score(y, predicted_petal)))
print('F1-score petal: {}'.format(metrics.f1_score(y, predicted_petal)))
print('Confusion matrix petal:\n{}'.format(metrics.confusion_matrix(y, predicted_petal)))
print('\n')
print('Why are there differences in the metric values?')
print('There are differences in the metric values because\n'
      '\t- each metric value represents a different error metric that has a unique formula '
      'for finding the metric value\n'
      '\t- each set of metrics are based on a different input (iris vs sepal vs petal)\n')

print('\n\n1.3)')
svc_iris = svm.SVC(kernel='linear', C=1)
cross_val_score_ten = model_selection.cross_val_score(svc_iris, iris.data, iris.target, cv=10)

print('Accuracy 10-fold: mean (+/- std deviation)')
print("Accuracy 10-fold: %0.2f (+/- %0.2f)\n" % (cross_val_score_ten.mean(), cross_val_score_ten.std() * 2))

print('What is k-fold cross validation?')
print('k-fold cross validation is a model validation technique where the goal is to predict an outcome, \n'
      'and estimate the accuracy a predictive model will perform in practice. Given a training dataset (known data) \n'
      'and a testing dataset (unknown data), cross validation defines a dataset to test the model in the \n'
      'training phase. Cross validation is based on the idea of partitioning a sample of the data into \n'
      'subsets and performing the analysis on one subset (training set) and validating the analysis \n'
      'on the other subsets (testing set). Multiple rounds (k rounds) of cross validation are performed using \n'
      'different partitions to reduce variability.\n')

svc_iris = svm.SVC(kernel='linear', C=1)
cross_val_score_five = model_selection.cross_val_score(svc_iris, iris.data, iris.target, cv=5)
print('Accuracy 5-fold: mean (+/- std deviation)')
print("Accuracy 5-fold: %0.2f (+/- %0.2f)\n" % (cross_val_score_five.mean(), cross_val_score_five.std() * 2))

print('Results comparison:')
print('5-fold cross validation yields more accurate results in this case.')
print('However, we must consider the fact that 5-fold cross validation has a higher variability than \n'
      '10-fold cross validation simply because it is run less times. Even though 5-fold cross validation \n'
      'outputs more accurate results, it is most likely true that the 10-fold cross validation result is \n'
      'a more accurate result overall.')

print('\n\n1.4)')
print('See code for the self-written cross validation function.')


def custom_cross_validation(x, k, randomize=False):
    if randomize:
        # User specifies random order, so shuffle the input:
        x = list(x)
        utils.shuffle(x)

    for num in range(k):
        # generate k training and validation pairs from the input x:
        training_set = [x for i, x in enumerate(x) if i % k != num] # iterable where length = (k-1)(len(x)/k)
        testing_set = [x for i, x in enumerate(x) if i % k == num]  # iterable where length = len(x)/k

        # return generators that will only be read once by the user:
        yield training_set, testing_set




