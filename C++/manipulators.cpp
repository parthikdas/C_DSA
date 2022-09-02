#include <iomanip>
#include <iostream>
using namespace std;
  
  //cout<<setprecision(2)<<3.71234;//3.7
  //to start after decimal do cout<<fixed<<setprecision(2)<<3.71234;//3.71

int main()
{
// Manipulators in C++
	/*
	Some important manipulators in <iomanip> are:
		setw (val): It is used to set the field width in output operations.
		setfill (c): It is used to fill the character ‘c’ on output stream.
		setprecision (val): It sets val as the new value for the precision of floating-point values.
		setbase(val): It is used to set the numeric base value for numeric values.
	Some important manipulators in <ios> are:
		showpos: It forces to show a positive sign on positive numbers.
		noshowpos: It forces not to write a positive sign on positive numbers.
		showbase: It indicates the numeric base of numeric values.
		uppercase: It forces uppercase letters for numeric values.
		nouppercase: It forces lowercase letters for numeric values.
		fixed: It uses decimal notation for floating-point values.
		scientific: It uses scientific floating-point notation.
		hex: Read and write hexadecimal values for integers and it works same as the setbase(16).
		dec: Read and write decimal values for integers i.e. setbase(10).
		oct: Read and write octal values for integers i.e. setbase(10).
		left: It adjusts output to the left.
		right: It adjusts output to the right.
	*/
    int a =3, b=78, c=1233;
    cout<<"The value of a without setw is: "<<a<<endl;
    cout<<"The value of b without setw is: "<<b<<endl;
    cout<<"The value of c without setw is: "<<c<<endl;

    cout<<"The value of a is: "<<setw(4)<<a<<endl;
    cout<<"The value of b is: "<<setw(4)<<b<<endl;
    cout<<"The value of c is: "<<setw(4)<<c<<endl;

    cout<<oct<<100;// to get octal of 100
    cout<<hex<<100;// to get hexadecimal of 100
    cout<<hex<<showbase<<100;// output: 0x64 // cout << hex << left << showbase << nouppercase;
    cout<< hex <<showbase<<uppercase<<100;// output: 0X64

// -------------------------------------------------------------------------
    double B = 2001.5251;
    cout << setbase(10) << left << setw(15)
     << setfill('-') << showpos
     << fixed << setprecision(2);
    // actual printed part
    cout << B << endl;// +2001.53-------
    cout << setbase(10) << left << setw(15)
     << setfill('-') << showpos
     << fixed << setprecision(2);
    // actual printed part
    cout << B << endl;// -------+2001.53

// -------------------------------------------------------------------------
	double C = 201455.2646;
     cout << scientific << uppercase
         << noshowpos << setprecision(9);
  
    // actual printed part
    cout << C << endl;// 2.014552646E+05

// -------------------------------------------------------------------------
    string name[7] = {"Parthik", "Ansh", "Devanshu", "Zaid", "Useless"};
    for(int i=0;i<5;i++) cout<<setw(9)<<left<<name[i]<<name[i]<<endl;
 	// Parthik  Parthik
	// Ansh     Ansh
	// Devanshu Devanshu
	// Zaid     Zaid
	// Useless  Useless
      // in c it its like #include <stdio.h>
        // int main() {
        //     int a = 5;
        //     printf("%4d\n",a);
        //     a+=5;
        //     printf("%4d\n",a);
        //     a+=100;
        //     printf("%4d",a);
        //     return 0;
}

return 0;
}