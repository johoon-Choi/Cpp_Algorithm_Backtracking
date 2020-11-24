#include <iostream>
#include <vector>

using namespace std;

int N;
vector<bool> leftDigonal(31, 1); // 2N - 1 개 필요 ( leftDigonal[ i - j + N - 1 ] 사용 )
vector<bool> rightDigonal(31, 1); // 2N - 1 개 필요
vector<bool> colCheck(16, 1); // N개 필요
// promising 하면 true

bool isPromising(int row, int col) {
	bool ans;
	ans = leftDigonal[row - col + N - 1] && rightDigonal[row + col] && colCheck[col];
	return ans;
}

int dfs(int row) {
	static int count = 0;
	// ********* input algorithm here ***********
	if (row == N) { // one case founded
		count++;
	}

	for (int col = 0; col < N; col++) {
		if (isPromising(row, col)) {
			leftDigonal[row - col + N - 1] = false;
			rightDigonal[row + col] = false;
			colCheck[col] = false;
			dfs(row + 1);
			leftDigonal[row - col + N - 1] = true;
			rightDigonal[row + col] = true;
			colCheck[col] = true;
		}
	}
	// ******************************************
	return count;
}

int main() {
	cin >> N;
	cout << dfs(0);
}