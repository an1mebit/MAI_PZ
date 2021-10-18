#include <iostream>
#include <string>
#include <map>

using namespace std;

void findString(string text, map<string, int>& word)
{
	int first, last;
	first = last = 0;

	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] == ' ')
		{

			last = i;

			string sub = text.substr(first, last - first);
			if (word.find(sub) == word.end()) word.insert(make_pair(sub, 1));
			else word[sub]++;

			first = last + 1;
		}
	}

	last = text.size();
	string sub = text.substr(first, last - first);
	if (word.find(sub) == word.end()) word.insert(make_pair(sub, 1));
	else word[sub]++;
}

int main()
{
	map<string, int> text;
	string cinText;

	getline(cin, cinText);
	findString(cinText, text);

	cout << endl;
	for (pair<string, int> out : text)
		cout << out.second << " " << out.first << endl;
}
