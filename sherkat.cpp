#include <iostream>
#include <string>
#include <vector>
namespace core
{
    void menu_asli()
    {
        system("cls");
        std::cout << "\n\n\tBE SYSTEM YEKPARCHE MODIRIAT KHOSH AMADID \n\n\n";
        std::cout << "*********lotfan bakhs mord nazar ra entekhab konid********* \n";
        std::cout << "1.BAKHSH MODIRAT KARMANDAN \n";
        std::cout << "2.BAKSH MODIRAIT MALI\n";
    }
    void timer(int x) // ignore it :)))
    {
        for (size_t z = 0; z < 1; z++)
        {
            for (size_t i = 0; i < 100000; i++)
            {
                for (size_t j = 0; j < x; j++)
                {
                }
            }
        }
    }
    using lli = long long int;
    using string = std::string;
    int Tedad_Karbaran{0}; // tedad karbaran vared shode
    /************************************************************************************************************************************/
    class Karmand // zir system etelat karmandan
    {
    public:
        Karmand() = default;
        // Karmand(string, string, int, string, string, lli);
        string get_name();
        string get_family();
        string get_kode_melli();
        string get_semat();
        lli get_hoghhogh();
        int get_sen();
        void Daryaft_Etelat(); // daryaft etelat az karbar
        void Print_Etelaat();

    protected:
        string m_name;
        string m_family;
        int m_sen;
        string m_kode_melli;
        string m_semat;
        lli m_hoghhogh;
    };
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    string Karmand::get_name()
    {
        return m_name;
    }
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    string Karmand::get_family()
    {
        return m_family;
    }
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    string Karmand::get_kode_melli()
    {
        return m_kode_melli;
    }
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    string Karmand::get_semat()
    {
        return m_semat;
    }
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    lli Karmand::get_hoghhogh()
    {
        return m_hoghhogh;
    }
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    int Karmand::get_sen()
    {
        return m_sen;
    }
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    void Karmand::Daryaft_Etelat()
    {
        system("cls");
        std::cout << "\n\n\t DARYAFT ETELEAT KARMAND \n\n";

        std::cout << "----------------------------------------------\n\n";
        std::cout << "Nam karmand : ";

        std::getline(std::cin >> std::ws, this->m_name);
        std::cout << "----------------------------------------------\n\n";

        std::cout << "Family karmand : ";
        std::getline(std::cin >> std::ws, this->m_family);
        std::cout << "----------------------------------------------\n\n";

        std::cout << "Kod Melli karmand : ";
        std::getline(std::cin >> std::ws, this->m_kode_melli);
        std::cout << "----------------------------------------------\n\n";

        std::cout << "Sen karmand : ";
        std::cin >> this->m_sen;
        std::cout << "----------------------------------------------\n\n";

        std::cout << "Semat karmand : ";
        std::getline(std::cin >> std::ws, this->m_semat);
        std::cout << "----------------------------------------------\n\n";

        std::cout << "etelalt ba moafaghiat sabt shod ! \n";
        Tedad_Karbaran++;
    }
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
    void Karmand::Print_Etelaat()
    {
        system("cls");
        std::cout << "\n\n\t NAMYESH ETELEAT KARMAND \n\n";
        if (!Tedad_Karbaran)
        {
            std::cout << "KARBARI VOJOOD NADARAD \n";
        }
        else
        {
            // for (int i = 0; i < Tedad_Karbaran; ++i)
            // {
            std::cout << "----------------------------------------------\n\n";
            std::cout << "Nam karmand : ";
            std::cout << vector[i].m_name;

            std::cout << "----------------------------------------------\n\n";
            std::cout << "Family karmand : ";
            std::cout << vector[i].m_family;

            std::cout << "----------------------------------------------\n\n";
            std::cout << "Kod Melli karmand : ";
            std::cout << vector[i].m_kode_melli;

            std::cout << "----------------------------------------------\n\n";
            std::cout << "Sen karmand : ";
            std::cout << vector[i].m_sen;

            std::cout << "----------------------------------------------\n\n";
            std::cout << "Semat karmand : ";
            std::cout << vector[i].m_semat;

            std::cout << "----------------------------------------------\n\n";
            // }
        }
    }
    /*||||||||||||||||||||||||||||||||||||||||||||||F|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

    /*******************************************************************************************************************************/
    class Pardakht : public Karmand // zir system pardakht hoghoogh
    {
    public:
    };
    /*******************************************************************************************************************************/
    class Barname
    {
    public:
        void strat_rec_info(std::vector<Karmand> &karmand)
        {
            Pardakht p;
            p.Daryaft_Etelat();
            karmand.push_back(p);
        }
        void start_show_personal_info(std::vector<Karmand> &karmand)
        {
            for (auto const &i : karmand)
            {
                i.Print_Etelaat();
            }
        }
    };
    /*********************************************************************************************************************************/
    void start()
    {
        std::cout << "kodoom gozine?";
        int gozine;
        std::cin >> gozine;
        std::vector<core::Karmand> karmand;
        Barname first;
        switch (gozine)
        {
        case 1:
            first.strat_rec_info(karmand);
            break;
        case 2:
            first.start_show_personal_info(karmand);
        default:
            break;
        }
    }
}
/*********************************************************************************************************************************/
int main()
{
    core::start();
}
