/**     TEMA 3 POO
        RUSE ALICE
        GRUPA 211


Agentia de turism: Exista turisti. Ei au anumite caracteristici (barbati/femei, grupa de
varsta si activitatile preferate). Exista destinatii turistice (Amsterdam, Thassos, etc.). Ele
permit o serie de activitati (plaja, mers pe munte, vizitat muzee, etc.) dintre care unele
pot fi potrivite doar pentru anumite sexe sau grupe de varsta. Unele activitati necesita
un autovehicul personal. O activitate dureaza un numar de zile. O activitate poate fi si
de grup (pot lua mai multi parte la ea). Pentru a ajunge la o destinatie se foloseste fie
transport cu avionul fie transport individual cu autovehiculul. Pentru un grup de turisti
(cu caracterstici si preferinte variate) sa se aleaga o destinatie potrivita si sa se realizeze
un plan de activitati (o lista) pe zile (maxim 14) astfel incat intreg grupul sa fie satisfacut.
Precizari:

● O activitate se desfasoara intr-un anumit loc la destinatie. Daca distanta
de la cazare pana la acel loc este mai mare de 2 Km, este necesar un
autovehicul.
● Unele destinatii permit inchirierea de autovehicule, altele nu.
● Orice activitate dureaza minim jumatate de zi.
● O destinatie poate avea mai multe plaje. O plaje poate fi acoperita cu
nisip sau pietricele mici (mai ales in Grecia).
● Unele plaje sunt de nudisti. Unele plaje de nudisti nu accepta minori.
● Mersul pe munte se poate efectua in grup. La fel si plaja.
● Mersul pe munte necesita un munte. Muntele prezinta diferite trasee de
dificultate usoara/medie/grea. Trasele de dificultate grea sunt interzise
copiilor sub 16 ani sau adultilor peste 90. Unele trasee pe munte necesita
mai multe zile. Dintre acestea unele presupun opriri la o manastire. Unele
manastiri nu accepta vizitatori femei.
● Exista mai multe tipuri de muzee (de arta, de istorie, stiintifice). In
anumite destinatii este interzisa vizitarea muzeelor stiintifice de catre
femei.
● Acelasi tip de activitati poate fi comun mai multor destinatii.
● Un turist care exprima preferinte pentru un anumit tip de activitate poate
omite anumite detalii, fiind indiferent la ele sau le poate preciza (e.g.
plaja; plaja cu nisip; mers pe munte minim 2 zile traseu mediu).


turisti-> b/f, gr varsta, activ pref
transport(av/auto pers)->destinatii->activitati(plaja, munte, muzee)->unele doar pt unii,
activitati->autovehicul pers (d/n)
	  ->durata(nr zile)
	  ->grup(d-/n)
cazare->destinatie act>2km=>auto
destinatii->inchiriere auto d/n
durata activitate minim 1/2 zi
destinatie->mai mlte plaje (nisip/pietre)
plaja-> nudisti->minori d/n /nu

mers munte->munte->trasee->dificultati(greu +16)
trasee de mai multe zile->oprire manastire (da, nu), accept femei(d/n)
muzee(arta/st->femei??)

*/


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int zile=0;

class Preferinta
{
    string activitate;
    string opt;
    int dur;
public:
    Preferinta(string activitate1="", string opt1="", int dur1=0);
    ~Preferinta() {};
    friend istream &operator >>(istream &i, Preferinta &preferinta);
    friend ostream &operator <<(ostream &i, Preferinta preferinta);
    Preferinta& operator =(const Preferinta &preferinta );
    int get_dur()
    {
        return dur;
    };
    string get_activitate()
    {
        return activitate;
    };
    string get_opt()
    {
        return opt;
    };
};


Preferinta:: Preferinta(string activitate1, string opt1, int dur1)
{
    activitate=activitate1;
    opt=opt1;
    dur=dur1;
}

istream &operator>>(istream &i, Preferinta &preferinta)
{
    //cout<<"hei";
    getline(i, preferinta.activitate);
    // cout<<preferinta.activitate;
    getline(i, preferinta.opt);
    i>>preferinta.dur;
    return i;

}
ostream &operator<<(ostream &i, Preferinta preferinta)
{
    i<<preferinta.activitate<<" ";
    i<<preferinta.opt<<" ";
    i<<preferinta.dur<<" zile(minim)";
    i<<"\n";
    return i;
}

