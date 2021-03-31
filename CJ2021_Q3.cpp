/*
 * Author: Kinda Lam
 * CodeJam 2021 Qualification -- Question 2 -- Reversort Engineering
 * https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d12d7
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_v(vector<int> v)
{
	if (v.size() > 0) {
		for (int i = 0; i < v.size() - 1; i++) {
			cout << v[i] << " ";
		}
		cout << v[v.size() - 1];
	}
	cout << endl;
}

vector<int> solve(int n, int c)
{
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}
	
	for (int i = n - 2; i >= 0; i--) {
		int k = min(c - i, n - i);
		int j = k + i - 1;
		reverse(v.begin() + i, v.begin() + j + 1);
		c = c - k;
	}
	return v;
}

int main() 
{
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int N, C; cin >> N >> C;
		
		cout << "Case #" << t << ": ";
		if (C < N - 1 || C >= N * (N + 1) / 2) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			print_v(solve(N, C));
		}
	}
	return 0;
}
