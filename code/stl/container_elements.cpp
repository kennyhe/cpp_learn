
#include <iostream>
#include <vector>

using namespace std;

class Obj1 {
public:
  Obj1(const int& val)
  {
    this->a = val;
    cout << "Obj1(" << a << ")\n";
  }
  Obj1(const Obj1& copy): a(copy.a * 10)
  {
    cout << "Obj1(const Obj1&, " << a << ")\n";
  }
  Obj1(Obj1&& move): a(move.a * 100)
  {
    cout << "Obj1(Obj1&&, " << a << ")\n";
  }
  ~Obj1() {
    cout << "~~~Obj1(" << a << ")\n";
  }
private:
  int a;
};

class Obj2 {
public:
  Obj2(const int& val): a{val}
  {
    cout << "Obj2(" << a << ")\n";
  }
  Obj2(const Obj2& copy): a{copy.a * 10}
  {
    cout << "Obj2(const Obj2&, " << a << ")\n";
  }
  Obj2(Obj2&& move) noexcept: a{move.a * 100}
  {
    cout << "Obj2(Obj2&&, " << a << ")\n";
  }
  ~Obj2() {
    cout << "~~~Obj2(" << a << ")\n";
  }
private:
  int a;
};


template <class T>
void append(vector<T>& v, const int& value) {
  cout << "before: size: " << v.size() << ", capacity: " << v.capacity() << endl;
  // v.emplace_back(value);
  v.push_back(value);
  cout << "after: size: " << v.size() << ", capacity: " << v.capacity() << endl;
}

int main()
{
  vector<Obj1> v1;
  v1.reserve(2);
  append(v1, 11);
  append(v1, 12);
  append(v1, 13);

  vector<Obj2> v2;
  v2.reserve(2);
  append(v2, 21);
  append(v2, 22);
  append(v2, 23);
}
