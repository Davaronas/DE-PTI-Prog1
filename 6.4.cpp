#include <iostream>

class LZWBinFa
{
public:
    LZWBinFa (): fa(&gyoker) {}

    void operator<<(char b)
    {
        if (b == '0')
        {
            // van '0'-s gyermeke az aktuális csomópontnak?
            if (!fa->nullasGyermek ()) // ha nincs, csinálunk
            {
                Csomopont *uj = new Csomopont ('0');
                fa->ujNullasGyermek (uj);
                fa = &gyoker;
            }
            else // ha van, arra lépünk
            {
                fa = fa->nullasGyermek ();
            }
        }
        else
        {
            if (!fa->egyesGyermek ())
            {
                Csomopont *uj = new Csomopont ('1');
                fa->ujEgyesGyermek (uj);
                fa = &gyoker;
            }
            else
            {
                fa = fa->egyesGyermek ();
            }
        }
    }
    void kiir (void)
    {
        melyseg = 0;
        kiir (&gyoker);
    }
    void szabadit (void)
    {
        szabadit (gyoker.jobbEgy);
        szabadit (gyoker.balNulla);
    }

private:

    class Csomopont
    {
    public:
        Csomopont (char b = '/'):betu (b), balNulla (0), jobbEgy (0) {};
        ~Csomopont () {};
        Csomopont *nullasGyermek () {
            return balNulla;
        }
        Csomopont *egyesGyermek ()
        {
            return jobbEgy;
        }
        void ujNullasGyermek (Csomopont * gy)
        {
            balNulla = gy;
        }
        void ujEgyesGyermek (Csomopont * gy)
        {
            jobbEgy = gy;
        }
        
    private:
        friend class LZWBinFa;
        char betu;
        Csomopont *balNulla;
        Csomopont *jobbEgy;
        Csomopont (const Csomopont &);
        Csomopont & operator=(const Csomopont &);
    };

    Csomopont gyoker;
    Csomopont *fa;
    int melyseg;

    LZWBinFa (const LZWBinFa &);
    LZWBinFa & operator=(const LZWBinFa &);

    void kiir (Csomopont* elem)
    {
        if (elem != NULL)
        {
            ++melyseg;
            kiir (elem->jobbEgy);
            // ez a postorder bejáráshoz képest
            // 1-el nagyobb mélység, ezért -1
            for (int i = 0; i < melyseg; ++i)
                std::cout << "---";
            std::cout << elem->betu << "(" << melyseg - 1 << ")" << std::endl;
            kiir (elem->balNulla);
            --melyseg;
        }
    }
    void szabadit (Csomopont * elem)
    {
        if (elem != NULL)
        {
            szabadit (elem->jobbEgy);
            szabadit (elem->balNulla);
            delete elem;
        }
    }

};

int
main ()
{
    char b;
    LZWBinFa binFa;

    while (std::cin >> b)
    {
        binFa << b;
    }

    binFa.kiir ();
    binFa.szabadit ();

    return 0;
}

