from sklearn import datasets, feature_extraction, metrics
from sklearn.ensemble import RandomForestClassifier
from sklearn.pipeline import Pipeline
from sklearn.neural_network import MLPClassifier
from pylab import *

print('2.1)')
newsgroups = datasets.fetch_20newsgroups()

train_20news = datasets.fetch_20newsgroups(subset='train', shuffle=True, random_state=42)
test_20news = datasets.fetch_20newsgroups(subset='test', shuffle=True, random_state=42)

print('What is the role of the \'categories\' parameter?')
print('The categories parameter is used to load a subset of the dataset based on the given \n'
      'collection of string inputs. This collection can for example be an array of strings. \n'
      'If categories is none (not specified), then the full dataset is loaded.')


print('\n\n2.2)')
print('CountVectorizer:')
print('Converts a collection of text documents into a matrix of token counts.\n')
print('TfidTransformer:')
print('Converts a count matrix into a normalized tf (term-frequency) or \n'
      'tf-idf (term-frequency times inverse document frequency) representation.\n')
print('TfidVectorizer:')
print('Converts a collection of raw documents into a matrix of tf-idf features.')
print('fit:')
print('Learn a vocabulary dictionary of all tokens in the raw documents. This is a \n'
      'function of CountVectorizer, TfidTransformer, and TfidVectorizer.\n')
print('fit_transform')
print('Learn the vocabulary dictionary and return term-document matrix. This function is a \n'
      'function of CountVectorizer, TfidTransformer, and TfidVectorizer. This function is \n'
      'also equivalent to calling fit followed by transform, but more efficiently implemented.\n')
print('transform:')
print('Transform documents to document-term matrix. This function is a \n'
      'function of CountVectorizer, TfidTransformer, and TfidVectorizer.\n')

vectorizer = feature_extraction.text.TfidfVectorizer()
train_vectors = vectorizer.fit_transform(train_20news.data)
test_vectors = vectorizer.transform(test_20news.data)

print('train_vectors:\n{}\n'.format(train_vectors))
print('test_vectors:\n{}'.format(test_vectors))

print('\n\n2.3)')
num_trees = 50
n = int(train_vectors.shape[0] / 2)
y1 = zeros(n, int)
y2 = zeros(n, int)+1
y = hstack((y1, y2))
RF = RandomForestClassifier(n_estimators=num_trees)

# training
RF.fit(train_vectors, y)

# testing
pred = RF.predict(test_vectors)

n_test = int(pred.size / 2)
y1_test = zeros(n_test, int)
y2_test = zeros(n_test, int)+1
y_test = hstack((y1_test, y2_test))

print('Accuracy-score: {}'.format(metrics.accuracy_score(y_test, pred)))
print('Precision-score: {}'.format(metrics.precision_score(y_test, pred)))
print('Recall-score: {}'.format(metrics.recall_score(y_test, pred)))
print('F1-score: {}'.format(metrics.f1_score(y_test, pred)))
print('Confusion matrix:\n{}'.format(metrics.confusion_matrix(y_test, pred)))


print('\n\n2.4)')
vectorizer = feature_extraction.text.TfidfVectorizer()
RF_pipe = RandomForestClassifier(n_estimators=num_trees)
n = int(train_vectors.shape[0] / 2)
y1 = zeros(n, int)
y2 = zeros(n, int)+1
y = hstack((y1, y2))
pipeline_training = Pipeline([('tfid_vectorizer', vectorizer), ('RF', RF_pipe)])

# training
pipeline_training.fit(train_20news.data, y)

# testing
pipeline_testing = pipeline_training.predict(test_20news.data)

# calculating scores
n_test = int(pipeline_testing.size / 2)
y1_test = zeros(n_test, int)
y2_test = zeros(n_test, int)+1
y_test = hstack((y1_test, y2_test))
print('Accuracy-score: {}'.format(metrics.accuracy_score(y_test, pipeline_testing)))
print('Precision-score: {}'.format(metrics.precision_score(y_test, pipeline_testing)))
print('Recall-score: {}'.format(metrics.recall_score(y_test, pipeline_testing)))
print('F1-score: {}'.format(metrics.f1_score(y_test, pipeline_testing)))
print('Confusion matrix:\n{}'.format(metrics.confusion_matrix(y_test, pipeline_testing)))

print('\n\n2.5)')
vectorizer = feature_extraction.text.TfidfVectorizer()
MLP = MLPClassifier(hidden_layer_sizes=(10, 20, 10), max_iter=10)
n = int(train_vectors.shape[0] / 2)
y1 = zeros(n, int)
y2 = zeros(n, int)+1
y = hstack((y1, y2))
MLP_pipeline = Pipeline([('tfid_vectorizer', vectorizer), ('MLP', MLP)])

# training
MLP_pipeline.fit(train_20news.data, y)

# testing
MLP_testing = MLP_pipeline.predict(test_20news.data)

# calculating scores
n_test = int(pipeline_testing.size / 2)
y1_test = zeros(n_test, int)
y2_test = zeros(n_test, int)+1
y_test = hstack((y1_test, y2_test))
print('Accuracy-score: {}'.format(metrics.accuracy_score(y_test, MLP_testing)))
print('Precision-score: {}'.format(metrics.precision_score(y_test, MLP_testing)))
print('Recall-score: {}'.format(metrics.recall_score(y_test, MLP_testing)))
print('F1-score: {}'.format(metrics.f1_score(y_test, MLP_testing)))
print('Confusion matrix:\n{}'.format(metrics.confusion_matrix(y_test, MLP_testing)))