Preferinta& Preferinta:: operator =(const Preferinta &preferinta )
{
    activitate=preferinta.activitate;
    opt=preferinta.opt;
    dur=preferinta.dur;
    return *this;
}


class Turist
{
    string nume;
    string prenume;
    int varsta;
    char sex;
    int nr_pref=0;
    Preferinta preferinta[10];///????????????????
public:
    Turist(string nume1="",string prenume1="", int varsta1=0, char sex1=0, int nr_pref1=0, Preferinta preferinta1[10]=NULL );
    ~Turist() {};
    friend istream &operator >>(istream &i, Turist &turist);
    friend ostream &operator <<(ostream &i, Turist turist);
    int get_varsta();
    char get_sex();
    int get_nrpref();
    Preferinta get_pref(int i);
    friend class Destinatie;
};


Turist::Turist(string nume1,string prenume1, int varsta1, char sex1, int nr_pref1, Preferinta preferinta1[10] )
{
    nume=nume1;
    prenume=prenume1;
    varsta=varsta1;
    sex=sex1;
    nr_pref=nr_pref1;
    for(int j=0; j<nr_pref; j++)
        preferinta[j]=preferinta1[j];

}

istream &operator >>(istream &i, Turist &turist)
{
    getline(i, turist.nume);
    getline(i, turist.prenume);
    i>>turist.varsta;
    i>>turist.sex;
    i>>turist.nr_pref;
    for(int k=0; k<turist.nr_pref; k++)
        i>>turist.preferinta[k];
    return i;
}
ostream &operator <<(ostream &i, Turist turist)
{
    i<<turist.nume<<" ";
    i<<turist.prenume<<" ";
    i<<turist.varsta<<" ";
    i<<turist.sex<<" ";
    //i<<turist.nr_pref
    for(int k=0; k<turist.nr_pref; k++)
        i<<turist.preferinta[k];
    i<<"\n";
    return i;
}

int Turist::get_varsta()
{
    return varsta;
}

char Turist::get_sex()
{
    return sex;
}

int Turist::get_nrpref()
{
    return nr_pref;
}

Preferinta Turist::get_pref(int i)
{
    return preferinta[i];
}



class Plaja
{
    string nume;
    string tip; ///pietre/nisip/scoici...
    string locatie;
    bool nudisti;
    bool minori;
    float durata;
    float distanta;

public:
    Plaja(string nume1="", string tip1="", string locatie1="", bool nudisti1=0, bool minori1=0, float durata1=0, float distanta1=0);
    friend istream &operator>>(istream &i, Plaja &plaja);
    friend ostream &operator<<(ostream &i, Plaja plaja);
    Plaja &operator=(const Plaja &plaja);
    string get_tip();
    void set_tip(string tip1);
    string get_locatie();
    void set_locatie(string locatie1);
    bool get_nudisti();
    void set_nudisti(bool nudisti1);
    bool get_minori();
    void set_minori(bool minori1);
    float get_durata();
    void set_durata(float durata1);
    float get_distanta();
    void set_distanta(float distanta1);
    string get_nume()
    {
        return nume;
    };
    bool get_femei()
    {
        return 0;
    };
};

Plaja::Plaja(string nume1, string tip1, string locatie1, bool nudisti1, bool minori1, float durata1, float distanta1)
{
    nume=nume1;
    tip=tip1;
    locatie=locatie1;
    nudisti=nudisti1;
    minori=minori1;
    durata=durata1;
    distanta=distanta1;
}
istream &operator>>(istream &i, Plaja &plaja)
{
    string nume1;
    getline(i,plaja.nume);
    //cout<<nume1;
    // plaja.nume=nume1;
    cout<<plaja.nume;
    getline(i,plaja.tip);
    getline(i,plaja.locatie);
    i>>plaja.nudisti;

    if(plaja.nudisti)
        i>>plaja.minori;
    else
        plaja.minori=0;

    i>>plaja.durata;
    i>>plaja.distanta;


    cout<<plaja.nume<<" ";

    cout<<plaja.tip<<" ";
    cout<<plaja.locatie<<" ";
    if(plaja.nudisti)
    {
        cout<<"Plaja nudisti ";
        if(plaja.minori)
            cout<<"Minorii nu au acces ";
    }
    cout<<plaja.durata<<" zile ";
    cout<<plaja.distanta<<" km \n";
    return i;

}
ostream &operator<<(ostream &i, Plaja plaja)
{
    i<<plaja.nume<<" ";
    cout<<plaja.nume;
    i<<plaja.tip<<" ";
    i<<plaja.locatie<<" ";
    if(plaja.nudisti)
    {
        i<<"Plaja nudisti ";
        if(plaja.minori)
            i<<"Minorii nu au acces ";
    }
    i<<plaja.durata<<" zile ";
    i<<plaja.distanta<<" km \n";
    return i;
}

