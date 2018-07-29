#include "Matrix.h"
#include <iostream>
using namespace std;

void testMatrixClass() {
    int num = 5;
    int values[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    Matrix<int>* m1 = new Matrix<int>(5, 5);
    Matrix<float>* m2 = new Matrix<float>(5, 5);
    Matrix<int>* m3 = new Matrix<int>(2, 4, values);
    Matrix<int>* m4 = new Matrix<int>(2, 4, values);
    Matrix<int>* m5 = new Matrix<int>(4, 2, values);

    // test constructors and toString:
    m1->toString();
    m2->toString();
    m3->toString();
    m4->toString();
    m5->toString();

    // test sum():
    int sumM1 = m1->sum();
    cout << "sum m1: " << sumM1 << endl;
    cout << endl;

    // test constant addition:
    m3 = m3->operator+(num);
    cout << "constant addition:" << endl;
    m3->toString();
    cout << endl;

    // test matrix addition:
    m3 = m3->operator+(m4);
    cout << "matrix addition:" << endl;
    m3->toString();
    cout << endl;

    // test constant subtraction:
    m3 = m3->operator-(num);
    cout << "constant subtraction:" << endl;
    m3->toString();
    cout << endl;

    // test matrix subtraction:
    m3 = m3->operator-(m4);
    cout << "matrix subtraction:" << endl;
    m3->toString();
    cout << endl;

    // test constant multiplication:
    m3 = m3->operator*(num);
    cout << "constant multiplication:" << endl;
    m3->toString();
    cout << endl;


    // test matrix multiplication:
    cout << "test illegal matrix multiplication:" << endl;
    Matrix<int>* error = m3->operator*(m4);
    error->toString();
    cout << endl;
    cout << "legal matrix multiplication:" << endl;
    m3 = m3->operator*(m5);
    error->toString();
    cout << endl;

    // test operator ^
    int raiseToPow = 2;
    m3 = m3->operator^(raiseToPow);
    cout << "Raising matrix to the power of 2:" << endl;
    m3->toString();
    cout << endl;

    // test expo():
    m3 = m3->expo();
    cout << "Performing expo() on the above matrix:" << endl;
    m3->toString();
    cout << endl;
    m1 = m1->expo();
    cout << "Performing expo() on a matrix of 0's and 1's:" << endl;
    m1->toString();
    cout << endl;

    // test transpose():
    Matrix<int>* m6 = new Matrix<int>(5, 5);
    cout << "Creating a new square matrix with 0's and 1's:" << endl;
    m6->toString();
    m6 = m6->transpose();
    cout << "The transpose is:" << endl;
    m6->toString();
    cout << endl;
    cout << "Testing transpose on a non-square matrix:" << endl;
    m5->toString();
    cout << "the transpose is:" << endl;
    m5 = m5->transpose();
    m5->toString();
    cout << endl;

    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
    delete m6;
}

/**
 * Apply the Sigmoid activation function: 1/(1 + exp(-input))
 */
Matrix<float>* activate(Matrix<float>* input) {
    Matrix<float>* zeros = new Matrix<float>(input->getRows(), input->getCols(), input->getRows() * input->getCols());
    Matrix<float>* result = zeros->operator-(input);
    result = result->expo();
    result = result->operator+(1);
    vector<vector<float>> data = result->getData();

    for (int row = 0; row < result->getRows(); row++) {
        for (int col = 0; col < result->getCols(); col++) {
            data[row][col] = 1 / data[row][col];
        }
    }

    return result;
}

/**
 * error for a prediction is y - _y, which means actual y minus the prediction result
 */
Matrix<float>* error_calculation(Matrix<float>* y, Matrix<float>* _y) {
    return y->operator-(_y);
}

/**
 * When we do back propagation, we need to modify weights and biases based on our error.
 * We first get a deviation_ratio, which is equal to learning_rate * activated * (1 - activated).
 * Note: you may have troubles with the shapes, so use transpose when you cannot calculate.
 * The deviation_ratio we got through calculation is a matrix with 1 element, so
 * we need to extract the scalar.
 * The new bias is the old bias + (error * deviation_ratio_scalar).
 * The new weight is the old weight + x * error * deviation_ratio_scalar.
 * Note: Here you may also have problems with the shapes, use transpose.
 * The size of bias and weight should not be changed through backprop.
 */
void backprop(Matrix<float>* weight,
              Matrix<float>* bias,
              Matrix<float>* activated,
              Matrix<float>* error,
              float learning_rate,
              Matrix<float>* x) {
    Matrix<float>* oneMinusActivated = new Matrix<float>();
    oneMinusActivated->setRows(activated->getRows());
    oneMinusActivated->setCols(activated->getCols());
    vector<vector<float>> data = activated->getData();

    // calculate (1 - activated):
    for (int row = 0; row < activated->getRows(); row++) {
        for (int col = 0; col < activated->getCols(); col++) {
            data[row][col] = 1 - data[row][col];
        }
    }

    oneMinusActivated->setData(data);

    // calculate learning_rate * activated:
    Matrix<float>* deviation_ratio = activated->operator*(learning_rate);

    // calculate (learning_rate * activated) * (1 - activated):
    deviation_ratio = deviation_ratio->operator*(oneMinusActivated);

    // extract the scalar:
    float deviation_ratio_scalar = deviation_ratio->getData()[0][0];

    // update the bias:
    bias = bias->operator+(error->operator*(deviation_ratio_scalar));

    // update the weight:
    weight = weight->operator+(x->operator*(error->operator*(deviation_ratio_scalar)));
}

void train_two_input_AND_gate() {
    cout << endl << "Training a two-input AND gate:" << endl;
    int toPow = 2;
    float learning_rate = 0.5;
	unsigned int cycles = 101;

	const int exampleNum = 4;
	const int featureNum = 2;
	const int outNum = 1;
	float data[] = {0, 0, 0, 1, 1, 0, 1, 1};
	float label[] = {0, 0, 0, 1};
	float zeros[] = {0, 0, 0, 0};
	Matrix<float>* x = new Matrix<float>(exampleNum, featureNum, data);  // 4x2 Matrix
	Matrix<float>* y = new Matrix<float>(exampleNum, outNum, label);     // 4x1 Matrix
	Matrix<float> w = Matrix<float>(featureNum, outNum);                 // 2x1 Matrix
	Matrix<float> b = Matrix<float>(exampleNum, outNum, zeros);          // 4x1 Matrix

    for (int i = 0; i < cycles; i++ ) {
		Matrix<float>* logits = x->operator*(&w)->operator+(&b);
		Matrix<float>* activated = activate(logits);
		Matrix<float>* error = error_calculation(y, activated);

        if (i % 100 == 0) {
            cout << "Error rate: " << (error->operator^(toPow))->sum() / (error->getRows() * error->getCols()) << endl;
        }

		backprop(&w, &b, activated, error, learning_rate, x);
	}
}

int main(void) {
    testMatrixClass();
    train_two_input_AND_gate();
	return 0;
}
