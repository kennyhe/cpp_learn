#include <iostream>
#include "json.hpp"

using namespace std;
using json_t = nlohmann::json;

int main() {
	json_t j;

	j["age"] = 3;
	j["name"] = "spiderman";
	vector<int> v = {1, 2, 3};
	j["numbers"] = v;

	map<string, int> m = {{"one", 1}, {"two", 2}};

	j["kv"] = m;

	cout << j.dump() << endl;
}