#ifndef S21_MATRIX_OOP_H_
#define S21_MATRIX_OOP_H_

#define EPS 1.0e-7

namespace s21 {

class S21Matrix {
  int rows_, columns_; // Rows & columns
                       // Pointer to the memory for the matrix
  void GetMemory();
  void FreeMemory();
  void S21Minor(const S21Matrix &other, int rows, int columns);

public:
  S21Matrix(); // constructor - defualt
  S21Matrix(
      int rows,
      int cols); // Parametrized constructor with number of rows and columns
  S21Matrix(const S21Matrix &other); // Copy constructor
  S21Matrix(S21Matrix &&other);      // Move constructor
  ~S21Matrix();                      // Destructor

  // void sum_matrix(const S21Matrix& other);
  bool EqMatrix(const S21Matrix &other);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // Other methods..

  S21Matrix operator+(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  S21Matrix operator*(const S21Matrix &other);
  S21Matrix operator*(const double num);
  bool operator==(const S21Matrix &other);
  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix operator+=(const S21Matrix &other);
  S21Matrix operator-=(const S21Matrix &other);
  S21Matrix operator*=(const S21Matrix &other);
  S21Matrix operator*=(const double num);
  double &operator()(int i, int j) const;

  int RowsGiven(); // getters
  int CollumnsGiven();
  void SetRows(int num); // setters
  void SetColumns(int num);

  void Print(); // help function
  double **matrix;
};

} // namespace s21

#endif // S21_MATRIX_OOP_H_
