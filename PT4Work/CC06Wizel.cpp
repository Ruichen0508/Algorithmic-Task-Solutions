#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include "pt4taskmaker.h"

void Task1()
{
	CreateTask();
	TaskText("\\ScountAPI.\\s You are given a list of API calls in the format \n"
		" / project / subproject / method.\n"
		"You need to calculate and print the number of calls to each node of\n"
		" the API endpoint as a tree.In this tree, projects, subprojects, and methods \n"
		"should be sorted in the same order as they were given in the input data.\n"
		" The output tree should consist of several strings. All subprojects fall\n"
		"under their parent project, and all methods fall under the subproject in \n"
		"which they are included.The string that represents a project starts with\n"
		" --, while subprojects start with ---- and methods start with ------. \n"
		"After the project, subproject, or method name, put the number of\n"
		"requests to this module in parentheses. Take a look at the \n"
		"example for a guide of what this tree should look like.\n"
	);


}

vector<string> solution2(vector<vector<string>> conversations, vector<string> currentConversation) {
	map<unsigned int, pair<int, int>> matches;
	set<string> currentConversationWords(currentConversation.begin(), currentConversation.end());

	for (int i = 0; i < conversations.size(); ++i)
	{
		set<string> conversationWords(conversations[i].begin(), conversations[i].end());
		vector<string> intersection;

		set_intersection(currentConversationWords.begin(), currentConversationWords.end(),
			conversationWords.begin(), conversationWords.end(),
			back_inserter(intersection));

		if (!intersection.empty()) {
			for (int j = conversations[i].size() - 1; j >= 0; --j)
			{
				if (find(intersection.begin(), intersection.end(), conversations[i][j]) != intersection.end())
				{
					matches.insert({ intersection.size(), {i, j} });
					break;
				}
			}
		}
	}

	if (!matches.empty()) {
		auto bestMatch = matches.rbegin()->second;
		currentConversation.insert(currentConversation.end(), conversations[bestMatch.first].begin() + bestMatch.second + 1, conversations[bestMatch.first].end());
	}

	return currentConversation;
}
void Task2()
{
	CreateTask();
	TaskText("\\SchatBot.\\s You have a list conversations, in which each\n"
		" element is a conversation that  is represented as an array of words. \n"
		" You need to create a chatbot that will complete a conversation\n"
		"that is currently in progress, currentConversation.\n"
		"To do that, the chatbot must find the conversation from the given list\n"
		" that has the largest number of unique words that match with words from the\n"
		"currentConversation.If there are several conversations that match\n"
		" this condition,the chatbot should use the one that \n"
		"appears first in conversations.\n"
		" If no conversation from the list contains any matching words from\n"
		"currentCoversation, the chatbot should leave currentConversation as it is.\n"
		"If there is a conversation that can complete currentConversation, \n"
		" the chatbot should find the first word in it that appears after all the\n"
		"matching words. The chatbot should then append this word, along with all the \n"
		" words that follow it in that conversation, to currentConversation.\n"
		"Return the final state of currentConversation.\n");
	vector<vector<string>> tasks_array[] =
	{
		{
			{"where","are","you","live","i","live","in","new","york"},
			{"are","you","going","somewhere","tonight","no","i","am","too","tired","today"},
			{"hello","what","is","your","name","my","name","is","john"}
		},
		{
			{"lets","have","some","fun"},
		{"i","never","get","it"},{"be","aware","of","this","house"},{"he","will","call","her"}
		},
		{
			{"it","is","my","favorite","movie"},
			{"really","i","did","not","know" },
		},
		{
			{"tonight","i","need","dollar","bills"},
		{"i","dont","keep","fun" },
		{"cheap","thrills","long","to","feel","money"},
		{"the","bills","dont","need","the","dancing","baby"},
		{"fun","dollar","dancing","thrills","the","baby","i","need"},{"dont","have","fun"},{"no","no","dont","have","dancing","fun","tonight"}
		},
		{
			{"fame","what","you","like","is","in","the","limo"},
		{"fame","what","you","get","is","no","tomorrow"},
		{"fame","what","you","need","you","have","to","borrow","fame"},
		{"fame","its","mine","its","mine","its","just","his","line"},
		{"to","bind","your","time","it","drives","you","to","crime"}
		},

	};
	vector<string> queries_array[] =
	{
		{"hello",
		"john",
			"do",
		"you",
		"have",
		"a",
		"favorite",
		"city",
		"to",
		"live",
		 "in",
		 "yes",
		"it",
		"is"},
		{
			"can",
			"you",
			"please"
		},
		{
			"what",
 "you",
 "think",
 "about",
 "this",
 "movie"
		},
		{
			"beat",
 "the",
 "can",
 "as",
 "i",
 "dont",
 "feel",
 "thrills"
		},
		{
			"what",
 "is"
		},



	};
	int i = RandomN(0, sizeof(tasks_array) / sizeof(tasks_array[0]) - 1);
	vector<vector<string>>& t = tasks_array[i];
	vector<string>& q = queries_array[i];
	vector<string> result = solution2(t, q);
	DataN("task\\\_Count = ", t.size(), 1, 1, 1);
	int x, y = 2;
	for (const vector<string>& v : t) {
		x = 1;
		DataN(v.size(), x, y, 1);
		x += to_string(v.size()).length() + 1;
		for (const string& s : v) {
			DataS(s.c_str(), x, y);
			x += s.length() + 3;
		}
		y++;
	}
	DataN("query\\\_Count = ", q.size(), 1, y++, 1);
	for (const string& v : q) {
		x = 1;
		DataS(v.c_str(), x, y);
		x += v.length() + 3;
		DataS(v.c_str(), x, y);
		y++;
	}
	ResultN(result.size(), 1, 1, 1);
	y = 2;
	//ResultS(result.c_str(), x, y);
	for (const string& v : result) {
		x = 1;
		//for (const char& s : v) {
		ResultS(v.c_str(), x, y);
		//x += s.length() + 3;
	//}
		y++;
	}

}
struct Task {
	string name;
	string start_date;
	string end_date;
	vector<string> members;

