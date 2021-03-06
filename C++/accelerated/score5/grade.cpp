#include "median.h"
#include "grade.h"
#include "student_info.h"
#include <vector>
#include <stdexcept>

using std::vector;
using std::domain_error;


double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final +  0.4 * homework;
}
/*
double grade(double midterm, double final, const vector<double>& homework)
{
	if (homework.size() == 0)
		throw domain_error("student has done no homework");
	
	return grade(midterm, final, median(homework));
}
*/
double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}

