
#include <algorithm>   // std::sort
#include <functional>  // std::less/greater/hash
#include <iostream>    // std::cout/endl
#include <string>      // std::string
#include <vector>      // std::vector
#include "output_container.hpp"

using namespace std;

int main()
{
  // 初始数组
  vector<int> v{13, 6, 4, 11, 29};
  cout << v << endl;

  // 从小到大排序
  sort(v.begin(), v.end());
  cout << v << endl;

  // 从大到小排序
  sort(v.begin(), v.end(),
       greater<int>());
  cout << v << endl;

  cout << hex;

  // auto hp = hash<int*>();
  hash<int*> hp;
  cout << "hash(nullptr)  = "
       << hp(nullptr) << endl;
  cout << "hash(v.data()) = "
       << hp(v.data()) << endl;
  cout << "v.data()       = "
       << static_cast<void*>(v.data())
       << endl;

  hash<string> hs;
  cout << "hash(\"hello\")  = "
       << hs(string("hello")) << endl;
  cout << "hash(\"hellp\")  = "
       << hs(string("hellp")) << endl;
}