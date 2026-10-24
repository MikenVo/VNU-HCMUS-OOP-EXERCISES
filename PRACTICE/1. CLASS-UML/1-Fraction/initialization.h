class Fraction {
    int numerator;
    int denominator;

    public:
        void inputfrac();
        void outputfrac();
        Fraction add(Fraction other);
        Fraction minus(Fraction other);
        Fraction multiply(Fraction other);
        void divide(Fraction other);
};