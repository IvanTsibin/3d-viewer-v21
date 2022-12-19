#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#define EPS 1.0e-7

class S21Matrix {
  int rows_, columns_; // Rows & columns
                       // Pointer to the memory for the matrix
  void getMemory();
  void freeMemory();
  void s21_minor(const S21Matrix &other, int rows, int columns);

public:
  S21Matrix(); // constructor - defualt
  S21Matrix(
      int rows,
      int cols); // Parametrized constructor with number of rows and columns
  S21Matrix(const S21Matrix &other); // Copy constructor
  S21Matrix(S21Matrix &&other);      // Move constructor
  ~S21Matrix();                      // Destructor

  // void sum_matrix(const S21Matrix& other);
  bool eq_matrix(const S21Matrix &other);
  void sum_matrix(const S21Matrix &other);
  void sub_matrix(const S21Matrix &other);
  void mul_number(const double num);
  void mul_matrix(const S21Matrix &other);
  S21Matrix transpose();
  S21Matrix calc_complements();
  double determinant();
  S21Matrix inverse_matrix();

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

  int rows_given(); // getters
  int collumns_given();
  void setRows(int num); // setters
  void setColumns(int num);

  void print(); // help function
  double **matrix;
};

#endif // SRC_S21_MATRIX_OOP_H_