Plaja& Plaja:: operator=(const Plaja &plaja)

{
    nume=plaja.nume;
    tip=plaja.tip;
    locatie=plaja.locatie;
    nudisti=plaja.nudisti;
    minori=plaja.minori;
    durata=plaja.durata;
    distanta=plaja.distanta;
    return *this;
}

string Plaja::get_tip()
{
    return tip;
}
void Plaja::set_tip(string tip1)
{
    tip=tip1;
}
string Plaja::get_locatie()
{
    return locatie;
}
void Plaja::set_locatie(string locatie1)
{
    locatie=locatie1;
}
bool Plaja::get_nudisti()
{
    return nudisti;
}
void Plaja::set_nudisti(bool nudisti1)
{
    nudisti=nudisti1;
}
bool Plaja::get_minori()
{
    return minori;
}
void Plaja::set_minori(bool minori1)
{
    minori=minori1;
}
float Plaja::get_durata()
{
    return durata;
}
void Plaja::set_durata(float durata1)
{
    durata=durata1;
}
float Plaja::get_distanta()
{
    return distanta;
}
void Plaja::set_distanta(float distanta1)
{
    distanta=distanta1;
}




class Munte
{
    string nume;
    string tip;
    string locatie;
    float durata;
    int nr_opriri;
    ///o clasa separata pt opriri ca sa punem si numele manastirii???
    bool femei;
    float distanta;
public:
    Munte(string nume1="",string tip1="",string locatie1="", float durata1=0, int nr_opriri1=0, bool femei1=0, float distanta1=0 );
    ~Munte() {};
    friend istream &operator>>(istream &i, Munte &munte);
    friend ostream &operator<<(ostream &i, Munte munte);
    Munte &operator=(const Munte munte );
    string get_tip();
    void set_tip(string tip1);
    string get_locatie();
    void set_locatie( string locatie1);
    int get_nr_opriri();
    void set_nr_opriri(int nr_opriri1);
    bool get_femei();
    void set_femei(bool femei1);
    float get_durata();
    void set_durata(float durata1);
    float get_distanta();
    void set_distanta(float distanta1);
    string get_nume()
    {
        return nume;
    };
};
Munte::Munte(string nume1,string tip1,string locatie1, float durata1, int nr_opriri1, bool femei1, float distanta1 )
{
    nume=nume1;
    tip=tip1;
    locatie=locatie1;
    durata=durata1;
    nr_opriri=nr_opriri1;
    femei=femei1;
    distanta=distanta1;

}

istream &operator>>(istream &i, Munte &munte)
{
    getline(i,munte.nume);
    getline(i,munte.tip);
    getline(i,munte.locatie);
    i>>munte.durata;
    if(munte.durata>1)
    {
        i>>munte.nr_opriri;
        if(munte.nr_opriri)
            i>>munte.femei;
        else
            munte.femei=0;


    }
    else
    {
        munte.nr_opriri=0;
        munte.femei=0;
    }
    i>>munte.distanta;

    return i;
}
ostream &operator<<(ostream &i, Munte munte)
{
    i<<munte.nume<<" ";
    i<<munte.tip<<" " ;
    i<<munte.locatie<<" ";
    i<<munte.durata<<" zile ";
    i<<munte.nr_opriri<<" opriri ";
    if(munte.femei)
        i<<"Femeile nu pot intra in manastire ";
    i<<munte.distanta<<" km "<<"\n";
    return i;


}

Munte& Munte::operator=(const Munte munte )
{
    nume=munte.nume;
    tip=munte.tip;
    locatie=munte.locatie;
    durata=munte.durata;
    nr_opriri=munte.nr_opriri;
    femei=munte.femei;
    distanta=munte.distanta;
}

