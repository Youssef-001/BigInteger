#include <iostream>
#include <string>
using namespace std;


class LongInt
{
	int result[500] = { 0 };
	string number;
	string Add(string n1, string n2)
	{
		string result;
		int sizeA = n1.size();;
		int sizeB = n2.size();
		int firstStr = sizeA - 1; // Index of last element in first string
		int secondStr = sizeB - 1; // Index of last element in second string


		int reminder = 0;
		while (firstStr >= 0 && secondStr >= 0)
		{
			int first = n1[firstStr] - '0'; // Convert char to integer
			int second = n2[secondStr] - '0';
			int total = first + second + reminder;
			int abs = total % 10;
			reminder = total / 10;
			result.insert(0, 1, (char)abs + '0');
			firstStr--;
			secondStr--;
		}

		if (firstStr != secondStr)
		{
			if (!reminder)
			{
				//Easy
				if (firstStr < 0)
				{
					result.insert(0, n2.substr(0, secondStr + 1));
				}
				else
				{
					result.insert(0, n1.substr(0, firstStr + 1));
				}
			}
			else
			{
				//Harder
				string remainingStr;
				if (firstStr < 0)
				{
					remainingStr = n2.substr(0, secondStr + 1);
				}
				else
				{
					remainingStr = n1.substr(0, firstStr + 1);
				}


				string second;
				second.insert(0, 1, (char)reminder + '0');


				string r = this->Add(remainingStr.c_str(), second);
				result.insert(0, r);
			}
		}
		else if (reminder != 0)
		{
			result.insert(0, 1, (char)reminder + '0');
		}


		return result;
	}
	string Subtraction(string number1, string number2)
	{
		int len1 = number1.size() - 1;
		int len2 = number2.size() - 1;

		string strResult = "";
		string revResult = "";
		string borrow = "";
		int temp = len1;
		int DigitIndex = len1 + 1;
		while (len1 >= 0 && len2 >= 0)
		{

			DigitIndex--;
			int result = 0;
			int first = number1[len1] - '0';
			int second = number2[len2] - '0';



			if (first >= second)
			{
				// Easy
				result = first - second;
				strResult.insert(0, 1, (char)result + '0');
				//revResult += (char)result + '0';
				temp--;
			}

			else if (first < second)
			{
				// Hard

				// First with no zeros


				do {
					borrow.insert(0, 1, (char)number1[temp - 1]);
				} while (number1[--temp] - '0' == 0);

				// Subtract 1 from borrow.
				string borrowNumm = Subtraction(borrow, "1");

				string st = borrowNumm;
				if ((borrow.length() - st.length()) > 0) // If length changed change len1 to fit.
					len1 -= ((borrow.length() - st.length()));

				string BorrowString = borrowNumm;

				// Get number after the carry, 3 >= 13
				string BiggerDigit = "1";
				BiggerDigit += number1[DigitIndex];

				int AfterCarry = stoi(BiggerDigit);

				number1.replace(temp, temp + borrow.length() + 1, BorrowString);

				int result = AfterCarry - (number2[len2] - '0');
				strResult.insert(0, 1, (char)result + '0');


			}


			len1--;
			len2--;
			borrow = "";
			temp = len1;
		}

		// Remove zeros on the left 
		int counterZero = 0;
		while (strResult[counterZero] == '0' && strResult.length() != 1)
			strResult.erase(counterZero, 1);

		// If string bigger than the other

		if (len1 != 0 || len2 != 0)
		{
			int bigger = len1 > len2 ? len1 : len2;
			int smaller = len1 < len2 ? len1 : len2;

			string RemainingPart = number1.substr(0, len1 + 1);
			strResult.insert(0, RemainingPart);
		}
		// Remove first zero if exists
		if (strResult.length() != 1 && strResult[0] == '0')
			strResult.erase(0, 1);

		return strResult;


	}
	string Multiplication(string number1, string number2)
	{

		reverse(number1.begin(), number1.end());
		reverse(number2.begin(), number2.end());

		for (int i = 0; i < number1.size(); i++)
		{
			for (int j = 0; j < number2.size(); j++)
			{

				int num1 = number1[i] - '0';
				int num2 = number2[j] - '0';

				int r = num1 * num2;
				result[i + j] += r;


			}
		}
		string resultt = "";

		for (int k = 0; k < 499; k++)
		{
			result[k + 1] = result[k + 1] + (result[k] / 10);
			result[k] = result[k] % 10;

		}
		int index = 0;
		for (int k = 499; k >= 0; k--)
			if (result[k] != 0)
			{
				index = k;
				break;
			}
		for (int k = index; k >= 0; k--)
		{
			resultt += result[k] + '0';
		}
		return resultt;
	}
public:
	LongInt()
	{
		number = "0";
	}


	LongInt(const char* n)
	{
		number = n;
	}


	const string GetNumber()
	{
		return number;
	}


	LongInt operator+(LongInt& n)
	{
		LongInt res;
		string r = Add(this->number, n.number);
		res.number = r;
		return res;
	}


	LongInt operator+(const char* n)
	{
		LongInt res;
		string r = Add(this->number, n);
		res.number = r;
		return res;
	}


	LongInt operator++(int)
	{
		string r = Add(this->number, "1");
		number = r;
		return *this;
	}


	LongInt operator++()
	{
		string r = Add(this->number, "1");
		number = r;
		return *this;
	}


	LongInt operator += (LongInt& n)
	{
		string r = Add(this->number, n.number);
		number = r;
		return *this;
	}


	LongInt operator += (const char* n)
	{
		string r = Add(this->number, n);
		number = r;
		return *this;
	}



	// Operator Overloading for subtraction

	LongInt operator -(LongInt& n)
	{
		LongInt result;
		string r = Subtraction(this->number, n.number);
		result.number = r;
		return result;
	}

	// Operator Overloading for multiplication

	LongInt operator * (LongInt& n)
	{
		LongInt result;
		string r = Multiplication(this->number, n.number);
		result.number = r;
		return result;
	}


	friend ostream& operator<<(ostream& out, LongInt& n)
	{
		out << n.number;
		return out;
	}


};


void main()
{
	LongInt n1 = "2";
	LongInt n2 = "5";
	LongInt result = n1*n2;

	cout << result;

	
}
