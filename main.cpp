#include <iostream>	
#include <vector>

struct Course {
	float grade;
	int creditHours;
};

float calculateCGPA(const std::vector<Course>& courses) {
	float totalGradePoints = 0;
	int totalCreditHours = 0;

	for (const auto& course : courses) {
		totalGradePoints += course.grade * course.creditHours;
		totalCreditHours += course.creditHours;
	}

	return totalGradePoints / totalCreditHours;
}

int main() {
	int numberOfCourses;
	std::cout << "Enter the number of courses: ";
	std::cin >> numberOfCourses;

	std::vector<Course> courses(numberOfCourses);

	for (int i = 0; i < numberOfCourses; ++i) {
		std::cout << "Enter grade and credit hours for course " << i + 1 << " in integer format ('Grade in #' 'space bar' 'Credit Hours in #' : ";
		std::cin >> courses[i].grade >> courses[i].creditHours;
	}

	float cgpa = calculateCGPA(courses);
	std::cout << "Your CGPA is: " << cgpa << std::endl;

	return 0;
}