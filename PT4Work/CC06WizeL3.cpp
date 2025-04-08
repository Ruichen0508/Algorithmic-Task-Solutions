#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include "pt4.h"

using namespace std;

struct ATask {
	string name;
    string start_date;
    string end_date;
    vector<string> members;

    ATask(const vector<string>& task) {
        name = task[0];
        start_date = task[1];
        end_date = task[2];
        for (int i = 3; i < task.size(); ++i) {
            members.push_back(task[i]);
        }
    }
};

bool compareTasks(const ATask& t1, const ATask& t2) {
    if (t1.end_date == t2.end_date) {
        return t1.name < t2.name;
    }
    return t1.end_date < t2.end_date;
}

vector<vector<string>> solution(vector<vector<string>> tasks, vector<vector<string>> queries) {
    vector<ATask> task_objects;
    for (const auto& task : tasks) {
        task_objects.push_back(ATask(task));
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
            return compareTasks(*find_if(task_objects.begin(), task_objects.end(), [&t1](const ATask& task) { return task.name == t1; }),
                                *find_if(task_objects.begin(), task_objects.end(), [&t2](const ATask& task) { return task.name == t2; }));
        });

        result.push_back(temp);
    }

    return result;
}

void Solve() {
	Task("CC06WizeL3");
	int n;
	pt>>n;
	vector<vector<string>> t,q,result;
	vector<string> temp;
	for(;n>0;n--) {
		temp=vector<string>(ptin_iterator<string>(0), ptin_iterator<string>());
		t.push_back(temp);
	}
	pt>>n;
	for(;n>0;n--) {
		temp=vector<string>(ptin_iterator<string>(2), ptin_iterator<string>());
		q.push_back(temp);
	}
	vector<vector<string>> r=solution(t,q);
	copy_if(r.begin(),r.end(),back_inserter(result),[](auto v){ return v.size()>0;});
	pt<<r.size();
	pt<<result;
}
