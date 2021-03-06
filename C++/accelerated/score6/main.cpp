#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>
#include "student_info.h"
#include "median.h"
#include "grade.h"


using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::streamsize;
using std::setprecision;
using std::vector;
using std::sort;
using std::domain_error;
using std::max;
using std::list;

bool fgrade(const Student_info& s)
{
	return grade(s) < 60;
}
/*
vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> pass, fail;
	
	for (vector<Student_info>::size_type i = 0; i < students.size(); ++i){
		if (fgrade(students[i]))
			fail.push_back(students[i]);
		else
			pass.push_back(students[i]);
	}
	students = pass;
	return fail;
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	
	for (vector<Student_info>::size_type i = 0; i < students.size(); ){
		if(fgrade(students[i])) {
			fail.push_back(students[i]);
			students.erase(students.begin() + i);
		} else {
			++i;
		}
	}
	return fail;
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	
	for (vector<Student_info>::iterator iter = students.begin(); iter != students.end();){
		if (fgrade(*iter)){
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else {
			++iter;
		}
	}
	
	return fail;
}
*/
list<Student_info> extract_fails(list<Student_info>& students)
{
	list<Student_info> fail;
	
	for (list<Student_info>::iterator iter = students.begin(); iter != students.end();){
		if (fgrade(*iter)){
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else {
			++iter;
		}
	}
	
	return fail;
}


int main()
{
	vector<Student_info> students;
	
	string::size_type maxlen = 0;
	Student_info s;
	while (read(cin, s)){
		maxlen = max(maxlen, s.name.size());
		students.push_back(s);
	}
	
	sort(students.begin(), students.end(), compare);
	
	for (int i = 0; i < students.size(); ++i){
		cout << students[i].name;
		cout << string(maxlen - students[i].name.size() +1,' ');
		
		try{
			double final_grade = grade(students[i]);
			
			streamsize prec = cout.precision();
			
			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		} catch (domain_error e){
			cout << e.what();
		}
	}
	
	//vector<Student_info> pass = students;
	//vector<Student_info> fail;
	list<Student_info> pass(students.begin(), students.end());
	list<Student_info> fail;
	fail = extract_fails(pass);
	
	cout << "pass list : " << endl;
	// for (vector<Student_info>::size_type i = 0; i != pass.size(); ++i)
	// 	cout << pass[i].name << endl;

	for (list<Student_info>::const_iterator iter = pass.begin(); iter != pass.end(); ++iter)
		cout << iter->name << endl;
	
	cout << "fail list : " << endl;
//	for (vector<Student_info>::size_type i = 0; i != fail.size(); ++i)
//		cout << fail[i].name << endl;
		
	for (list<Student_info>::const_iterator iter = fail.begin(); iter !=fail.end(); ++iter)
		cout << iter->name << endl;
	
	
	return 0;
}