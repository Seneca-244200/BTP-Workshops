/***********************************************************************
// OOP244 Workshop 4 lab: Account Module
//
// File	Account.cpp
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

#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
   // already implemeted functions

   void Account::cpyName(const char* src) {
      int i;
      for (i = 0; src[i] && i < 30; i++) {
         m_holderName[i] = src[i];
      }
      m_holderName[i] = char(0);
   }
   bool Account::isValidNumber(int number) const {
      return number >= 10000 && number <= 99999;
   }
   Account::Account(const char* holderName) {  
      setEmpty();
      if (holderName && holderName[0]) {
         cpyName(holderName);
         m_number = 0;
         m_balance = 0.0;
      }
   }
   Account::Account(const char* holderName, int number, double balance ) {
      setEmpty();
      if (holderName && holderName[0] && isValidNumber(number)
         && balance > 0) {
         cpyName(holderName);
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout.fill(' ');
         cout.width(NameMaxLen);
         cout.setf(ios::left);
         cout << m_holderName;
         cout.unsetf(ios::left);
         cout << " | ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << " ";
         cout.fill(' ');
         cout.width(30);
         cout.setf(ios::left);
         cout << m_holderName;
         cout.unsetf(ios::left);
         cout << " |  NEW  |         0.00 ";
      }
      else {
         cout << " Bad Account                    | ----- | ------------ ";
      }
      return cout;
   }

   // To be implemented by students
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
      m_holderName[0] = char(0);
   }

   Account::operator bool()const {
      return isValidNumber(m_number) ;
   }
   Account::operator int()const {
      return m_number;
   }
   Account::operator double() const {
      return m_balance;
   }
   Account::operator const char* () const {
      return m_holderName;
   }
   char& Account::operator[](int index) {
      return m_holderName[index % NameMaxLen];
   }
   const char Account::operator[](int index) const {
      return m_holderName[index % NameMaxLen];
   }
   Account& Account::operator=(double balance) {
      if (balance >= 0.0) {
         m_balance = balance;
      }
      else {
         setEmpty();
      }
      return *this;
   }
   Account& Account::operator=(int number) {
      if (isValidNumber(number)) {
         if(~*this) m_number = number;
      }
      else {
         setEmpty();
      }
      return *this;
   }
   Account& Account::operator<<(Account& RO) {
      if (this != &RO && *this && RO) {
         m_balance += RO.m_balance;
         RO.m_balance = 0.0;
      }
      return *this;
   }
   Account& Account::operator>>(Account& RO) {
      if (this != &RO && *this && RO) {
         RO.m_balance += m_balance;
         m_balance = 0.0;
      }
      return *this;
   }


   Account& Account::operator+=(double value) {
      if (*this && value > 0) {
         m_balance += value;
      }
      return *this;
   }

   Account& Account::operator-=(double value) {
      if (*this && value > 0 && value <= m_balance) {
         m_balance -= value;
      }
      return *this;
   }

   Account& Account::operator++() {
      m_balance += 1;
      return *this;
   }
   Account& Account::operator--() {
      m_balance -= 1;
      return *this;
   }
   Account Account::operator++(int) {
      Account old = *this;
      m_balance += 1;
      return old;
   }
   Account Account::operator--(int) {
      Account old = *this;
      m_balance -= 1;
      return old;
   }


   bool Account::operator~() const {
      return m_number == 0;
   }

}