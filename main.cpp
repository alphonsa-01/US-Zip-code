#include<fstream>
#include<iomanip>
#include<iostream>
#include<string>

/*!
Represents the decimal number needed as a divisor to get the digits seperated, which equals to 10.
*/
const int k_decimal_radix = 10;
/*!
Represents the number needed to do the mod operation to check whether the digits are multiples of 10.
*/
const int k_mod_divisor = 10;
/*!
Represents the decimal value of the coloumn width on the final output. Equals to 9 here
*/
const int k_set_width_decimal = 9;

/*!
Represents one of the digits of the zip code,equals to 1.
*/
const int k_bar_code_digit_one = 1;
/*!
Represents one of the digits of the zip code,equals to 2.
*/
const int k_bar_code_digit_two = 2;
/*!
Represents one of the digits of the zip code,equals to 3.
*/
const int k_bar_code_digit_three = 3;
/*!
Represents one of the digits of the zip code,equals to 4.
*/
const int k_bar_code_digit_four = 4;
/*!
Represents one of the digits of the zip code,equals to 5.
*/
const int k_bar_code_digit_five = 5;
/*!
Represents one of the digits of the zip code,equals to 6.
*/
const int k_bar_code_digit_six = 6;
/*!
Represents one of the digits of the zip code,equals to 7.
*/
const int k_bar_code_digit_seven = 7;
/*!
Represents one of the digits of the zip code,equals to 8.
*/
const int k_bar_code_digit_eight = 8;
/*!
Represents one of the digits of the zip code,equals to 9.
*/
const int k_bar_code_digit_nine = 9;

/*!
\brief Returns the check digit of the 5 digit zip code.

Calculates the checck digit from the given zip code. Check digit is a value which would make the sum of the 5 digits in zip code equals to multiple of 10.

\param zip 5 digit zip code from the user

\return returns the check digit of the given zip code.
*/
int check_digit(int zip);

/*!
\brief returns the encoded digit of the given digit

calculates the bar code representation of the given digit.

\param digit each digit we pass from the zip code

\return returns the encoded digit of the given digit
*/

std::string encode_digit(int digit);

/*!
\brief Converts the given zip code to its bar code representation.

Calculates the encoded digits for all the five digits of the zip code we pass, also the bar code representation of check digit and enclose the entire bar
code representation in between two pipes.

\param zip_code Given 5 digit zip_code

\return returns the complete bar code representation of the given zip code.
*/
std::string encode_zip_code(int zip_code);

/*!
\brief Returns the string entered from the given prompt.

Based on the prompt we pass, extract the string entered by the user.

\param prompt prompts the user for the input

\return returns the complete string entered by the user.
*/
std::string get_string(std::string prompt);

/*!
\brief Gets the integer value enterd by the user based on the given prompt

Based on the prompt we pass,extract the integer value entered by the user.

\param prompt prompts the user for input

\return returns the integer entered by the user.
*/
int get_int(std::string prompt);

int main()
{
	auto full_name = get_string("Enter your name: ");
	auto street_name = get_string("Enter your street with number: ");
	auto city = get_string("Enter your city: ");
	auto state = get_string("Enter your state: ");
	auto zip = get_int("Enter 5 digit zip code: ");
	auto zip_extension = get_int("Enter 4 digit zip extension: ");
	
	auto encode = encode_digit(zip);
	auto encoded_digits = encode_zip_code(zip);
	
	std::ofstream fout;
	fout.open("Label.txt");

	fout << full_name << std::endl;
	fout << street_name << std::endl;
	fout << city <<std::setw(k_set_width_decimal)<<std::right<<state << " "<<zip<<"-"<<zip_extension<<std::endl;
	fout << encoded_digits << std::endl;

	fout.close();

	std::cout << "your label is located in Label.txt" << std::endl;
	
	
	return 0;
}

