#include <iostream>

class PhanSo {
    int* tuso;
    int* mauso;

    public:
        // Setter
        void GanTuSo(int tuso);
        void GanMauSo(int mauso);
        
        // Getter
        int LayTuSo() const;
        int LayMauSo() const;

        // ----------------------------------------------------

        // Constructor
        // Default
        PhanSo() {
            tuso = new int;
            mauso = new int;

            *tuso = 0;
            *mauso = 1;
        }

        // 1 parameter
        PhanSo(int sotu) {
            tuso = new int;
            mauso = new int;

            *tuso = sotu;
            *mauso = 1;
        }

        // 2 parameters
        PhanSo(int sotu, int somau) {
            tuso = new int;
            mauso = new int;

            *tuso = sotu;
            *mauso = somau;
        }

        // Copy
        PhanSo(const PhanSo& ps) {
            tuso = new int;
            mauso = new int;

            *tuso = *ps.tuso;
            *mauso = *ps.mauso;
        }

        // Delete
        ~PhanSo() {
            delete tuso;
            delete mauso;
        }

        // ----------------------------------------------------

        // Operations
        // Plus
        PhanSo plus(const PhanSo& f2);

        // Minus
        PhanSo minus(const PhanSo& f2);

        // Multiply
        PhanSo multiply(const PhanSo& f2);

        // Divide
        PhanSo divide(const PhanSo& f2);

        // ----------------------------------------------------

        // Auxiliary Functions

        void Input();

        // Fraction Output
        void Output(const PhanSo& answer) const;

        // Number Output
        double NumOutput(const PhanSo& answer) const;

        // Greatest Common Divisor
        static int GCD(int a, int b);
};