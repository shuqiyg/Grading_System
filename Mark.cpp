/* W05 DIY
   Name: Shuqi Yang
   Std ID: 132162207
   Email: syang136@myseneca.ca
   Date: 02-18-2021
   -------------------------------------------------------
   I have done all the coding by myself and only copied the
   code that my professor provided to complete my workshops
   and assignments.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

namespace sdds {
	void Mark::validate(int value) {
		if (value > 100 || value < 0) {
			setInvalid();
		}
		else {
			this->mark = value;
			this->grade = toGrade(mark);
			this->scale_4_mark = toScale_4(grade);
		}
	}
	void Mark::setEmpty() {
		 mark = 0;
		 grade = ' ';
		 scale_4_mark = 0.0f;
	}
	void Mark::setInvalid() {
		mark = 0;
		grade = 'X';
		scale_4_mark = 0.0f;	
	}
	char Mark::toGrade(int mark) {
		if (mark >= 80 && mark <= 100) {
			return 'A';
		}
		else if (mark < 80 && mark >= 70) {
			return 'B';
		}
		else if (mark < 70 && mark >= 60) {
			return 'C';
		}
		else if (mark < 60 && mark >= 50) {
			return 'D';
			}
		return 'F';
	}
	double Mark::toScale_4(char grade) {
		switch (grade) {
		case 'A':
			return 4;
		case 'B':
			return 3;
		case 'C':
			return 2;
		case 'D':
			return 1;
		default:
			return 0;
		}
	}
	Mark::Mark() {
		setEmpty();
	}
	Mark::Mark(int value) {
		validate(value);
	
	}
	Mark::operator int()const {
		return mark;
	}
	Mark& Mark::operator+=(int value) {
		if (this->grade != 'X') {
			validate(this->mark + value);
		}
		return *this;
	}
	Mark& Mark::operator=(int value) {
		validate(value);
		return *this;	
	}
	Mark::operator double()const {
		return scale_4_mark;
	}
	Mark::operator char()const {
		return grade;
	}	
	int operator+=(int& a, Mark m) {
		if (char(m) != 'X') {
			return a += int(m);
		}
		else
			return a;
	}
}