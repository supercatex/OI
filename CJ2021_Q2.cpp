/*
 * Author: Kinda Lam
 * CodeJam 2021 Qualification -- Question 2 -- Moons and Umbrellas
 * https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1145
 */
#include <iostream>
#include <string>
using namespace std;

int get_cost(int x, int y, string s)
{
	if (s.size() <= 1) return 0;
	
	int cost = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i - 1] == 'C' && s[i] == 'J') cost += x;
		if (s[i - 1] == 'J' && s[i] == 'C') cost += y;
	}
	return cost;
}

int unknown_string_cost(int x, int y, string s)
{
	int i = s.find("?");
	int j = s.rfind("?") + 1;

	for (int k = i; k < j; k++) s[k] = 'C';
	int cost = get_cost(x, y, s);
	
	for (int k = i; k < j; k++) s[k] = 'J';
	cost = min(get_cost(x, y, s), cost);
	
	for (int k = i; k < j; k++) s[k] = (k % 2 == 0) ? 'C' : 'J';
	cost = min(get_cost(x, y, s), cost);
	
	for (int k = i; k < j; k++) s[k] = (k % 2 == 1) ? 'C' : 'J';
	cost = min(get_cost(x, y, s), cost);
	
	return cost;
}

int solve(int x, int y, string s)
{
	int i = s.find("?");
	if (i == -1) return get_cost(x, y, s);
	int j = i;
	while (j < s.size() && s[j] == '?') j++;
	
	string s1 = s.substr(0, i);
	string s2 = s.substr(j, s.size() - j);
	int cost = solve(x, y, s1) + solve(x, y, s2);
	
	string s3 = s.substr(i, j - i);
	if (s1.size() > 0) s3 = s1[s1.size() - 1] + s3;
	if (s2.size() > 0) s3 = s3 + s2[0];
	cost += unknown_string_cost(x, y, s3);
	
	return cost;
}

int main()
{
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int X, Y; cin >> X >> Y;
		string S; cin >> S;
		
		cout << "Case #" << t << ": ";
		cout << solve(X, Y, S) << endl;
	}
	return 0;
}
