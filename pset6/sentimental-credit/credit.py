import re


def main():
    # User's input will be only numbers (instructions)
    credit_number = input("Credit card number: ")
    # Checking initial digit and length
    if not re.match(r"^4\d{12}$|^4\d{15}$|^3[47]\d{13}$|^5[1-5]\d{14}$", credit_number):
        print("INVALID")
        return

    if luhn_algorithm(credit_number) % 10 != 0:
        print("INVALID")
        return

    # Check which card type
    if int(credit_number[:1]) == 4:
        print("VISA")
    elif int(credit_number[:2]) in [34, 37]:
        print("AMEX")
    elif int(credit_number[:2]) in [51, 52, 53, 54, 55]:
        print("MASTERCARD")


def luhn_algorithm(number):
    sum_double_digits = 0
    sum_undoubled_digits = 0
    double_digit = False

    # Iterate through all digits
    for i in range(len(number) - 1, -1, -1):
        # Transform the numbers in integers
        digit = int(number[i])
        if double_digit:
            double_number = digit * 2
            sum_double_digits += (double_number // 10) + (double_number % 10)
        else:  # double_digit = False
            sum_undoubled_digits += digit
        double_digit = not double_digit

    # Total sum for Luhn Algorithm
    total_sum = sum_double_digits + sum_undoubled_digits
    return total_sum


if __name__ == "__main__":
    main()