string Munte::get_tip()
{
    return tip;
}
void Munte::set_tip(string tip1)
{
    tip=tip1;
}
string Munte::get_locatie()
{
    return locatie;
}
void Munte::set_locatie( string locatie1)
{
    locatie=locatie1;
}
bool Munte::get_femei()
{
    return femei;
}
void Munte::set_femei(bool femei1)
{
    femei=femei1;
}
int Munte::get_nr_opriri()
{
    return nr_opriri;
}
void Munte::set_nr_opriri(int nr_opriri1)
{
    nr_opriri=nr_opriri1;
}

float Munte::get_durata()
{
    return durata;
}
void Munte::set_durata(float durata1)
{
    durata=durata1;
}
float Munte::get_distanta()
{
    return distanta;
}
void Munte::set_distanta(float distanta1)
{
    distanta=distanta1;
}


class Muzeu
{
    string nume;
    string tip;///arta, stiinte, istorie
    string locatie;
    bool femei;
    float durata;
    float distanta;
public:
    Muzeu(string nume1="", string tip1="",string locatie1="", bool femei1=0, float durata1=0, float distanta1=0);
    ~Muzeu() {};
    friend istream &operator>>(istream &i, Muzeu &muzeu);
    friend ostream &operator<<(ostream &i, Muzeu muzeu);
    Muzeu &operator=(const Muzeu &muzeu);
    string get_tip();
    void set_tip( string tip1);
    string get_locatie();
    void set_locatie( string locatie1);
    bool get_femei();
    void set_femei(bool femei1);
    float get_durata();
    void set_durata(float durata1);
    float get_distanta();
    void set_distanta(float distanta1);
    string get_nume()
    {
        return nume;
    };

};

Muzeu::Muzeu(string nume1, string tip1,string locatie1, bool femei1, float durata1, float distanta1)
{
    nume=nume1;
    tip=tip1;
    locatie=locatie1;
    femei=femei1;
    durata=durata1;
    distanta=distanta1;
}
istream &operator>>(istream &i, Muzeu &muzeu)
{

    getline(i,muzeu.nume);
    getline(i,muzeu.tip);
    getline(i,muzeu.locatie);
    if(muzeu.tip=="stiinte")
        i>>muzeu.femei;
    else
        muzeu.femei=0;
    i>>muzeu.durata;
    i>>muzeu.distanta;
    return i;

}
ostream &operator<<(ostream &i, Muzeu muzeu)
{
    i<<muzeu.nume;
    i<<" ";
    i<<muzeu.tip;
    i<<" ";
    i<<muzeu.locatie;
    i<<" ";
    if(muzeu.femei)
        i<<"Femeile nu pot intra ";
    i<<muzeu.durata<<" zile ";
    i<<muzeu.distanta<<" km ";
    i<<"\n";
    return i;
}

Muzeu& Muzeu::operator=(const Muzeu &muzeu)
{
    nume=muzeu.nume;
    tip=muzeu.tip;
    locatie=muzeu.locatie;
    femei=muzeu.femei;
    durata=muzeu.durata;
    distanta=muzeu.distanta;
}

string Muzeu::get_tip()
{
    return tip;

}
void Muzeu::set_tip( string tip1)
{
    tip=tip1;
}
string Muzeu::get_locatie()
{
    return locatie;
}
void Muzeu::set_locatie( string locatie1)
{
    locatie=locatie1;
}
bool Muzeu::get_femei()
{
    return femei;
}
void Muzeu::set_femei(bool femei1)
{
    femei=femei1;
}
float Muzeu::get_durata()
{
    return durata;
}
void Muzeu::set_durata(float durata1)
{
    durata=durata1;
}
float Muzeu::get_distanta()
{
    return distanta;
}
void Muzeu::set_distanta(float distanta1)
{
    distanta=distanta1;
}


class Program : public Preferinta
{
    string nume;
    string descriere;
    int dur;
public:

