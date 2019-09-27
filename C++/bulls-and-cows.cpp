#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
#include <utility>
#include <sstream>

using namespace std;
const int GAME_SIZE = 3;

int init_rand() {
	vector<int> arr;
	for (int i = 0; i < 10; i++) arr.push_back(i);
	while (arr[0] == 0) {
		random_shuffle(arr.begin(), arr.end());
	}
	int result = 0;
	for (int i = 0; i < GAME_SIZE; i++) {
		result = result * 10 + arr[i];
	}
	return result;
}

int user_input() {
	int result;
	while (true) {
		string str;
		bool flag = false;
		cout << "숫자를 입력해 주세요 : ";
		getline(cin, str);
		istringstream(str) >> result;
		str = to_string(result);
		if (str.size() <= GAME_SIZE) {
			for (int i = 0; i < str.size(); i++) {
				for (int j = 0; j < str.size(); j++) {
					if (i == j) continue;
					if (str[i] == str[j]) {
						flag = true;
					}
				}
				if (flag) break;
			}
			if (!flag) return result;
		}
	}
}

pair<int, int> checknum(int com, int user) {
	pair<int, int> result = { 0,0 };
	string com_str = to_string(com);
	string user_str = to_string(user);
	for (int i = 0; i < GAME_SIZE; i++) {
		for (int j = 0; j < GAME_SIZE; j++) {
			if (com_str[i] == user_str[j]) {
				if (i == j) result.first++;
				else result.second++;
			}
		}
	}
	return result;
}

int main() {
	srand((unsigned int)time(0));
	int answer = init_rand();
	while (true) {
		int user = user_input();
		pair<int, int> result = checknum(answer, user);
		if (result.first == 3) {
			cout << "축하드립니다. 정답 : " << answer << "\n";
			break;
		}
		else {
			if (result.first == 0 && result.second == 0) {
				cout << "아웃\n";
			}
			else {
				cout << "Strike : " << result.first << " / ball : " << result.second << "\n";
			}
		}
	}
	return 0;
}