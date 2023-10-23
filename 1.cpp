#include <iostream>  
#include <cmath>  
  
using namespace std;  
  
int main() {  
    setlocale(LC_ALL, "Russian");  
    double loan_amount = 0;  
    int loan_term = 0;  
    double interest_rate = 0;  
    string loan_type;  
   
  
    cout << "Введите общую сумму кредита: ";  
    cin >> loan_amount;  
  
    cout << "Введите срок кредита в месяцах: ";  
    cin >> loan_term;  
  
    cout << "Введите процентную ставку (годовую): ";  
    cin >> interest_rate;  
  
    cout << "Введите тип кредита (1-дифференцированный или 2-аннуитетный): ";  
    cin >> loan_type;  
  
    double monthly_payment = 0, total_payment = 0, overpayment = 0;  
    double* payments;  
    payments = (double*)malloc(loan_term * sizeof(double));  
    if (loan_type == "1") {  
        double ostatok = loan_amount;  
        long double monthly_rate = interest_rate / (12 * 100);  
        for (int i = 1; i <= loan_term; i++) {  
              
            double residue = loan_amount - (loan_amount / loan_term) * (i - 1);  
            payments[i - 1] = loan_amount / loan_term + residue * monthly_rate;  
        }  
          
        for (int i = 0; i < loan_term; i++) {  
            cout << payments[i] << endl;  
            overpayment += payments[i]; 
        }  
        total_payment = overpayment + loan_amount; 
        monthly_payment = overpayment / loan_term; 
  
    }  
    else if (loan_type == "2") {  
       
  
        double monthly_interest_rate = interest_rate / 12 / 100;  
        monthly_payment = loan_amount * (monthly_interest_rate / (1 - pow(1 + monthly_interest_rate, -loan_term)));  
        total_payment = monthly_payment * loan_term;  
        overpayment = total_payment - loan_amount;  
    }  
    else {  
        cout << "Неверный тип кредита." << endl;  
        return 1;  
    }  
  
    cout << "Ежемесячный платеж: " << monthly_payment << endl;  
    cout << "Переплата по кредиту: " << overpayment << endl;  
    cout << "Общая выплата: " << total_payment << endl;  
  
  
  
    return 0;  
}
