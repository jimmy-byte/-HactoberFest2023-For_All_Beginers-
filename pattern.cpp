// CPP program to print all occurrences of a pattern in a text

#include <bits/stdc++.h>
using namespace std;

void printOccurrences(string txt, string pat)
{
	int found = txt.find(pat);
	while (found != string::npos) {
		cout << "Pattern found at index " << found << endl;
		found = txt.find(pat, found + 1);
	}
}

int main()
{
	string txt = "aaaa", pat = "aa";
	printOccurrences(txt, pat);
	return 0;
}