	Task(const vector<string>& task) {
		name = task[0];
		start_date = task[1];
		end_date = task[2];
		for (int i = 3; i < task.size(); ++i) {
			members.push_back(task[i]);
		}
	}
};

bool compareTasks(const Task& t1, const Task& t2) {
	if (t1.end_date == t2.end_date) {
		return t1.name < t2.name;
	}
	return t1.end_date < t2.end_date;
}

vector<vector<string>> solution(vector<vector<string>> tasks, vector<vector<string>> queries) {
	vector<Task> task_objects;
	for (const auto& task : tasks) {
		task_objects.push_back(Task(task));
	}

	vector<vector<string>> result;
	for (const auto& query : queries) {
		vector<string> temp;
		string name = query[0];
		string date = query[1];

		for (const auto& task : task_objects) {
			if (date >= task.start_date && date <= task.end_date &&
				find(task.members.begin(), task.members.end(), name) != task.members.end()) {
				temp.push_back(task.name);
			}
		}

		sort(temp.begin(), temp.end(), [&task_objects](const string& t1, const string& t2) {
			return compareTasks(*find_if(task_objects.begin(), task_objects.end(), [&t1](const Task& task) { return task.name == t1; }),
			*find_if(task_objects.begin(), task_objects.end(), [&t2](const Task& task) { return task.name == t2; }));
			});

		result.push_back(temp);
	}

	return result;
}
void Task3()
{
	CreateTask();
	TaskText("\\Sroadmap.\\s HIHIHI You have a roadmap, which is the\n"
		" list of tasks that your team needs to complete. \n"
		"Each task in this list has a title, a start date,\n"
		" an end date, and a list of the people who will be working\n"
		"on it. You are given some queries,\n"
		"each of which contains a specific person's name and a date. \n"
		" For each query that is made, you need to return\n"
		"  the list of tasks on which that person will be working on the \n"
		"date specified in the query, sorted by the tasks' end dates. \n"
		" If their end dates are equal, then sort by the tasks' titles.\n"
		"The first line of the input data is the task count {task\\\_Count},\n"
		"and each of the next {task\\\_Count} lines represents one task.\n"
		"Task format : number of strings contained in this task All strings\n"
		"that make up this task.The next line is the query count {query\\\_Count},\n"
		" followed by {query\\\_Count} lines each line represents a query, the query \n"
		"format is : name date.\n"
	);
	vector<vector<string>> tasks_array[] =
	{
		{
			{"A","2017-02-01","2017-03-01","Sam","Eva","Tro"},
			{"B","2017-01-16","2017-02-15","Tro"},
			{"C","2017-02-13","2017-03-13","Sam","Eva"}
		},
		{
			{"GOUGZ","2017-05-20","2017-08-10","Kai"}
		},
		{
			{"RXGWB", "2017-10-10", "2017-12-09", "Kyl"},
			{"QOEHU", "2017-08-25", "2017-12-11", "Cor", "Kai", "Kal", "Reu" },
			{"HRCPX", "2017-04-04", "2017-07-21", "Cor", "Jen", "Kyl"},
			{"SQFYX", "2017-07-07", "2017-12-02", "Reu", "Kal", "Kai", "Kyl"},
			{"BIDVM", "2017-04-20", "2017-12-08", "Kal"}
		},
		{
			{"LNWBN","2017-08-13","2017-12-24","Cor","Kyl","Kal","Reu"},
			{"NSXEN","2017-08-20","2017-09-18","Kai" },
			{"DNMDC","2017-06-19","2017-08-07","Kal","Kai","Kyl","Reu"},
			{"UYWEQ","2017-04-23","2017-07-18","Cor","Kyl","Reu","Kai"},
			{"LIVNH","2017-11-01","2017-12-24","Kal","Kai"}
		},
		{
			{"YEEXQ","2017-01-07","2017-09-18","Lan","Jam","Cor","Reu","Kyl","Dax"},
			{"GURYR","2017-05-21","2017-08-09","Reu","Jam","Kyl","Cor","Lan" },
			{"RPHDE","2017-10-20","2017-12-10","Jen","Vin","Kyl"},
			{"QVCPD","2017-03-01","2017-09-23","Kal","Dax","Vin","Reu","Cor","Kai"},
			{"XCDYD","2017-12-08","2017-12-20","Dax","Kal","Reu","Jen","Kai","Cor"}
		},
		{
			{"BWTYQ", "2017-09-07", "2017-09-09", "Kal"},
			{"IVNTU", "2017-06-15", "2017-09-07", "Vin", "Kai", "Lan", "Jen" },
			{"YZNVZ", "2017-06-06", "2017-06-20", "Cor", "Reu", "Kyl", "Dax"},
			{"UKZGD", "2017-09-16", "2017-09-19", "Kai", "Kyl", "Jen", "Jam"},
			{ "ZLYNM", "2017-08-24", "2017-10-01", "Kyl", "Kai", "Jam"},
			{"EXLAG", "2017-06-05", "2017-09-19", "Kal", "Kyl", "Kai"},
			{"ANBUQ", "2017-05-16", "2017-09-08", "Kai"},
			{"MVTMI", "2017-07-16", "2017-08-24", "Kyl", "Lan"},
			{"ITXJC", "2017-09-05", "2017-09-06", "Reu", "Cor", "Dax"},
			{"KLFDO", "2017-05-25", "2017-09-15", "Cor", "Jen", "Kai"}
		},
	};
	vector<vector<string>> queries_array[] =
	{
		{
			{"Eva","2017-03-10"},
			{"Tro","2017-02-04"}
		},
		{
			{"Kai", "2017-06-10"},
		},
		{
			{"Reu", "2017-06-09"},
			{"Jen", "2017-04-13"},
			{"Cor", "2017-12-01"},
			{"Jen", "2017-05-23"},
			{"Cor", "2017-08-19"}
		},
		{
			{"Cor","2017-10-21"},
			{"Reu","2017-03-16"},
			{"Kal","2017-11-22"},
			{"Reu","2017-10-06"}
		},
		{
			{"Jam","2017-02-12"},
			{"Kyl","2017-01-09"},
			{"Lan","2017-07-07"},
			{"Kai","2017-02-08"},
			{"Lan","2017-06-25"},
			{"Dax","2017-03-09"},
			{"Lan","2017-10-25"},
			{"Dax","2017-06-16"},
			{"Cor","2017-05-19"},
			{"Jam","2017-09-24"}
		},
		{
			{"Kal", "2017-05-01"},
			{"Kyl", "2017-09-11"},
			{"Kai", "2017-10-22"},
			{"Jen", "2017-08-17"},
			{"Jen", "2017-08-06"},
			{"Reu", "2017-06-25"},
			{"Jen", "2017-08-10"},
			{"Kal", "2017-06-03"},
			{"Jen", "2017-06-10"},
			{"Vin", "2017-06-24"},
			{"Vin", "2017-06-14"},
			{"Kai", "2017-08-01"},
			{"Kal", "2017-09-14"},
			{"Lan", "2017-07-24"},
			{"Lan", "2017-05-03"},
			{"Jen", "2017-10-13"},
			{"Kyl", "2017-07-07"},
			{"Cor", "2017-07-08"},
			{"Lan", "2017-05-04"},
			{"Cor", "2017-09-06"}
		},
	};
	int i = RandomN(0, sizeof(tasks_array) / sizeof(tasks_array[0]) - 1);
	vector<vector<string>>& t = tasks_array[i];
	vector<vector<string>>& q = queries_array[i];
	vector<vector<string>> result = solution(t, q);
	DataN("task\\\_Count = ", t.size(), 1, 1, 1);
	int x, y = 2;
	for (const vector<string>& v : t) {
		x = 1;
		DataN(v.size(), x, y, 1);
		x += to_string(v.size()).length() + 1;
		for (const string& s : v) {
			DataS(s.c_str(), x, y);
			x += s.length() + 3;
		}
		y++;
	}
	DataN("query\\\_Count = ", q.size(), 1, y++, 1);
	for (const vector<string>& v : q) {
		x = 1;
		DataS(v[0].c_str(), x, y);
		x += v[0].length() + 3;
		DataS(v[1].c_str(), x, y);
		y++;
	}
	ResultN(result.size(), 1, 1, 1);
	y = 2;
	for (const vector<string>& v : result) {
		x = 1;
		for (const string& s : v) {
			ResultS(s.c_str(), x, y);
			x += s.length() + 3;
		}
		y++;
	}
	SetTestCount(5);

}

void _stdcall InitTask(int num)
{
	switch (num)
	{
	case 1:
		Task1(); break;
	case 2:
		Task2(); break;
	case 3:
		Task3(); break;
	}
}

void _stdcall inittaskgroup()
{
	CreateGroup("CC06WizeL", "Group description",
		"", "qwqfsdf13dfttd", 3, InitTask);
}