    Program(string nume1="", string descriere1="", int dur1=0):Preferinta()
    {
        nume=nume1;
        descriere=descriere1;
        dur=dur1;
    }
    ~Program() {};
    friend istream &operator>>(istream &i, Program &program);
    friend ostream &operator<<(ostream &i, Program program);
    int get_dur()
    {
        return dur;
    };
    void set_dur(int i)
    {
        dur=i;
    };
    string get_nume()
    {
        return nume;
    };
    string get_descriere()
    {
        return descriere;
    };
    void set_nume(string n)
    {
        nume=n;
    };
    void set_descriere(string d)
    {
        descriere=d;
    };
};
istream &operator>>(istream &i, Program &program)
{
    getline(i, program.nume);

    i>>program;
    return i;
}
ostream &operator<<(ostream &i, Program program)
{
    i<<program.nume<<" ";
    i<<program<<" ";
    i<<"\n";
    return i;
}

class Destinatie
{
    string nume_dest;
    bool inchiriere_vehicul;
    string transport;///????? aici sau la fiecare? merg toti cu acelasi mijloc de transport??
    int nr_plaje;
    int nr_munti;
    int nr_muzee;
    Plaja plaja[10];
    Munte munte[10];
    Muzeu muzeu[10];
    Program program[15];
    int pr=0;
public:
    ///metode
    Destinatie(string nume_dest1="", bool inchiriere_vehicul1=0, string transport1="", int nr_plaje1=0, int nr_munti1=0, int nr_muzee1=0,Plaja plaja1[10]=NULL, Munte munte1[10]=NULL, Muzeu muzeu1[10]=NULL);
    ~Destinatie() {};
    friend istream &operator>>(istream &i, Destinatie &destinatie);
    friend ostream &operator<<(ostream &i, Destinatie destinatie);
    friend class Turist;
    bool get_vehicul()
    {
        return inchiriere_vehicul;
    };
    int get_nrplaje()
    {
        return nr_plaje;
    };
    int get_nrmuzee()
    {
        return nr_muzee;
    };
    int get_nrmunti()
    {
        return nr_munti;
    };
    int get_pr()
    {
        return pr;
    };
    void set_pr(int i)
    {
        pr=1;
    };
    Plaja get_plaja(int i)
    {
        return plaja[i];
    };
    Munte get_munte(int i)
    {
        return munte[i];
    };
    Muzeu get_muzeu(int i)
    {
        return muzeu[i];
    };
    void set_program(int i, int val) {};
    Program get_program(int i)
    {
        return program[i];
    }
};

Destinatie::Destinatie(string nume_dest1, bool inchiriere_vehicul1, string transport1, int nr_plaje1, int nr_munti1, int nr_muzee1,Plaja plaja1[10], Munte munte1[10], Muzeu muzeu1[10])
{
    nume_dest=nume_dest1;
    inchiriere_vehicul=inchiriere_vehicul1;
    transport=transport1;
    nr_plaje=nr_plaje1;
    nr_munti=nr_munti1;
    nr_muzee=nr_muzee1;
    for(int k=0; k<nr_plaje; k++)
        plaja[k]=plaja1[k];
    for(int k=0; k<nr_plaje; k++)
        munte[k]=munte1[k];
    for(int k=0; k<nr_muzee; k++)
        muzeu[k]=muzeu1[k];
}
istream &operator>>(istream &i, Destinatie &destinatie)
{
    getline(i, destinatie.nume_dest);
    i>>destinatie.inchiriere_vehicul;
    getline(i, destinatie.transport);
    i>>destinatie.nr_plaje;
    i>>destinatie.nr_munti;
    i>>destinatie.nr_muzee;
    for(int k=0; k<destinatie.nr_plaje; k++)
        i>>destinatie.plaja[k];
    for(int k=0; k<destinatie.nr_plaje; k++)
        i>>destinatie.munte[k];
    for(int k=0; k<destinatie.nr_muzee; k++)
        i>>destinatie.muzeu[k];
    return i;

}
ostream &operator<<(ostream &i, Destinatie destinatie)
{
    i<<destinatie.nume_dest<<" ";
    i<<destinatie.inchiriere_vehicul<<" ";
    i<<destinatie.transport<<" ";
    i<<destinatie.nr_plaje<<" ";
    i<<destinatie.nr_munti<<" ";
    i<<destinatie.nr_muzee<<" ";
    for(int k=0; k<destinatie.nr_plaje; k++)
        i<<destinatie.plaja[k]<<" ";
    for(int k=0; k<destinatie.nr_munti; k++)
        i<<destinatie.munte[k]<<" ";
    for(int k=0; k<destinatie.nr_muzee; k++)
        i<<destinatie.muzeu[k]<<" ";
    i<<"\n";
    return i;
}
///verificam dca e potrivit pt femei
template <class T> bool verif_fem(T activ,int nr_turisti, Turist turist[20])///---------------------------------
{
    int ok=0;
    for(int i=0; i<nr_turisti; i++)
    {
        if(turist[i].get_sex()=='f')
            ok=1;
    }
    if (ok==1 && activ.get_femei()==1)
        return 0;
    else
        return 1;
}


