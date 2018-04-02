import numpy as np
import matplotlib.pyplot as plt
import itertools as itools
import datetime as dt

print('1.1)')
print('loadtxt: loads data from a text file where each row in the text file must have the same number of values.')
print('genfromtxt: loads data from a text file where missing values are handled as specified.')

iris_data = np.loadtxt('fisheriris.data', delimiter=',')
feature_names = np.genfromtxt('attributes.txt', dtype='str', delimiter=',').tolist()
target_names = np.genfromtxt('feature.txt', dtype='str', delimiter=',').tolist()

print('\n1.2)')
target = iris_data[:, [4]]
iris_data = np.delete(iris_data, 4, 1)
feature_names = np.delete(feature_names, 4, 0).tolist()

print('size of Fisher\'s measurements: {}'.format(iris_data.size))
print('Number of elements in the second dimension of the iris_data array: {}'.format(iris_data[:, [1]].size))

print('\n1.3)')
for i in range(0, 3):
    print('Sum column {}: {}'.format(i, np.sum(iris_data[:, [i]])))

print('Sum of all columns: {}'.format(np.sum(iris_data)))
print('Sum of 2nd and 4th columns: {}'.format(np.sum(iris_data[:, [1]]) + np.sum(iris_data[:, [3]])))

row_indices = []
for i in range(27, 48):
    row_indices.append(i)
row_indices = np.array(row_indices)
col_indices = np.array([0, 1, 2, 3])
sub_matrix = iris_data[row_indices[:, None], col_indices]
for i in range(0, 3):
    print('Max value of column {}: {}'.format(i, sub_matrix[:, [i]].max()))

row_indices = []
for i in range(1, 34):
    if i % 2 == 1:
        row_indices.append(i)
row_indices = np.array(row_indices)
sub_matrix_odd = iris_data[row_indices[:, None], col_indices]
for i in range(0, 1):
    print('Min value of column {}: {}'.format(i, sub_matrix[:, [i]].min()))

print('\n1.4)')
first_column = iris_data[:, [0]]
third_column = iris_data[:, [2]]
r13rd = np.append(first_column, third_column)
print('Sum of r13rd: {}'.format(np.sum(r13rd)))

r13rd_cubed = np.power(r13rd, 3)
print('r13rd cubed: {}'.format(r13rd_cubed))

print('\n1.5)')
mat1 = first_column[[0, 1, 2, 3], :]
second_column = iris_data[:, [1]]
mat1 = np.append(mat1, second_column[[0, 1, 2, 3], :])

mat2 = third_column[[0, 1, 2, 3], :]
fourth_column = iris_data[:, [3]]
mat2 = np.append(mat2, fourth_column[[0, 1, 2, 3], :])

print('Adding mat1 and mat2: {}'.format(np.add(mat1, mat2)))
print('Multiplying mat1 and mat2: {}'.format(np.dot(mat1, mat2)))

print('\n1.6)')
mat3 = np.inner(mat1, mat2)
np.savetxt('mat3.csv', np.array([mat3]))
print('mat3 has been saved to mat3.csv')

print('\n1.7)')
print('Creating a bar chart...')
num_groups = 4

mean_sepal_length = np.mean(first_column)
std_sepal_length = np.std(first_column)

mean_sepal_width = np.mean(second_column)
std_sepal_width = np.std(second_column)

mean_pedal_length = np.mean(third_column)
std_pedal_length = np.std(third_column)

mean_pedal_width = np.mean(fourth_column)
std_pedal_width = np.std(fourth_column)

means = (mean_sepal_length, mean_sepal_width, mean_pedal_length, mean_pedal_width)
stds = (std_sepal_length, std_sepal_width, std_pedal_length, std_pedal_width)

ax = plt.subplots()
index = np.arange(num_groups)
bar_width = 0.35
opacity = 0.4
error_config = { 'ecolor': '0.3'}

rectangle1 = plt.bar(
    index,
    means,
    bar_width,
    alpha=opacity,
    color='r',
    yerr=stds,
    error_kw=error_config,
    label='Measurements'
)
plt.xlabel('Measurements')
plt.ylabel('Centimeters')
plt.title('Measurements in centimeters')
plt.xticks(index + bar_width / 2, ('Sepal Length', 'Sepal Width', 'Pedal Length', 'Pedal Width'))
plt.legend()
plt.tight_layout()
plt.show()

