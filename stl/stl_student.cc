#include <iostream>
#include <vector>
#include <algorithm>
#include <fmt/format.h>

using namespace std;

enum Sex {
	MALE,
	FEMALE,
};

enum Major {
	COMPUTER,
	PHYSICS,
	ENGLISH,
};

struct Student {
private:
	int no;
	string name;
	Sex sex;
	string birth_place;
	Major major;
public:
	explicit Student(int no, string name, Sex sex, string birth_place, Major major)
		: no(no), name(name), sex(sex), birth_place(birth_place), major(major)
		{}

	int get_no() { return no; }
	string get_name() { return name; }
	int get_sex() { return sex; }
	Major get_major() { return major; }
	void display() {
		cout << " no = " << no << '\n'
		     << " name = " << name << '\n'
		     << " sex = " << sex << '\n'
		     << " birth_place = " << birth_place << '\n'
		     << " major = " << major << endl;
	}
};

class MatchMajor {
	Major major;
public:
	MatchMajor(Major m) { major = m; }
	bool operator ()(Student& s) { return s.get_major() == major; }
};

bool compare_no(Student &s1, Student &s2) {
	return s1.get_no() > s2.get_no();
}

void display(Student &s) {
	s.display();
	cout << endl;
}

bool match_computer(Student &s) { return s.get_major() == COMPUTER; }
bool match_physics(Student &s) { return s.get_major() == PHYSICS; }

int main()
{
	int num = 0;
	vector<Student> students;

	cout << "please input total students : ";
	cin >> num;

	for (int i = 0; i < num; ++i) {
		int no = i + 1;
		string name = fmt::format("liming-{}", i);
		Sex sex;
		if (i % 2 == 0)
			sex = MALE;
		else
			sex = FEMALE;
		string birth_place = fmt::format("beijing-{}", i);
		Major major;
		if (i % 3 == 0)
			major = COMPUTER;
		else if (i % 3 == 1)
			major = PHYSICS;
		else
			major = ENGLISH;

		Student stu(no, name, sex, birth_place, major);
		students.push_back(stu);
	}

	sort(students.begin(), students.end(), compare_no);
	for_each(students.begin(), students.end(), display);

	cout << count_if(students.begin(), students.end(), MatchMajor(COMPUTER)) << endl;
	cout << count_if(students.begin(), students.end(), MatchMajor(PHYSICS)) << endl;

	return 0;
}