bool verif_minori(Plaja activ,int nr_turisti, Turist turist[20])
{
    int ok=0;
    for(int i=0; i<nr_turisti; i++)
    {
        if(turist[i].get_varsta()<18)
            ok=1;
    }
    if (ok==1 && activ.get_minori()==1)
        return 0;
    else
        return 1;
}

bool verif_traseu(Munte munti,int nr_turisti, Turist turist[20])
{
    int ok=0;
    for(int i=0; i<nr_turisti; i++)
    {
        if(turist[i].get_varsta()<16 ||turist[i].get_varsta()>90 )
            ok=1;
    }
    if (ok==1 && munti.get_tip()=="greu")
        return 0;
    else
        return 1;
}

template <class T> bool verif_transport(T activ, Destinatie dest)
{
    if(activ.get_distanta()>2 && dest.get_vehicul()==0)
        return 0;
    else return 1;
}

int maxim(int v[20],int n)
{
    int maxx=0;
    for(int i=0; i<n; i++)
    {
        if(maxx<v[i])
            maxx=v[i];
    }
    return maxx;
}




int durata_minima(  string activ,Turist turist[20],int  nr_turisti)
{
    int i=0;
    Preferinta p;
    int durata[20];
    for(int j=0; j<nr_turisti; j++)
    {
        for(int k=0; k<turist[j].get_nrpref(); k++)

        {
            //p=turist[j].get_pref();///------------------------------- get, nu e metoda
            if( turist[j].get_pref(k).get_activitate()==activ)
                durata[i]=turist[j].get_pref(k).get_dur();
            i++;
        }
    }
    return maxim(durata, i);
}


/**

define pt plaja 1, munte 2, etc
o singura clasa cu destiatiile
 distanta de la cazare??? cum fac????


 Copacabana
nisip
Brazilia
0
0.5
2.5


Alpi
greu
Elvetia
2
3
0
2.5


VanGogh
arta
Amsterdam
1
5


Popescu
Vasile
30
b
2

*/