print('\n1.8)')
print('Creating a scatter plot...')
scatter_plot_data = np.loadtxt('fisheriris.data', delimiter=',')
scatter_plot_data = np.delete(scatter_plot_data, [2, 3], 1)
setosa_indices = []
versicolor_indices = []
virginica_indices = []
for i in range(0, 49):
    setosa_indices.append(i)
for i in range(50, 99):
    versicolor_indices.append(i)
for i in range(100, 149):
    virginica_indices.append(i)
setosa_indices = np.array(setosa_indices)
versicolor_indices = np.array(versicolor_indices)
virginica_indices = np.array(virginica_indices)
setosa = scatter_plot_data[setosa_indices[:, None], [0, 1, 2]]
versicolor = scatter_plot_data[versicolor_indices[:, None], [0, 1, 2]]
virginica = scatter_plot_data[virginica_indices[:, None], [0, 1, 2]]
setosa_scatter = plt.scatter(
    setosa[:, [0]],
    setosa[:, [1]],
    c='b',
    alpha=0.5
)
versicolor_scatter = plt.scatter(
    versicolor[:, [0]],
    versicolor[:, [1]],
    c='r',
    alpha=0.5
)
virginica_scatter = plt.scatter(
    virginica[:, [0]],
    virginica[:, [1]],
    c='g',
    alpha=0.5
)
plt.xlabel(feature_names[0])
plt.ylabel(feature_names[1])
plt.title('Scatter Plot for iris species')
plt.legend(
    (setosa_scatter, versicolor_scatter, virginica_scatter),
    (target_names[0], target_names[1], target_names[2]),
    scatterpoints=1,
    ncol=1
)
plt.show()

print('\n1.9)')
print('Creating a scatter plot...')
scatter_plot_data = np.loadtxt('fisheriris.data', delimiter=',')
feature_names = np.genfromtxt('attributes.txt', dtype='str', delimiter=',').tolist()
combinations = list(itools.combinations(range(4), 2))
scatter_plots = []
legend_strs = []

for combination in combinations:
    legend_str = '{}, {}'.format(combination[0], combination[1])
    legend_str = legend_str\
        .replace('0', feature_names[0])\
        .replace('1', feature_names[1])\
        .replace('2', feature_names[2])\
        .replace('3', feature_names[3])
    plot = plt.scatter(
        scatter_plot_data[:, [combination[0]]],
        scatter_plot_data[:, [combination[1]]],
        alpha=0.5
    )
    scatter_plots.append(plot)
    legend_strs.append(legend_str)


plt.title('All Combinations')
plt.legend(
    scatter_plots,
    legend_strs,
    scatterpoints=1,
    ncol=2
)
plt.show()

print('\n1.10)')

print('seed(a, version):')
print('initializes the random number generator. Uses current system time if a is not provided.\n')

print('RandomState:')
print('container that exposes a number of functions for generating random numbers drawn from a large')
print('number of different probability distributions.\n')
print('rand(d0, d1, ..., dn):')
print('function that returns an array (or matrix) of the given shape (defined in the input params)')
print('populated with random samples from a uniform distribution over (0, 1).\n')
print('randn(d0, d1, ..., dn):')
print('function that returns an array (or matrix) of the given shape (defined in the input params)')
print('populated with random samples from the "standard normal" distribution.\n')
print('randint(a, b):')
print('function that returns a random integer n such that a <= n <= b.\n')
print('RandomState before the random generator function:')
print('Sometimes it\'s beneficial to create a new instance for the random number generator and not use')
print('the global numpy random function. RandomState also has the advantage of having more')
print('probability distributions to choose from, so if you need to choose a specific distribution, then')
print('it is good practice to create a new RandomState instance.\n')

cent = np.random.randn(5, 5)
print('cent: 5x5 matrix using random values drawn from the normal distribution:')
print(cent)

print('\nNegative numbers explanation:')
print('cent contains negative numbers because the normal distribution extends from -infinity to infinity.')

r = np.random.RandomState(dt.datetime.now().second)
cent_fix = r.lognormal(cent)

print('\n1.11)')
v = np.random.rand(1, 5)
print('1x5 row vector v: {}'.format(v))
np.concatenate((v, np.random.rand(1, 5)), axis=0)
print('new v after concatenation: {}'.format(v))



