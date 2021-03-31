/*
 * Author: Kinda Lam
 * CodeJam 2021 Qualification -- Question 1 -- Reversort
 * https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d0a5c
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int> v)
{
	int total_cost = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		int j = min_element(v.begin() + i, v.end()) - v.begin();
		reverse(v.begin() + i, v.begin() + j + 1);
		total_cost += j - i + 1;
	}
	return total_cost;
}

int main()
{
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int N; cin >> N;
		vector<int> v(N, 0);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}

		cout << "Case #" << t << ": ";
		cout << solve(v) << endl;
	}
	return 0;
}
