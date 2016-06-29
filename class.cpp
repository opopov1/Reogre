// Oleksandr Popov
///////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
using namespace std;
#include "class.h"

namespace sict{
  void AccountNumber::name(const char name[]){
    strncpy(_name, name, MAX_NAME_LENGTH);
    _name[MAX_NAME_LENGTH] = 0;
  }
  void AccountNumber::accountNumber(int bankCode, int branchCode, int accountNumber){
    _bankCode = bankCode;
    _branchCode = branchCode;
    _accountNumber = accountNumber;
    _validAccNumber = bankCode >= MIN_BANKCODE && bankCode <= MAX_BANKCODE &&
      branchCode >= MIN_BRANCHCODE && branchCode <= MAX_BRANCHCODE &&
      accountNumber >= MIN_ACCNO && accountNumber <= MAX_ACCNO;
  }
  void AccountNumber::displayName()const{
    cout << "Name: " << _name;
  }
  void AccountNumber::displayNumber()const{
    cout << "Account number: " << _bankCode << "-"
      << _branchCode << "-" << _accountNumber;
  }

  void AccountNumber::display(bool displayName, bool displayNumber) const{
    if (isValid()){
      if (displayName) this->displayName();
      if (displayNumber){
        displayName && cout << ", ";
        this->displayNumber();
      }
      (displayName || displayNumber) && cout << endl;
    }
    else{
      cout << _name << " does not have a valid account number." << endl;
    }
  }
  bool AccountNumber::isValid() const{
    return _validAccNumber;
  }
}
