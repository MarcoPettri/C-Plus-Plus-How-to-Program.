// DollarAmount class Two stores dollar amounts as a whole number of pennies

#include<string>
#include<cmath>

class DollarAmount {

public:

	//Initialize amount from an int64_t value
	DollarAmount(int64_t whole, int16_t cents)
		: dollars{ whole }, cents{ cents },
		amount{ whole * 100 + cents } {}

	// add right's amount to this object's amount
	void add(DollarAmount right) {
		// can access private data of other objects of the same class
		amount += right.amount;
	}
	// subtract right's amount to this object's amount
	void substract(DollarAmount right) {
		// can access private data of other objects of the same class
		amount -= right.amount;
	}

	void divide(int divisor) {

		int64_t result{ amount / divisor };

		if (result % 100 >= 50) {
			amount = result + (100 - (result % 100));
		}
		else {
			amount = result - (result % 100);
		}
	}

	// uses integer arithmetic to calculate interest amount;
	// then calls add with the interest amount
	void addInterest(int rate, int divisor) {

		// Calculate the interest 
		int64_t total{ (amount * rate + divisor / 2) / divisor };

		if ((total % 100) / 10 == 5) {

			int64_t whole{ total / 100 };
			int64_t cents{ total % 100 };

			if (whole % 2 == 0) {
				total -= cents;
			}
			else {
				total += 100 - cents;
			}
		}

		//create a object dollarAmount interest with the whole number and the cents
		DollarAmount interest{ total / 100, total % 100 };

		add(interest); // add interest to this object's amount
	}

	// return a string representation of a DollarAmount object
	std::string toString() const {

		std::string dollars{ std::to_string(amount / 100) };
		std::string cents{ std::to_string(std::abs(amount % 100)) };
		return dollars + "." + (cents.size() == 1 ? "0" : "") + cents;
	}

private:
	int64_t dollars{ 0 };
	int64_t cents{ 0 };
	int64_t amount{ 0 };

};

