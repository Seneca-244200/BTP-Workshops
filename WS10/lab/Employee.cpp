/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 10
// Version 1.0
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Employee.h"
namespace seneca {
   Employee::Employee() {
      set(0, "", 0.0, 0);
   }
   Employee::Employee(int stno, const char* name, double salary, int office) {
      set(stno, name, salary, office);
   }
   void Employee::set(int stno, const char* name, double salary, int office) {
      m_empno = stno;
      strcpy(m_name, name);
      m_salary = salary;
      m_office = office;
   }
   ostream& Employee::display(ostream& os)const {
      return os << m_empno << " " << m_name << " (Office# " << m_office << ") Salary: $" << setprecision(2) << fixed << m_salary;
   }
   istream& Employee::read(istream& is) {
      is >> m_empno;
      is.getline(m_name, 40, ',');
      is >> m_salary;
      return is;
   }
   bool Employee::operator==(int office)const {
      return m_office == office;
   }
}
