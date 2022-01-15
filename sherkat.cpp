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
        std::cout << "3.KHROOJ AZ SAMANE\n";
    }
    void menu_karmandan()
    {
        system("cls");
        std::cout << "\n\n\tBAKHSH MODIRIAT KARBARAN\n\n\n";
        std::cout << "\t*********lotfan bakhs mord nazar ra entekhab konid********* \n";
        std::cout << "1.EZAFE KARDAN KARMDAN\n";
        std::cout << "2.EKHRAJ KARMAND\n";
        std::cout << "3.JOSTO JOO KARMAND BAR ASAS KOD MELLI\n";
        std::cout << "5.NAMYESH TAMAM KARMANDAN\n";
        std::cout << "6.BAZGASHT BE MENU GHABL\n";
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

        std::cout << "----------------------------------------------\n\n";
        std::cout << "Nam karmand : ";
        std::cout << this->get_name() << '\n';

        std::cout << "----------------------------------------------\n\n";
        std::cout << "Family karmand : ";
        std::cout << this->get_family() << '\n';

        std::cout << "----------------------------------------------\n\n";
        std::cout << "Kod Melli karmand : ";
        std::cout << this->get_kode_melli() << '\n';

        std::cout << "----------------------------------------------\n\n";
        std::cout << "Sen karmand : ";
        std::cout << this->get_sen() << '\n';

        std::cout << "----------------------------------------------\n\n";
        std::cout << "Semat karmand : ";
        std::cout << this->get_semat() << '\n';

        std::cout << "----------------------------------------------\n\n";
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
            system("cls");
            std::cout << "\n\n\t DARYAFT ETELEAT KARMAND \n\n";
            if (!Tedad_Karbaran)
            {
                std::cout << "KARBARI VOJOOD NADARAD \n";
                system("pause");
                return;
            }
            for (auto &i : karmand)
            {
                i.Print_Etelaat();
            }
            system("pause");
        }
    };
    /*********************************************************************************************************************************/
    void start()
    {
        int gozine_asli, gozine_karmandan;
        std::vector<core::Karmand> karmand;
        Barname first;
        do
        {
        here:
            menu_asli();
            std::cin >> gozine_asli;
            switch (gozine_asli)
            {
            case 1: // MODIRAT karmandan
            ebteda_karmand:
                menu_karmandan();
                std::cin >> gozine_karmandan;
                switch (gozine_karmandan)
                {
                case 1:
                    first.strat_rec_info(karmand);
                    goto ebteda_karmand;
                case 5:
                    first.start_show_personal_info(karmand);
                    goto ebteda_karmand;
                case 6:
                    goto here;
                default:
                    std::cout << "lotfan gozine monaseb ra vared konid\n";
                    system("pause");
                    goto ebteda_karmand;
                }
                first.strat_rec_info(karmand);
                break;
            case 2:
                first.start_show_personal_info(karmand);
            default:
                break;
            }
        } while (true);
    }
    /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
}
/*********************************************************************************************************************************/
int main()
{
    core::start();
}
