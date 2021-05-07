/* W05 DIY
   Name: Shuqi Yang
   Std ID: 132162207
   Email: syang136@myseneca.ca
   Date: 02-15-2021
   -------------------------------------------------------
   I have done all the coding by myself and only copied the
   code that my professor provided to complete my workshops
   and assignments.
 */
#ifndef MARK_H_
#define MARK_H_
namespace sdds {
	class Mark {
		int mark;
		char grade;
		double scale_4_mark;
		void setEmpty();
		void validate(int);
		void setInvalid();

	public:
		Mark();
		Mark(int);
		char toGrade(int);
		double toScale_4(char grade);
		operator int()const;
		Mark& operator+=(int);
		Mark& operator=(int);
		operator double()const;
		operator char()const;
		
	};
	int operator+=(int& a, Mark m);
}

#endif // !MARK_H_

