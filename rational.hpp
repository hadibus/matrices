#ifndef RATIONAL_HPP
#define RATIONAL_HPP

class Rational{
	private:
	unsigned numerator;
	unsigned denominator;
	bool positive;
	public:
	Rational();
	Rational(int);
	display(bool);
};


#endif
