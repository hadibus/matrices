#ifndef MATRIX_HPP
#define MATRIX_HPP
#include<string>

class Matrix{
public:
  Matrix();
  Matrix(unsigned, unsigned, std::string);
  Matrix(const Matrix &);
  Matrix(Matrix &&);
  void display(bool debug = false);
  unsigned getCols();
  double getDigit(const unsigned &, const unsigned &);
  unsigned getRows();
  static Matrix multiply(Matrix, double);
  Matrix & operator = (const Matrix &);
  Matrix operator *(double);
  Matrix operator +(Matrix);
  void setDigit(const unsigned &, const unsigned &, double);

  ~Matrix();
private:
  unsigned m_rows;
  unsigned m_cols;
  double ** m_numbers;
};

#endif
