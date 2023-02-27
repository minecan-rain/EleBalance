#include "EleMatrix.h"

EleMatrix::EleMatrix() {
	
}

EleMatrix::EleMatrix(int n) {
	M = new Matrix[n];
}

Matrix& EleMatrix::operator[](int n) {
	return M[n];
}