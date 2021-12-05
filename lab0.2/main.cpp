#include <iostream>
#include <cmath>

class Complex{

 public:
  Complex();
  Complex(double r, double j);

  double modul(Complex x);
  Complex conj(); //Сопряженное число
  Complex to_alg(Complex x); //Перевод в алгебраический вид
  Complex to_trig(Complex x); //Перевод в тригонометрический вид

  friend std::istream& operator>> (std::istream &in, Complex &num); //Перегрузка оператора вывода
  friend std::ostream& operator<< (std::ostream &out, const Complex &num); //Перегрузка оператора вывода
  Complex operator + (const Complex &x);
  Complex operator - (const Complex &x);
  Complex operator * (const Complex &x);
  Complex operator / (const Complex &x);
  bool operator == (const Complex &x);
  bool operator < (const Complex &x);
  bool operator > (const Complex &x);
 private:
  double r,j;
};

Complex::Complex(double r, double j) {
  this->r = r;
  this->j = j;
}

Complex Complex::to_alg(Complex x) {
  return {x.r * cos(x.j), x.r * sin(x.j)};
}

Complex Complex::to_trig(Complex x) {
  double a = x.r, b = x.j;
  double z = sqrt(a * a + b * b);
  double argZ = (-3.14 + atan(b / a)) * (180 / 3.14);
  return {z, argZ};
}

Complex Complex::conj() {
  return {this->r, -this->j};
}

Complex::Complex() {
  this->r = 0;
  this->j = 0;
}

std::ostream &operator<<(std::ostream &out, const Complex &num) {
  out << "Complex num in trigonometric form: " << num.r << "*(cos" << num.j << " + i * sin" << num.j << ")" << std::endl;
  return out;
}

std::istream &operator>>(std::istream &in, Complex &num) {
  in >> num.r >> num.j;
  return in;
}
Complex Complex::operator+(const Complex &x) {
  Complex alg_form1 = to_alg(*this);
  Complex alg_form2 = to_alg(x);
  Complex result(alg_form1.r + alg_form2.r, alg_form1.j + alg_form2.j);
  return to_trig(result);
}
Complex Complex::operator-(const Complex &x) {
  if(this->r == x.r && this->j == x.j) return {0, 0};
  Complex alg_form1 = to_alg(*this);
  Complex alg_form2 = to_alg(x);
  Complex result(alg_form1.r - alg_form2.r, alg_form1.j - alg_form2.j);
  return to_trig(result);
}
Complex Complex::operator*(const Complex &x) {
  return {this->r * x.r, this->j + x.j};
}
Complex Complex::operator/(const Complex &x) {
  if(x.r == 0 && x.j == 0){
    std::cout << "На 0 делить нельзя!" << std::endl;
    return *this;
  }
  return {this->r / x.r, this->j - x.j};
}
bool Complex::operator==(const Complex &x) {
  return this->r == x.r && this->j == x.j;
}
double Complex::modul(Complex x) {
  Complex sub = to_alg(x);
  return sqrt(sub.r * sub.r + sub.j * sub.j);
}
bool Complex::operator<(const Complex &x) {
  return modul(*this) < modul(x);
}
bool Complex::operator>(const Complex &x) {
  return modul(*this) > modul(x);
}

Complex operator "" _complex(const char* str, size_t size) {
  int cnt = 0;
  std::string s;
  while (str[cnt] != ' '){
    s += str[cnt++];
  }
  double r = 0, j = 0;
  for (char i : s) {
    r *= 10;
    r += i - '0';
  }
  s = "";
  while (str[cnt++] != '\0') {
    s += str[cnt];
  }
  for (int i = 0; i < s.size() - 1; ++i) {
    j *= 10;
    j += s[i] - '0';
  }
  Complex res(r, j);
  return res;
}

int main() {
  Complex test_num1, test_num2;

  std::cin >> test_num1;
  std::cin >> test_num2;

  std::cout << test_num1 << test_num2 << std::endl;
  //Литерал
  std::cout << "10 40"_complex << std::endl;
  //Все операции
  std::cout << "Сложение: " << test_num1 + test_num2 << std::endl;
  std::cout << "Вычитание: " << test_num1 - test_num2 << std::endl;
  std::cout << "Умножение: " << test_num1 * test_num2 << std::endl;
  std::cout << "Деление: " << test_num1 / test_num2 << std::endl;
  std::cout << "Проверка на равенство: " << bool(test_num1 == test_num2) << std::endl;
  std::cout << "Сопряженное число: " << test_num1.conj() << std::endl;
  std::cout << "Сравнение по модулю: " << bool(test_num1 > test_num2) << std::endl;

  return 0;
} //Сложение: Complex num in trigonometric form: 4.63849*(cos-109.508 + i * sin-109.508)