

#ifndef PHANSO_H
#define PHANSO_H

class Phanso{
    private:
        int a , b;  // Phân số có dạng a/b
    public:
        Phanso(int x = 0);  // default fraction equal zero
        Phanso(const Phanso &); // create Fraction from different Fraction
        void createFraction(int  , int ); // create Fraction with numerator and denominator
        void createFractionInt(int n); // create Fraction with integer
        ~Phanso();      // Hàm giải phóng vùng nhớ
        void output(); // Hàm xuất phân số 
        int getNumerator(const Phanso &); // lấy tử số
        int getDenominator(const Phanso &); // lấy tử số
        void inverse(const Phanso &); // inverse fraction
        int UCLN(const Phanso &);
        void compact(const Phanso &); // rút gọn phân số
        void plusFraction(const Phanso & , const Phanso &); // Phép cộng 2 phân số
        void subtractFraction(const Phanso & , const Phanso &); // Phép trừ 2 phân số
        void multipleFraction(const Phanso & , const Phanso &); // Phép nhân 2 phân số
        void divideFraction(const Phanso & , const Phanso &); // Phép chia 2 phân số 
        int compare(const Phanso & , const Phanso &); // so sánh hai phân số 
};

#endif