/*!
\brief Returns the check digit of the 5 digit zip code.

Calculates the checck digit from the given zip code. Check digit is a value which would make the sum of the 5 digits in zip code equals to multiple of 10.

\param zip 5 digit zip code from the user

\return returns the check digit of the given zip code.
*/
int check_digit(int zip)
{
	auto check_digit = 0;
	auto temp_zip = 0;
	temp_zip = zip;

	auto digit_five = temp_zip % k_mod_divisor;
	temp_zip = temp_zip / k_decimal_radix;
	auto digit_four = temp_zip % k_mod_divisor;
	temp_zip = temp_zip / k_decimal_radix;;
	auto digit_three = temp_zip % k_mod_divisor;
	temp_zip = temp_zip / k_decimal_radix;
	auto digit_two = temp_zip % k_mod_divisor;
	temp_zip = temp_zip / k_decimal_radix;
	auto digit_one = temp_zip % k_mod_divisor;

	auto sum_of_digits = digit_one + digit_two + digit_three + digit_four + digit_five;

	auto sum_checker = sum_of_digits % k_mod_divisor;

	auto is_sum_multiple_of_ten = sum_checker == 0;

	if (is_sum_multiple_of_ten)
	{
		check_digit = sum_checker;
	}
	else
	{
		check_digit = k_mod_divisor - sum_checker;
	}

	return check_digit;
}

/*!
\brief returns the encoded digit of the given digit

calculates the bar code representation of the given digit.

\param digit each digit we pass from the zip code

\return returns the encoded digit of the given digit
*/
std::string encode_digit(int digit)
{
	std::string encode_value;
	if (digit == k_bar_code_digit_one)
	{
		encode_value = ":::||";
	}
	else if (digit == k_bar_code_digit_two)
	{
		encode_value = "::|:|";
	}
	else if (digit == k_bar_code_digit_three)
	{
		encode_value = "::||:";
	}
	else if (digit == k_bar_code_digit_four)
	{
		encode_value = ":|::|";
	}
	else if (digit == k_bar_code_digit_five)
	{
		encode_value = ":|:|:";
	}
	else if (digit == k_bar_code_digit_six)
	{
		encode_value = ":||::";
	}
	else if (digit == k_bar_code_digit_seven)
	{
		encode_value = "|:::|";
	}
	else if (digit == k_bar_code_digit_eight)
	{
		encode_value = "|::|:";
	}
	else if (digit == k_bar_code_digit_nine)
	{
		encode_value = "|:|::";
	}
	else
	{
		encode_value = "||:::";
	}

	return encode_value;
}

/*!
\brief Converts the given zip code to its bar code representation.

Calculates the encoded digits for all the five digits of the zip code we pass, also the bar code representation of check digit and enclose the entire bar
code representation in between two pipes.

\param zip_code Given 5 digit zip_code

\return returns the complete bar code representation of the given zip code.
*/
std::string encode_zip_code(int zip_code)
{
	auto temp_zip = 0;
	temp_zip = zip_code;

	auto digit_five = temp_zip % k_mod_divisor;
	temp_zip = temp_zip / k_decimal_radix;
	auto digit_four = temp_zip % k_mod_divisor;
	temp_zip = temp_zip / k_decimal_radix;;
	auto digit_three = temp_zip % k_mod_divisor;
	temp_zip = temp_zip / k_decimal_radix;
	auto digit_two = temp_zip % k_mod_divisor;
	temp_zip = temp_zip / k_decimal_radix;
	auto digit_one = temp_zip % k_mod_divisor;

	auto check_digit_zip_code = check_digit(zip_code);

	auto encoded_zip_code_digit_one = encode_digit(digit_one);
	auto encoded_zip_code_digit_two = encode_digit(digit_two);
	auto encoded_zip_code_digit_three = encode_digit(digit_three);
	auto encoded_zip_code_digit_four = encode_digit(digit_four);
	auto encoded_zip_code_digit_five = encode_digit(digit_five);
	auto encoded_zip_code_check_digit = encode_digit(check_digit_zip_code);

	auto complete_encoded_zip_code = "|" + encoded_zip_code_digit_one + encoded_zip_code_digit_two + encoded_zip_code_digit_three +
		encoded_zip_code_digit_four + encoded_zip_code_digit_five + encoded_zip_code_check_digit + "|";

	return complete_encoded_zip_code;
}

/*!
\brief Returns the string entered from the given prompt.

Based on the prompt we pass, extract the string entered by the user.

\param prompt prompts the user for the input

\return returns the complete string entered by the user.
*/
std::string get_string(std::string prompt)
{
	std::cout << prompt;
	std::string value;
	std::getline(std::cin, value);

	return value;
}

/*!
\brief Gets the integer value enterd by the user based on the given prompt

Based on the prompt we pass,extract the integer value entered by the user.

\param prompt prompts the user for input

\return returns the integer entered by the user.
*/
int get_int(std::string prompt)
{
	std::cout << prompt;
	auto value = 0;
	std::cin >> value;

	return value;
}