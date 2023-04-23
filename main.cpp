#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <MMSystem.h>

using namespace std;
class interfataIO
{
public:
    virtual istream &input(istream &) = 0;
    virtual ostream &output(ostream &) const = 0;
};
class Arma : public interfataIO
{

protected:
    string denumire;
    int razaDeActiune;

public:
    Arma();
    Arma(string denumire, int razaDeActiune);
    Arma(const Arma &obj);
    Arma &operator=(const Arma &obj);
    istream &input(istream &);
    friend istream &operator>>(istream &, const Arma &obj);
    ostream &output(ostream &out) const;
    friend ostream &operator<<(ostream &out, const Arma &obj);
    virtual int getRaza() { return razaDeActiune; }
    virtual string getDenumire() { return denumire; }
    virtual void Atac() const = 0;
};
Arma::Arma()
{
    denumire = "unknown";
    razaDeActiune = 0;
}
Arma::Arma(string denumire, int razaDeActiune)
{
    this->denumire = denumire;
    this->razaDeActiune = razaDeActiune;
}
Arma::Arma(const Arma &obj)
{
    denumire = obj.denumire;
    razaDeActiune = obj.razaDeActiune;
}
Arma &Arma::operator=(const Arma &obj)
{
    if (this != &obj)
    {
        denumire = obj.denumire;
        razaDeActiune = obj.razaDeActiune;
    }
    return *this;
}
ostream &Arma::output(ostream &out) const
{
    out << "Denumire: " << denumire << endl;
    out << "Raza de actiune: " << razaDeActiune << "m" << endl;
    return out;
}
ostream &operator<<(ostream &out, const Arma &obj)
{
    return obj.output(out);
}
istream &Arma::input(istream &in)
{

    cout << "Denumire: ";
    in >> denumire;
    cout << endl
         << "Raza de actiune: ";
    in >> razaDeActiune;
    cout << endl;
    return in;
}

