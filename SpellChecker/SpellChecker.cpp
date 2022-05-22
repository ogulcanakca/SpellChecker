#include <fstream>
#include <iostream>
#include <list>

using namespace std;


list<string> fileReading(ifstream& file_reading_1, ifstream& file_reading_2)
{
	char item;
	string temp_ch;
	list<string> searching_words;
	list<string> dictionary;
	list<string> existing_words;
	string temp_ch_spec;
	list<string> special = { "'bout","'cause","'course","'cuse",
	"'em","'frisco","'gain","'kay","'m","'n","'round",
	"'s","'til","'tis","'twas","a's","a.","a.'s","a.d.","a.m.",
	"a.s" };
	if (file_reading_1)
	{
		while (file_reading_1.get(item))
		{
			if (item != '\n' && item != ' ')
			{
				
				temp_ch_spec += tolower(item);;
				if (item != '.' && item != ' ' && item != '\''
					&& item != '!' && item != ',' && item != '\"'
					&& item != '(' && item != ')' && item != ';'
					&& item != ':' && item != '?')
				{
					temp_ch += tolower(item);
				}
			}
			else
			{

				for (string spec : special)
				{
					if (spec == temp_ch_spec)
					{
						searching_words.push_back(temp_ch_spec);
						temp_ch_spec = "";
					}
				}
				searching_words.push_back(temp_ch);
				temp_ch = "";

			}
		}
	}
	if (file_reading_2)
	{
		while (file_reading_2.get(item))
		{
			if (item != ' ' && item != '\n' && item != '\t')
			{


				temp_ch += tolower(item);

			}
			else
			{

				dictionary.push_back(temp_ch);
				temp_ch = "";

			}
		}
	}
	for (string words_item : searching_words)
	{
		for (string dic_item : dictionary)
		{
			if(words_item==dic_item)
			{
				existing_words.push_back(dic_item);
			}
		}
	}
	for (string existing_word_item : existing_words)
	{
		for (string searching_words_item : searching_words)
		{
			
			if (!existing_words.front().find(searching_words_item))
			{
				cout << existing_word_item << "is not found"<< endl;
				existing_words.pop_front();
			}
			else
			{
				cout << existing_word_item << "is found"<<endl;
			}
		}
	}
	
	return searching_words;
}

int main()
{
	list<string> words;
	ifstream file_reading_1;
	string filename_1 = "alice.txt";
	file_reading_1.open(filename_1);
	ifstream file_reading_2;
	string filename_2 = "cmudict.dict";
	file_reading_2.open(filename_2);
	words = fileReading(file_reading_1,file_reading_2);
}

