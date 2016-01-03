#include<bits/stdc++.h>
 
using namespace std;
 
 
double getMult(double num) {
  if (num <= 400.0) return 0.15;
  else if(num <= 800.0) return 0.12;
  else if(num <= 1200.0) return 0.10;
  else if(num <= 2000.0) return 0.07;
  else return 0.04;
}
 
int getIntMult(double num) {
  if (num <= 400.0) return 15;
  else if(num <= 800.0) return 12;
  else if(num <= 1200.0) return 10;
  else if(num <= 2000.0) return 7;
  else return 4;
}
 
double salary;
 
int main() {
  cin>>salary;
  double mult = getMult(salary);
  double new_salary = (1.0+1.0*mult)*salary;
  printf("Novo salario: %.2f\n", new_salary);
  printf("Reajuste ganho: %.2f\n", new_salary - salary);
  printf("Em percentual: %d %%\n", getIntMult(salary));  
}