// metode Arma
class ArmaAlba : virtual public Arma
{
protected:
    string modActiune; // taiere, impungere, lovire
    int dimensiune;    // cm
public:
    ArmaAlba();
    ArmaAlba(string denumire, int razaDeActiune, string modActiune, int dimensiune);
    ArmaAlba(const ArmaAlba &obj);
    ArmaAlba &operator=(const ArmaAlba &obj);
    string getModActiune() const { return modActiune; }
    void Atac() const;
    friend ostream &operator<<(ostream &, const ArmaAlba &obj);
    ostream &output(ostream &) const;
    istream &input(istream &);
    friend istream &operator>>(istream &, const ArmaAlba &obj);
};
ArmaAlba::ArmaAlba() : Arma()
{
    modActiune = "unknown";
    dimensiune = 0;
}
ArmaAlba::ArmaAlba(string denumire, int razaDeActiune, string modActiune, int dimensiune) : Arma(denumire, razaDeActiune)
{
    this->modActiune = modActiune;
    this->dimensiune = dimensiune;
}
ArmaAlba::ArmaAlba(const ArmaAlba &obj) : Arma(obj)
{
    modActiune = obj.modActiune;
    dimensiune = obj.dimensiune;
}
ArmaAlba &ArmaAlba::operator=(const ArmaAlba &obj)
{
    if (this != &obj)
    {
        Arma::operator=(obj);
        modActiune = obj.modActiune;
        dimensiune = obj.dimensiune;
    }
    return *this;
}
void ArmaAlba::Atac() const
{
    PlaySound(TEXT("C:\\Users\\user\\Documents\\C++\\proiect oop 2\\sound\\ArmaAlba.wav"), NULL, SND_ASYNC);
    // system("pause");
    Sleep(1500);
    cout << "atac prin " << modActiune;
}
ostream &operator<<(ostream &out, const ArmaAlba &obj)
{
    return obj.output(out);
}
ostream &ArmaAlba::output(ostream &out) const
{
    Arma::output(out);
    out << "Mod de actiune: " << modActiune << endl;
    out << "Dimensiune: " << dimensiune << "cm" << endl;
    return out;
}
istream &ArmaAlba::input(istream &in)
{
    Arma::input(in);
    cout << "Modul de actiune: ";
    in >> modActiune;
    cout << endl
         << "Dimensiune: ";
    in >> dimensiune;
    cout << endl;
    return in;
}
istream &operator>>(istream &in, ArmaAlba &obj)
{
    return obj.input(in);
}
class ArmaDeFoc : virtual public Arma
{
protected:
    string model;
    int nrSerie;
    float calibru; // mm
public:
    ArmaDeFoc();
    ArmaDeFoc(string denumire, int razaDeActiune, string model, int nrSerie, float calibru);
    ArmaDeFoc(const ArmaDeFoc &obj);
    ArmaDeFoc &operator=(const ArmaDeFoc &obj);
    void Atac() const;
    ostream &output(ostream &out) const;
    friend ostream &operator<<(ostream &, const ArmaDeFoc &obj);
    istream &input(istream &in);
    friend istream &operator>>(istream &in, ArmaDeFoc &obj);
};
// metode ArmaDeFoc
ArmaDeFoc::ArmaDeFoc() : Arma()
{
    model = "unknown";
    nrSerie = 0;
    calibru = 0;
}
ArmaDeFoc::ArmaDeFoc(string denumire, int razaDeActiune, string model, int nrSerie, float calibru) : Arma(denumire, razaDeActiune)
{
    this->model = model;
    this->nrSerie = nrSerie;
    this->calibru = calibru;
}
ArmaDeFoc::ArmaDeFoc(const ArmaDeFoc &obj) : Arma(obj)
{
    this->model = obj.model;
    this->nrSerie = obj.nrSerie;
    this->calibru = obj.calibru;
}
ArmaDeFoc &ArmaDeFoc::operator=(const ArmaDeFoc &obj)
{
    if (this != &obj)
    {
        Arma::operator=(obj);
        this->model = obj.model;
        this->nrSerie = obj.nrSerie;
        this->calibru = obj.calibru;
    }
    return *this;
}
void ArmaDeFoc::Atac() const
{
    PlaySound(TEXT("C:\\Users\\user\\Documents\\C++\\proiect oop 2\\sound\\ArmaDeFoc.wav"), NULL, SND_ASYNC);
    // system("pause");
    Sleep(1500);
    cout << "impuscatura:POC!!!!!";
}
ostream &ArmaDeFoc::output(ostream &out) const
{
    Arma::output(out);
    out << "Model: " << model << endl;
    out << "nrSerie: " << nrSerie << endl;
    out << "Calibru: " << calibru << endl;
    return out;
}
ostream &operator<<(ostream &out, const ArmaDeFoc &obj)
{
    return obj.output(out);
}
istream &ArmaDeFoc::input(istream &in)
{
    Arma::input(in);
    cout << "Model: ";
    in >> model;
    cout << endl
         << "Nr. Serie: ";
    in >> nrSerie;
    cout << endl
         << "Calibru: ";
    in >> calibru;
    cout << endl;
    return in;
}
istream &operator>>(istream &in, ArmaDeFoc &obj)
{
    return obj.input(in);
}
class Pusca : public ArmaDeFoc
{
protected:
    int gloantePerFoc;

public:
    Pusca();
    Pusca(string denumire, int razaDeActiune, string model, int nrSerie, float calibru, int gloantePerFoc);
    Pusca(const Pusca &obj);
    void Atac() const;
    Pusca &operator=(const Pusca &obj);
    ostream &output(ostream &out) const;
    friend ostream &operator<<(ostream &out, const Pusca &obj);
    istream &input(istream &in);
    friend istream &operator>>(istream &in, Pusca &obj);
};
Pusca::Pusca() : ArmaDeFoc()
{
    gloantePerFoc = 0;
}
Pusca::Pusca(string denumire, int razaDeActiune, string model, int nrSerie, float calibru, int gloantePerFoc) : Arma(denumire,razaDeActiune),ArmaDeFoc(denumire, razaDeActiune, model, nrSerie, calibru)
{
    this->gloantePerFoc = gloantePerFoc;
}
Pusca::Pusca(const Pusca &obj) : ArmaDeFoc(obj)
{

    gloantePerFoc = obj.gloantePerFoc;
}
ostream &Pusca::output(ostream &out) const
{
    ArmaDeFoc::output(out);
    out << "Gloante per tragere: " << gloantePerFoc << endl;
    return out;
}
ostream &operator<<(ostream &out, const Pusca &obj)
{
    return obj.output(out);
}
istream &Pusca::input(istream &in)
{
    ArmaDeFoc::input(in);
    cout << "Gloante per foc: ";
    in >> gloantePerFoc;
    cout << endl;
    return in;
}
istream &operator>>(istream &in, Pusca &obj)
{
    return obj.input(in);
}
Pusca &Pusca::operator=(const Pusca &obj)
{
    if (this != &obj)
    {
        ArmaDeFoc::operator=(obj);
        gloantePerFoc = obj.gloantePerFoc;
    }
    return *this;
}
void Pusca::Atac() const
{
    PlaySound(TEXT("C:\\Users\\user\\Documents\\C++\\proiect oop 2\\sound\\Pusca.wav"), NULL, SND_ASYNC);
    // system("pause");
    Sleep(1500);
    cout << "impuscatura:puf!";
}
class PuscaAutomata : public ArmaDeFoc
{
protected:
    int capacitateIncarcator;
    int rataDeFoc;

public:
    PuscaAutomata();
    PuscaAutomata(string denumire, int razaDeActiune, string model, int nrSerie, float calibru, int capacitateIncarcator, int rataDeFoc);
    PuscaAutomata(const PuscaAutomata &obj);
    PuscaAutomata &operator=(const PuscaAutomata &obj);
    void Atac() const;
    ostream &output(ostream &) const;
    friend ostream &operator<<(ostream &, const PuscaAutomata &obj);
    istream &input(istream &in);
    friend istream &operator>>(istream &in, PuscaAutomata &obj);
};
PuscaAutomata::PuscaAutomata() :Arma(), ArmaDeFoc()
{
    capacitateIncarcator = 0;
    rataDeFoc = 0;
}
PuscaAutomata::PuscaAutomata(string denumire, int razaDeActiune, string model, int nrSerie, float calibru, int capacitateIncarcator, int rataDeFoc) :Arma(denumire,razaDeActiune), ArmaDeFoc(denumire, razaDeActiune, model, nrSerie, calibru)
{
    this->capacitateIncarcator = capacitateIncarcator;
    this->rataDeFoc = rataDeFoc;
}
PuscaAutomata::PuscaAutomata(const PuscaAutomata &obj) : ArmaDeFoc(obj)
{

    capacitateIncarcator = obj.capacitateIncarcator;
    rataDeFoc = obj.rataDeFoc;
}
PuscaAutomata &PuscaAutomata::operator=(const PuscaAutomata &obj)
{
    if (this != &obj)
    {
        ArmaDeFoc::operator=(obj);
        capacitateIncarcator = obj.capacitateIncarcator;
        rataDeFoc = obj.rataDeFoc;
    }

    return *this;
}
void PuscaAutomata::Atac() const
{
    PlaySound(TEXT("C:\\Users\\user\\Documents\\C++\\proiect oop 2\\sound\\PuscaAutomata.wav"), NULL, SND_ASYNC);
    // system("pause");
    Sleep(1500);
    cout << "impuscatura:puf!";
}
ostream &PuscaAutomata::output(ostream &out) const
{
    ArmaDeFoc::output(out);
    out << "Capacitatea incarcatorului: " << capacitateIncarcator << "gloante" << endl;
    out << "Rata de tragere: " << rataDeFoc << "gloante pe minut" << endl;
    return out;
}
ostream &operator<<(ostream &out, const PuscaAutomata &obj)
{
    return obj.output(out);
}
istream &PuscaAutomata::input(istream &in)
{
    ArmaDeFoc::input(in);
    cout << "Capacitatea incarcatorului(gloante): ";
    in >> capacitateIncarcator;
    cout << endl
         << "Rata de tragere(gloante/minut): ";
    in >> rataDeFoc;
    cout << endl;
    return in;
}
istream &operator>>(istream &in, PuscaAutomata &obj)
{
    return obj.input(in);
}
class Baioneta : public ArmaDeFoc, public ArmaAlba
{
protected:
public:
    Baioneta();
    Baioneta(string denumire, int razaDeActiune, string model, int nrSerie, float calibru, string modActiune, int dimensiune);
    Baioneta(const Baioneta &obj);
    Baioneta &operator=(const Baioneta &obj);
    virtual void Atac() const;
    ostream &output(ostream &out) const
    {
        Arma::output(out);
        out << "Mod de actiune: " << modActiune << endl;
        out << "Dimensiune: " << dimensiune << "cm" << endl;
        out << "Model: " << model << endl;
        out << "nrSerie: " << nrSerie << endl;
        out << "Calibru: " << calibru << endl;
        return out;
    }
    friend ostream &operator<<(ostream &out, const Baioneta &obj)
    {
        return obj.output(out);
    }
    istream &input(istream &in)
    {
        Arma::input(in);
        cout << "Modul de actiune: impungere ";
        cout << endl;
        modActiune = "impungere";
        cout << "Dimensiune: ";
        in >> dimensiune;
        cout << endl;
        cout << "Model: ";
        in >> model;
        cout << endl
             << "Nr. Serie: ";
        in >> nrSerie;
        cout << endl
             << "Calibru: ";
        in >> calibru;
        cout << endl;
        return in;

        return in;
    }
    friend istream &operator>>(istream &in, Baioneta &obj)
    {
        return obj.input(in);
    }
};
Baioneta::Baioneta() : Arma(), ArmaDeFoc(), ArmaAlba()
{
    modActiune = "impungere";
}
Baioneta::Baioneta(string denumire, int razaDeActiune, string model, int nrSerie, float calibru, string modActiune, int dimensiune) : Arma(denumire, razaDeActiune), ArmaDeFoc(denumire, razaDeActiune, model, nrSerie, calibru), ArmaAlba(denumire, razaDeActiune, modActiune, dimensiune)
{
    this->modActiune = "impungere";
}
Baioneta::Baioneta(const Baioneta &obj) : Arma(obj), ArmaDeFoc(obj), ArmaAlba(obj)
{
}
Baioneta &Baioneta::operator=(const Baioneta &obj)
{
    if (this != &obj)
    {
        Arma::operator=(obj);
        ArmaDeFoc::operator=(obj);
        ArmaAlba::operator=(obj);
    }
    return *this;
}
void Baioneta::Atac() const
{
    PlaySound(TEXT("C:\\Users\\user\\Documents\\C++\\proiect oop 2\\sound\\Pusca.wav"), NULL, SND_ASYNC);
    // system("pause");
    Sleep(1500);
    PlaySound(TEXT("C:\\Users\\user\\Documents\\C++\\proiect oop 2\\sound\\ArmaAlba.wav"), NULL, SND_ASYNC);
    // system("pause");
    Sleep(1500);
    cout << "Te ciurui si apoi te impung";
}
//
void menu(vector<Arma *> a)
{
    int n1 = 1;
    cout << "_______" << endl;
    cout << "|"
         << "MENIU"
         << "|" << endl;
    cout << "¯¯¯¯¯¯¯" << endl;

    while (n1)
    {
        cout << "1.Adauga o arma" << endl;
        cout << "2.Vezi toate armele" << endl;
        cout << "0.iesire" << endl;
        cin >> n1;
        switch (n1)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            int n2 = 3;
            while (n2)
            {
                cout << "Alege tipul de arma: " << endl;

                cout << "1.Arma Alba" << endl;
                cout << "2.Arma De Foc" << endl;
                cout << "3.Baioneta" << endl;
                cout << "0.iesire" << endl;
                cin >> n2;
                switch (n2)
                {
                case 0:
                    n2 = 0;
                    break;
                case 1:
                {
                    ArmaAlba *p = new ArmaAlba;
                    a.push_back(p);
                    cin >> (*p);
                    break;
                }
                case 2:
                {
                    int n3 = 1;
                    cout << "Alege tipul de arma de foc" << endl;
                    ;
                    while (n3)
                    {
                        cout << "1.Pusca" << endl;
                        cout << "2.Pusca Automata" << endl;
                        cout << "3.Generic" << endl;
                        cout << "0.iesire" << endl;
                        cin >> n3;

                        switch (n3)
                        {
                        case 0:
                        {
                            n3 = 0;
                            break;
                        }
                        case 1:
                        {
                            Pusca *p = new Pusca;
                            a.push_back(p);
                            cin >> (*p);
                            break;
                        }
                        case 2:
                        {
                            PuscaAutomata *p = new PuscaAutomata;
                            a.push_back(p);
                            cin >> (*p);
                            break;
                        }
                        case 3:
                        {
                            ArmaDeFoc *p = new ArmaDeFoc;
                            a.push_back(p);
                            cin >> (*p);
                            break;
                        }
                        }
                    }
                    break;
                }
                case 3:
                {
                    Baioneta *p = new Baioneta;
                    a.push_back(p);
                    cin >> (*p);
                    break;
                }
                }
            }
            break;
        }
        case 2:
        {
            int n4 = 1;
            int i = 0;

            while (n4)
            {
                cout << "ARMA: " << a[i]->getDenumire() << endl;
                cout<<i<<endl;
                cout << "1.Vezi detalii" << endl;
                cout << "2.Foloseste" << endl;
                cout << "3.Arma Urmatoare" << endl;
                cout << "4.Arma Precedenta" << endl;
                cout << "0.iesire" << endl;
                cin >> n4;
                switch (n4)
                {
                case 0:
                {
                    n4 = 0;
                    break;
                }
                case 1:
                {
                    cout << *a[i];
                    break;
                }
                case 2:
                {

                    a[i]->Atac();
                    cout << endl;
                    break;
                }
                case 3:
                {   
                    if(i+1<a.size())
                    i++;
                    break;
                }
                case 4:
                {   
                    if(i-1>=0)
                    i--;
                    break;
                }
                }
            }
            break;
        }
        }
    }
}
int main()
{
    vector<Arma *> v;
    ArmaAlba *a = new ArmaAlba("Cutit", 1, "taiere", 30);
    ArmaDeFoc *b = new ArmaDeFoc("Pistol",2000,"Glock",3123,9);
    Pusca *c = new Pusca("ShotGun",1000,"combat",3213,28,2);
    PuscaAutomata *d = new PuscaAutomata("AK-47",2500,"AK203",12312,16,80,600);
    Baioneta *e = new Baioneta("Mosin", 3000, "Nagant",377,20,"dddd",30);
    


    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    v.push_back(e);
    menu(v);
    return 0;
}