Destinatie cautare_destinatie(int nr_turisti, Turist turist[20],int  nr_destinatii, Destinatie rezultat[10], Destinatie destinatie[20])
{
    int p_plaja=0, p_munte=0, p_muzeu=0, zile_plaja=0, zile_munte=0, zile_muzeu=0, zile_totale=0, rez=0, z;

    string optiune, act;
    for(int j=0; j<nr_turisti; j++)
    {
        for(int k=0; k<turist[j].get_nrpref(); k++)
        {
            optiune=turist[j].get_pref(k).get_opt();
            act=turist[j].get_pref(k).get_activitate() ;
            for(int i=0; i<nr_turisti; i++)
            {
                for(int m=0; m<turist[i].get_nrpref(); m++)
                {
                    if(act==turist[i].get_pref(m).get_activitate() && optiune!=turist[i].get_pref(m).get_opt() && i!=j)
                        if(act=="plaja")
                            p_plaja=-1;
                    if(act=="munte")
                        p_munte=-1;
                    if(act=="muzeu")
                        p_muzeu=-1;
                }
            }
        }
    }

    for(int j=0; j<nr_turisti; j++)
    {
        for(int k=0; k<turist[j].get_nrpref(); k++)
        {
            act=turist[j].get_pref(k).get_activitate() ;
            if(act=="plaja")
                p_plaja=1;
            if(act=="munte")
                p_munte=1;
            if(act=="muzeu")
                p_muzeu=1;
        }
    }
    if(p_plaja==1)
    {
        zile_plaja=durata_minima("plaja", turist, nr_turisti);

        for(int w=0; w<nr_destinatii; w++)
        {
            if(destinatie[w].get_nrplaje()!=0)
            {
                for(int q=0; q<destinatie[w].get_nrplaje(); q++) ///verificam chestii
                {
                    z=zile_plaja/destinatie[w].get_plaja(q).get_durata();///de cate ori tb sa faca activitatea
                    if(verif_transport(destinatie[w].get_plaja(q), destinatie[w]) && verif_fem(destinatie[w].get_plaja(q),nr_turisti, turist) && verif_minori(destinatie[w].get_plaja(q),nr_turisti, turist) && zile_totale+z<=14)
                        ///
                    {
                        destinatie[w].get_program(destinatie[w].get_pr()).set_nume(destinatie[w].get_plaja(q).get_nume());
                        destinatie[w].get_program(destinatie[w].get_pr()).set_descriere(destinatie[w].get_plaja(q).get_tip());
                        destinatie[w].get_program(destinatie[w].get_pr()).set_dur(destinatie[w].get_plaja(q).get_durata());
                        destinatie[w].set_pr(destinatie[w].get_pr()+1);
                        rezultat[rez]=destinatie[w];
                        rez++;

                    }


                }
            }
        }



    }
    if(p_munte==1)
    {
        zile_munte=durata_minima("munte", turist, nr_turisti);
        for(int w=0; w<nr_destinatii; w++)
        {
            if(destinatie[w].get_nrmunti()!=0)
            {
                for(int q=0; q<destinatie[w].get_nrmunti(); q++) ///verificam chestii
                {

                    z=zile_munte/destinatie[w].get_munte(q).get_durata();///de cate ori tb sa faca activitatea
                    if(verif_transport(destinatie[w].get_munte(q), destinatie[w]) && verif_fem(destinatie[w].get_munte(q),nr_turisti, turist) &&verif_traseu(destinatie[w].get_munte(q),nr_turisti, turist) && zile_totale+z<=14)
                    {
                        destinatie[w].get_program(destinatie[w].get_pr()).set_nume(destinatie[w].get_munte(q).get_nume());
                        destinatie[w].get_program(destinatie[w].get_pr()).set_descriere(destinatie[w].get_munte(q).get_tip());
                        destinatie[w].get_program(destinatie[w].get_pr()).set_dur(destinatie[w].get_munte(q).get_durata());
                        destinatie[w].set_pr(destinatie[w].get_pr()+1);

                        rezultat[rez]=destinatie[w];
                        rez++;
                    }
                }
            }

        }

    }




    if(p_muzeu==1)
        zile_muzeu=durata_minima("muzeu", turist, nr_turisti);
    for(int w=0; w<nr_destinatii; w++)
    {
        if(destinatie[w].get_nrmuzee()!=0)
        {
            for(int q=0; q<destinatie[w].get_nrmuzee(); q++) ///verificam chestii
            {

                z=zile_muzeu/destinatie[w].get_muzeu(q).get_durata();///de cate ori tb sa faca activitatea
                {
                    if(verif_transport(destinatie[w].get_muzeu(q), destinatie[w]) && verif_fem(destinatie[w].get_muzeu(q),nr_turisti, turist)  && zile_totale+z<=14)
                    {
                        destinatie[w].get_program(destinatie[w].get_pr()).set_nume(destinatie[w].get_muzeu(q).get_nume());
                        destinatie[w].get_program(destinatie[w].get_pr()).set_descriere(destinatie[w].get_muzeu(q).get_tip());
                        destinatie[w].get_program(destinatie[w].get_pr()).set_dur(destinatie[w].get_muzeu(q).get_durata());
                        destinatie[w].set_pr(destinatie[w].get_pr()+1);

                        rezultat[rez]=destinatie[w];
                        rez++;
                    }
                }
            }

        }

    }
    return *rezultat;
}








int main()
{
    int nr_turisti, nr_destinatii;
    Destinatie rezultat[10], destinatie[20];
    Preferinta pref[2];
    Turist turist[20];
    for(int k=0; k<2; k++)
        fin>>pref[k];
    for(int k=0; k<2; k++)
        cout<<pref[k];

    /**
        Turist turist[2];
        fin>>turist[0];
        cout<<turist[0];
        Turist turist[2];
        for(int j=0;j<2;j++)
            f>>turist[j];
        for(int j=0;j<2;j++)
            cout<<turist[j];


    //Muzeu plj;
    //fin>>plj;
    //cout<<plj;
    ///string str;
    ///getline(fin, str);
    ///cout<<str;
    */
}
