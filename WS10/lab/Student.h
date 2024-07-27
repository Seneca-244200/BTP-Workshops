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

#include <iostream>
#ifndef SENECA_STUDENT_H_
#define SENECA_STUDENT_H_
#include "ReadWrite.h"
namespace seneca {
   class Student : public ReadWrite {
      int m_stno;
      char m_name[41];
      double m_gpa;
   public:
      Student();
      Student(int stno, const char* name, double gpa);
      void set(int stno, const char* name, double gpa);
      std::ostream& display(std::ostream& os)const;
      std::istream& read(std::istream& is);
      bool operator==(double gpa)const;
   };
}
#endif // !SENECA_STUDENT_H_

