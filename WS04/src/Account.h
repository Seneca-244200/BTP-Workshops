/***********************************************************************
// OOP244 Workshop 4 lab: Account Module
//
// File	Account.h
// Version 0.5
// Date	2025/06/03
// Partialy implemented by	Fardad Soleimanloo
// to be completed by the students
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   const int NameMaxLen = 30;
   class Account {
      double m_balance;
      int m_number;
      char m_holderName[NameMaxLen + 1];
 // already implemented
      void cpyName(const char* src);
      bool isValidNumber(int number)const;
   public:
      Account(const char* holderName = nullptr);
      Account(const char* holderName, int number, double balance);
      std::ostream& display()const;
 // to be implemented by the students
      void setEmpty();
      operator bool()const;
      operator int()const;
      operator double() const;
      operator const char* () const;


      char& operator[](int index);
      const char operator[](int index)const;


      Account& operator=(double Balance);
      Account& operator=(int number);
      Account& operator<<(Account&);
      Account& operator>>(Account&);
      Account& operator+=(double value);
      Account& operator-=(double value);

      Account& operator++();
      Account& operator--();
      Account operator++(int);
      Account operator--(int);

      bool operator~()const;
   };
  

}
#endif // SENECA_ACCOUNT_H_